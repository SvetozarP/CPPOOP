# C++ OOP — SoftUni Solutions

This repository contains my solutions to the exercises and assignments from the **SoftUni C++ OOP** course.

## Solutions

| Topic | Task | Description |
|-------|------|-------------|
| **01 Objects and Classes** | [01 Letters](01ObjectsAndClasses/01letters/) | Reads a line of text, stores unique words (punctuation stripped), then for each character you enter prints all words containing that letter (case-insensitive). Enter `.` to exit. Uses a `Letters` class with a `set` of words and `getAllWords(char)`. |
| **01 Objects and Classes** | [02 Rust](01ObjectsAndClasses/02rust/) | 10×10 grid simulation: reads a grid of rust (`!`), alpaka (`#`), and empty (`.`) cells, then runs N ticks where rust spreads to adjacent empty cells (alpaka blocks spread). Uses a `Rust` class with an inner `Tile` class and `RustState` enum; `doRust()` applies one tick, then the final grid is printed. |
| **01 Objects and Classes** | [03 Matching Locations](01ObjectsAndClasses/03matchingLocations/) | Reads location data as `name,lat,long` lines until `.`; then for each query either coordinates (`lat long`) or a name, prints matching entries as `name,lat,long`. Uses `GeoLoc` for coordinates and `LocationsData` with parallel vectors; supports lookup by coords or by name. |

Solutions are organized by topic; each is written in C++ and uses OOP concepts (classes, encapsulation, STL containers, etc.).

## Requirements

- A C++ compiler with C++11 or later (e.g. GCC, Clang, MSVC)
- Optionally: CMake or your IDE’s build system

## Building and Running

- Use your preferred IDE (Visual Studio, CLion, VS Code, etc.) or the command line to compile and run the source files.
- Example with `g++`:
  ```bash
  g++ -std=c++17 -o program main.cpp
  ./program
  ```

## Course

Part of the [SoftUni](https://softuni.bg/) programming curriculum — **C++ OOP** module.
