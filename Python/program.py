import bridge

def setup(serialData):
    #Program Setup
    pass

def loop(serialData):
    #Program Loop
    route, value = bridge.serialToOSC(serialData)
    bridge.sendOSC(route, value)
