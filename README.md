# DSA — Data Structures and Algorithms

My DSA-I and DSA-II coursework, practice programs, assignments, and study references, organized in one repository.

**Maintained by [Adeeb Sharar](https://github.com/ash01-forge)**  
Computer Science and Engineering student, United International University.

## Repository structure

~~~text
DSA/
  DSA-I/
    Lab/       C and C++ programs, practice, assignment archives
    Theory/    Problem sets and examination references
  DSA-II/
    Lab/       Assignments, graph algorithms, STL, greedy and DP practice
    Theory/    Lecture slides, problem sheets and examination references
  FILE_INDEX.md
  SOURCE_MAP.json
  README.md
~~~

The GitHub repository name is **DSA**. DSA-I and DSA-II remain separate inside it so similarly named files and different versions remain available.

## DSA-I learning material

| Area | Where to start |
| --- | --- |
| C programming practice | [C programs](DSA-I/Lab/C/) |
| Sorting exercises | [Sorting practice](DSA-I/Lab/C/Practice_Prob_Sorting/), [selection sort](DSA-I/Lab/C/Selection_Sort_Problems/) |
| Searching | [Searching codes](DSA-I/Lab/C/Searching_Codes/) |
| Linked lists | [Linked-list exercises](DSA-I/Lab/C/Linked_List/) |
| Stacks and applications | [Stack programs](DSA-I/Lab/C%2B%2B/Stack/) |
| Queues | [Queue programs](DSA-I/Lab/C%2B%2B/Queue/) |
| Binary trees and traversals | [Binary-tree programs](DSA-I/Lab/C%2B%2B/Binary%20Tree/) |
| Theory and exam preparation | [DSA-I theory](DSA-I/Theory/) |

Assignments and scratch practice files keep their original names. Some scratch files or unfinished exercises may not be standalone programs.

## DSA-II learning material

| Area | Where to start |
| --- | --- |
| STL, divide and conquer, greedy algorithms, dynamic programming | [Exam practice collection](DSA-II/Lab/DSA_Exam_Practice_Codes/) |
| DSU, minimum/maximum spanning trees, Kruskal and Prim | [Graph algorithm collection](DSA-II/Lab/Graph_Algorithms_Faculty_Style/), [graph exam practice](DSA-II/Lab/Graph_Exam_CPP/) |
| Dijkstra and Bellman-Ford, paths and variations | [Graph algorithm collection](DSA-II/Lab/Graph_Algorithms_Faculty_Style/), [graph exam practice](DSA-II/Lab/Graph_Exam_CPP/) |
| Assignments and problem sheets | [DSA-II lab](DSA-II/Lab/) |
| Complexity, recurrence, hashing, string matching, greedy methods and graph theory | [Theory slides and references](DSA-II/Theory/) |

Topics in lecture materials are study references; the folder list does not claim a separate implemented program exists for every theoretical topic.

## Run one program at a time

Most exercises are independent programs. Select one file with its own main function and compile it separately. Keep any matching local header files in place.

### C example

From the repository root, with GCC installed:

~~~bash
mkdir -p build
gcc -std=c11 "DSA-I/Lab/C/firstprogram.c" -o build/firstprogram
./build/firstprogram
~~~

### C++ example

From the repository root, with G++ installed:

~~~bash
mkdir -p build
g++ -std=c++17 "DSA-I/Lab/C++/Stack/Stack_Vector.cpp" -o build/stack-vector
./build/stack-vector
~~~

These commands use a Bash-style terminal such as GitHub Codespaces. On Windows, use an installed C/C++ compiler or your IDE and the corresponding executable path. Input formats and prompts vary by exercise; read the selected source file and the collection's own README before running it.

Do not compile the whole repository as a single application. Some original references are intentionally incomplete. In particular, the graph exam collection documents its incomplete original Bellman-Ford reference and the completed practice variations separately.

## Study collections and reference code

This repository is a learning collection. It contains coursework, practice solutions, faculty/reference examples and study variations. Existing comments, teacher labels, explanatory notes and reference credits are retained. Inclusion in this repository does not mean every file was independently authored by the maintainer.

- Original ZIP archives are retained at their mapped course locations.
- If an archive contains additional or different study content, its readable files are also expanded under an ArchiveContents folder next to the archive.
- Existing folder versions and archived versions are both retained when they differ.
- Duplicate archives are retained for completeness, even where their content is already available as loose files.
- PDFs, slides and the Word study document are reference/course materials and retain their original ownership; no new license is assigned to them.

## File index and preservation

[FILE_INDEX.md](FILE_INDEX.md) lists the prepared files. [SOURCE_MAP.json](SOURCE_MAP.json) maps preserved content to its course-relative origin and records SHA-256 checksums.

Source code and copied course materials were preserved without code edits. This organization pass checked file integrity and archive restoration; it did not compile, run or establish the correctness of every exercise.

The GitHub package omits the installed VS Code application, loose compiled executables, local editor settings, empty scratch files, large class recordings, and a personal chat transcript. The original files on the local drives remain unchanged. Original coursework ZIPs may contain historical build artifacts as part of the preserved submissions.

## Related work

- [Java Contact Manager](https://github.com/ash01-forge/Java-Contact-Manager)
- [Java Practice Codes](https://github.com/ash01-forge/Java-Practice-Codes)
- [BlueCycle](https://github.com/ash01-forge/BlueCycle-Smart-Pond-Monitoring-System)
