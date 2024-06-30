.. READY - submitted 30 JUN 2024

Script use and augmentation
++++++++++++++++++++++++++++

.. _unit4-ref:

.. Tip::
   `Download my Unit 4 source by following this link <https://drive.google.com/file/d/1ohsr5GTyzS12N20lMOpcU4KrF_eqrI6d/view?usp=drive_link>`_. Unpack the .zip and view the README.txt to learn more about the file structure. `You can also check out my project on GitHub <https://github.com/hectorbarquero/technicalwriting_sandbox>`_


Summary
========

   *"I chose to use input validation, sourced from Rasel Mahmud (https://gist.github.com/rsmahmud) on GitHub. Jump to my critique to see what it does. I leave review comments in his code and I integrated an improved version in my HTML5."*


The work
==========
.. describe briefly what you have done as work for that unit.

1. Visit `AU course book <https://scis.lms.athabascau.ca/mod/book/view.php?id=13065>`_ > **print book** as .pdf for offline reading.

2. Read the 33 instruction pages.

    .. Note::
       The Unit 4 reading markup is provided as an attachment under **References**.

3. Find a small piece (or pieces) of javascript from the web, and integrate it into one or more of your web pages. **Make sure to cite it**.

4. In your learning diary, describe what it does. Critique it. Describe how it relates to your personas from Unit 1.

5. Upload the docs to GitHub and submit a learning diary post as a blog entry in the **Group Blog**



Assignment 4 submission
========================
.. describe the rationale for what you have done, relating your work explicitly to the personas and scenarios you developed in Unit 1.

Javascript critique
--------------------

I chose to use input validation, sourced from `Rasel Mahmud <https://gist.github.com/rsmahmud>`_ on GitHub, since the pre-reqs require collecting this and my personas want to stay updated with industry news. It's important the emails I collect actually are genuine.

On `his commit <https://gist.github.com/rsmahmud/f6ad75b8a212a18720fd833b54ea6644>`_, he uses javascript in a script tag to manage form and email validation.

The code is on line ``53`` to ``118``. 

I'll review the code below, providing a comment on each line.

.. tip::
   Want to read code block this without the scrollbar? Copy it > paste it in your favourite IDE or text editor.


.. code-block:: javascript

  <script type="text/javascript">            
      function Validate(){ // he declares a funct called Validate, self describing. Good.
          if(document.myForm.Name.value==""){ // first check = is name empty. He doesn't comment this one. Personally I think it's fine because it's self describing, but he does comment email validation.
              alert("Please provide your name!"); // alert text warns user - I think this is bad practice. Should use modal dialog and callbacks bc alert will block js execution. Personal comment as well, the prompt isn't UX friendly.
              document.myForm.Name.focus(); // sets focus to the name field, which helps the user debug. Good
              return false; // this is how he does client side form validation, he cancels the submission by returning false
          }
          //Email Validation
          if(document.myForm.EMail.value==""){ // second block here is the exact same as above, but changes to check email != empty
              alert("Please provide your email id!"); 
              document.myForm.EMail.focus();
              return false;
          }
          // in this block, he declares values and initializes some. No comment, which is fine. The logic below shows you how they're used and they're named well.
          var str = document.myForm.EMail.value; // get val of email, load into var called Str
          var len=str.length; // get the length of the email string
          var atcount=0; // initialize a counter. In the code on line 76, this correlates to the @ char
          var atpos; // declares a var to store the position of the @ char, see line 75
          var flag=1; // a bool-like flag to check for syntax. in CS and js, 0 = false, 1 = true... I think I would have set this to 0 but it starts counterintuitively assuming an invalid state, incorrectly using 1 as false
          
          for(i=0; i<len; i++){ // as long as i is less than var len, increase i. He is looping through the email str here 
              if(str[i]=='@'){ // if the email str has @ as a char...
                  atpos=i; // store the position
                  atcount++; // increment the counter
              }
              if(str[i]==' '){ // checks if the email str has a space, then uses the same logic as ln 56 - 58
                  alert("Email address doesn't contain space!");
                  document.myForm.EMail.focus(); 
                  return false;
              }
          }
          // Here he probably should have commented only bc it has a few OR statements, but it basically checks the email has x1 @ char, and the decimals are in the right spot.
          // the code reads fine though so a comment is stylistic; I was able to read np
          if(atcount!=1 || str[len-1]=='.'|| str[len-2]=='.' || str[atpos+1]=="."){ // if @ char count != 1 OR the len(); of str input -1 has a . OR str position + 1 = decimal ... throw an error with same method again.
              alert("Invalid syntax!"); 
              document.myForm.EMail.focus();
              return false;
          }
          for(i=atpos; i<len; i++){ // loops to check position starting from the @ char
              if(str[i]=="."){ // check until and stop when the decimal is found
                  flag=0; // bool 0 false, this seems backwards to me
                  break; // breaks out of the loop
              }
          }
          if(flag){ // when the flag is set to 0 still, it means no decimal was found-- so it throws an error. I think I would reverse the flag here, set to 1, init at 0.
              alert("Invalid syntax!");
              document.myForm.EMail.focus();
              return false;
          }
          //End of email validation... I deleted the irrelevant code for my purposes since I'm not taking country, postal code, address etc.
          
          alert("Submission Successfull!"); // Alerts when successful check, but again, should use modal dialog + callback
      }
  </script>
  

The learning map
=================
.. for each learning outcome for the unit, explain how you have met it, with reference to the content that you produce (typically your code or other design artifacts).

Find the rubric here and grade my work here:


Expected outcomes for Unit 4
-----------------------------
1. Critique JavaScript code written by others, identifying examples of both good and bad practice.

2. Use JavaScript to add dynamic content to pages.

3. Modify existing JavaScript code to extend and alter its functionality and, where appropriate, to correct errors and cases of poor practice


What went right and wrong
==========================
.. describe what you would do differently if you had to do it again.

If I were to do this unit again, I might go back to Unit 1 and have proposed better mockups that suit javascript snippets. I designed my website holistically and did not know we would be introducing small modules in unit 4, so I feel I struggled a bit to pick something small and simple that was already done on the web. 

Most of my designs and plans seem to be larger and more complex, so this worked against me.



Additional reading
===================

+ :download:`COMP 266 - Unit 4 orientation notes <./attachments/readings/unit4Reading.pdf>`
+ `Learning diary <https://github.com/hectorbarquero/university-COMP266>`_
+ `Project website <https://github.com/hectorbarquero/portfolio>`_
+ :ref:`Unit 0 learning diary <unit0-ref>`
+ :ref:`Unit 1 learning diary <unit1-ref>`
+ :ref:`Unit 2 learning diary <unit2-ref>`
+ :ref:`Unit 3 learning diary <unit3-ref>`

Get in touch
=============

I don't check my emails often. Connect with me on `LinkedIn <https://www.linkedin.com/in/hectorbarquero>`_, or see what I'm up to on `GitHub <https://github.com/hectorbarquero>`_.

