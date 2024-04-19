# IDOLHELL_Gamepad
An Arduino based arcade style controller for my friends first game released on Steam!

This is a super fun and short(haha) project to create an Arduino based arcade style game controller.
The goal of this project is to be able to use arcade style joystick and buttons to play games on Steam.
Specifically IDOL HELL, a game created by some of my friends! Check it out here: https://store.steampowered.com/app/2067470/Idol_Hell/

Parts List & Links:
Sanwa 30mm arcade pushbuttons - https://focusattack.com/sanwa-obsf-30mm-pushbuttons-green/
Sanwa 8-way arcade joystick - https://focusattack.com/sanwa-jlf-tp-8yt-joystick/
Any ATMEGA32u4 Microcontroller, I used this one - https://www.adafruit.com/product/3677
(optional based on mcu and code) 10k Ohm Resistors on each digital I/O pin used
22AWG wire
(optional) Any protoboard/strip board you would like
access to a 3d printer

# Physical build

After pretending I didn't have to design the case for a long time, I finally got it done. Found a cool resource that talks about button layout that helped me break the wall and start working on it: https://www.slagcoin.com/joystick/layout.html

In the name of making things easier to print I decided to pull all the details on the cover off into their own separate files and glue them on. This meant there was a nice flat surface touching the print bed for everything.

*insert photo of final result*

# Electronics

The electronics here are pretty simple, a microcontroller with 8 GPIO pins and USB/Serial capability is all you need!
Although it would be super cool to make a custom PCB, it just feels overkill for using a couple GPIO pins so I have hand soldered everything and used the internal pullup resistors on the microcontroller.
Specifically I am using an Adafruit itsy-bitsy 5V 16MHZ Atmega32u4. The code I've written should really work on any Atmega32u4 board, just remember to change the pins!


*insert schematic here*

In case you don't like or don't have an mcu with internal pullup resistors here is a schematic with them placed externally:

*insert schematic here*

# Code

I went pretty simplistic with the code and it functions basically exactly like a macropad. This allows the buttons to easily be rebound and work on a large variety of games.
The Arduino keyboard.h library made this super simple too.

The one trick to remember is that since we are using internal pullup resistors to pull the disconnected state of each button high, we need to invert all of the inputs so they are active low(key pressed when shorted to ground).

