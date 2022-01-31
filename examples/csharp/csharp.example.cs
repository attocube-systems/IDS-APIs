using Attocube.IDS;
using Attocube.API;
using System;
using System.Threading;

namespace Example
{
    public class ExampleTest
    {
        static void Main(string[] args)
        {
            AttocubeIDS ids = new AttocubeIDS();
            string IP = "192.168.1.1";

            // Connect to TCP API (Port 9090)
            ids.Connect(IP, 9090);

            // Measure on axis 1
            // Internally, axes are numbered 0 to 2
            int axis = 0; // Axis 1

            // Start alignment
            ids.System_StartOpticsAlignment();

            // Wait until alignment is running
            while (!ids.Adjustment_GetAdjustmentEnabled()) {
                Thread.Sleep(1000);
            }

            // Get contrast
            var result = ids.Adjustment_GetContrastInPermille(axis);
            Console.WriteLine("Contrast: {0}, Baseline: {1}, Mixcontent: {2}", result.Item2, result.Item3, result.Item4);

            // Stop alignment and start measurement
            ids.System_StopOpticsAlignment();
            while (!ids.System_GetCurrentMode().Equals("system idle")) {
                Thread.Sleep(1000);
            }
            ids.System_SetInitMode(0); // enable high accuracy mode
            ids.System_StartMeasurement();

            // Wait until alignment is running
            while (!ids.Displacement_GetMeasurementEnabled()) {
                Thread.Sleep(1000);
            }

            // Get position
            var abspos = ids.Displacement_GetAbsolutePosition(axis);
            Console.WriteLine("Position {0} pm", abspos.Item2);

            // Stop measurement
            ids.System_StopMeasurement();

            ids.Disconnect();
        }
    }
}
