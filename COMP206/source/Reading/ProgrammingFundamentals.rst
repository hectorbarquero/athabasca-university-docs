Programming fundamentals
++++++++++++++++++++++++
Supplementary reading, I took my time reviewing the entirety of the book with extra focus to the chapters called out during the reading curriculum for COMP206.

+--------------+-----+
| Total pages  | 342 |
+--------------+-----+
| Currently on | 342 |
+--------------+-----+


Chapter synopsis and notes
==========================

Chapter 1: Introduction to programming
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces the systems development life cycle, basic C++ tooling, modularization, functions, and the normal layout of a C++ program. The chapter treats programming as a process of planning, coding, compiling, testing, and maintaining rather than only writing syntax.

+ A program should be divided into manageable modules instead of written as one large block.
+ ``main`` acts as the program control function and coordinates the program's execution.
+ Compiler and IDE details can change, but the edit-build-run-debug cycle stays the same.


Chapter 2: Program planning and design
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Explains how to understand a problem before coding it. It introduces design tools, pseudocode, test data, model checking, and code checking so that the planned solution can be verified before and after implementation.

+ Pseudocode describes program logic without depending on exact C++ syntax.
+ Test data should include normal, boundary, and invalid cases.
+ Design errors are cheaper to fix before they become code.


Chapter 3: Data and operators
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces C++ data types, identifier rules, constants, variables, assignment, arithmetic operators, and type conversion. The focus is on how values are represented, named, changed, and combined in expressions.

+ A variable has a type, identifier, storage location, and current value.
+ Assignment stores a value; it does not test equality.
+ Conversions can change precision or range, especially between floating-point and integer types.


Chapter 4: Often-used data types
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Expands on integer, floating-point, and string data, along with compound assignment, lvalues, rvalues, integer division, and modulus. It connects common types to the operators that can validly be used with them.

+ Integer division discards the fractional portion of the result.
+ Modulus returns the remainder and is useful for divisibility and digit extraction.
+ An lvalue identifies a storage location, while an rvalue represents a value used in an expression.


Chapter 5: Integrated development environment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Covers the role of an IDE, common compile and runtime errors, standard input and output, and compiler directives. The chapter shows how source code moves through preprocessing, compilation, linking, and execution.

+ ``cin`` and ``cout`` use stream extraction and insertion operators.
+ Compiler errors should be fixed from the first reported error downward.
+ Directives such as ``#include`` are handled before normal compilation.


Chapter 6: Program control functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces function-oriented program structure using pseudocode, hierarchy charts, control functions, ``void``, and source-code documentation. The goal is to make program flow visible and keep the top-level control logic simple.

+ A hierarchy chart shows which functions call other functions.
+ A ``void`` function performs work without returning a value.
+ Readable indentation, names, and function comments reduce maintenance cost.


Chapter 7: Specific task functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Explains how functions can be created to perform one focused task. It covers local and global storage, declarations, definitions, parameters, return values, and placing user-defined functions in header files.

+ Local variables limit accidental coupling between functions.
+ Global variables make data widely accessible but harder to reason about.
+ Function interfaces should clearly define what data enters and what result leaves.


Chapter 8: Standard libraries
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces C++ standard libraries and the reusable functions, types, and constants they provide. The chapter emphasizes using existing library facilities instead of rewriting common operations.

+ Header files expose declarations needed by the compiler.
+ Library documentation is part of normal programming work.
+ Reusing tested library code is usually safer than creating an equivalent from scratch.


Chapter 9: Character data, sizeof, typedef, and sequence
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Covers the ``char`` type, character codes, the ``sizeof`` operator, type aliases with ``typedef``, and the sequence or comma operator. These topics connect source-level syntax to storage size and expression evaluation.

+ A character is stored as a numeric code even when written as a quoted symbol.
+ ``sizeof`` reports how many bytes a type or object occupies.
+ ``typedef`` creates another name for an existing type; it does not create a distinct type.


Chapter 10: Introduction to structured programming
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces structured programming through sequence, selection, and iteration. It uses pseudocode and flowcharts to model control flow and replace unstructured jumps with predictable control structures.

+ Most program logic can be expressed using sequence, selection, and repetition.
+ Flowcharts visualize decisions, loops, input, output, and function calls.
+ Structured control flow is easier to test and trace than arbitrary jumps.


Chapter 11: Two-way selection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces ``if``, ``else``, Boolean values, relational operators, and compound statements. It focuses on choosing between two execution paths based on a true-or-false condition.

+ Relational operators produce Boolean results.
+ Braces group multiple statements into one compound statement.
+ Conditions should describe the decision clearly rather than rely on clever side effects.


Chapter 12: Multiway selection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Expands selection using nested ``if`` statements, logical operators, truth tables, and the ``switch`` structure. It also discusses branching statements and the limits of each selection method.

+ ``&&``, ``||``, and ``!`` combine or reverse Boolean conditions.
+ ``switch`` works best when comparing one expression against discrete constant choices.
+ Nested conditions should be ordered so the most specific or restrictive cases are handled correctly.


Chapter 13: Test-after loops
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces the ``do-while`` loop, flag-controlled repetition, assignment versus equality, and the pseudocode concept of repeat-until. A test-after loop always executes its body at least once.

+ Use ``do-while`` when the action must occur before the continuation test.
+ A flag is a Boolean or sentinel value used to control repetition.
+ ``=`` changes a value, while ``==`` compares two values.


Chapter 14: Test-before loops
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces prefix and postfix increment and decrement, the ``while`` loop, counting patterns, and infinite-loop risks. A test-before loop may execute zero times when its condition starts false.

+ The loop body must eventually change something used by the condition.
+ Prefix and postfix forms differ when their resulting value is used inside a larger expression.
+ ``while`` is appropriate when repetition is driven mainly by a condition rather than a fixed count.


Chapter 15: Counting loops
~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces ``for`` loops, integer wraparound, formatted output, and nested loops. It shows how initialization, testing, and updating can be placed together for count-controlled repetition.

+ ``for`` makes the counter lifecycle visible in one statement.
+ Integer types have finite ranges and can wrap when their limits are exceeded.
+ Nested loops are useful for tables, grids, combinations, and repeated row-column processing.


Chapter 16: String class and unary operators
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces the C++ ``string`` class and common operations such as assignment, comparison, concatenation, and length. It also distinguishes unary positive and unary negative from addition and subtraction.

+ ``string`` provides a safer abstraction than manually managing character arrays.
+ Unary negative changes the sign of the value produced by an expression, not the stored variable.
+ Unary positive usually has no practical effect.


Chapter 17: Conditional operator and recursion
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Covers the conditional ``?:`` operator and compares recursive solutions with iterative ones. It explains how recursion repeatedly calls the same function until a base condition ends the process.

+ The conditional operator produces one of two values from a Boolean condition.
+ Every recursive solution needs a reachable base case.
+ Iteration is often simpler and uses less call-stack space, while recursion can mirror naturally recursive problems.


Chapter 18: Introduction to arrays
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces arrays as fixed-size collections of same-type elements. It covers array declaration, indexing, initialization, and displaying members using loops.

+ Array indexing begins at zero.
+ Valid indexes run from zero through one less than the array size.
+ C++ built-in arrays do not automatically protect against out-of-bounds access.


Chapter 19: File I/O and array functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Combines file streams with arrays and functions. It covers opening files, loading array values, passing arrays to functions, and calculating statistics such as totals and averages.

+ Always verify that a file opened successfully before reading or writing.
+ Arrays passed to functions normally decay to pointers, so size information must be supplied separately.
+ Separate file handling from calculations to make both parts easier to test.


Chapter 20: More array functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Builds reusable array-processing functions for finding a specific value and sorting array members. The chapter introduces basic searching and sorting as common data-processing operations.

+ A linear search checks elements until the target is found or the array ends.
+ Sorting changes the arrangement of data and can make later searching or reporting easier.
+ Search and sort functions should clearly define how failure or duplicate values are handled.


Chapter 21: More on typedef
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Uses ``typedef`` to make array-processing code easier to modify for different data types. The chapter distinguishes flexible code, which adapts to array size, from versatile code, which adapts to different types.

+ A type alias can centralize a type choice used throughout a program.
+ ``sizeof`` can help calculate a built-in array's element count in the same scope.
+ Modern C++ generally uses ``using`` aliases instead of ``typedef`` for new code.


Chapter 22: Pointers
~~~~~~~~~~~~~~~~~~~~
Introduces memory addresses, the address operator, references, pointer variables, and the indirection operator. It connects pointers to parameter passing, arrays, and direct access to stored objects.

+ ``&value`` obtains an object's address, while ``*pointer`` accesses the pointed-to object.
+ Pass-by-reference lets a function modify the caller's original object.
+ Uninitialized, null, and dangling pointers must not be dereferenced.


Chapter 23: More arrays and compiler directives
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces multidimensional arrays and conditional compilation. It shows how arrays can represent rows and columns and how preprocessor conditions can include or exclude source code.

+ A two-dimensional array is commonly processed with nested loops.
+ Dimensions and index order must remain consistent across declarations and function parameters.
+ Conditional compilation is useful for platform differences and optional debugging code, but can make builds harder to reason about.


Chapter 24: OOP and high-performance computing
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Provides a transition from modular structured programming to object-oriented programming, where data and related functions are encapsulated together. It also introduces high-performance computing, parallel work, sequential limits, multiple processors, and FLOPS as a performance measure.

+ C++ supports both procedural and object-oriented program design.
+ Parallel processing helps only when a task can be divided into independent or coordinated parts.
+ More processors do not guarantee proportional speedup because some work remains sequential or requires coordination.


Chapter 25: Review materials
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Organizes the book's material into foundation, modular programming, structured programming, intermediate, and advanced topic groups. It is intended as a consolidated review before assignments or exams.

+ Review should connect concepts across chapters rather than memorize isolated syntax.
+ Weak fundamentals in data, expressions, functions, or control flow affect every later topic.
+ Rewriting small programs is more useful than only rereading completed examples.


Chapter 26: Appendix
~~~~~~~~~~~~~~~~~~~~
Provides reference material including operator precedence, reserved C++ keywords, the ASCII character set, file-extension settings, and academic-integrity guidance.

+ Parentheses are clearer than relying heavily on memorized precedence.
+ Reserved keywords cannot be used as identifiers.
+ File extensions should remain visible so source files and compiled files are not confused.