"""
The code is written by Philipp Neubauer
"""

from time import sleep
import serial
import time
import csv
import sys

ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM15'
ser.timeout=5
ser.open()


data_bus=0
data_mcu=0
data_time=0


def readsens():
    f= open('data.csv',mode='w',newline='')
    writer=csv.writer(f)

    while True:
        serdata=ser.readline()
        serdatastr=str(serdata)
        
        index_time= serdatastr.find("Time:")
        index_mcu = serdatastr.find("MCU:")
        index_bus= serdatastr.find("BUS:")
        
        startindextime=round(sys.getsizeof(index_time)/8)
        startindexmcu=round(sys.getsizeof(index_mcu)/8)
        startindexbus=round(sys.getsizeof(index_bus)/8)
        #print(startindextime)
        start_time = serdatastr[index_time+startindextime+1:] 
        start_mcu = serdatastr[index_mcu+startindexmcu:] 
        start_bus = serdatastr[index_bus+startindexbus:] 

        end_time = start_time.find("MCU:")
        end_mcu = start_mcu.find("BUS:")
        end_bus = start_bus.find("\r\n")
        endindexbus=round(sys.getsizeof(end_bus)/8)
        endindextime=round(sys.getsizeof(end_time)/8)
        
        data_time=start_time[:end_time]
        data_mcu=start_mcu[:end_mcu]
        data_bus=start_bus[:end_bus-endindexbus]
    
        writer.writerow([data_time,data_mcu, data_bus])

        print("time"+start_time[:end_time])    
        print("MCU"+start_mcu[:end_mcu])
        print("BUS"+start_bus[:end_bus-endindexbus])

        if(len(serdata) == 0): 
            f.close()
            break
        #sleep(0.2)  
    
if __name__ == "__main__":
    readsens()
