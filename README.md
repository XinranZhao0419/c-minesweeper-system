# Text-Based MineSweeper in C 💣

This project implements a fully interactive text-based MineSweeper system using the C programming language. The program runs entirely in a terminal environment and allows users to explore a hidden grid, infer mine distribution from partial observations, and progressively reconstruct the underlying state of the system.

The implementation focuses on structured state representation, recursive spatial expansion, and interactive decision-making within a discrete grid environment.

## 🖥️ Execution Environment

This program is designed to run in a standard terminal with a C compiler.

### Operating Systems

The program has been designed to run on:

- Linux (Ubuntu, Debian, etc.)
- macOS
- Windows (using MinGW, WSL, or any GCC-compatible terminal)

### Compiler Requirements

The following compilers are supported:

- GCC (recommended)
- Clang

### C Standard

- C11 or later

### Compilation

Use the following command:

```bash
gcc -std=c11 -O2 -Wall -Wextra -o mine_clearance mine_clearance.c
```

### Execution

```bash
./mine_clearance
```

No external libraries or dependencies are required.

The program runs entirely within the terminal.

## 🎯 What This Program Does

This program implements a complete MineSweeper system with interactive gameplay.

### Grid-Based Hidden State System

The program generates a two-dimensional grid containing hidden mines.

Each grid cell has an internal state and a visible state.

The user interacts with the grid by selecting cells to reveal or flag.

### Cell Reveal Mechanism

When a cell is revealed, the program performs the following logic:

- If the cell contains a mine, the game ends immediately.

- If the cell does not contain a mine, the program displays the number of mines in the surrounding 8 neighboring cells.

- If the cell has zero neighboring mines, the program automatically expands and reveals adjacent cells.

This process continues until all connected safe cells are revealed.

### Flagging Mechanism

The program allows users to place flags on cells suspected to contain mines.

Flags can also be removed.

This enables the user to track inferred mine locations.

### Automatic Game State Detection

The program automatically determines:

- Loss condition: when a mine is revealed

- Win condition: when all safe cells have been revealed

The program terminates accordingly.

## ✨ Project Highlights

### Recursive Region Expansion (Flood Fill)

One of the most important features is the automatic expansion of safe regions.

When a zero-adjacent-mine cell is revealed, the system recursively reveals neighboring cells.

This behavior mimics real MineSweeper systems and demonstrates region propagation algorithms commonly used in grid analysis and spatial computing.

### Structured Internal State Representation

The system maintains independent internal data structures for:

- Mine distribution

- Visible grid state

- Neighbor mine counts

This separation improves correctness, clarity, and maintainability.

### Clear and Deterministic Terminal Visualization

The grid is rendered in a structured text format.

Rows and columns are labeled to ensure precise interaction.

This improves usability and debugging clarity.

### Lightweight and Portable Design

The program:

- Requires no graphical interface

- Uses no external libraries

- Runs entirely in terminal

- Has minimal memory requirements

It can run on virtually any system with a C compiler.

### Modular and Maintainable Implementation

The code is designed with:

- Clear functional decomposition

- Logical state transitions

- Readable structure

This makes the system easy to extend and maintain.

## 🧩 Conceptual Perspective

This system represents a partially observable grid environment.

The user interacts with incomplete information and gradually reconstructs hidden system states.

This model reflects core concepts used in:

- Spatial inference systems

- Autonomous exploration

- Grid-based state reconstruction

- Interactive decision systems

## 🚀 Summary

This project provides a complete and portable implementation of a MineSweeper system in C.

It demonstrates:

- Interactive terminal-based operation

- Recursive spatial expansion

- Structured state management

- Cross-platform compatibility

The system provides a clean and efficient implementation of a classical grid-based hidden state exploration problem.
