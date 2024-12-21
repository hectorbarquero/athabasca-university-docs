.. I'm on 66/89 right now
.. I have not submitted the challenge work yet
.. an assignment is required for chapter 2 "Assignment 1 – choose ONE exercise each from Chapters 2 and 3"


Unit one, section two
++++++++++++++++++++++

.. quote goes here


General reading notes
======================

* Psuedocode is an informal and natural way to express a program design. It's a design notation.
* High-level programming languages have a high level of abstraction from machine language, so they're close to plain speak, but they carry cryptic syntax.
* Psuedocode ignores the cryptic syntax of high-level programming language, making the transfer of an idea during the programming concept easier.
* Psuedocode is simple, highly readable, and has virtually no grammatical rules. It's often called *a programming language without the details*
* In psuedocode, it doesn't matter how you write your instructions. They just need to be clear, effective, computable, and unambiguous.
* A variable is a named storage location which holds data. It's often compared to a mailbox where you can place a value and retrieve it.
* An algorithm that lacks routes or options is called a sequential algorithm, or a straight-line algorithm. The control flow for it is linear and it's execution is top-down.
* Conditional and iterative operations are called control operations.
* Conditional statements are the question asking operations of an algorithm, the if/then/else statements.
* Iteration is akin to looping, which is called the while statement.
* In a while statement, the value that evaluates if the condition is still true is called the continuation condition.
* The part of a while condition that is executed as long as the continuation condition is met is called the loop body.
* If for some reason the continuation condition never becomes false, then we have an infinite loop.
* A pretest loop is when the continuation condition is checked at the beginning before the loop body executes on each pass. In this case, it's possible the loop never executes at all.
* A more useful approach is the posttest loop where the continuation condition is checked at the bottom or end of the loop body on each pass rather than the start.
* In a do/while condition, the loop is always executed at least once.
* A while condition can execute 0, 1, 2, or more times.
* To be considered effective, algorithms need to accomplish tasks in a reasonable time.


*Notes are ongoing, pending completion*


Algorithm discovery and design
================================
Finding a solution to a given problem is called *algorithm discovery*.

When you write psuedocode, it needs to carry three basic sequential operations:

1. Computation
2. Input
3. Output

Practice problem A
~~~~~~~~~~~~~~~~~~~~
An algorithm that gets three data values `x`, `y`, and `z` as input and outputs the average of those three values.

.. code-block:: javascript

   // declare variables x,y,z
   // create a function with x,y,z as arguments
   // in the function, return the sum of all variables divided by three
   // run the function which gets user inputs for x,y,z

   let x = 0;
   let y = 0;
   let z = 0;

   function averageValues(x,y,z){
      return (x + y + z) / 3;
   }

   console.log(averageValues(3,2,1))


Practice problem B 
~~~~~~~~~~~~~~~~~~~~
Write an algorithm that gets as input three data values `x`, `y`, and `z` and outputs the average of these values **if the value of x is positive**. If the value of `x` is either `0` or negative, your algorithm should not compute the average but should print the error message *Bad Data* instead.

.. code-block:: javascript

   // create a function with x,y,z as arguments, declaring vars in scope
   // in the function, return the sum of all variables divided by three if:
   // x is greater than zero. Else, if x is less than zero, return "Bad Data" 
   // return null when it's printing Bad Data
   // run the function which gets user inputs for x,y,z


   function averageValues(x,y,z){
      if (x > 0) {
      return (x + y + z) / 3;
    }
      else { 
      console.log("Bad Data");
      return null;
    } 
   }

   console.log(averageValues(0,2,1))



Challenge work submission
===========================

1. Read chapter two of the textbook.
2. Complete challenge work #3, on page 88 of the text.


.. note:: 
   Corresponds to challenge work #3, on page 88 of the text. The instructions say a short paper, but the course Brightspace says 2-3 paragraphs is sufficient.


Pending completion


Works cited
~~~~~~~~~~~~

Pending completion