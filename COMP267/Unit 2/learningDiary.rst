.. currently working this file

Unit 2 HTML site building learning diary
++++++++++++++++++++++++++++++++++++++++++

.. _unit2-ref:

.. Caution::
   Nothing to see here yet. I'm still working this unit. Check back soon.

Summary
========

   *"Despite working with HTML 4.01 in the past, I chose to use HTML5 to benefit from deeper learning, which required me to read a lot of W3 and MDN docs."*


The work
==========
.. describe briefly what you have done as work for that unit.

1. Visit `AU course book <https://scis.lms.athabascau.ca/mod/book/view.php?id=13061>`_ > **print book** as .pdf for offline reading.

2. Read the 18 instruction pages.

    .. Note::
       The Unit 2 reading markup is provided as an attachment under **References**.

3. Prepare the site HTML.

   - Create my HTML pages, compliant with HTML5
   - Add several images, custom made
   - Hyperlinks between all the pages using relative URLs
   - Sufficient text for three heading styles
   - Several unordered lists
   - Several div, span, and id tags for styling, to be applied later
   - A table
   - A form, which mails the contents to me

4. Upload the docs to GitHub and submit a learning diary post as a blog entry in the **Group Blog**

5. Notify the tutor of the submission, and upload to the **AU drop box**.



Assignment 2 submission
========================
.. describe the rationale for what you have done, relating your work explicitly to the personas and scenarios you developed in Unit 1.

Review of sample.html
----------------------

Overall, `sample1.html <..attachments/src/sample1.html>`_ is missing a lot of closing tags and has poor structure and readability including lacking indentation and semantic writing. In terms of accessibility, the file is missing meaningful content, which could be optimized in meta tagsets. The document lacks roles and attributes, which would help accessibility. 

The .html file is using inline .css styling, which could be better left to a stylesheet. It may be better to use span tags in those areas.

`sample2.html <..attachments/src/sample2.html>`_ seems to be empty, but is at least declared correctly. In my opinion, it would be better to move this to html5, but it appears the purpose for sample2.html is to allow sample1.html to demonstrate linking.


.. code-block:: html
   :caption: Undeclared/unspecified DOCTYPE -- missing encoding and responsive declaration
   :linenos:

   <html>
   <head>
   ...


.. code-block:: html
   :caption: Missing title and meta info.
   :linenos:

   <html>
   <head>
   <title></title>
   </head>
   ...

.. code-block:: html
   :caption: Para tag is not closed. h1 is declared in wrong spot, move to meta, and lowercase for best practice.
   :linenos:

   <body>
   <H1> This page is poorly written</H1>
   <p>
   There are many things wrong with this page. It's not so bad that it won't work on most browsers, but it has many things that could be written much better.
   Your job is to use this code as a starting point and improve it.
   ...

.. code-block:: html
   :caption: h2 missing closing tag, uppercase. Para tag missing closing, uppercase.
   :linenos:

   ...
   that could be written much better.
   Your job is to use this code as a starting point and improve it.

   <H2>You could, of course, cheat!
   <P>There is nothing wrong with using an HTML cleaner
   ...

.. code-block:: html
   :caption: inline styles.
   :linenos:

   ...
   you will find it <i>much</i> harder later on.
   ...

.. code-block:: html
   :caption: h3 uppercase, not closed. a href is closed incorrectly.
   :linenos:

   ...
   <H3>
   Adding links
   <p><a href="sample2.html">This is a link to the other page in this badly written pair of pages</a>).
   ...

.. code-block:: html
   :caption: missing roles in img tag, img tag not closed properly. Para tag not closed.
   :linenos:

   ...
   <h3>Using pictures</h3>
   <p>Pictures are not a part of a web page - 
   ...
   <img src=aulogo.gif>
   ...

.. No highlighting. Lex linting doesn't know what to do with the tags in sample.
.. code-block::
   :caption: ul tags are not closed properly or indented.
   :linenos:

   ...
   <h3>Making lists...
   <ul>...<ul<li>indented<ol><li>numbered<li>like this</li></ol></ul><li> and more</li></ul>
   ...

.. code-block:: html
   :caption: Table tags not closed properly, h3 is not closed.
   :linenos:

   ...
   <h3>Making tables
   <table border=1><tr><td>Tables should only be used for tabular data<td>and never for layout</tr>
   <tr><td>but many people do <td>use them for layout</tr>
   <tr><td colspan=2>It's not good for accessibility. Stylesheets work much better for this</td>
   </tr>
   </table>
   ...

.. code-block:: html
   :caption: sample 2 is declared better, but empty. Could be improved by moving to html5
   :linenos:

   <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
   <html xmlns="http://www.w3.org/1999/xhtml">
   <head>
   <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
   <title>Untitled Document</title>
   </head>

   <body>
   </body>
   </html>



Pages versus personas
----------------------

It's important to note that some of the requests for Unit 2 shaped the build, which directly conflicts with the personas. Rather than edit the personas to comply with the needed tags of Unit 2, I decided to use workarounds. An example is my persona Peter J Demarko, who doesn't like giving his email. A requirement of Unit 2 is to *give an email which mails to me*, so to workaround this, I used a privacy declaration in a README.txt. Some other requirements can be better fixed in Unit 3 and 4, where ``.css`` and ``.js`` files will be able to provide better solves. The below was implemented with .html only, per the requests of Unit 2. 

+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Name                | Wants                 | Requests             | Needs             | Solve                                                                                                                                                               |
+=====================+=======================+======================+===================+=====================================================================================================================================================================+
| Peter J Demarko     | News                  | Privacy              | Hearing aid       | No popups, aria labels for screen readers, and a privacy declaration in the README.txt                                                                              |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Lena Wagner-Bauer   | Skills                | No pay walls         | Vision aid        | GNU license, headings for visibility, aria-labels for readers. Unit 3 will handle more vision impairment help.                                                      |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Priya Patel         | Tools                 | No pop ups           | Colour blind help | No plans for js pop ups. Unit 3 will have dark and light mode, high contrast                                                                                        |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Simran Gupta-Sharma | Images                | No nested navigation | None              | Navbar doesnt go many indentures deep. iFrame supports rendering content on similar pages                                                                           |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| John Aaron Smith    | Short posts           | Slow loading pages   | None              | Used lazy loading, and plans for dns soaking, and cache busting                                                                                                     |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Lee-anne Rutherland | Videos, one stop shop | No external links    | Neurodivergent    | Used embedded video to show tool in one stop. Downloads available on same site, but external links optional. Will keep styling as minimally distracting as possible |
+---------------------+-----------------------+----------------------+-------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+


The learning map
=================
.. for each learning outcome for the unit, explain how you have met it, with reference to the content that you produce (typically your code or other design artifacts).

Use this section to map my learning with the expected outcomes. This section is for the assessors who are grading my work.

Expected outcomes for Unit 2
-----------------------------
1. Write well-structured, easily maintained, standards-compliant, accessible HTML code.

My mapped learning
-------------------

.. Tip::
   AU evaluators use this rubric to grade assignments. To comment, open the build menu, titled **v: latest** > select .pdf to > comment on a local pdf reader.


.. csv-table:: Template for mapping your activities to learning outcomes
   :file: ../attachments/learningTemplate2.csv
   :widths: 45, 35, 10, 10
   :header-rows: 1



What went right and wrong
==========================
.. describe what you would do differently if you had to do it again.

Despite working with HTML 4.01 in the past, I chose to use HTML5 to benefit from deeper learning. I'm optimistic about the default canvas graphics API in HTML5, the native support for features like .svg, <audio> and <video> tags, the strong focus on the DOM, mobile optimization, and form controls. 

This unit required me to read a lot of W3 and MDN docs, which is good because now I understand a range of html tags and best practices, like semantic writing and ARIA compliance.

If I were to do this unit again, I would focus on completing *just* enough to submit and move on to Unit 3, rather than completing all of my site .html pages. 

The reason I think this would have been better is that it would have allowed me to get to the later units more quickly, and discover what might need to change sooner. I'm sure there will be needed changes.

Normally, I program both side-by-side, and doing all of the .html first might become problematic later and require more technical debt.



Related topics
================
.. link related reading or topics

+ :ref:`Unit 0 learning diary <unit0-ref>`
+ :ref:`Unit 1 learning diary <unit1-ref>`


Additional reading
===================

+ :download:`COMP 266 - Unit 2 orientation notes <../attachments/readings/unit2Reading.pdf>`
+ `Hectors project GitHub <https://github.com/hectorbarquero/university-COMP266>`_
+ :download:`COMP 266 - Unit 2 source code <../attachments/unit2.zip>`


Get in touch
=============

I don't check my emails often. Connect with me on `LinkedIn <https://www.linkedin.com/in/hectorbarquero>`_, or see what I'm up to on `GitHub <https://github.com/hectorbarquero>`_.

