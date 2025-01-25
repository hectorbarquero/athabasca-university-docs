.. I'm on page 214/468 right now <-- NOT STARTED
.. Challenge work required, page 467 question 6 <-- NOT STARTED
.. assignment 4 is one exercise from chapter 9, 10, 11, and 12
.. QUESTION KEY
.. chapter 9, page 467, question 5. - DONE
.. chapter 10, page 523, question 8 - DONE
.. chapter 11, page 572, question 17. - DONE
.. chapter 12, page 618, question 38. - DONE



Unit four, section one
++++++++++++++++++++++++


General reading notes
======================

* Pending completion. I'm currently tackling the course content in reverse. Check back soon.


Introduction to high level programming
========================================

.. note::
   Pending completion. I'm currently tackling the course content in reverse. Check back soon.



Challenge work submission
===========================

1. Lorem ipsum
2. Lorem ipsum


.. note:: 
   Corresponds to challenge work #??, on page ??? of the text. The instructions may say a short profile, but the course Brightspace says 2-3 paragraphs is sufficient.



Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.


Assignment 4 (chapter four, section one)
===========================================

5. Again create a data file of random integers. Then write a program in the language of your choice to implement the selection sort algorithm of Figure 3.6 using file input data. Write a separate function (method, procedure) to find the location of the largest number in the unsorted section of the list (see Figure 2.14) and have your main function call that as needed. Write your sorted list to another data file.

Psuedocode
~~~~~~~~~~~
I chose this answer to revisit a similar question that I approached in an earlier unit, with a newfound understanding of what's happening *under the hood*. The psuedo has been simplified from my earlier approach, and I again chose javascript (my most natural language).

.. note::
   1. create a .txt file with random ints
   2. run the selection sort algorithm against it, similar to unit 1 section 3
   3. use a helper function to find the largest int in the sort
   4. re-write the sort data to another .txt file


This selection sort solution is a time complexity of O(n^2), which is inefficient for large tasks but fine for this small educational task. In a larger production, I would use something with better performance like a merge sort or quick sort.


Program 
~~~~~~~~

.. code-block:: javascript

   const fs = require('fs');

   //make .txt file with ran ints
   function createRandomInts(fileName, count, min, max) {
      const data = Array.from({ length: count }, () => Math.floor(Math.random() * (max - min + 1)) + min);
      fs.writeFileSync(fileName, data.join('\n'), 'utf8');
   }

   //helper func to find largest in .txt
   function findLargest(arr, end) {
      let largestPosition = 0;
      for (let i = 1; i <= end; i++) {
         if (arr[i] > arr[largestPosition]) {
               largestPosition = i;
         }
      }
      return largestPosition;
   }

   //run sort
   function selectionSort(arr) {
      const n = arr.length;
      for (let i = n - 1; i > 0; i--) {
         const largestPosition = findLargest(arr, i);
         // Swap the largest element with the last unsorted element
         [arr[i], arr[largestPosition]] = [arr[largestPosition], arr[i]];
      }
      return arr;
   }

   //read, then write out to another file
   function sortDataFile(inputFile, outputFile) {
      const data = fs.readFileSync(inputFile, 'utf8').split('\n').map(Number);
      const sortedData = selectionSort(data);
      fs.writeFileSync(outputFile, sortedData.join('\n'), 'utf8');
   }

   const inputFileName = 'input.txt';
   const outputFileName = 'output.txt';

   createRandomInts(inputFileName, 100, 1, 1000); // # of ints, range low, range max
   sortDataFile(inputFileName, outputFileName);

   console.log(`Sort completed. Open "${outputFileName}" for data.`);



Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.

"Mozilla Developer Docs, Math Functions." MDN Web Docs, Mozilla, https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math. Accessed 25 Jan. 2025.