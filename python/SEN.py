from . import ACS
from .network import Network
from .nlc import Nlc
from .realtime import Realtime
from .system import System
from .adjustment import Adjustment
from .ecu import Ecu
from .pilotlaser import Pilotlaser
from .update import Update
from .axis import Axis
from .about import About
from .displacement import Displacement
from .manual import Manual
from .system_service import System_service
try:
    from .streaming.streaming import Streaming
except:
    pass


class Device(ACS.Device):
    def __init__(self, address):
        super().__init__(address)

        self.network = Network(self)
        self.nlc = Nlc(self)
        self.realtime = Realtime(self)
        self.system = System(self)
        self.adjustment = Adjustment(self)
        self.ecu = Ecu(self)
        self.pilotlaser = Pilotlaser(self)
        self.update = Update(self)
        self.axis = Axis(self)
        self.about = About(self)
        self.displacement = Displacement(self)
        self.manual = Manual(self)
        self.system_service = System_service(self)
        
        try:
            self.streaming = Streaming(self)
        except NameError as e:
            if "Streaming" in str(e):
                print("Warning: Streaming is not supported on your platform")
            else:
                raise e
        

def discover():
    return Device.discover("sen")
