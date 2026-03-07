# C++ OOP — SoftUni Solutions

This repository contains my solutions to the exercises and assignments from the **SoftUni C++ OOP** course.

## Solutions

| Topic | Task | Description |
|-------|------|-------------|
| **01 Objects and Classes** | [01 Letters](01ObjectsAndClasses/01letters/) | Reads a line of text, stores unique words (punctuation stripped), then for each character you enter prints all words containing that letter (case-insensitive). Enter `.` to exit. Uses a `Letters` class with a `set` of words and `getAllWords(char)`. |
| **01 Objects and Classes** | [02 Rust](01ObjectsAndClasses/02rust/) | 10×10 grid simulation: reads a grid of rust (`!`), alpaka (`#`), and empty (`.`) cells, then runs N ticks where rust spreads to adjacent empty cells (alpaka blocks spread). Uses a `Rust` class with an inner `Tile` class and `RustState` enum; `doRust()` applies one tick, then the final grid is printed. |
| **01 Objects and Classes** | [03 Matching Locations](01ObjectsAndClasses/03matchingLocations/) | Reads location data as `name,lat,long` lines until `.`; then for each query either coordinates (`lat long`) or a name, prints matching entries as `name,lat,long`. Uses `GeoLoc` for coordinates and `LocationsData` with parallel vectors; supports lookup by coords or by name. |
| **02 Objects and Classes (Ex)** | [01 Sentence Shifter](02ObjectsAndClassesEx/1sentenceShifter/) | Reads a line of words and a shift value; outputs the sentence with words rotated by that amount (e.g. shift 1: last word becomes first). Uses `WordShifter` with a `vector` and modulo-based indexing. |
| **02 Objects and Classes (Ex)** | [01.1 Sentence Shifter](02ObjectsAndClassesEx/01.1sentenceShifter/) | Same idea: sentence + shift count; returns shifted sequence. Uses `SentenceShifter` with a `deque`, shifting by repeatedly moving back to front. |
| **02 Objects and Classes (Ex)** | [02 Distance](02ObjectsAndClassesEx/02distance/) | Reads two 2D points (x, y); prints Euclidean distance between them. Uses a `Point` class with `calculateDistance(const Point&)`. |
| **02 Objects and Classes (Ex)** | [02.1 Distance](02ObjectsAndClassesEx/02.1distance/) | Same: two points from input, print distance. `Point` with `istream` constructor and `eucledianDistance(const Point&)`. |
| **02 Objects and Classes (Ex)** | [03 Sales](02ObjectsAndClassesEx/03sales/) | Reads N sales (town, product, price, quantity); aggregates total sales per town in a `map`; prints `town -> total`. Uses `Sale` class with `getTown()` and `getTotalPrice()`. |
| **02 Objects and Classes (Ex)** | [03.1 Sales](02ObjectsAndClassesEx/03.1sales/) | Same: sales from stream, report by town. Uses `Sale`, `Sales` (holds vector of sales), and `SalesReport` to build and return the formatted report string. |
| **02 Objects and Classes (Ex)** | [04 Total Average of Students](02ObjectsAndClassesEx/04totalAverageOfStudents/) | Reads N students (name, surname, average); prints each student line and then the class average. Uses `Student` and a free function `calculateTotalClassAverage`. |
| **02 Objects and Classes (Ex)** | [04.1 Total Average of Students](02ObjectsAndClassesEx/04.1totalAverageOfStudents/) | Same: N students (name/surname on separate lines), print each and total average. `Student` with `read(istream)` and `print(ostream)`. |

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
