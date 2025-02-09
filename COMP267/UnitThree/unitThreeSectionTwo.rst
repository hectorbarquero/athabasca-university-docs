.. I'm on page 214/388 right now <-- NOT STARTED
.. Challenge work required, page 386 question 21 <-- DONE, submitted feb 1 2025
.. assignment 3 is one exercise from chapter 6, 7, and 8
.. QUESTION KEY
.. chapter 6, question 13 page 329
.. chapter 7, question 10 page 385
.. chapter 8, question 9 page 418


Unit three, section two
++++++++++++++++++++++++


Computer networks
===================

Challenge work submission
===========================

1. Read chapter seven of the textbook.
2. Complete challenge work #21, on page 386 of the text.


.. note:: 
   Corresponds to challenge work #21, on page 386 of the text. The instructions may say a short profile, but the course Brightspace says 2-3 paragraphs is sufficient.

Radia Perlman, programmer and network engineer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Radia Perlman is a pivotal but often under-recognized figure in the field of computer networking. Known for her invention of the Spanning Tree Protocol (STP) which she had developed in the 1980s. Her work addressed the issue of network loops that would cause congestion and disruption in ethernet based networks. The STP protocol allows network bridges and switches to identify and eliminate redundant paths, ensuring data travels through the most efficient node structures without infinite loops. The protocol became a cornerstone for the development of ethernet networks, allowing scalable and reliable communication across large systems. Radia contributed to the modern networks ability to self-map.

At the current age of 73, Radia holds over 200 US patents and continues to be influential in the development of numerous other networking protocols, including IS-IS (Intermediate System to Intermediate System), a routing protocol used in large-scale networks like those run by ISPs.

While currently co-teaching at Texas A&M University, her continued research expands on network security and the ongoing challenges of securing global communication systems, covering topics like routing, security, and distributed systems. 

Despite being relatively lesser-known outside of networking circles, her work has been crucial to the functioning of modern internet.



Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.

Capitol Technology University. "Dr. Radia Perlman: One of the First Female Programmers and Inventor of the Internet's Protocols." Capitol Technology University, 1 Feb. 2025, https://www.captechu.edu/blog/dr-radia-perlman-one-of-first-female-programmers-and-inventor-internets-protocols. Accessed 1 Feb. 2025.


Assignment 3 (chapter three, section two)
===========================================
.. this is technically part 2/3 for assignment 3. The third part is in the next chapter, unitThreeSectionThree.rst

*10. Agree or disagree with the following assertion and state why: In an Ethernet network, even though there are collisions, every message is guaranteed to be delivered in some maximum amount of time T.* (Chapter 7, page 385)

Disagree
~~~~~~~~~
In old ethernet networks that use carrier sense multiple access with collision detection (CSMA/CD), there is no guaranteed max time for message delivery due to the *exponential backoff mechanism* (Gupta & Walrand, 2007). After a collision, devices would wait for random intervals before re-transmitting, and these intervals grow exponentially with repeat collisions. When there is network congestion, delays become significant and unpredictable.

Ethernet is designed for efficiency but it doesn't promise deterministic packet delivery, although in the modern full-duplex networks, collision wouldn't occur-- but it would still be impossible to gaurantee a maximum delivery time due to unpredictable variables like network congestion, payload size, and hardware specifications. 


Works cited
~~~~~~~~~~~~
Schneider, G. Michael, and Judith Gersting. Invitation to Computer Science. 6th ed., Cengage Learning, 2013.

Gupta, R., and J. Walrand. "Impatient Backoff Algorithm: Fairness in a Distributed Ad-Hoc MAC." IEEE Xplore, IEEE, 2007, https://ieeexplore.ieee.org/document/4289259. Accessed 19 Jan. 2025.