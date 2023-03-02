import socket
import serial

teensy = None
udp = None

HOST = "127.0.0.1"
PORT = 53532

def connect():
    udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp.connect((HOST, PORT))

def main():
    teensy = serial.Serial('/dev/cu.usbmodemOJA_0011', 19200, timeout=1)


    teensy.close()
    udp.close()

if __name__ == "__main__":
    main()