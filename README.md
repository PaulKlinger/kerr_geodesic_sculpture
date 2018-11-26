# 3D printed light sculpture showing the trajectory of a particle around a spinning black hole


[![](http://img.youtube.com/vi/DfhZvKPe3HQ/0.jpg)](http://www.youtube.com/watch?v=DfhZvKPe3HQ "")

This shows a timeslice of the path of a massive particle (with some specific initial position and velocity that gives a nice looking trajectory) around a [spinning (Kerr) black hole](https://en.wikipedia.org/wiki/Kerr_metric) (with parameters m=1, a=1/3). The black (very slightly squashed) sphere in the center represents the event horizon of the black hole.

I calculated the trajectory using mathematica (code in the notebook.nb file)by directly integrating the [geodesic equations](https://en.wikipedia.org/wiki/Geodesics_in_general_relativity). [Here's](https://i.imgur.com/O50RE7Q.png) the piece of it in the sculpture, and [here's](https://i.imgur.com/HQwdpmr.png) a longer section. The particle will continue to orbit the black hole indefinitely, with the radius changing between a minimum and maximum value. In contrast to orbits around non-spinning black holes or stars/planets (which can only spin very slowly) the trajectory is three-dimensional, i.e. it doesn't just stay in one plane.

I imported the trajectory into Fusion 360, put a hollow tube around it, and [printed it](https://i.imgur.com/pHP71ye.jpg) on my Prusa Mk3. Then I pushed some [side glow fiber optic](https://www.aliexpress.com/item/5mX-Transparent-side-glow-plastic-PMMA-fiber-optic-cable-solid-core-optic-cable-diameter-2mm-3mm/32807597828.html) through the tube (that was the hardest part of the whole thing...). The base and black hole are also printed. In the base there is an attiny85 microcontroller, a potentiometer, and two WS2812b LEDs, powered via a micro usb socket. [Here's a picture](https://i.imgur.com/nm2dvyY.jpg) of the internals.

Twisting the black hole turns the potentiometer and changes the illumination between off, fixed color, color changing, and white.