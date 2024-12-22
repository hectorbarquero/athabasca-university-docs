.. I'm on 83/89 right now
.. I have not submitted the challenge work yet
.. an assignment is required for chapter 2 "Assignment 1 – choose ONE exercise each from Chapters 2 and 3"


Unit one, section two
++++++++++++++++++++++

    *"an algorithm is deemed correct only when it produces the correct result for all possible cases."*


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
* A sequential search algorithm takes an array of data and parses it without any sort.
* An algorithm is deemed correct only when it produces the correct result for *all* possible cases.
* In while loops, we use an index pointer, usually a variable denoted as *i*. This acts as a moving finger scanning the list of data as we iterate through the loop.
* The selection of an algorithm to solve a problem is greatly influenced by the way the input data for that problem are organized.
* A sorting algorithm can reduce the time it takes to use a sequential search algorithm.
* A collection of prewritten algorithms is called a library, and they are important tools in design and development for more algorithms.
* "compare and save or discard" is referring to a sorting algorithm in the text. If it comes up in a test, it's probably going to ask which algorithm does this correlate to.
* Instructions that tell us not to do anything are usually omitted from an algorithm, because they do not carry any meaningful information.
* The process of searching for a special pattern of symbols within a larger collection of information is called *pattern matching*.
* Most word processors and text editors provide this as a feature in the **Find** tool.
* Pattern matching can be applied to any media type.
* Abstraction refers to the separation fo the high-level view of an entity or an operation from the low-level details of its implementation.
* Abstraction is one of the most important tools in computer science.
* In the design process, we use abstraction to ignore how we'll implement an algorithm so we can focus on the details of the design.
* This is called top-down design. (viewing the problem at a high level, implementing the details later).
* A *sliding forward* step in an algorithm helps to begin searching for a pattern in the next array or sequential position.
* When you use the *sliding forward* step, you can fall off the search string or input by exceeding the length of the search sequence. You need to terminate the sliding search by the length value.
* Designing a technically correct algorithm to solve a given problem is only part of what computer scientists do. We must also ensure that we have the most efficient algorithm.


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


Practice problem C
~~~~~~~~~~~~~~~~~~~~
Modify the algorithm of Figure 2.14 so that it finds the smallest value in a list rather than the largest. Describe exactly what changes were necessary

.. image:: ../images/figure-214.png
   :height: 400px

.. code-block:: javascript

   // declare a flag to check if swap is done or not
   // do: set flag to false
   //   for loop while the counter is less than the array length.. 
   //   if the array index n is greater than the index of n + 1...
   //   swap the elements. 
   //   swap = array n, array n + n = array n + 1, array n
   //   set swap flag to true to restart
   // use postcheck: while the flag is false...
   // return sorted array

   function sortArray(arr) {
   let swapCheck;

   do {
      swapCheck = false;
      for (let i =0; i < arr.length - 1; i++) {
         if (arr[i] > arr[i + 1]) {
         [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
         swapCheck = true;
       }
      }
    } while (swapCheck);
    return arr;
   }

   console.log(sortArray([10,1,5,17,2]));


I re-wrote the algorithm to be designed behind a dynamically typed programming language, and not a static one. Variables are declared as I use them, specifically the counter and index, so it's omitted from the psuedo. I changed the operand which checks if the array index is smaller, to checking if it's larger. 

I also switched the continuation condition to a postcheck for better error handling, since there's a possibility that the loop would not run at all.


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


Assignment 1 (chapter one, section two)
========================================
.. this is technically part 1/2 for assignment 1. The second part is in the next chapter, unitOneSectionThree.rst