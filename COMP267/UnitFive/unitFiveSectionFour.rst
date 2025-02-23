.. I'm on page 214/468 right now <-- NOT STARTED
.. Challenge work required, page 755 question 9 <-- not started
.. assignment 5 is one exercise from chapter 13, 14, 15 and 16
.. QUESTION KEY
.. chapter 13, question 10 page 650
.. chapter 14, question 4, page 684
.. chapter 15, question 3a, 3b, page 724, 725
.. chapter 16, question 4, page 754


Unit five, section four
++++++++++++++++++++++++
Computer graphics and entertainment



Challenge work submission
===========================

1. Read chapter 16 of the textbook.
2. Complete challenge work #9, on page 755 of the text.


.. note:: 
   Corresponds to challenge work #9 on page 755 of the text. The instructions may say a short profile, but the course Brightspace says 2-3 paragraphs is sufficient.


Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.


Assignment 5 (chapter sixteen, section five)
==============================================
.. this is technically part 4/4 for assignment 5. The earlier parts are in the first chapters, unitFiveSection[n].rst

*4. Assume a polygon mesh contains 250,000 vertices. If a single matrix multiplication requires 28 floating-point operations, how fast a GPU is needed (floating-point operations per second) to produce real-time graphics at the rate of 30 frames per second? (Chapter 16, page 754)*


Solution
~~~~~~~~~

The formula to calculate fast of a GPU is needed is:

.. math::

   \text{FLOPS per second} = (\text{Number of vertices} \times \text{Floating-point operations per vertex}) \times \text{Frames per second}

Therefore:

.. math::

   \text{FLOPS per second} = (250,000 \times 28) \times 30 = 210,000,000

.. tip:: 
   You can copy and paste the javascript to test the formula in the console of a web browser:

.. code-block:: javascript

   const vertices = 250000;
   const operationsPerVertex = 28;
   const framesPerSecond = 30;

   const totalFLOPS = vertices * operationsPerVertex * framesPerSecond;
   console.log(totalFLOPS); // outputs = 210000000



Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.