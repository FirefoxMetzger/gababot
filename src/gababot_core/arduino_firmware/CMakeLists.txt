cmake_minimum_required(VERSION 2.8.3)

include_directories(${ROS_LIB_DIR})

generate_arduino_firmware(arduino
	SRCS 
		arduino_main.cpp
		Encoder.cpp
		${ROS_LIB_DIR}/time.cpp
		Motor.cpp
		MotorControl.cpp
		MovingBase.cpp
	HDRS
		initio.h
		Encoder.h
		Motor.h
		MotorControl.h
		MovingBase.h
	BOARD uno
	PORT /dev/ttyACM0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
