# AED Arduino Alarm

1) Use arduino C code under **'main'** folder
2) Microcontroller automatically searches and connects to YK's phone hotspot
3) Alarm turns on when "switch" key is set to 1, and turns off when set to 0.
4) LED
a) Permanently lit on: unable to connect to wifi
b) Blinking: unable to connect to api endpoint using GET
c) Off: all connections and api requests working fine
5) Flask API test server
a) Run in terminal: python app.py
b) GET /switch to get current switch value
c) GET /switchVal to change switch value
