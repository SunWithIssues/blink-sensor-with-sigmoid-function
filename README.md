# Blink Sensor With Sigmoid Function
A simple Arduino project made more complicated! Has the rate which two LEDs flash depending on the environment, uses the Sigmoid function.

## Sigmoid Function
The sigmoid function is a bounded, real function. Its bounded by two horizontal asymptotes as x approaches positive and negative infinity. Graphically, the function produces an "S"-shaped curve.

The function is represented by the formula:

   ![formula](https://github.com/SunWithIssues/blink-sensor-with-sigmoid-function/blob/master/images/sigmoid_function.gif)

## Why the Sigmoid Function?
In simple terms, since the function both has an upperbound and a lowerbound asymptote, we can have the speed at which the LEDs blink never go too fast or too slow. (Basically, I know that flashing lights are bad for the eye and I am impatient. Hence, the use for the function.)

## Modifications of the Function in the Code
For the environment which I built the Arduino, the brightest measured light was below 1100 and the darkest was above 800. (Measured by photocell/LDR in the kit.) The longest I was able to wait for the lights to blink was 2000ms and the shortest blink was 100ms.  

Therefore the modified formula is:
     ![modified_formula](https://github.com/SunWithIssues/blink-sensor-with-sigmoid-function/blob/master/images/modified_sigmoid.PNG)
     
Of course, these variables might be different for you!
