# Arduino-Traffic-Light
A Mini Traffic light system with a basic Arduino set. While not complicated, is a good way to learn and start with embedded programming by applying it to something we are all familiar with.
## Components used:
- Arduino Uno
- Red LED (x2)
- Green LED (x2)
- Yellow/Orange LED
- 1kOhm Resistors (x5)
- Passive Buzzer


## Block digram representation of the System:
![Block Diagram](BlockDiagramTraffic.png "Blk diagram picture")

### Arduino
The main controller of the system, it waits for an interrupt activation via the button
which tells it to change state and that the pedestrian's light should be green.

### Car Traffic lights
By default is green then when Arduino detects the button, the lights will go into the sequence:
1. A (1s)
2. R (While buzzer plays sound)
3. RA (1s)
4. G


R = Red
A = Amber
G = Green

When a letter doesn't appear in a specific step of the sequence, that means it's turned off.

### Pedestrian Lights
Similar to the Car Traffic Lights except its just R & G. By default it's pressed, then when 
the buzzer starts making the high frequency noise, G comes on until the buzzer stops it's crossing sound.

### Passive Buzzer
As soon as the traffic light turns red, the Buzzer plays sound similar to that of the Australian/Singaporean
pedestrian sound (https://www.youtube.com/watch?v=C1MMZDY9zZ0, https://www.youtube.com/watch?v=3YhQiC3x31w).

Unlike in real life, if a countdown timer was included, it would require the Arduino to juggle between playing
the sound and counting down on a display screen (since it can't run tasks in parallel like an RPi or FPGA), 
so as of 17th August 2026, this feature has not been added. 

To let the pedestrians know the time is up, a woodpecker sound is added in the end after the main sound just before
the green pedestrian light turns off.

### Button
Once pressed, this will activate an interrupt in the Arduino telling it to stop the default state
(green light and red pedestrian light).

## Flowchart of how the system will operate:
![Flowchart](FlowChartSystem.png "flowchart of the system") 

This helps visualise how the whole thing will play out on the Arduino as it shows how the Arduino can do it
all sequentially rather than parallel (one of it's limitations).


## References used:
- Arduino Documentation
- ChatGPT

Whilst using AI is not always the answer, as the world progresses and AI becomes more integrated with
our lives, lots of people and companies have used it to help speed up the process. it's good to practice
to get use to using it properly - making sure you understand what it tells and gives you.