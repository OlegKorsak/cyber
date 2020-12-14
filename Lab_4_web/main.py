from flask import Flask, render_template
import pandas as pd
from datetime import datetime
# import RPi.GPIO as GPIO
# import Adafruit_DHT as dht

app = Flask(__name__)
# GPIO.setmode(GPIO.BOARD)
# DHT_pin = 7


@app.route("/temp")
def temp():
    #  _, temperature = Adafruit_DHT.read_entry(Adafruit_DHT.DHT11, DHT_pin)
    # data ...
    return render_template('main.html', temperature=data)


@app.route("/hum")
def humidity():
    pass


def main():
    # humidity, temperature = Adafruit_DHT.read_entry(Adafruit_DHT.DHT11, DHT_pin)
    temperature = 22
    template_data = {'datetime': datetime.now(),
                     'temperature': temperature}
    return render_template('main.html', **template_data)


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)

