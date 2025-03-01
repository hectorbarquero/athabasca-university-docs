.. I'm on page 214/528 right now <-- NOT STARTED
.. Challenge work required, page 525 question 2 <-- NOT STARTED
.. assignment 4 is one exercise from chapter 9, 10, 11, and 12
.. QUESTION KEY
.. chapter 9, page 467, question 5. - DONE
.. chapter 10, page 523, question 8 - DONE
.. chapter 11, page 572, question 17. - DONE
.. chapter 12, page 618, question 38. - DONE

Unit four, section two
++++++++++++++++++++++++
The tower of babel


Challenge work submission
===========================

1. Read chapter ten of the textbook.
2. Complete challenge work #2, on page 525 of the text.


.. note:: 
   Corresponds to challenge work #2, on page 525 of the text. The instructions may say a report, but the course Brightspace says 2-3 paragraphs is sufficient.


Vehicle dynamics (with a focus on fluid dynamics)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**Von Neumann sequential processing vs parallel processing, the benefits of distributed computing**

Vehicle dynamics involves modeling how force acts on all components of vehicle in motion, including aeronautic, traction based force, **and fluid dynamics**. Vehicle dynamics, including fluid, can build accurate simulations that help optimize all aspects of a vehicle, including safety and efficiency. Solving these problems improves safety, reduces operations costs, and improves cost savings for consumers.

Computationally, a challenge comes from solving large, nonlinear differential equations in real time. Accurate vehicle dynamics requires near real time and responsive physics simulations. Sequential processing does not do well with real time scenarios since they're calculated per item, and can overload a GPU or CPU. Fortunately, *parallel processing* is faster and can handle more complex simulations with distributed computing-- splitting the workload across various distributed CPUs and GPUs. 

Currently, AI and high-performance GPU development is allowing the use of real time embedded systems and supercomputer clusters, like the NVIDIA Jetson AGX Orin, which significantly improves simulations. In the past, supercomputers and more processing power were not practical for mounting on vehicles, but the advancements have made these computers small and practical, allowing them to be mounted on a dashboard or small engine.


Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.

NVIDIA. "Fast Fluid Dynamics Simulation on the GPU." GPU Gems, https://developer.nvidia.com/gpugems/gpugems/part-vi-beyond-triangles/chapter-38-fast-fluid-dynamics-simulation-gpu. Accessed 1 Mar. 2025.


Assignment 4 (chapter four, section two)
===========================================

1. 	In the following two Java output statements, Why do you think the first uses println and the second uses print?

**Answer**: Fundamentally, it corresponds to the UI/UX of the program. Both could be correct, but with the context of the message, each is better suited to their intended application.

Statement 1
~~~~~~~~~~~~~

.. code-block:: java

   System.out.println("Hello. Welcome to this program.");

This first statement uses the new line to create a line break, so that the welcome message is printed above where the cursor is moved to. This makes sense since the context of the message is to welcome the user, so a new block of text underneath would maybe be printed.

Statement 2
~~~~~~~~~~~~~

.. code-block:: java

   System.out.print("Tell me your favorite number: ");

The second statement uses print, and does not force the cursor to a new line. Instead, the user enters the input on the same console output as the printed message, giving the appearance that the two are connected. Though the programmer could have used a line break with *println*, this makes more sense given that there may be multiple questions or input/outputs, flooding the console. 

Extra space with the line break may create unecessary difficulty in reading or correlating the input and outputs when reading input from a user.


Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.
