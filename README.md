# Gababot
A software project created in fulfillment of the requirements 
for SOFT561 by Torbjorn Dahl at Plymouth University.

This repository contains code to operate a small 
[robotic platform](http://4tronix.co.uk/initio/). The system is distributed 
and uses the following devices:

* Raspberry Pi 3
* Samsung Galaxy S5
* Arduino Uno
* A laptop (for heavy computation and remote control)

This project offers a flexible and easy way to teleoperate the robot. In particular it allows convenient control via keyboard through a webbrowser, while forwarding a webcam stream obtained through the phone.
Further, the project offers extensibility towards the ROS navigation stack as well as SLAM packages such as LSD-SLAM. The latter has been tested on the robot, yet remains in an experimental stage.

Note: LSD-SLAM is licensed under GPL. Thus, it is not included in this distribution of software, to keep the code under MIT.

## Author
Sebastian Wallkoetter
sebastian@wallkoetter.net

## Requirements


### Software
* ROS Kinetic
* apache2 (or equivalent)

### ROS Packages
All these should be installable by apt
* rosserial
* rosbridge
* cv_camera (or equivalent)
* image_transport + compressed_image_transport

(experimental LSD-SLAM)
* image_proc
* camera_calibration
* LSD-SLAM

## Installation


## Folder Structure
This repository contains all packages written for this project.
jake -- Just Another Keyboard Eventhandler. A flexible way to integrate a keyboard for teleoperation in ROS. It provides a Keyboard message, which can store currently pressed Key messages. __jake_twist__ is a conversion node. Listening for keypresses it converts them into twist messages and publishes them at 10Hz. It is fully customizable through the .launch file.
website -- the website published by the webserver. Note: At the moment this does not offer any security, thus anybody could potentially steer the buggy.
