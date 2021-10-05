# JOURNAL
**Shortcuts: [Day 1](journal.md#day-1-october-1), [Day 2](journal.md#day-2-october-3), [Day 3](journal.md#day-3-october-5)**

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

## DAY 3: October 5

Today, I wanted to get to the bottom of why the delays of the emotion animations were so late after the button is pressed. However, before doing this, I created a small box for the neopixel that would serve as the "head" of the robot. I was happy with how sturdy I made it: usually my box making skills aren't that good.

![](images/neoBox.gif)


Now to tackle the delayed response in the animation. Testing a few things, I noticed that my motors acted immediately after the button is pressed, and only when the neopixel animations are added do they become delayed as well.

![](images/fastMotors.gif)


After discussing this with Jack, he said that it was most likely due to the delay function in the neopixel animation. Together, we came up with a code that would make use of millis() instead. This is something I already tried, but I thought the method of adding it would be different as we are using bytes rather than numbers.

![](images/jackNotes.jpg)


After using this code, the animations finally worked quickly! I was very happy with how it turned out. However, one thing I am still confused about is why the radio is giving a signal of 2 even when I'm not pressing anything. This makes the neopixel stuck on the "stoic" animation and intersect with other animations if I press it for less than a second.

![](images/emotionMix.gif)
