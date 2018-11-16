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
> **Note:** If you are extremely worried about your GameCube controller, you can use a logic level converter, how many converters **cannot** handle the small modulations we'll be dealing with. The logic level converter is NOT necessary, but will lower the voltage down to the proper frequency. We weren't able to get one that was fast enough.

### Libraries:

To start, you will need to install the [Arduino Nintendo Library](https://github.com/NicoHood/Nintendo) into your Arduino IDE. Here's how to do that:
1. Click the link > **"Clone or Download"** > **"Download ZIP"**
2. Rename the downloaded file to **"Nintendo.zip"**
3. Open your Arduino IDE > **"Sketch"** > **"Include Libraries"** > **"Add .ZIP Library..."**
4. Located the downloaded and renamed **"Nintendo.zip"**

## Hardware

#### Bluetooth Preparation
> **Note:** Most of the following instructions are taken from [here](https://mitxela.com/projects/bluetooth_hid_gamepad). Reference them if you're having issues.

[Instructions for Bluetooth flashing and stuff]

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

All you have to do is download and extract the repository, and run the **"[name of main file]"** file inside the **/src/** folder. This will initialize the HID device, and you should be able to connect to the Arduino just like a regular Bluetooth controller. The controller input is preset, so all rebinding will have to be done ingame, but it should match the controls of a regular gamepad.

## Team

- Cole Crouter
- Tyson Potter

## Credits

- [NicoHood](https://github.com/NicoHood/) - GameCube API *and* hardware instructions for the controller, as well as LOTS of help getting a working prototype.
- Mitxela.com - Instructions on creating a Bluetooth HID device with a HC-05
