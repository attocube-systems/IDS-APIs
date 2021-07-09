import ACS
from about import About
from access import Access
from adjustment import Adjustment
from axis import Axis
from displacement import Displacement
from ecu import Ecu
from manual import Manual
from network import Network
from nlc import Nlc
from pilotlaser import Pilotlaser
from realtime import Realtime
from system import System
from system_service import System_service
from update import Update

try:
    from streaming.streaming import Streaming
except Exception:
    pass

class Device(ACS.Device):

    def __init__ (self, address):
    
        super().__init__(address)
        
        self.about = About(self)
        self.access = Access(self)
        self.adjustment = Adjustment(self)
        self.axis = Axis(self)
        self.displacement = Displacement(self)
        self.ecu = Ecu(self)
        self.manual = Manual(self)
        self.network = Network(self)
        self.nlc = Nlc(self)
        self.pilotlaser = Pilotlaser(self)
        self.realtime = Realtime(self)
        self.system = System(self)
        self.system_service = System_service(self)
        self.update = Update(self)
        try:
            self.streaming = Streaming(self)
        except NameError as e:
            if "Streaming" in str(e):
                print("Warning: Streaming is not supported on your platform")
            else:
                raise e

def discover():
    return Device.discover("ids")