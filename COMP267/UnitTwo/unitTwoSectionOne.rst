.. I'm on page 159/218 right now
.. Challenge work required, page 217 question 3
.. assignment is ??

Unit two, section one
++++++++++++++++++++++

   *"currently working, nothing to see here"*



General reading notes
======================

* 10 decimal is numerics, and sign/magnitude is +(n) or -(n) notation. Decimal notation is used for real numbers, and a decimal point separates fractional parts. Alpha chars for A-Z.
* Computers use an internal and external representation of these, what the machine sees and what we see are different.
* Internally, computers use binary.
* Binary is a base 2 positional numbering system.
* Decimal is a base 10.
* In a base 2 positional numbering system, the worth of a number is based on it's position, not it's value.
* Bits is the contraction of binary and digits.
* Any whole number that can be represented in base 10, can be represented in base 2, but it will take more digits to represnt a decimal digit in binary.
* To convert decimal to binary, we use the decimal to binary algorithm, dividing the decimal by two and examining the quotient. The remainder represents the binary of 1 or 0. We do this again until the decimal value has a quotient of 0.
* In every computer, there is a maximum of binary digits that can be used to store an int. Usually, 16, 32, or 64 bit systems.
* in an 8 bit, max value is 11111111. In 16 bit, it would be 16x1 for a total of 65,535 bits. Anything over this cannot be represented without a higher bit system.
* Attempting to represent a binary digit larger would result in a buffer overflow, or arithmetic overflow.
* One of the differences in math and computer science is that in math, a quantity can take any representation. Computer science deals with finite representations, and it has to handle errors for exceeding those.
* In binary addition, if you add 1+1 you get 10, which in base 2 is a total of 2.
* I recommend looking up a video on how to add binary numbers, because the text book doesn't present this well. It's easier to see in a short video.
* Binary can also represent signed integers and characters. For signed ints, it will have a 1 for minus, and 0 for addition. For example 1 110001 is -49, and 0 000011 is +3.
* The meaning of a binary number is based solely on the context in which it's used, meaning that a computer technically doesn't know the difference between 1110001 and 1 110001. It's the context of how we use it.
* This isn't irregular when you think about the english language i.e ball (sports) vs ball (event).
* The reason is to avoid the messy representation of negative zero (1 00000..000) vs zero (0 0000...0000). Consider if a = b, do X. Else do y. What if both are 0, but one is + and the other -?.
* To avoid this, computer designers prefer signed int's that don't suffer the two zero problem, hence the context.
* Two's complement representation is when you write binary patterns in a circular form in increasing order. The positive works clockwise, whereas the negative is counter clockwise.
* In the Two's Complement Representation, there is only a single zero (000 ... 0000). There is a problem with the existence of a singular zero pattern.




Heading
=========================





Challenge work submission
===========================

1. Read chapter four of the textbook.
2. Complete challenge work #3, on page 217 of the text.


.. note:: 
   Corresponds to challenge work #3 on page 217 of the text.


Works cited
~~~~~~~~~~~~
