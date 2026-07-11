Rooks guide to C++
++++++++++++++++++++
I took a short break as work got busy and returned to finish this book in March 2026.

This book was shorter, but somehow felt a bit longer. I think because I read Think C++ first, then this one didn't feel as enjoyable as it had repeat content. I should have read them side by side, but instead went one before the other. 

The content in the later half of this book was more enjoyable than the content in the first half, especially the arithmetic and dynamic data. 


+--------------+-----+
| Total pages  | 160 |
+--------------+-----+
| Currently on | 160 |
+--------------+-----+


Chapter synopsis and notes
============================

History
~~~~~~~~
Sets context for why C++ exists and what problems it was built to solve, plus the rough evolution from C to “C with classes” to modern C++. The point is to understand the tradeoffs C++ keeps: performance, control over memory, and a large language surface area.

+ C++ keeps low-level control and high-level abstraction in the same language.
+ A lot of “weirdness” is historical baggage, not design elegance.
+ You’ll see multiple ways to do the same thing because the language evolved over decades.
  

Variables
~~~~~~~~~~
Introduces naming values so programs can keep state. Focus is on declaration, initialization, scope basics, and how the compiler uses types to reason about what operations are allowed.

+ Prefer initializing at declaration to avoid garbage state.
+ Name things for meaning, not for the type.
+ Most beginner bugs are “wrong variable, wrong scope, wrong value”.
  

Literals and constants
~~~~~~~~~~~~~~~~~~~~~~~
Covers literal values (numbers, chars, strings) and making values non-changeable using constants. The goal is to reduce accidental mutation and encode assumptions in code.

+ Constants make intent explicit and prevent accidental reassignment.
+ Literal types matter (e.g., integer vs floating literal) because conversions can change results.
+ Use constants to replace “magic numbers”.
  

Assignments
~~~~~~~~~~~~
Explains how variables get new values using assignment, and how assignment differs from equality. Also covers compound assignment and common assignment patterns.

+ Assignment mutates state; equality compares state.
+ Compound assignments (`+=`, `-=`, etc.) are shorthand but still mutation.
+ Watch for accidental assignment in conditions in languages that allow it.
  

Output
~~~~~~~
Introduces writing to the console and basic formatting. Emphasis is on building confidence by observing program state and results.

+ Output is a debugging tool, not just user-facing UI.
+ Formatting matters when humans must read the results.
+ Separate “compute” from “print” when code starts to grow.
  

Input
~~~~~
Introduces reading from the user and dealing with the messiness of real input. Focus is on parsing, validation, and handling failure states.

+ Input is adversarial by default; validate.
+ Distinguish between reading tokens vs full lines.
+ Always handle stream failure and leftover newline issues.
  

Arithmetic
~~~~~~~~~~~
Covers numeric operators and the difference between integer arithmetic and floating-point arithmetic. Includes precedence and common pitfalls (division, truncation).

+ Integer division truncates; this is a frequent bug source.
+ Modulus is for integers and is useful for digit extraction and periodic behavior.
+ Overflow exists; don’t assume “big enough”.
  

Comments
~~~~~~~~~
Explains using comments to communicate intent, constraints, and non-obvious decisions. The goal is maintainability, not narrating every line.

+ Comment “why”, not “what”.
+ Outdated comments are worse than no comments.
+ Prefer expressive code; comments are a supplement.


Data types and conversion
~~~~~~~~~~~~~~~~~~~~~~~~~~
Covers built-in types, signedness, ranges, and converting between types. Emphasis is on loss of information, implicit conversions, and when to be explicit.

+ Conversions can be narrowing (lose data) without being obvious.
+ Signed/unsigned mixing creates surprising comparisons.
+ Be explicit when precision or range matters.


Conditionals
~~~~~~~~~~~~~
Introduces branching (`if`, `else if`, `else`) and boolean logic. Focus is on writing correct conditions and avoiding deeply nested logic.

+ Most bugs are wrong conditions, not wrong bodies.
+ Prefer clear boolean expressions over cleverness.
+ Short-circuit logic matters for safety (guard checks).


Strings
~~~~~~~~
Covers strings as sequences of characters and common operations (length, indexing, concatenation, comparison). Emphasis is on boundary safety and input interaction.

+ Indexing is where most string bugs live (off-by-one, bounds).
+ Choose token input vs line input deliberately.
+ Comparing strings is semantic; comparing pointers is not.


Loops
~~~~~~
Introduces repetition (`while`, `do-while`, `for`) and loop control. Focus is on invariants, termination conditions, and common iteration patterns.

+ Always know what makes the loop stop.
+ Off-by-one errors are the default failure mode.
+ Prefer `for` when counting and `while` when condition-driven.


Arrays
~~~~~~~
Introduces fixed-size contiguous storage and indexing. Emphasis is on bounds, lifetime, and why arrays are error-prone compared to safer containers.

+ Arrays don’t track their own size.
+ Bounds violations can silently corrupt memory.
+ Use safer containers when available, but understand arrays for fundamentals.


Blocks, functions, and scope
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Explains `{}` blocks, variable lifetime, function decomposition, parameters, return values, and scope rules. Focus is on controlling visibility and reducing complexity.

+ Scope is a tool to prevent misuse, not a nuisance.
+ Functions should do one job and have clear inputs/outputs.
+ Returning values beats global mutation for testability.


Problem solving & troubleshooting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Gives a workflow for breaking problems down and debugging systematically: reproduce, isolate, test assumptions, and verify fixes. Focus is on process over guessing.

+ Reduce the problem until it’s obvious.
+ Add observability (prints, assertions) to test hypotheses.
+ Fix the cause, not the symptom.


The preprocessor
~~~~~~~~~~~~~~~~
Introduces `#include`, `#define`, and conditional compilation. Emphasis is on understanding that preprocessing happens before compilation and can create hard-to-debug behavior.

+ Macros are text substitution, not typed functions.
+ Prefer constants and inline functions over macros when possible.
+ Header inclusion order and guards matter.

Advanced arithmetic
~~~~~~~~~~~~~~~~~~~~
Expands into topics like numeric limits, precision, rounding, overflow behavior, and bitwise operations. The goal is to reason about correctness when numbers get tricky.

+ Floating-point equality is usually wrong; compare with tolerance when needed.
+ Bitwise ops are common in systems-level tasks, but easy to misuse.
+ Know the numeric limits of your types.


File I/O
~~~~~~~~~
Introduces reading and writing files, stream state, and parsing structured text. Emphasis is on error handling and data validation.

+ Always handle “file didn’t open” and partial reads.
+ Parsing needs a plan: format assumptions, separators, failure modes.
+ Keep I/O separate from computation for cleaner code.


Pointers
~~~~~~~~~
Introduces addresses, dereferencing, and pointer semantics. Focus is on when indirection is needed, and how misuse leads to crashes or corruption.

+ Uninitialized and dangling pointers are catastrophic.
+ Pointer arithmetic is powerful and dangerous.
+ Prefer references and safer abstractions unless pointers are required.


Dynamic data
~~~~~~~~~~~~~~
Covers allocating data at runtime and managing lifetime. Emphasis is on ownership, leaks, and avoiding manual memory management where possible.

+ Leaks happen when ownership isn’t clear.
+ Double-free and use-after-free are common failure modes.
+ Prefer RAII-style ownership patterns rather than raw `new`/`delete`.


Classes and abstraction
~~~~~~~~~~~~~~~~~~~~~~~~~
Introduces building types that combine data and behavior with encapsulation. Focus is on invariants, interfaces, constructors, and keeping representations private.

+ A class should protect its invariants by construction.
+ Public API should be minimal and coherent.
+ Encapsulation is about controlling mutation and coupling.


Separate compilation
~~~~~~~~~~~~~~~~~~~~~
Explains splitting programs into multiple files, headers vs source, declarations vs definitions, and linking. Focus is on build structure and avoiding multiple-definition errors.

+ Headers declare; source files define.
+ Include guards (or equivalents) prevent redefinition.
+ Linker errors are usually “declared but not defined” or “defined twice”.

STL
~~~
Introduces standard library containers, algorithms, and iterators as the idiomatic way to write safer and more expressive C++. Focus is on choosing the right container and leveraging algorithms.

+ Prefer `std::vector`, `std::string`, and standard algorithms by default.
+ Algorithms reduce bugs compared to hand-rolled loops.
+ Iterators unify containers but can be confusing without practice.