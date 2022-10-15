<div align="center">

  <img src="https://user-images.githubusercontent.com/62047147/195847997-97553030-3b79-4643-9f2c-1f04bba6b989.png" alt="logo" width="100" height="auto" />
  <h1>TFT LCD Neopixel INT</h1>
  
  <p>
    Control Nepixels Via TFT LCD
  </p>
  
  
<!-- Badges -->

<p>
<a href="https://github.com/cifertech/TFT-LCD-Neopixel-INT" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=cifertech&message=TFT-LCD-Neopixel-INT&color=white&logo=github" alt="cifertech - TFT-LCD-Neopixel-INT"></a>
<a href="https://github.com/cifertech/TFT-LCD-Neopixel-INT"><img src="https://img.shields.io/github/stars/cifertech/TFT-LCD-Neopixel-INT?style=social" alt="stars - TFT-LCD-Neopixel-INT"></a>
<a href="https://github.com/cifertech/TFT-LCD-Neopixel-INT"><img src="https://img.shields.io/github/forks/cifertech/TFT-LCD-Neopixel-INT?style=social" alt="forks - TFT-LCD-Neopixel-INT"></a>
   
<h4>
    <a href="https://twitter.com/cifertech1">TWITTER</a>
  <span> · </span>
    <a href="https://www.instagram.com/cifertech/">INSTAGRAM</a>
  <span> · </span>
    <a href="https://www.youtube.com/c/cifertech">YOUTUBE</a>
  <span> · </span>
    <a href="https://cifertech.net/">WEBSITE</a>
  </h4>
</div>

<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Pictures](#camera-Pictures)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Schematic](#electric_plug-Schematic)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Contributing](#wave-contributing)
- [License](#warning-license)
- [Contact](#handshake-contact)

  

<!-- About the Project -->
## :star2: About the Project
Smarter and easier control of neopixels has always been interesting and challenging. In the past, I published tutorials that we used to control ws2812 neopixels in different ways, such as controlling these powerful and interesting LEDs using web servers. I want to teach you how to control these neopixels using TFT LCD, so that you can control and change their status in the shortest possible time. In this tutorial, you will have complete control just by touching the elements displayed on the screen.

<!-- Pictures -->
### :camera: Pictures

<div align="center"> 
  <img src="https://user-images.githubusercontent.com/62047147/156326363-ecf68ea3-f73e-4738-8705-48f740f1c75b.jpg" alt="screenshot" />
</div>

<!-- Features -->
### :dart: Features

- Choose the desired colors by touching the screen
- responsive

<!-- Getting Started -->
## 	:toolbox: Getting Started

I used Arduino mega because we have more GPIO available, and TFT LCD ili9488.

- Arduino Mega/UNO
- TFT LCD ili9488
- Neopixel ws2812b

<!-- Schematic -->
### :electric_plug: Schematic

Make the connections according to the table and schematic below.

| Arduino Mega| Neopixel|
| ----   | -----|
| 21  | Din |
| 5v  | Vcc |
| GND | GND |


* Complete Schematic

<img src="https://user-images.githubusercontent.com/62047147/195982176-7a197a65-c783-49fe-94f9-076dae689c5c.jpg" alt="screenshot" width="800" height="auto" />


<!-- Installation -->
### :gear: Installation

By changing this part of the code, you can change the pin connected to the LEDs.
```c++
#define PIN 21
```

These two items are related to the number of LEDs and their light intensity
```c++
#define NUM_LEDS 165
#define BRIGHTNESS 100
```
  
<!-- Usage -->
## :eyes: Usage

Just touch the desired color!

<!-- Contributing -->
## :wave: Contributing

<a href="https://github.com/cifertech/TFT-LCD-Neopixel-INT/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=cifertech/TFT-LCD-Neopixel-INT" />
</a>


<!-- License -->
## :warning: License

Distributed under the MIT License. See LICENSE.txt for more information.


<!-- Contact -->
## :handshake: Contact

CiferTech - [@twitter](https://twitter.com/cifertech1) - CiferTech@gmali.com

Project Link: [https://github.com/cifertech/TFT-LCD-Neopixel-INT](https://github.com/cifertech/TFT-LCD-Neopixel-INT)

