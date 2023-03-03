import serial
import keyboard
import program
from pythonosc import udp_client

UDP_HOST = "127.0.0.1"
UDP_PORT = 53532

SERIAL_PORT = "/dev/tty.usbmodemOJA_0011"

teensy = None
udp = udp_client.SimpleUDPClient(UDP_HOST, UDP_PORT)


def main():
    print ("Opening serial port... ({serial_port})".format(serial_port = SERIAL_PORT))
    teensy = serial.Serial(SERIAL_PORT, 9600, timeout=1)
    if teensy.is_open == False:
        print("ERROR: Could not communicate on serial port: {serial_port}", serial_port=SERIAL_PORT)
        quit()
    
    print("Successfully connected to serial port!")
    
    print("Successfully established UDP connection!")

    program.setup(teensy.readline())

    print("Now running... (press Ctrl+C to quit)")

    isRunning = True

    while isRunning:
        program.loop(teensy.readline())


    print("Closing...")
    teensy.close()

def serialToOSC(bData):
    strData = str(bData)

    route = strData.split(' ')[0].split('\'')[1]
    value = int(strData.split(' ')[1].split('\\')[0])

    return route, value

def readLineFromSerial():
    return teensy.readline()

def sendOSC(route, value):
    udp.send_message(route, value)
if __name__ == "__main__":
    main()