import paho.mqtt.client as mqtt
import time
import RPi.GPIO as GPIO


# Set the MQTT Broker details
BROKER = "???"  # Replace with your broker IP or domain
PORT = 1883
TOPIC_TEMP = "???"
TOPIC_HUMIDITY = "???"

# Initialize global variables for temp and humidity
temp = " "
humidity = " "

# Callback function when message is received
def on_message(client, userdata, msg):
    global temp, humidity
    if msg.topic == TOPIC_TEMP:
        temp = float(msg.payload.decode())
    elif msg.topic == TOPIC_HUMIDITY:
        humidity = float(msg.payload.decode())
    

    if temp is not None and humidity is not None:
        
        print(f"Temp: {???}C") 
        print(f"Humidity: {???}%")

# Setup the MQTT client
client = mqtt.Client()
client.on_message = on_message

# Connect to the broker
client.connect(???, ???, 60)

# Subscribe to the topics
client.subscribe(???)
client.subscribe(????)

# Start the loop to listen for messages
client.loop_start()

try:
    while True:
        time.sleep(1)  # Sleep to allow the program to run continuously
except KeyboardInterrupt:
    print("Disconnected.")
    client.loop_stop()


