# evaluator-o-matic

A dead simple calculator used to learn a smidge of C

# Cans and Can'ts

```diff
+ Handles positive, negative and decimal values
+ Accepts + - * / ^ ( ) operators
+ Dynamically sized stacks, as opposed to hard coded stack sizes (wow such feature) 
- Can't do implicit multiplication (eg: 1(2 + 3))
- Tokens must be seperated by spaces when being input
```

# Compiling

This requires you to have make and gcc installed. I've only tested this on Apple silicon but I see no reason why it shouldn't work elsewhere.

To compile, just run `make`