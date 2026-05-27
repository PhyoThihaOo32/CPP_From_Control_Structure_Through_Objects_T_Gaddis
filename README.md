# C++: From Control Structures through Objects (Tony Gaddis)

This repository is a large C++ learning workspace built around **Tony Gaddis, _C++: From Control Structures through Objects_**.  
It contains chapter-by-chapter practice code, programming challenges, and supplemental coursework folders.

## Project Overview

- Primary purpose: practice and reference implementations while learning core C++ topics.
- Code style: many small single-file programs focused on one concept at a time.
- Coverage: fundamentals through OOP, STL, pointers, files, recursion, and linked lists.

## Repository Structure

The main learning content is organized by chapter folders:

- `Chapter2_Introduction_to_C++`
- `Chapter3_Expression_And_Interactivity`
- `Chapter4_Relational_Operation`
- `Chapter5_II_Files`
- `Chapter5_Loops_And_Files`
- `Chapter6_Functions`
- `Chapter7_Arrays`
- `Chapter7_STL_Vectors`
- `Chapter8_Searching_And_Sorting_Arrays`
- `Chapter9_Pointers`
- `Chapter10_Characters, C_Strings, and More About the string Class`
- `Chapter11_Structured_Data`
- `Chapter12_Advanced_File_Operation`
- `Chapter13_Introduction_to_Classes`
- `Chapter14_More_About_Classes`
- `Chapter15_Inheritance_Polymorphism_And_Visual_Functions`
- `Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)`
- `Chapter17_Linked_Lists`
- `Chapter19_Recursion`

Additional learning banks:

- `Programming Challenges`
- `CSC111_ProfYan`
- `CSC211H_Prof_Azhar`

## Chapter and Folder Metrics

Current high-level counts (source/header/executable files):

| Folder | `.cpp` | `.h/.hpp` | Executables |
|---|---:|---:|---:|
| Chapter2_Introduction_to_C++ | 3 | 0 | 3 |
| Chapter3_Expression_And_Interactivity | 13 | 0 | 13 |
| Chapter4_Relational_Operation | 22 | 0 | 21 |
| Chapter5_II_Files | 6 | 0 | 6 |
| Chapter5_Loops_And_Files | 16 | 0 | 16 |
| Chapter6_Functions | 16 | 0 | 16 |
| Chapter7_Arrays | 26 | 0 | 25 |
| Chapter7_STL_Vectors | 9 | 0 | 7 |
| Chapter8_Searching_And_Sorting_Arrays | 9 | 0 | 8 |
| Chapter9_Pointers | 22 | 0 | 22 |
| Chapter10_Characters, C_Strings, and More About the string Class | 14 | 0 | 13 |
| Chapter11_Structured_Data | 7 | 0 | 7 |
| Chapter12_Advanced_File_Operation | 21 | 0 | 17 |
| Chapter13_Introduction_to_Classes | 14 | 6 | 12 |
| Chapter14_More_About_Classes | 20 | 13 | 12 |
| Chapter15_Inheritance_Polymorphism_And_Visual_Functions | 34 | 26 | 22 |
| Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL) | 19 | 5 | 17 |
| Chapter17_Linked_Lists | 3 | 1 | 2 |
| Chapter19_Recursion | 6 | 0 | 4 |
| Programming Challenges | 43 | 4 | 36 |
| CSC111_ProfYan | 78 | 2 | 68 |
| CSC211H_Prof_Azhar | 109 | 30 | 56 |

## How to Compile and Run

Compile a single program from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Chapter3_Expression_And_Interactivity/program3_1_cin_object.cpp -o program3_1
./program3_1
```

If a file uses multiple headers/sources in the same folder, compile them together.

## Learning Path Suggestion

Recommended progression:

1. Chapter 2 to Chapter 4 (core syntax, variables, expressions, decisions)
2. Chapter 5 to Chapter 8 (loops, functions, arrays, searching/sorting)
3. Chapter 9 to Chapter 12 (pointers, strings, structured data, files)
4. Chapter 13 to Chapter 17 (classes, inheritance, templates/STL, linked lists)
5. Chapter 19 recursion and Programming Challenges for consolidation

## Repository Analysis and Improvement Plan

This repo is strong as a personal study archive, but a few improvements would make it much cleaner for GitHub:

- Track source files only; remove compiled executables from version control.
- Add a root `.gitignore` (for `*.o`, `*.out`, compiled binaries, `.DS_Store`, and `tempCodeRunnerFile.cpp`).
- Keep one consistent naming convention for folders/files.
- Add per-chapter mini README files with goals and key exercises.
- Separate course-assignment work (`CSC111_...`, `CSC211H_...`) from textbook chapter folders if you want a cleaner public portfolio.

## Notes

- This repository currently contains many compiled artifacts alongside source code.
- A few `tempCodeRunnerFile.cpp` files exist and can be safely removed/ignored.

