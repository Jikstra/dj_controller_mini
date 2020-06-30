import mido
import serial
import time
import traceback
import sys

SLEEP_INTERVAL = 0.3

#with mido.open_input('MiniX1', client_name='MiniX1', virtual=True) as input:
#    with mido.open_output('MiniX1', client_name='MiniX1', virtual=True) as output:
#        while True:
#            for msg in input.iter_pending():
#                output.send(msg)

device = '/dev/ttyACM0'
with mido.open_output('MiniX1', client_name='MiniX1', virtual=True) as output:
    while True:
        try:
            connection = None
            try:
                connection = serial.Serial(device, 115200, timeout=1, exclusive=True)
            except Exception as e:
                print("Error: ", e)
                print(traceback.format_exc())
                print(sys.exc_info()[0])
                time.sleep(SLEEP_INTERVAL)
                connection.close()

            try:
                while True:
                    buf = connection.read(3)
                    if len(buf) != 3:
                        continue
                    message = mido.parse(buf)
                    print(message)
                    output.send(message)
            except Exception as e:
                print("Error: ", e)
                print(traceback.format_exc())
                print(sys.exc_info()[0])
                time.sleep(SLEEP_INTERVAL)
                connection.close()
        except Exception as e:
            print("Error: ", e)
            print(traceback.format_exc())
            print(sys.exc_info()[0])
            time.sleep(SLEEP_INTERVAL)
