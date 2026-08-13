 Employee Management System Using Hash Tables

A C-based Employee Management System developed to demonstrate the practical application of Hash Tables, Linked Lists, Pointers, Structures, and Dynamic Memory Allocation for efficient employee data management.

 Project Overview

The Employee Management System provides an organized way to store and manage employee records such as Employee ID, Name, Designation, Experience, and Age.

The system uses a hash function to map each employee's unique ID to an index in the hash table. When multiple employee IDs generate the same index, collisions are handled using chaining with linked lists.

This approach provides fast employee record insertion, searching, deletion, and display operations.

  Features

-  Insert new employee records
-  Search employees using Employee ID
-  Delete employee records
-  Display all employee records
-  Collision handling using chaining
-  Menu-driven interface
-  Fast average-time operations

 Technologies & Concepts

- C Programming
- Hash Tables
- Hash Functions
- Linked Lists
- Structures
- Pointers
- Dynamic Memory Allocation
- GCC / C Compiler

 Hashing Technique

The project uses the following hash function:

```text
Index = Employee ID % Table Size
