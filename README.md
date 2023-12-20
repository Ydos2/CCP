# CCP

##Code Compiler for CCP Programming Language

Welcome to the Code Compiler for CCP! This project aims to provide a robust compiler that translates the CCP programming language into x86 assembly code, which can subsequently be converted into machine code for execution.

## Overview

A compiler is a crucial tool in the realm of computer science and software engineering. It takes source code written in one language (the source language) and converts it into another language (the target language). For this project, our primary target language is x86 assembly code.

## Project Goals

- Lexical Analysis (Scanning): Breaking down the source code into tokens.
- Syntax Analysis (Parsing): Verifying the syntactic structure of the program.
- Semantic Analysis and Type Checking: Ensuring that the program adheres to the language's semantics and rules.
- Code Generation: Translating the parsed code into x86 assembly instructions.

## Resources

For a comprehensive understanding of compilers and the methodologies adopted in this project, the following resources are recommended:

- Textbook: Engineering a Compiler (3rd edition) by Keith D. Cooper and Linda Torczon, Morgan Kaufmann. While this textbook provides a foundational understanding, it's essential to note that lecture notes complement the material extensively.

## Tools and Technologies

To accomplish the tasks outlined above, we utilize:

- Compiler-Generator Tools: Such as lex and yacc for the development of the compiler's front-end.
- Custom Data Structures: Including abstract syntax trees and symbol tables to facilitate semantic analysis.
- Assembly Code Generation: For producing x86 assembly instructions.

## Compilation and Execution

Once the compiler generates the x86 assembly code, you can use gcc (specifically, the gas assembler) to convert this code into its machine code representation, known as an object file. This object file can then be linked to create an executable program, which can be directly executed on a Linux machine without the need for any emulators.

Use the shell file "./try.sh" or "./compile.sh" to make things easier.

## Credit

This project is based on Professor Christopher Kruegel's "Translation of Programming Languages" course at the University of California Santa Barbara.
