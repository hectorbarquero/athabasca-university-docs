.. I'm on page 214/468 right now <-- NOT STARTED
.. Challenge work required, page 755 question 9 <-- DONE, submitted
.. assignment 5 is one exercise from chapter 13, 14, 15 and 16 <-- DONE, submitted
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

Animating the motion of an arm raising a glass to mouth.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The arm has three animation variables in this inverse or forward kinematic system; the shoulder (X), elbow (Y), and wrist (Z). We have context knowing that the arm shouldn't be hyperflexible, so respectively (X), (Y), and (Z) can rotate but not always perform reflection, since that would mean a hypermobile joint especially on (Y) in relation to the range of (Z). Niether of the joints can truly translate since they would separate from the body, so their motion is done by rotation of another control point. 

To raise the glass, (X) would rotate, and (Y) would compensate with additional rotation after a slight delay, followed by (Z). In this way, the final rendered outcome would be the smooth motion of reaching for a glass starting from movement in the shoulder, to bending and rotating the shoulder and elbow as needed, before a small wrist adjustment to grasp the glass. 

None of the movements are truly object translation since the control points are still locked and not being translated away from the origin, but instead are working off of eachother mathematically to create difference angles and orbits. If the glass were grasped with the hand first, the remaining joints could be inversely calculated. If the movement begins in the shoulder, the kinematic system would need to be forward.


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