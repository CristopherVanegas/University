from machine import I2C, Pin, PWM
import ssd1306
from imu import MPU6050
from time import sleep

sCodo = PWM(Pin(28))
sCodo.freq(50)

i2c = I2C(0, scl=Pin(5), sda=Pin(4))

oled_ancho = 128
oled_alto = 64
oled = ssd1306.SSD1306_I2C(oled_ancho, oled_alto, i2c)

imu = MPU6050(i2c)

# funcion para mapear los grados del servo
def map(x):
    return int((x-0) * (2500000 - 500000) / (180 - 0) + 500000)

while True:
  sCodo.duty_ns(map(15))
  ax = imu.accel.x
  ay = imu.accel.y
  az = imu.accel.z
  gx = imu.gyro.x
  gy = imu.gyro.y
  gz = imu.gyro.z
  t = imu.temperature
  
  print("ax:", ax, "ay: ", ay, "az:", az)
  #print("gx:", gx, "gy: ", gy, "gz:", gz)
  oled.fill(0)
  oled.text("ax:"+str(ax), 0, 0)
  oled.text("ay:"+str(ay), 0, 9)
  oled.text("az:"+str(az), 0, 18)
  oled.text("gx:"+str(gx), 0, 27)
  oled.text("gy:"+str(gy), 0, 36)
  oled.text("gz:"+str(gz), 0, 45)
  oled.text("Temp:"+str(t), 0, 54)
  oled.show()
  sleep(0.5)
  sCodo.duty_ns(map(90))
  sleep(0.5)

