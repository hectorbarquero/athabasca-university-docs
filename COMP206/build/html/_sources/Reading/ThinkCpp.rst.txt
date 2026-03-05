Think C++
+++++++++
I wrapped up this book in December 2025. It was an easy read, but I took down some of the most interesting "refresher" type notes. It's probably useful if you understand another language.

+--------------+-----+
| Total pages  | 191 |
+--------------+-----+
| Currently on | 191 |
+--------------+-----+


Chapter synopsis and notes
===========================

The way of the program
~~~~~~~~~~~~~~~~~~~~~~
This chapter introduces what programming is and how C++ fits as a formal, compiled language. It defines programs as precise instructions, explains why errors are unavoidable, and frames debugging as a systematic, experimental activity. It contrasts formal and natural languages to set expectations about precision and walks through a minimal first program to establish structure.

+ Programming demands precision; computers do exactly what is written.
+ Debugging is a core activity, not a failure state.
+ Compile-time, run-time, and logic errors are fundamentally different.
+ Effective debugging is experimental and methodical.
+ Formal languages eliminate ambiguity.

Variables and types
~~~~~~~~~~~~~~~~~~~
This chapter explains how programs store and manipulate data. It covers values, variables, assignment, output, keywords, operators, and precedence rules, including how characters are treated numerically. The core idea is building complexity by composing simple expressions under strict rules.

+ Assignment changes state; it is not mathematical equality.
+ Types constrain behavior and catch errors early.
+ Operator precedence can silently change results.
+ Characters are numeric under the hood.
+ Expression composition is foundational.

Function
~~~~~~~~
This chapter introduces functions as the primary tool for decomposition. It covers floating-point behavior, type conversion, math functions, defining and using functions, parameters, locality, and returning results to control data flow in multi-function programs.

+ Functions manage complexity more than they save typing.
+ Floating-point arithmetic is approximate.
+ Parameters and local variables are scope-limited.
+ Returning values is the main data flow mechanism.
+ Programs are built from many small functions.

Conditionals and recursion
~~~~~~~~~~~~~~~~~~~~~~~~~~
This chapter focuses on control flow through conditionals and recursion. It explains selective execution, chaining and nesting, the role of `return`, and how recursion works via the call stack, including common failure modes.

+ Control flow determines execution paths.
+ `return` exits a function immediately.
+ Recursion depends on correct base cases.
+ Infinite recursion usually means a missing stop condition.
+ Stack diagrams clarify recursive execution.

Fruitful functions
~~~~~~~~~~~~~~~~~~
This chapter deepens the use of functions that return values. It emphasizes incremental development, composition, overloading, boolean logic, and more advanced recursion patterns that rely on trusting correct function design.

+ Functions with return values are easier to test and reuse.
+ Boolean logic underpins decision-making.
+ Overloading can reduce clarity if misused.
+ Correct recursion relies on trusting contracts.
+ Programs evolve incrementally.

Iteration
~~~~~~~~~
This chapter introduces repetition with loops. It covers multiple assignment, `while` and `for` loops, common looping patterns, nested iteration, and how encapsulation and generalization turn repeated logic into reusable functions.

+ Loops express controlled repetition.
+ `while` expresses logic; `for` expresses counting.
+ Nested loops increase complexity quickly.
+ Encapsulation turns patterns into tools.
+ Generalization extends solutions beyond examples.

Strings and things
~~~~~~~~~~~~~~~~~~
This chapter treats strings as containers of characters. It covers storage, indexing, length, traversal, searching, counting, concatenation, mutability, comparison, and character classification, emphasizing safe and repeatable patterns.

+ Strings must be traversed carefully.
+ Indexing errors are common bugs.
+ Searching and counting follow standard patterns.
+ Strings are mutable in C++.
+ Character utilities avoid hard-coded logic.

Structures
~~~~~~~~~~
This chapter introduces `struct` for grouping related data. It explains defining structures, accessing fields, passing them to functions, call-by-value vs call-by-reference, returning structures, and basic input handling.

+ Structures model related data.
+ Passing by reference enables efficiency and mutation.
+ Returning structures is safe and common.
+ Value vs reference affects behavior.
+ Input handling requires defensive coding.

More structures
~~~~~~~~~~~~~~~
This chapter refines structured programming by focusing on design choices. It introduces pure functions, `const` correctness, modifiers, incremental development, and thinking in terms of reusable algorithms.

+ Pure functions simplify reasoning.
+ `const` communicates intent and safety.
+ Modifiers change state; pure functions do not.
+ Incremental development reduces risk.
+ Algorithms are reusable problem-solving ideas.

Vectors
~~~~~~~
This chapter introduces vectors as dynamic sequences. It covers access, copying, iteration, size management, randomness, statistics, counting, histograms, and efficient single-pass algorithms.

+ Vectors manage dynamic storage safely.
+ Size must always be queried, never assumed.
+ Single-pass algorithms are usually preferable.
+ Randomness requires explicit seeding.
+ Histograms reveal data distribution.

Member functions
~~~~~~~~~~~~~~~~
This chapter moves behavior closer to data by introducing member functions. It explains implicit access to instance variables, constructors, header files, and separating interface from implementation.

+ Behavior belongs with the data it operates on.
+ Member functions implicitly know their object.
+ Constructors enforce valid initial state.
+ Header files define interfaces.
+ Structure matters as programs grow.

Vectors of Objects
~~~~~~~~~~~~~~~~~~
This chapter combines vectors with user-defined types. Using cards and decks, it introduces comparison, searching, sub-collections, and bisection search for efficiency.

+ Collections of objects need comparison logic.
+ Equality and ordering must be explicit.
+ Search efficiency depends on organization.
+ Sorted data enables faster algorithms.
+ Decomposition applies to data structures.

Objects of Vectors
~~~~~~~~~~~~~~~~~~
This chapter focuses on objects that contain vectors. It introduces enums, `switch`, shuffling, sorting, dealing, and mergesort, emphasizing composition and algorithmic thinking.

+ Composition scales better than flat designs.
+ Enumerations clarify state.
+ Sorting and shuffling expose tradeoffs.
+ Mergesort shows divide-and-conquer.
+ Algorithms depend on structure, not content.

Classes and invariants
~~~~~~~~~~~~~~~~~~~~~~
This chapter formalizes classes as a safer evolution of structures. It covers private data, accessors, invariants, preconditions, and encapsulation, using complex numbers as an example.

+ Classes protect correctness.
+ Private data enforces invariants.
+ Accessors expose intent safely.
+ Preconditions document assumptions.
+ Invariants define valid states.

File Input/Output and apmatrixes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This chapter introduces streams and file I/O. It covers parsing text and numbers, simple data structures, matrices, and validating structured data from external sources.

+ Files introduce persistence and failure modes.
+ Parsing must be defensive.
+ Data structures often mirror file layout.
+ Matrices formalize 2D data.
+ Correctness outweighs performance in I/O.

Appendix: AP class reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Provides reference material for `apstring`, `apvector`, and `apmatrix`, used throughout the book to simplify learning.

+ AP classes simplify learning.
+ They abstract away STL complexity.
+ Used consistently throughout the book.