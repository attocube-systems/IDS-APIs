from . import ACS
from .pilotlaser import Pilotlaser
from .update import Update
from .system import System
from .nlc import Nlc
from .realtime import Realtime
from .access import Access
from .adjustment import Adjustment
from .ecu import Ecu
from .manual import Manual
from .system_service import System_service
from .about import About
from .axis import Axis
from .network import Network
from .displacement import Displacement
try:
    from .streaming.streaming import Streaming
except:
    pass


class Device(ACS.Device):
    def __init__(self, address):
        super().__init__(address)
        self.pid = "sen"
        self.pilotlaser = Pilotlaser(self)
        self.update = Update(self)
        self.system = System(self)
        self.nlc = Nlc(self)
        self.realtime = Realtime(self)
        self.access = Access(self)
        self.adjustment = Adjustment(self)
        self.ecu = Ecu(self)
        self.manual = Manual(self)
        self.system_service = System_service(self)
        self.about = About(self)
        self.axis = Axis(self)
        self.network = Network(self)
        self.displacement = Displacement(self)
        
        try:
            self.streaming = Streaming(self)
        except NameError as e:
            if "Streaming" in str(e):
                print("Warning: Streaming is not supported on your platform")
            else:
                raise e
        

def discover():
    return Device.discover("sen")
