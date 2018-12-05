# GameCube Controller Bluetooth Adapter for Arduino

This project will allow the user to wirelessly connect a GameCube controller to the device of their choosing, as a regular HID Bluetooth device.

## Prerequisites

### What you need:
- Arduino Uno
- GameCube controller
- (Optional) Controller extension cable
- HC-05/HC-06 Bluetooth module
- FTDI serial adapter
- Some elbow grease (a lot)
> **Note:** If you're *extremely* worried about your GameCube controller, you can use a logic level converter, however, logic level converters **cannot** handle the small modulations we'll be dealing with. The logic level converter is NOT necessary, but will lower the voltage down to the proper frequency. We weren't able to get one that was fast enough.

### Libraries:

To start, you will need to install the [Arduino Nintendo Library](https://github.com/NicoHood/Nintendo) into your Arduino IDE. Here's how to do that:
1. Click the link > **"Clone or Download"** > **"Download ZIP"**
2. Rename the downloaded file to **"Nintendo.zip"**
3. Open your Arduino IDE > **"Sketch"** > **"Include Libraries"** > **"Add .ZIP Library..."**
4. Located the downloaded and renamed **"Nintendo.zip"**

## Hardware

#### Bluetooth Preparation
> **Note:** Most of the following instructions are taken from [here](https://mitxela.com/projects/bluetooth_hid_gamepad). Reference them if you're having issues.

The first thing you're going to need to do is flash the HC-05 chip that you have with firmware from an RN42. This will allow the HC-05 to act like a traditional HID device. In order to do this, follow the detailed instructions in [this](https://www.youtube.com/watch?v=y8PcNbAA6AQ). (There are lots of steps, so it's easier just to follow the video)

After you have finished wiring up your controller, it's time to configure the HC-05. Unplug the FTDI adapter, and wire up your RX and TX wires to the pin 2 and 3 on your Arduino. Then, download and run [this](https://github.com/evankale/RN42Config/blob/master/RN42Config.ino), open the Serial Monitor, make sure the baud rate is set correctly, set line ending to "No line ending", then type in '$$$' and press enter. Then, set line return to "Newline", then type and enter the following:
- SF,1
- S~,6
- SN,[the name you want your device to be]
- SH,0230
- R,1
  
Once you have completed this, you should have a perfectly function Bluetooth device. Open up your phone or another Bluetooth enabled device, and you should see the name you chose come up as an available device.

> **Note:** If you are having trouble flashing the chip, reference (this)[https://youtu.be/y8PcNbAA6AQ?t=625] or (this)[https://youtu.be/mt8uF9IblUU?t=77]. Play with the baud rates in the program and in the monitor (some chips act differently), and try swapping the RX and TX wires. Lastly, sometimes you need to unplug the Arduino entirely.

#### Controller Preparation
> **Note:** Most of the following instructions are taken from [here](https://github.com/NicoHood/Nintendo/wiki/Gamecube). Reference them if you're having issues.

Start by cutting the end off of your GameCube controller/extension cable. Proceed to strip the main cable, then the individual 6 or 7 wires. Solder the ends of the wires to your own cables, shrink-tube or otherwise insulate them, then plug them into individual lanes on your breadboard. If you're using an original controller, your pin-out should look like this:

|Colour|Function     |
|-----:|:------------|
|Yellow|5V           |
|White |Data         |
|Red   |Ground       |
|Brown |Ground       |
|Green |Not connected|
|Blue  |3.3V         |
|Black |Ground       |

Otherwise, you can reference NicoHood's table [here](https://docs.google.com/spreadsheets/d/1X-F21F838uQRCuYsc7nQoAv6I2dchvXtBSNTf-ZOc9M/), or you can look at the severed end of the controller, and try to guess which wire is which in regards to this diagram:

![alt text](https://github.com/ThirdDegreeCancer/CS207Project/blob/intro/img/connections.png "Female port on GameCube")

Once you have the wires connected to your breadboard, recreate the following diagram:

[Insert picture]

Once you have completed this step, you've finished the circuit!

> **Note:** If you're getting a repeated *"Controller not found"* error in the monitor, go back and make sure you have your controller wired up properly. Reference the image above. It is the FEMALE end (on the GameCube), so wire accordingly.

## Software

All you have to do is download and extract the repository, and run the **"[name of main file]"** file inside the **/src/** folder. **MAKE SURE you temporarily unplug the RX and TX pins**, or else you will be unable to upload the sketch. Now, just connect to the controller. The controller input is configurable in the sketch, but it should match the controls of a regular gamepad. (Many buttons cannot be bound yet. We will do some research and see if it is possible to make the buttons work)

> **Note:** If you aren't getting any input from the controller, try disconnecting and reconnecting to the device, or even unplugging the Arduino.
## Team

- Cole Crouter
- Tyson Potter

## Credits

- [NicoHood](https://github.com/NicoHood/) - GameCube API *and* hardware instructions for the controller, as well as LOTS of help getting a working prototype.
- [Mitxela.com](https://mitxela.com/projects/bluetooth_hid_gamepad) - Instructions on creating a Bluetooth HID device with a HC-05
- [Evan Kale](https://github.com/evankale) - Instructions and software for flashing and using the HC-05 chip
- [Brian Lough](https://www.youtube.com/channel/UCezJOfu7OtqGzd5xrP3q6WA) - Even more instructions on flashing the HC-05
