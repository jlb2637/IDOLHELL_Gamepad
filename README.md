# IDOLHELL_Gamepad
An Arduino based arcade style controller for my friends first game released on Steam!

![IdolHellGamePadDone](https://github.com/jlb2637/IDOLHELL_Gamepad/assets/47393028/e6606cb6-95ad-4198-b2aa-e8f82126ea0a)



The goal of this project was to be able to use arcade style joystick and buttons to play games on Steam, specifically IDOL HELL. A game created by some of my friends! Check it out here: https://store.steampowered.com/app/2067470/Idol_Hell/

optional parts
(optional based on mcu and code) 10k Ohm Resistors on each digital I/O pin used
22AWG wire
(optional) Any protoboard/strip board you would like
access to a 3d printer

### Main Parts List

|Part|Cost Estimate|Link to part|
| -- | ----------- | ---------- |
| Sanwa 24mm arcade pushbuttons | $10 | https://focusattack.com/sanwa-obsf-24mm-pushbutton-green/ |
| Sanwa 8-way arcade joystick | $23 | https://focusattack.com/sanwa-jlf-tp-8yt-joystick/ |
| Adafruit ItsyBitsy32U4 5v 16MHz | $10 | https://www.adafruit.com/product/3677 |
| Stranded Core wire, any color you like | $3 for a small spool | https://www.adafruit.com/product/2976 |
| screws#1 | hardware to be added | hardware to be addded |
| screws#2 | tba | tba |
| MatterHackers MH Build Series Pink | $21 per 1Kg Spool | [filament to be addded](https://www.matterhackers.com/store/l/175mm-pla-filament-pink-1-kg/sk/M81ZR601) |

### Tools Required

Screwdriver (with flathead and philips bits)
3D Printer Access
Soldering Iron & accompanying tools (solder, sponge, etc.)

## Physical build

![idolhellboxexploded](https://github.com/jlb2637/IDOLHELL_Gamepad/assets/47393028/9bbc0c20-663f-4027-a242-bbc9349b73cb)

After pretending I didn't have to design the case for a long time, I finally got it done. Found a cool resource that talks about button layout that helped me break the wall and start working on it: https://www.slagcoin.com/joystick/layout.html

In the name of making things easier to print I decided to pull the logo on the cover off into its own separate files and glue the parts on. This meant there was a nice flat surface touching the print bed for everything.

![Logo](https://github.com/jlb2637/IDOLHELL_Gamepad/assets/47393028/5f7f7340-7272-4846-998a-04c0976d4597)


## Electronics

![IdolHellInternalWWalls](https://github.com/jlb2637/IDOLHELL_Gamepad/assets/47393028/03cdae44-87db-4b10-8b45-27715f25f3ec)

The electronics here are pretty simple, a microcontroller with 8 GPIO pins and USB/Serial capability is all you need!
Although it would be super cool to make a custom PCB, it just feels overkill for using a couple GPIO pins so I have hand soldered everything and used the internal pullup resistors on the microcontroller.
Specifically I am using an Adafruit itsy-bitsy 5V 16MHZ Atmega32u4. The code I've written should really work on any Atmega32u4 board, just remember to change the pins!


*insert schematic here*

In case you don't like or don't have an mcu with internal pullup resistors here is a schematic with them placed externally:

*insert schematic here*

## Code

I went pretty simplistic with the code and it functions basically exactly like a macropad. This allows the buttons to easily be rebound and work on a large variety of games.
The Arduino keyboard.h library made this super simple too.

The one trick to remember is that since we are using internal pullup resistors to pull the disconnected state of each button high, we need to invert all of the inputs so they are active low(key pressed when shorted to ground).

