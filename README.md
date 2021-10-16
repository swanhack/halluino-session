# swan_hack Halluino Session
Hello everyone!<br>
Today we will get you started with programming arduinos to make something cool with pumpkins and RGB strips.<br>
This is a basic course that requires absolutely no programming knowledge, and so anyone is welcome!<br>
The layout is as follows:
1. [Basics about programming](https://github.com/swanhack/halluino-session/blob/main/README.md#basics-about-programming)
2. How to set up your arduino
3. Cycling through light patterns I've programmed
4. Making your own light patterns 
<br>
Note, folks who know how to do all this stuff should head to THIS LINK THAT WILL DEFINITELY EXIST IN THE FUTURE <br>

## Basics about Programming
### Code execution
Typical code looks like this:
```
1    int x = 4 + 2
2    int y = 6 - 9
3    blinkNumberOfTimes(x + y)
```
- This program creates two "variables", 
  - On line 1, it creates an integer (number) variable "x", which stores the result of 4 + 2
  - On line 2, it creates an integer (number) variable "y", which stores the result of 6 - 9
  - Think of variables as temporary storage, we give it a name on the right side, and then assign a value using `=` and some computation (like `4 + 2`)
- Then it calls a "function", which basically calls more code that is defined elsewhere by you or someone else.
  - In this case, lets imagine we have a function caled "blinkNumberOfTimes" which allows you to pass in a value, and then it blinks the LEDs that many times.
  - You can pass in a value after by calling its name (i.e. `blinkNumberOfTimes`) followed by an open bracket `(`, the value (e.g. `42` or `x + y`), and then a closed bracket `)`
 
### Loops
Let's take a look at our previous example, but with two additional lines:
```
1    for ( int i = 0; i < 15; i = i + 1) {
2        int x = 4 + 2
3        int y = 6 - 9
4        blinkNumberOfTimes(x + y)
5    }
```
- Line 1 basically just says, "do the following 15 times".
  - So the program would define variables `x` and `y`, and then call the function `blinkNumberOfTimes` 15 times
  - Which means the LEDs will blink 15 * (`x` + `y`) times!
  - If you want the loop to repeat less or more times, just change the `15` to something else!
  - Make sure to specify where you want the loop to end with a closed curly bracket `}` !

### Some important notes
Please note that this is an **extremely** simplified tutorial of programming<br>
You can naturally do a lot more with programming and control flow, this is just a starting point to get you comfortable with the basics!<br>
If something is not working, you would like something to be explained, or you want to know how to do something specific, don't hesitate to ask!<br>
