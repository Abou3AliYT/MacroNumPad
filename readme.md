# Introduction

Before anything, I would like to deeply and kindly thank [ai03](https://ai03.com/), [reuiqimao](https://github.com/ruiqimao), [Joe Scotto](https://www.youtube.com/@joe_scotto), and [masterzen](https://www.masterzen.fr/keyboard/) for providing guides and videos on how you can start a keyboard design process yourself, I will link all of their work in the references section of the Readme. I began with designing the PCB using KiCad EDA, a free and open source software used for circuit design and electrical work. At the beginning I used an ATmega32u4 MCU (Micro Controller Unit :nerd:) for simplicity and ease of access at the time. I will be dumbing down the steps of the design process to Lamin's terms for easier understanding, which are drawing the schematic, wiring the PCB and Fabricating the PCB on JLCPCB.com. 

**NOTE:** If you know everything I offer here, I will provide all of the files related to this project such as the KiCad project, STL file for CAD, QMK/VIA firmware and other stuff that I might have forgotten for your tinkering and learning purposes.
## Chapter I, Part I - The Schematic

Following the guides provided by the individuals I mentioned earlier, I first made a simple 4x6 switch matrix with each switch getting it's own diode and two of the switches removed to make space for the 128x32 OLED. Each row and column will be using a pin on the ATmega32u4 so we will assign each of them a **global label** for ease of wiring in the MCU schematic, and I wired the OLED according to the pinout shown in the picture below:

![[Screenshot_232.png]]

For this part I highly recommend referring to ai03's guide on how to properly wire an ATmega32u4 to it's respective components, but the picture below shows how it is generally meant to be wired. I will also mention that when wiring any MCU, it is also highly recommend to refer to the original data sheet containing the proper information on how and what to wire to the respective MCU. 

![[Screenshot_233 1.png]]
## Part II - The PCB 

Here is some of the worst wiring possible for the MCU, here is a picture below:

![[Pasted image 20250604192905.png]]

Organization is a very important skill when in comes to wiring the PCB, and when it comes to circuitry involved with MCUs and small components such as this, it requires wiring from, to and back to the original component, meaning that there is an order of components to be wired first with constant consideration of keeping sufficient space for the pinout of all the other components and the MCU pinouts. 

![[Screenshot_236.png]]
## Provided Guides And References

If you have the time, please check out these guys' GitHubs, YouTube and Websites if you have any interests in keyboard stuff, these people are awesome. 

[ai03's PCB guide](https://wiki.ai03.com/books/pcb-design/page/pcb-guide-part-1---preparations)
[masterzen's PCB guide](https://www.masterzen.fr/2020/05/03/designing-a-keyboard-part-1/)
[Ruiqi Mao's PCB guide](https://github.com/ruiqimao/keyboard-pcb-guide) 
[Joe Scotto's YouTube Channel](https://www.youtube.com/joescotto)
