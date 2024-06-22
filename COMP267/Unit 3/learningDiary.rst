.. currently working this file

Unit 3 CSS site styling learning diary
++++++++++++++++++++++++++++++++++++++++++

.. _unit3-ref:

.. Warning::
   Nothing to see here. I am currently working Unit 3. Check back soon, since I'm updating these docs as I work on the code.

Summary
========

   *"Since I already know CSS, I decided to learn SASS and SCSS. This unit was difficult to execute because it requires knowing about the technologies in the units ahead, before actually studying them. I found myself studying into unit 4 and 5 concurrently to overcome this. For example, I found myself thinking the only way to animate something was with CSS, but in later units, we would be learning how to do this with javascript. This incurred a bit of technical debt which I hope is paid off."*


The work
==========
.. describe briefly what you have done as work for that unit.

1. Visit `AU course book <https://scis.lms.athabascau.ca/mod/book/view.php?id=13063>`_ > **print book** as .pdf for offline reading.

2. Read the 15 instruction pages.

    .. Note::
       The Unit 3 reading markup is provided as an attachment under **References**.

3. Make code I created in Unit 2 **"...beautiful and useable without changing HTML**.

    - Can change ``div``, ``span``, and add extra ``id`` or ``class`` tags.
    - ideally **do not change HTML unless necessary**.
    - change ``head`` tags as needed.

4. Upload the docs to GitHub and submit a learning diary post as a blog entry in the **Group Blog**


Assignment 3 submission
========================
.. describe the rationale for what you have done, relating your work explicitly to the personas and scenarios you developed in Unit 1.

Blank heading - fill in with assignment heading
-------------------------------------------------

:download:`You can download my Unit 3 source code by clicking here<../attachments/src/unit3-code.zip>`. Unpack the .zip and view the README.txt to learn more about the file structure. `You can also check out my project on GitHub <https://github.com/hectorbarquero/technicalwriting_sandbox>`_


The learning map
=================
.. for each learning outcome for the unit, explain how you have met it, with reference to the content that you produce (typically your code or other design artifacts).

Use this section to map my learning with the expected outcomes. This section is for the assessors who are grading my work.

Expected outcomes for Unit 3
-----------------------------
1. Write well-structured, easily maintained, standard compliant CSS to present HTML pages in different ways.


What went right and wrong
==========================
.. describe what you would do differently if you had to do it again.

- Figuring out how to keep scope and specificity of CSS was tricky. My CSS is actually one large file called ``styles.css`` generated from my SCSS when I run the command ``npm run sass`` to execute the generic SASS build script. It's nice because I can manage complex style sheets as modules, but it's tedious to manage selector scope. I had to debug a few things and settle with some common global values.

- SCSS learning curve. After a lot of reading, I was able to do some things that bare metal vanilla CSS can't do, and I could take advantage of some features like nesting, indentation, variables, and functions, right inside my SCSS.

- Minor edits to HTML as seen in source code. Download my .zip, and diff the two files to see where I had issues. I ended up needing to add more classes, or restructure a few tags to allow the specificity to be applied correctly.


Related topics
================
.. link related reading or topics

+ :ref:`Unit 0 learning diary <unit0-ref>`
+ :ref:`Unit 1 learning diary <unit1-ref>`
+ :ref:`Unit 2 learning diary <unit2-ref>`


Additional reading
===================

+ :download:`COMP 266 - Unit 3 orientation notes <./attachments/readings/unit3Reading.pdf>`
+ `Hectors project GitHub <https://github.com/hectorbarquero/university-COMP266>`_
+ :download:`COMP 266 - Unit 3 source code <>`


Get in touch
=============

I don't check my emails often. Connect with me on `LinkedIn <https://www.linkedin.com/in/hectorbarquero>`_, or see what I'm up to on `GitHub <https://github.com/hectorbarquero>`_.

