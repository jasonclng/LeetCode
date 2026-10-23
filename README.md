# LeetCode Solutions

![Language: C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black)
![Language: Java](https://img.shields.io/badge/Java-ED8B00?logo=openjdk&logoColor=white)
![Problems Solved](https://img.shields.io/badge/solved-1-blue)

My solutions to [LeetCode](https://leetcode.com/) problems, each written in both **C** and **Java**.

## Progress

| Easy | Medium | Hard | Total |
| :--: | :----: | :--: | :---: |
|  0   |   1    |  0   | **1** |

## Solutions

| #    | Title | Difficulty | Topics | C | Java |
| ---: | ----- | ---------- | ------ | - | ---- |
| 1111 | [Maximum Nesting Depth of Two Valid Parentheses Strings](problems/1111-maximum-nesting-depth-of-two-valid-parentheses-strings/PROBLEM.md) | Medium | String, Stack | [C](problems/1111-maximum-nesting-depth-of-two-valid-parentheses-strings/solution.c) | [Java](problems/1111-maximum-nesting-depth-of-two-valid-parentheses-strings/Solution.java) |

## Repository Layout

```
problems/
└── <number>-<problem-slug>/
    ├── PROBLEM.md      # original problem statement
    ├── solution.c      # C solution
    ├── main.c          # C test driver
    ├── Solution.java   # Java solution
    └── Main.java       # Java test driver
```

Folders use the four-digit, zero-padded problem number (for example, `0001-two-sum`), so they list in problem order.

## Building and Testing

Each problem has a C test driver (`main.c`) and a Java test driver (`Main.java`). They check the solution's output and exit with a non-zero code on failure. Warnings are treated as errors in both languages (`/W4 /WX` with MSVC, `-Wall -Wextra -Werror` with GCC/Clang, `-Xlint:all -Werror` with `javac`).

| | Windows | Linux |
| --- | --- | --- |
| C (CMake + CTest) | `build-c.bat` | `./build-c.sh` |
| Java | `build-java.bat` | `./build-java.sh` |

C executables are built to `build/c/<problem>/main` (`main.exe` on Windows), and Java classes to `build/java/<problem>/`.

### Windows

**Prerequisites**

- [Visual Studio](https://visualstudio.microsoft.com/) 2022 or later (or the Build Tools for Visual Studio) with the **Desktop development with C++** workload
- [CMake](https://cmake.org/download/) 3.20 or later on your `PATH`
- A JDK, such as [Microsoft Build of OpenJDK](https://learn.microsoft.com/java/openjdk/download) 21, with `javac` and `java` on your `PATH`

Install CMake and the JDK with `winget`:

```bat
winget install Kitware.CMake
winget install Microsoft.OpenJDK.21
```

**Build and test** from a Command Prompt or PowerShell window. A Developer Command Prompt is not required, because CMake finds Visual Studio on its own.

```bat
git clone https://github.com/jasonclng/LeetCode.git
cd LeetCode

build-c.bat
build-java.bat
```

Run a single problem's C tests directly:

```bat
build\c\1111-maximum-nesting-depth-of-two-valid-parentheses-strings\main.exe
```

The `.sh` scripts also work on Windows in Git Bash.

### Linux

**Prerequisites**

- GCC or Clang
- CMake 3.20 or later
- A JDK, such as OpenJDK 21

On Debian or Ubuntu:

```bash
sudo apt update
sudo apt install build-essential cmake default-jdk
```

**Build and test:**

```bash
git clone https://github.com/jasonclng/LeetCode.git
cd LeetCode

./build-c.sh
./build-java.sh
```

Run a single problem's C tests directly:

```bash
./build/c/1111-maximum-nesting-depth-of-two-valid-parentheses-strings/main
```

---

<sub>Problem statements are © LeetCode and are included here for reference only.</sub>
