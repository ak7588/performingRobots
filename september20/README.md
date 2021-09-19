# 🤖 Welcome Bob - my first performing robot!

Firstly, let me define what is a robot. 

#### A robot is a programmed hardware that can perform a set of commands defined by the programmer. A robot *can* have a special physical appearance for a better audience impression, but it's not required to.

# 🕺 The Performance

Here is the final (and the best of all) performances of Bob. Bob is just learning how to "walk" (drive) and is trying to move back and forth. Hence the awkaradness in movements. Please be patient while Bob is taking his first steps.

![](performingRobot.gif)

# 🔧 How I built this?

Now let's dive into the process. Before having the final version of my robot, I spent some time trying to (1) physically build a robot that can move with wheels, (2) write good code so that wheels can actually move.

Take a look at some of the failed attempts to build Bob:

![](failedAttempt.gif)

(Failed Version #1: a version of Bob with the unsustainable physique)

Finally, after tinkering around with Bob's physique, I was able to build this final look:

<img src="https://github.com/ak7588/performingRobots/blob/main/september20/bob.JPG" width="300">

You are probably wondering how the wheels work -- I connected them with a piece of cardbox that I glued to the plastic part of the motor. I was too scared to glue motors directly as it could damage them, so cardbox seemed like a quick workaround. This version of wheel placement came after the first unsuccessful attempt to build Bob (see Failed Version #1 above).

# 🕹 What's with the code?

Bob is supposed to move in one direction right after pressing two buttons at the same time. After 5 seconds pass, Bob moves in the opposite direction if the buttons are still pressed.

Before this working version, there were many fails. Here is a short depiction of my failed attempts to write a working code for the motors:

![](failedAttempt2.gif)

(Failed Version #2: a version of Bob that can't properly move because of wrong code)

After a while of trying to time and delay different motors, I was able to come up with this code for Bob to move:

````
  // move in one direction before 7 seconds passed
  if ((millis() - delayTime) >= 7000) {
      if (digitalRead(button_one) == HIGH) {
        digitalWrite(in4Pin, LOW);
        digitalWrite(in3Pin, HIGH);
      } else {
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
      }
    
      if (digitalRead(button_two) == HIGH) {
         digitalWrite(in1Pin, LOW);
         digitalWrite(in2Pin, HIGH);
      } else {
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
      }
  // change direction to go backwards    
  } else {
      if (digitalRead(button_one) == HIGH) {
        digitalWrite(in3Pin, LOW);
        digitalWrite(in4Pin, HIGH);
      } else {
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
      }
    
      if (digitalRead(button_two) == HIGH) {
         digitalWrite(in2Pin, LOW);
         digitalWrite(in1Pin, HIGH);
      } else {
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
      }
  }
````
