# SMARTCAR

Final Project

# FOOTPRINT
We need to create a car so we need materials for this, a list of the complete materials that were used in this project is shown above:

* Car chassis (We had this one: http://www.geekbotelectronics.com/producto/kit-chasis-carro-robot-4wd/) and wheels.
* Arduino Mega 2560
* Ultrasonic HC-SR04 sensor.
* 2 pairs of Li-Ion batteries.
* WiFi esp8266 module. 
* A lot of glue.
* Paperboard.
* A computer to program all these devices together.
* Patience. 

We started by designing the car, with a free software design tool called Inkscape. 

We need this to cut the paperboard to form the car.  After we have this we can print it in real life, I’ve used a 579x800 cm paperboard.  We got started working with the car chassis, soldering all 4 DC-motors, connecting them to the MCUfriend motor shield, checking its polarity with test programs in arduino, etc… We ended up with this as result, a mockup with no functionality whatsoever but ready to be programmed.

This was just the beginning, since we need to program all the functionality of the car AND the online application.

# ARDUINO
We used an arduino mega 2560. This was programmed fairly easy, we defined a lot of control functions for our motor shield like moving the motors forward, backward, to the right, to the left, stopping, etc…

After that we just needed a function to check the distance between the car and any object, using the Ultrasonic HC-SR04 sensor we accomplished this one pretty easily. 

Finally we needed to create a Wire.h protocol with the NodeESP8266 WiFi Module, using that library was a piece of cake since there are a lot of tutorials on how to do it. 

For more information about the code, you can check the Annexes where all the code repositories are published and completely open to the public.

# WIFI MODULE
This one was a tricky one, we used the NodeESP8 which was completely used by the master-slave technique, using the module as the master and arduino as the slave we had a great deal of work with timing and request-time managing. 

The hard work here comes from the fact that we needed to program and API and actually publish it to the internet, this was only done with Google Cloud Engine, I will talk you through this in the next step. 

For the wifi module we just needed to create an HTTP GET request which gave us the state of the car, active or inactive. After that, it was fairly easy because we just needed a Wire.h connection to the arduino controlled by the SP1 and SP0 pins. 

# CLOUD API AND APP

After all the hardware was programmed correctly, we needed an API to connect with. We approached this by utilizing the Google Cloud services, where we hosted a Virtual Instance Machine running Ubuntu 18.04LTS, we installed Nginx working as a reverse proxy for a NodeJS api. 

We wanted to make sure that everything was simple and efficient, so we just deployed a SPA with Express.js; this allowed us to focus on actually getting the work done rather than spending time configuring another service for our frontend.

We ended up with a page like this one:

Pretty intuitive, there’s a car in the middle which you can press, and when you press it you change from inactive (red) to active (green).  This page is hosted in the next URL: http://34.67.46.38/ 
