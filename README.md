# carduino
RC Car made with Arduino

## Installing the IDE

You can download and install the IDE from arduino.cc: https://www.arduino.cc/en/Main/Software

Or using Homebrew on Mac:

```brew cask install Caskroom/cask/arduino```

If you don't have Homebrew: http://brew.sh

## Libraries

Before editing and compiling the code using the Ardunino IDE, you need to copy the libraries from _lib/_ to the IDE libraries folder if it is not already there.

```cp -r lib/{AFMotor,NewPing} ~/Documents/Arduino/libraries/```

After that, you need to reastart the IDE.

## IDE

After connecting the Arduino to the computer using the USB cable, you need to select the port for the IDE to use.

```Menu > Tools > Port > [arduino port]```

Port example: `/dev/cu.usbmodem1421 (Arduino/Geniuno Uno)`
