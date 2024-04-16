# IDOLHELL_Gamepad
An Arduino based arcade style controller for my friends first game released on Steam!

This is a super fun and short project to create an Arduino based arcade style game controller.
The goal of this project is to be able to use arcade style joystick and buttons to play games on Steam.
Specifically IDOL HELL, a game created by some of my friends! Check it out here: https://store.steampowered.com/app/2067470/Idol_Hell/

Parts List & Links:
Sanwa 30mm arcade pushbuttons - https://focusattack.com/sanwa-obsf-30mm-pushbuttons-green/
Sanwa 8-way arcade joystick - https://focusattack.com/sanwa-jlf-tp-8yt-joystick/
Any ATMEGA32u4 Microcontroller, I used this one - https://www.adafruit.com/product/3677
10k Ohm Resistors on each digital I/O pin used
22AWG wire
Any protoboard/strip board you would like

# Physical build

I'm back to finally finish this up! Honestly I had just been procrastinating the case design for a long time. Found a cool resource that talks about button layout thats been helping: https://www.slagcoin.com/joystick/layout.html

# Electronics

The electronics here are pretty simple, a microcontroller with 8 GPIO pins and USB/Serial capability is all you need!

*insert schematic here*

# Code

The code was pretty nice to work through because of the Arduino Keyboard.h libraries available

I'm looking at trying to set it up with an RP2040 board because I have one with a USB C
Although it would be super cool to make a custom PCB, it just feels overkill for using a couple GPIO pins.
