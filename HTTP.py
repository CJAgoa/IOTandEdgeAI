import time
import board
import adafruit_dht
import requests
import RPi.GPIO as GPIO
sensor = adafruit_dht.DHT11(????)
# ThingSpeak Write API Key and URL
write_api_key = "??????????"
url = f"https://api.thingspeak.com/update?api_key={write_api_key}"
try:
 while True:
 try:
 # Read temperature and humidity from the DHT11 sensor
 temperature_c = sensor.temperature
 temperature_f = temperature_c * (9 / 5) + 32
 humidity = sensor.humidity

 # Print the values to the serial port
 print(f"Temp={temperature_c:.1f}ºC, Temp={temperature_f:.1f}ºF, Humidity={humidity:.1f}%")

 # Send data to ThingSpeak
 payload = {
 'field1': ??, 
 'field2': ??,
 }

 # Perform the HTTP GET request to send the data
 response = requests.get(???, params=????)

 if response.status_code == 200:
 print("Data sent to ThingSpeak successfully")
 else:
 print(f"Failed to send data. HTTP status code: {response.status_code}")

 except RuntimeError as error:
 # Handle occasional runtime errors (such as failed sensor readings)
 print(f"Runtime error: {error.args[0]}")
 time.sleep(2.0) # Wait before retrying

 except Exception as error:
 # In case of any unexpected error, raise the error
 print(f"An error occurred: {error}")
 raise error

 # Sleep before next reading (DHT11 typically needs a 1-2 second gap)
 time.sleep(3.0) # Sleep for 3 seconds between readings
finally:
 # Cleanup - Release any resources used by the sensor
 print("Cleaning up sensor resources...")
 sensor.exit() # This ensures any resources used by the sensor are freed

 # Cleanup GPIO pins
 GPIO.cleanup() # Ensure all GPIO pins are reset to their default state
 print("GPIO cleanup complete.")
 print("Sensor cleanup complete.")
