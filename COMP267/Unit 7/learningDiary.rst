.. Currently working

Using external data sources
+++++++++++++++++++++++++++++

.. danger::
   Currently working this final unit. Nothing to see here. Check back soon.

.. _unit7-ref:
.. SWITCH THE LINK HERE
.. Tip::
   Download my Unit 7 source by following this link ``PENDING``. Unpack the .zip and view the README.txt to learn more about the file structure. `You can also check out my project on GitHub <https://github.com/hectorbarquero/technicalwriting_sandbox>`_


Summary
========

   *"There were warnings for this unit about needing a server for the API, but I found that it wasn't required for the API functionality, but instead, I needed a server to hide the API token itself with a server function. For best practice, you should not expose your token. I remedied this issue by creating a server function which hides the token in a proxy, and exposes only the data retrieved by the back-end.*"


The work
==========

1. Visit `AU course book <https://scis.lms.athabascau.ca/mod/book/view.php?id=13071>`_ > **print book** as .pdf for offline reading.

2. Read the 15 instruction pages.

    .. Note::
       The Unit 7 reading markup is provided as an attachment under **References**.

3. Write a proposal explaining what API integration you'd like to do, and submit it to the AU portal.

4. Code it.
   
5. Upload the docs to GitHub and submit a learning diary post as a blog entry in the **Group Blog**.



Assignment 7 submission
========================
.. WORKING

API implementations
--------------------

Tech news API -> NewsAPI.org
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Done - this was tricky because it doesn't use a public API, it requires a private key, and that I don't want to have it revoked if stolen and misused. I ended up needing to create a proxy server, and then a back-end serverless function to hide my key in an environment variable. 

This was complicated, and the most timely component to this unit since I had to watch headers and understand the requests and responses to debug why my CORS was being denied.

It's done, and I'll upload design docs momentarily-- my live build works, and I'm okay with the end result (though it could use more refining; this might extend beyond the scope of this course as I continue my studies after this course ends)


Github Repositories API -> Github REST API
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Once I figured out the first API implementation, I used this API and found it much easier. It uses a public key, so there was no need to abstract the key into an environment variable like GITHUB_API_KEY. I am happy with the outcome because I went further into the MDN docs to learn how to use existing .css in the javascript, so that the output seems to populate my tools index.html page automatically while appearing to be the same aesthetic.

Once I figured out the first implementation, this was much simpler and saved me a lot of time instead of needing to populate a table by myself. Now the API takes care of it for me, and all I need to do is take care of my GitHub repo's and projects.


Expected outcomes for Unit 7
-----------------------------
When you have completed this unit, you should be able to use JavaScript to access and use web services for dynamic content (AJAX, JSON, etc.).


What went right and wrong
==========================

This unit was quoted to be an approximate 10 hours. With good documentation, using webhooks, APIs, and libraries seems to take much less time... the bulk of these allocated hours went to having to configure and build a server.

There are warnings in the unit package stating that a server *may* be required for this unit, but it wasn't required to run the API itself.

Instead, I found myself needing to use a server to deploy a server function in order to hide my API token.

For best practice, you should not expose your API token. It's considered bad practice, and can be damaging in sensitive operations. For this program, fortunately it would mean rate limit abuse and API key revocation in the worst circumstance, but I see no value in lazily completing this unit without taking an attempt of hiding my API token.

I'm also worried that if I don't secure the API token with a server function, then it may be revoked without my knowing, and the site will suddenly break.

I remedied this issue by creating a server function which hides the token in a proxy server, and is never exposed to the client. The client only sees the data retrieved by the back-end. The trade-off is a slightly slower latency in computing time, since the order of magnitude increases slightly.

Once I had figured out how to accomplish this once, it was easy to repeat the solution for the other API implentations. I only needed to reference the documentation to know which webhooks were available for me.



Additional reading
===================

+ :download:`COMP 266 - Unit 7 orientation notes <../attachments/readings/unit6Reading.pdf>`
+ `Learning diary <https://github.com/hectorbarquero/university-COMP266>`_
+ `Project website <https://github.com/hectorbarquero/portfolio>`_
+ :ref:`Unit 0 learning diary <unit0-ref>`
+ :ref:`Unit 1 learning diary <unit1-ref>`
+ :ref:`Unit 2 learning diary <unit2-ref>`
+ :ref:`Unit 3 learning diary <unit3-ref>`
+ :ref:`Unit 4 learning diary <unit4-ref>`
+ :ref:`Unit 5 learning diary <unit5-ref>`
+ :ref:`Unit 6 learning diary <unit6-ref>`


Get in touch
=============

I don't check my emails often. Connect with me on `LinkedIn <https://www.linkedin.com/in/hectorbarquero>`_, or see what I'm up to on `GitHub <https://github.com/hectorbarquero>`_.