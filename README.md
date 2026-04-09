# 42 C++ Modules (00–09)

## Overview

This repository contains my implementation of the **42 School C++ Modules** curriculum, from **Module 00** to **Module 09**.
The C++ Modules track is designed to progressively build strong foundations in modern object-oriented and generic programming concepts using C++ (typically within C++98 constraints defined by the subject).

Each module is split into exercises (`ex00`, `ex01`, etc.), and each exercise is an independent mini-project with its own source files and `Makefile`.

## What the C++ Modules Are

The 42 C++ Modules are a step-by-step learning path that introduces and reinforces:

- C++ syntax and idioms
- Object-oriented programming (encapsulation, inheritance, polymorphism)
- Canonical class form and operator overloading
- Memory management and resource ownership
- Exception handling and robust error control
- Templates and generic programming
- Standard Template Library (STL) usage
- Data processing and algorithmic problem solving

The curriculum emphasizes writing clear, maintainable, and standards-compliant C++ code through practical exercises.

## Repository Structure

- `cppModule-00/`
- `cppModule-01/`
- `cppModule-02/`
- `cppModule-03/`
- `cppModule-04/`
- `cppModule-05/`
- `cppModule-06/`
- `cppModule-07/`
- `cppModule-08/`
- `cppModule-09/`

Inside each module:

- one folder per exercise (`ex00`, `ex01`, ...)
- a dedicated `Makefile` per exercise
- source/header files required by that specific subject

## Build and Run

From the root, navigate to the target exercise folder and run:

```bash
cd cppModule-XX/exYY
make
./<executable_name>
```

If available in the exercise Makefile, cleanup targets usually follow:

```bash
make clean
make fclean
make re
```

## Development Standards

This repository follows the 42 project expectations:

- strict compilation flags (commonly `-Wall -Wextra -Werror`)
- no unnecessary dependencies
- clear separation between headers and implementation files
- behavior matching each module subject's required output

## Learning Goal

The main goal of this repository is to document a full progression through C++ fundamentals to more advanced concepts, with each module building directly on the previous one.

---

If needed, module-specific details are documented in each module's local `README.md`.
