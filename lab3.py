import RPi.GPIO as GPIO
import time
    
GPIO.setmode(GPIO.BOARD)
    
LED_pin = 11
Sensor_pin = 13
buzzer_pin = 15
GPIO.setup(Sensor_pin, GPIO.IN)
GPIO.setup(LED_pin, GPIO.OUT)
GPIO.setup(buzzer_pin, GPIO.OUT, initial=GPIO.LOW)
    
def sens(null):
    print "stop"
    GPIO.output(LED_pin, GPIO.HIGH)
    GPIO.output(buzzer_pin, GPIO.HIGH)
    
GPIO.add_event_detect(Sensor_pin, GPIO.FALLING, callback=sens, bouncetime=10)
try:
    while True:
        time.sleep(1)
        print "wait"
        if GPIO.input(Sensor_pin) == 1:
            GPIO.output(LED_pin, GPIO.LOW)
            GPIO.output(buzzer_pin, GPIO.LOW)
except KeyboardInterrupt:
    GPIO.cleanup()