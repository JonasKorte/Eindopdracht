import socket
import serial
import keyboard
import program

UDP_HOST = "127.0.0.1"
UDP_PORT = 53532

SERIAL_PORT = "/dev/cu.usbmodemOJA_0011"

teensy = None
udp = None

def connect():
    udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    if udp == None:
        return False
    
    udp.connect((UDP_HOST, UDP_PORT))

    return True

def main():
    print ("Opening serial port... ({serial_port})".format(serial_port = SERIAL_PORT))
    teensy = serial.Serial(SERIAL_PORT, 19200, timeout=1)
    if teensy.is_open == False:
        print("ERROR: Could not communicate on serial port: {serial_port}", serial_port=SERIAL_PORT)
        quit()
    
    print("Successfully connected to serial port!")

    udp_status = connect()
    if udp_status == False:
        print("ERROR: Could not establish UDP connection on: {host}:{port}", host=HOST, port=PORT)
        print("Closing...")
        teensy.close()
        quit()
    
    print("Successfully established UDP connection!")

    program.setup()

    print("Now running... (press Q to quit)")

    while True:
        try:
            if keyboard.is_pressed('q'):
                break
        except:
            continue

        program.loop()


    print("Closing...")
    teensy.close()

if __name__ == "__main__":
    main()