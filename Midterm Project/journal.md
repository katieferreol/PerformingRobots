# JOURNAL
**Shortcuts: [Day 1](journal.md#day-1-october-1), [Day 2](journal.md#day-2-october-3)**

## DAY 1: October 1

Starting off this project, I first created a sketch of what I want the robot to look like: I want it to use a Neopixel to show emotion, as well as evoke a different speed depending on its mood (fast for happy, back and forth for angry, etc.)

![](images/sketch.jpg)

During this time, my two Arduinos still weren't communicating well with each other. With this said, I decided to first work on the expression of the robot, which I thought would work best with the Neopixel. I began drawing a grid to determine which pixels I have to turn on.

I created four emotion animations:

STOIC:

![](images/stoic.jpg)
![](images/stoic.gif)

HAPPY:

![](images/happy.jpg)
![](images/happy.gif)

SAD:

![](images/sad.jpg)
![](images/sad.gif)

ANGRY:

![](images/angry.jpg)
![](images/angry.gif)

## DAY 2: October 3

Finishing all of my work in my other classes, I had the whole day today to work on what I was doing wrong with my second radio. It would still heat up when I tried to run the code. So, I went to the IM Lab to get advice and realized that *MY WIRING WAS COMPLETELY BACKWARDS!*

Attached is what I did, and what I was supposed to do. After finally rewiring it properly, I finally got it to work.

![](images/myVersion.jpg)
![](images/actualVersion.jpg)
![](images/finally.gif)

With now being able to clean my wires, I changed the buttons to the bigger ones from my Intro to IM kit and moved all the wires to the right so my finger won't get caught.

![](images/messyButtons.jpg)
![](images/cleanButton.jpg)

Taking what I learned in Professor's class, I added the Transmitter and Receiver class so each button will show a different emotion with the button. However, the reaction is very slow: as you can see, it stays stoic even when I press the happy button repeatedly.

![](images/slowReaction.gif)
