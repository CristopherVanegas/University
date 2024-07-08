from machine import I2C, Pin, PWM
import ssd1306
from imu import MPU6050
from time import sleep

# Configuración del servo
sCodo = PWM(Pin(28))
sCodo.freq(50)

# Configuración del I2C
i2c = I2C(0, scl=Pin(5), sda=Pin(4))

# Configuración de la pantalla OLED
oled_ancho = 128
oled_alto = 64
oled = ssd1306.SSD1306_I2C(oled_ancho, oled_alto, i2c)

# Inicialización del sensor MPU6050
imu = MPU6050(i2c)

# Función para mapear los valores de gx a un rango de 0 a 180 grados
def map_gx_to_degrees(gx):
    return int((gx + 250) * (180 - 0) / (500 - (-250)))

# Variable para almacenar el valor anterior de gx
last_gx = None

while True:
    # Capturar los valores de los sensores
    ax = imu.accel.x
    ay = imu.accel.y
    az = imu.accel.z
    gx = imu.gyro.x
    gy = imu.gyro.y
    gz = imu.gyro.z
    t = imu.temperature

    # Si gx ha cambiado, actualizar el servo y la pantalla OLED
    if gx != last_gx:
        mapped_gx = map_gx_to_degrees(gx)
        sCodo.duty_ns(int((mapped_gx * 2000000 / 180) + 500000))
        last_gx = gx

        # Actualizar la pantalla OLED con los nuevos valores
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
