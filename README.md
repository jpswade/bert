# Project Bert - The Robot Car Project.

## Brief

Project Bert is a robot research and development project to create an Internet of Things (IoT) controlled “robot” car.

The aim is to build two prototypes to begin with, to entertain my nephews. I’m hoping that this will not only keep them entertained, but inspire them to explore science and engineering.

## Objective

The goal is use this as a base line operation to help fund further research and development into creating a more accessible entry level robotics kit.

The plan is to put together a kit that people could buy and assemble themselves. The kit will provide everything they need to get started along with a much needed user manual and an online community, a forum owned and operated by the project. Additional supporting material, such as a book which can be purchased by those wanting more in depth guidance.

The long term goal is to be to be able to provide, in kit form or pre-built, an IoT robot that you can purchase for under £30 and can fit in your pocket.

## Analysis

The prototypes will be based on the existing “Smart Robot Cars” that are available for import.

* [Doit 2WD L293D WIFI RC Smart Car With NodeMCU + Shield For ESP-12E Based On ESP8266 (on Bandgood.com for £17.41)](http://www.banggood.com/Geekcreit-Doit-2WD-L293D-WIFI-RC-Smart-Car-With-NodeMCU-Shield-For-ESP-12E-Based-On-ESP8266-p-995166.html)

The prototypes need to be easily accessible, using off the shelf parts where possible so that it is easy to replicate.

### Chassis

The chassis will need to be appealing to the audience. Something that sticks in your mind, such as the Johnny Five style chassis.

- [Robot Caterpillar Tank Treads, Johnny Five Style - 3D Print](http://www.instructables.com/id/Robot-Caterpillar-Treads-Johnny-Five-Style-3D-P/)

An alternative chassis is the Zumo chassis:

- [Zumo Chassis Kit](http://shop.pimoroni.com/products/zumo-chassis-kit-no-motors)

Some seriously cheap alternative ideas:

- [Wooden vehicle track plans](https://woodgears.ca/tracked_vehicle/plans.html)
- [Wooden Tank](https://www.youtube.com/watch?v=ZYvNLW1jg90)
- [MAKING A CARDBOARD TANK PART 1 – CHASSIS AND TRACKS](https://andersmakes.wordpress.com/2014/04/10/making-a-cardboard-tank-part-1-chassis-and-tracks/)
- [Cardboard Electric T34-88 Tank Model As Seen in World of Tanks Game](http://www.instructables.com/id/Cardboard-Electric-T34-88-Tank-Model-As-Seen-in-Wo/)

### Controller

The NodeMCU ESP8266 platform was chosen over Raspberry Pi or Arduino options for a number of reasons, mainly that it has what I need at less cost. Compared to the Raspberry Pi, it has a much smaller profile. Ultimately, it does everything I need and will ultimately be more cost effective while still having a highly extendable (or “hackable”) platform at the heart of it.

- [ESP8266 SMT Module - ESP-12S](http://www.adafruit.com/product/2491)
- [ESP8266EX Datasheet](https://cdn-shop.adafruit.com/product-files/2471/0A-ESP8266__Datasheet__EN_v4.3.pdf)

#### Platform

As the controller is ESP8266 based we have some options for our platform.

There's a number of ways to program the ESP8266 chip.

#### Lua

Lua is a lightweight programming language, ideal for embedded systems, but as it requires compiling it, which means a complex toolchain.

- [Esp32/esp8266 lua sdk](http://github.com/Nicholas3388/LuaNode)
- [Getting started with the NodeMCU devkit on OSX](http://github.com/nodemcu/nodemcu-devkit/wiki/Getting-Started-on-OSX)

#### Arduino

We're going to use the Arduino platform which allows us to leverage the Arduino IDE and extensive libraries.

- [Arduino core for ESP8266 WiFi chip](http://github.com/esp8266/Arduino)
- [ESP8266 Arduino core documentation](http://esp8266.github.io/Arduino/versions/2.3.0/)
- [Async Web Server for ESP8266 and ESP32](http://github.com/me-no-dev/ESPAsyncWebServer)
- [ESP8266 Thing Hookup Guide](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon)
- [How to Install FTDI Drivers on Mac](http://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/mac)

#### Other platforms

"While there are other platforms for controlling hardware over the internet (Particle, ThingSpeak, Temboo, IFTTT), Blynk is one of the most user-friendly I’ve seen yet, and it’s also free and open-source under an MIT license"

- [Control an Arduino with Your Smartphone via Blynk](https://makezine.com/2015/07/06/control-arduino-your-smartphone-via-blynk/)

This might be worth a revisit in the next version.

### Motor driver

- [User Manual for ESP12E Motor Shield](http://cdn.hackaday.io/files/8856378895104/user-mannual-for-esp-12e-motor-shield.pdf)
- [HG7881 H bridge Stepper Motor Dual DC Motor Driver Controller](https://chioszrobots.com/2014/06/01/hg7881-h-bridge-stepper-motor-dual-dc-motor-driver-controller/)
- [PUSH-PULL FOUR CHANNEL DRIVER WITH DIODES](http://www.arduino.cc/documents/datasheets/H-bridge_motor_driver.PDF)

### Parts

#### Motors

The motors are small, low power and easy to source.

- [Micro Metal Gearmotor (Extended back shaft)](http://shop.pimoroni.com/products/micro-metal-gearmotor-extended-back-shaft)
- [50:1 Micro Metal Gearmotor (Extended back shaft)](https://cdn.shopify.com/s/files/1/0174/1800/files/JL-12FN20-50-06420_XG2014111401-Model.pdf?9187369518581184232)

### Related projects

- [Wifi Controlled Motors using ESP8266 and ATtiny85](http://blog.nyl.io/esp8266-motor/)
- [A Segway-style WiFi controlled robot built on ESP8266](http://flannelhead.github.io/projects/espway.html)
- [NodeMCU Motor Shield Review](https://blog.the-jedi.co.uk/2015/11/26/nodemcu-motor-shield-review/)
- [Connect an L293D motor Driver to Netduino](http://fritzing.org/projects/l293d-motor-driver)
- [Esp8266 12e motor shield joystick blynk](http://community.blynk.cc/t/esp8266-12e-motor-shield-joystick-blynk/10498)
- [SmartArduino DoitCar - AP and STA source code](http://github.com/SmartArduino/DoitCar)
- [Wifi Car](http://github.com/squix78/esp8266-projects/tree/master/arduino-ide/wifi-car)
- [Node MCU Motor Shield](http://hackaday.io/project/8856-incubator-controller/log/29291-node-mcu-motor-shield)
- [Arduino Lesson 15. DC Motor Reversing - L293D](http://learn.adafruit.com/adafruit-arduino-lesson-15-dc-motor-reversing/lm293d)
- [Arduino/ESP8266 Wifi Smart Car](http://osoyoo.com/2017/01/18/smartcar/)
- [User Manual for WiFi Car by NodeMCU (DoitCar)](http://smartarduino.gitbooks.io/user-manual-for-wifi-car-by-nodemcu-doitcar-/content/)
- [Setting up NodeMCU ESP8266 Internet Browser WiFi Controlled Robot Car Kit](http://www.alictronix.com/archives/256)
- [NodeMCU ESP8266 Wifi RC robot car kit 2WD Acrylic Chassis IoT Internet of Things](http://www.alictronix.com/product/2060)

## See also

- http://www.electrodragon.com/w/ESP_Relay_Board
- http://www.ftdichip.com/Drivers/VCP.htm
- http://www.gitbook.com/book/smartarduino/user-mannual-for-esp-12e-motor-shield/details
- http://www.instructables.com/id/A-very-cheap-ESP8266-WiFi-smart-car-controlled-by-/
- http://www.instructables.com/id/Motorize-IoT-With-ESP8266/
- http://www.jayconsystems.com/tutorials/zumo-esp12/
- http://www.jjrobots.com/product/b-robot-kit-plug-and-play-robot-version/
- http://www.mblock.cc/
- http://www.thingiverse.com/thing:1848621
- http://www.thingiverse.com/thing:2017018
- http://www.ti.com/lit/ds/symlink/l293.pdf
- http://www.tindie.com/products/doit/esp8266-develop-kit-nodemcu-board-motor-shield/
- http://www.tindie.com/products/doit/wifi-rc-tank-t200-with-esp8266-development-kit/
- http://www.youtube.com/watch?v=EGSz-_uYLqU
- http://www.youtube.com/watch?v=QCqxOzKNFks
- https://web.archive.org/web/20170209144251/http://www.rudiswiki.de/wiki/WiFiCar-NodeMCU
- https://www.slideshare.net/e2m/nodemcu-with-blynk-and-firebase
- https://developer.ibm.com/recipes/tutorials/how-i-help-my-front-door-to-speak-using-watson/
- https://www.geekstips.com/esp8266-arduino-tutorial-iot-code-example/
