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
| **03 Objects and Classes (Advanced)** | [01 Rolling Sticks](03ObjectsAndClassesAdvanced/01rollingSticks/) | Console animation: sticks (characters cycling `_` `\` `|` `/`) roll along a 50-character line; new sticks spawn randomly. Uses `Stick` (position, rotation, `nextAnimation()`), a list of sticks, and platform-specific `clearScreen()` (Windows/Linux). |
| **03 Objects and Classes (Advanced)** | [02 Fraction Class](03ObjectsAndClassesAdvanced/02fractionClass/) | `Fraction` class with reduce (gcd), `operator<` (for `set`), `operator==`, `operator+`/`operator-`, prefix/postfix `operator++`, and stream I/O. Demo: set of fractions, equality, read/write, increment, and arithmetic. |
| **04 Objects and Classes Advanced (Ex)** | [01 Car](04ObjectsAndClassesAdvancedEx/01car/) | Reads brand, model, and year; creates a `Car` object and prints its data via getters (`GetBrand`, `GetModel`, `GetYear`). |
| **04 Objects and Classes Advanced (Ex)** | [02 Sum of Vectors](04ObjectsAndClassesAdvancedEx/02sumOfVectors/) | Reads two `vector<string>`s of the same size and uses `operator+` to produce their element-wise concatenation (or sum); prints the result. Custom `operator+` for `vector<string>`. |
| **04 Objects and Classes Advanced (Ex)** | [03 Operators](04ObjectsAndClassesAdvancedEx/03operators/) | Builds a formatted list: custom `operator<<` pushes heading, separator, and numbered lines (index, text, length in parentheses) into a `vector<string>`; then `operator<<` to ostream prints it. |
| **04 Objects and Classes Advanced (Ex)** | [04 Resources](04ObjectsAndClassesAdvancedEx/04resources/) | Reads N resources (id, type, etc.); stores in a `set<Resource>`; counts by `ResourceType` in a map; prints resources by id and then counts by type. Uses `SoftUni::Resource` and `ResourceType`. |
| **04 Objects and Classes Advanced (Ex)** | [05 Lectures](04ObjectsAndClassesAdvancedEx/05lectures/) | Extends the resource model: `Lecture` collects resources via `lecture << r`, supports range-for and `lecture[type]` for counts; custom `operator<<` to fill a vector of types. Builds on `Resource`/`ResourceType`. |
| **04 Objects and Classes Advanced (Ex)** | [06 Memory Allocator](04ObjectsAndClassesAdvancedEx/06memoryAllocator/) | Command-driven allocator: reads memory size and N command lines; `executeCommand(command, memory)` interprets each (allocate/free style) on a `vector<int*>`, returns `ErrorCode`; prints result per command. |
| **04 Objects and Classes Advanced (Ex)** | [07 Bytes Parsing](04ObjectsAndClassesAdvancedEx/07bytesParsing/) | Reads a command string and raw data bytes; `parseData` interprets commands and fills a vector of parsed numbers; outputs `ErrorCode` and parsed results. Parses byte stream according to given commands. |
| **05 Code Organisation and Templates** | [01 Compile](05CodeOrganisationAndTemplates/01compile/) | Demonstrates conditional compilation: code inside `#ifndef DONT_COMPILE_THIS` contains intentional errors; when the macro is defined, that block is excluded. Uses `Defines.h` and a namespace alias; reads and echoes a string. |
| **05 Code Organisation and Templates** | [02 Censorship](05CodeOrganisationAndTemplates/02censorship/) | `Article13Filter` built from a set of copyrighted words; reads lines until `end`, prints only lines not blocked; blocked lines are filtered by content. Prints "Blocked: " and the list of blocked items at the end. |
| **05 Code Organisation and Templates** | [03 Parser](05CodeOrganisationAndTemplates/03parser/) | Template `Parser<T>`: reads type (`i`/int, `w`/string, `s`/Song), a stop line, then tokens until that line; fills a vector and prints it. Uses `PrintUtils` and stream I/O for `Song` (name, length). |
| **05 Code Organisation and Templates** | [04 Split and Join](05CodeOrganisationAndTemplates/04splitAndJoin/) | Template `split<T>(line, separator)` and `join(container, joinStr)`: reads separator, line, type (`i`/`w`/`s`), and join string; splits the line into `vector<T>`, joins with the given string, prints result. |
| **05 Code Organisation and Templates** | [05 Sorting](05CodeOrganisationAndTemplates/05sorting/) | Like 03 Parser but stores in a `set` with comparator `Reverse<T, LessThan<T>>` (reverse order). Reads int/string/Song until stop line; prints container. Uses `Parser`, `Comparators`, `PrintUtils`, and `Song`. |
| **06 OOP Constructors** | [01 Echo](06OOPConstructors/01echo/) | Contact Manager UI: optional echo/hints; uses `Echo`, `EmailContact`, and `ContactManagerUI`. Creates a vector of contacts, runs the UI with `ui.start()`; demonstrates constructor usage and multi-file organisation. |
| **06 OOP Constructors** | [02 Notes](06OOPConstructors/02notes/) | Template `NoteParser<Naming>` with a translator; uses `SolfegeNoteNaming` to convert note text (e.g. Do, Re, Mi) to `NoteName`. Reads note strings until `end`, stores in a vector, prints. |
| **06 OOP Constructors** | [03 Vectors](06OOPConstructors/03vectors/) | Reads N vectors from input; stores in a `multiset<Vector, ReverseComparer<Vector, VectorLengthComparer>>` (sorted by length, reverse order); prints each. Uses custom `Vector` and `VectorComparisons`. |
| **07 OOP Constructors (Ex)** | [01 Try Parse](07OOPConstructorsEx/01tryParse/) | Reads two strings; `tryParse` attempts to parse each into an `int`. If both succeed, prints their sum; otherwise prints parsed values or `[error] <original string>` for failures. |
| **07 OOP Constructors (Ex)** | [02 Find](07OOPConstructorsEx/02find/) | Reads `Company` objects from lines until `end`, then an id; `find(companies, id)` returns the matching `Company*` or `nullptr`. Prints the company or `[not found]`; heap-allocated companies are deleted. |
| **07 OOP Constructors (Ex)** | [03 Order](07OOPConstructorsEx/03order/) | `OrderedInserter` keeps a `vector<const Company*>` sorted while inserting heap-allocated companies read until `end`. Prints all companies in order, then deletes them. |
| **07 OOP Constructors (Ex)** | [04 Profits](07OOPConstructorsEx/04profits/) | Reads `Company` lines until `end`, then `ProfitCalculator` lines per company id until `end`. `getProfitReport` builds a profit report for the inclusive range from first to last company using the calculators map. |
| **07 OOP Constructors (Ex)** | [05 Register](07OOPConstructorsEx/05register/) | `Register` with fixed capacity: `add(Company)` and `get(id)`. Replays the same input `numRuns` times to verify lookup consistency; prints the final looked-up company. |
| **07 OOP Constructors (Ex)** | [06 Words](07OOPConstructorsEx/06words/) | `Word` in a `set` tracks word text and occurrence count; two input lines (separated by `---`) are processed; prints each distinct word with its count. |
| **07 OOP Constructors (Ex)** | [07 Divisible By 45](07OOPConstructorsEx/07divisibleBy45/) | `BigInt` range from `s` to `e`; increments by 1 and prints values divisible by 45 using digit rules for 5 and 9 (no full division on huge numbers). |
| **07 OOP Constructors (Ex)** | [08 Sequences](07OOPConstructorsEx/08sequences/) | Template `Sequence<T, Generator>` with `generateNext` and iteration; `IntegersGenerator` or `FibonacciGenerator` functors. Reads how many values to generate, prints them, repeats interactively. |
| **08 Rule of 3-5-0** | [01 Smart Array (Rule of 3)](08RuleOf3-5-0/01smartArray/) | `SmartArray<T>` with dynamic storage: destructor, copy constructor, and copy assignment (Rule of Three). Indexing, `print()`, copy/assign demos. |
| **08 Rule of 3-5-0** | [02 Smart Array Resize](08RuleOf3-5-0/02smartArrayResize/) | Extends `SmartArray` with `resize()` while keeping correct copying semantics; demo grows/shrinks the array and assigns elements. |
| **08 Rule of 3-5-0** | [03 Smart Array Copy Idiom](08RuleOf3-5-0/03smartArrayCopyIdiom/) | Same resize behaviour; implements assignment via the **copy-and-swap** idiom for exception-safe, self-assignment-safe `operator=`. |
| **08 Rule of 3-5-0** | [04 Smart Array Iterator](08RuleOf3-5-0/04smartArrayIterator/) | Adds iterators (`begin`/`end`) so `SmartArray` works with range-based `for` and mutates elements through references. |
| **08 Rule of 3-5-0** | [05 Smart Array (Rule of 0)](08RuleOf3-5-0/05smartArrayRuleOf0/) | **Rule of Zero**: `SmartArray` uses a standard container (or similar) to own memory so no user-defined destructor/copy/move are needed; same demo as 04. |
| **09 Rule of 3-5-0 (Ex)** | [01 Min By](09RuleOf3-5-0Ex/01minBy/) | Template `minBy(Iterable, Compare)`: reads a line of strings and a mode—lexicographically smallest (1), shortest string (2), or longest string (3)—and prints the chosen element. |
| **09 Rule of 3-5-0 (Ex)** | [02 Remove Invalid](09RuleOf3-5-0Ex/02removeInvalid/) | Builds a `list<Company*>` from id/name lines until `end`; every 10 insertions runs `removeInvalid`; final cleanup pass, then prints and deletes remaining companies. |
| **09 Rule of 3-5-0 (Ex)** | [03 Make Company](09RuleOf3-5-0Ex/03makeCompany/) | Factory `makeCompany(properties)` builds a company from parsed line fields; copies the handle/result and prints `toString()` for each line until `end` (exercises resource-safe company creation). |
| **09 Rule of 3-5-0 (Ex)** | [04 Parse Unique Companies](09RuleOf3-5-0Ex/04parseUniqueCompanies/) | Buffers lines until `end`, reads uniqueness mode (by id, by name, or by name+id). `parseUniqueCompanies` returns a dynamic array of unique `Company` objects; prints them and `delete[]`s storage. |
| **09 Rule of 3-5-0 (Ex)** | [05 Register of Three](09RuleOf3-5-0Ex/05registerOfThree/) | `Register` with **Rule of Three** semantics and stream extraction: reads `numCompanies`, fills a register, assigns via copy. `doRun` replays input to lookup by id; multi-run consistency check like the earlier register exercise. |
| **09 Rule of 3-5-0 (Ex)** | [06 Array of Pointers](09RuleOf3-5-0Ex/06arrayOfPointers/) | `ArrayOfPointers` stores heap `Company*` entries with `add`/`get`/`getSize`; parses companies and id from a replayed buffer; finds matching id and returns `Company`. Alternate folder: [`061arrayOfPointers`](09RuleOf3-5-0Ex/061arrayOfPointers/). |
| **09 Rule of 3-5-0 (Ex)** | [07 List](09RuleOf3-5-0Ex/07list/) | Custom `List` of sorted integers; reads lines of numbers until `end`, merges each line into a running sorted list via `mergeSortedLists` (two-pointer merge). Prints `toString()`. |
| **09 Rule of 3-5-0 (Ex)** | [08 Overloading Madness](09RuleOf3-5-0Ex/08overloadingMadness/) | `Matrix` with overloaded `+=`, `-=`, `*=`, `/=` (and stream output). Reads five square matrices, orders them by dimension, then applies add/subtract/multiply/divide chains on the largest matrix; prints the result. |
| **10 Inheritance** | [01 Sort Pointers](10Inheritance/01sortPointers/) | Reads company lines (`name` and `id`) until `end`, then a sort key (`name` or `id`); builds heap-allocated `Company` objects and sorts the pointer array with `sortBy` (`SortBy.h`), which wraps `std::sort` and compares dereferenced companies via a `lessThan` function pointer; prints each line with `toString()`. |
| **10 Inheritance** | [02 Ranges](10Inheritance/02ranges/) | `Range` (`from`, `to`, `operator<` by `from`) and `RangeDatabase`: reads `[from, to]` pairs until `.`, `prepare()` sorts ranges, then reads query integers until `.` and prints `in` or `out` depending on `isInside` (binary search over sorted intervals). |
| **10 Inheritance** | [03 Serialize](10Inheritance/03serialize/) | Buffers lines until `end`; `serializeToMemory` writes `Company` data into a raw `byte` buffer and returns length. Prints each byte value as an integer, then `delete[]`s the buffer. |
| **11 Inheritance (Ex)** | [01 Max Sum Array](11InheritanceEx/01maxSumArray/) | Template `Array<T>` with indexing, assignment, and iteration; reads several int arrays and keeps the one whose elements have the **maximum sum**; prints that array’s elements. |
| **11 Inheritance (Ex)** | [01.1 Max Sum Array](11InheritanceEx/01.1maxSumArray/) | Same exercise as 01 Max Sum Array (pick the array with maximum element sum, print it); separate project folder with the same `main` flow. |
| **11 Inheritance (Ex)** | [02 Shapes](11InheritanceEx/02shapes/) | Polymorphic shape hierarchy: `Circle`, `Rectangle`, and `CoordinateSystemCenter` (with `Vector2D`); reads shape type and parameters, prints center and **area** with fixed precision. |
| **11 Inheritance (Ex)** | [03 Indexed Set](11InheritanceEx/03indexedSet/) | `IndexedSet` with `add`, `operator[]`, and `size`; reads multiple sets (lines until `end`), then index list; picks the set with the largest **sum of elements at those indices** and prints it. |
| **11 Inheritance (Ex)** | [04 Memory Allocator Reforged](11InheritanceEx/04memoryAllocatorReforged/) | Command-driven allocator on a `vector<MemoryNode>` of fixed `BUFFER_SIZE`; reads N commands, `executeCommand` per line, `ErrorCode` and `printResult` (inheritance-based refactor of the memory exercise). |
| **11 Inheritance (Ex)** | [05 Snake](11InheritanceEx/05snake/) | Snake game: `parseFieldConfig` reads grid size, start position, obstacles, and power-ups; `CommandExecutor` runs movement commands while the game is active. |

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
