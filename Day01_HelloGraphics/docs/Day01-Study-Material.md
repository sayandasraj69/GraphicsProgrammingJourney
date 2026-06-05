# Graphics Programming Roadmap

# Day 1 Study Material

## Environment Setup & Software Development Foundations

---

# 1. What Is Graphics Programming?

Graphics Programming is the field of software engineering responsible for generating images on a computer.

A graphics programmer develops systems that transform:

3D Models
+
Textures
+
Materials
+
Lights
+
Camera Data

into

Pixels displayed on a monitor.

The primary objective is to produce visually correct images while maintaining high performance.

---

# 2. Graphics Programming vs Game Development

Game Development focuses on:

* Gameplay
* AI
* UI
* Networking
* Combat Systems
* Progression Systems

Graphics Programming focuses on:

* Rendering
* Lighting
* Shadows
* Materials
* Shaders
* Reflections
* GPU Optimization

Example:

Gameplay Programmer:

"How much damage does the bullet do?"

Graphics Programmer:

"How is the bullet, smoke, and muzzle flash rendered?"

---

# 3. Graphics Programmer vs Unreal Developer

Unreal Developer:

* Uses Unreal Engine systems
* Creates gameplay
* Uses Blueprints
* Builds UI
* Creates game mechanics

Graphics Programmer:

* Builds rendering systems
* Creates shaders
* Optimizes GPU workloads
* Implements lighting systems
* Extends engine rendering features

A Graphics Programmer often works below the engine features that an Unreal Developer uses.

---

# 4. Graphics Programmer vs Rendering Engineer

These titles are often interchangeable.

Graphics Programmer:
Broader graphics responsibilities.

Rendering Engineer:
Specialized focus on rendering systems and image generation.

Both require:

* C++
* Mathematics
* GPU knowledge
* Rendering pipeline understanding

---

# 5. Industries Hiring Graphics Programmers

1. AAA Games
2. Indie Games
3. CAD Software
4. Scientific Visualization
5. Medical Imaging
6. GIS Systems
7. Robotics
8. Automotive Visualization
9. Film and VFX
10. Defense Simulators
11. AR/VR
12. Digital Twins

---

# 6. How A Frame Is Created

Rendering Pipeline Overview:

Models
↓
Meshes
↓
Materials
↓
Textures
↓
Lights
↓
Camera
↓
GPU
↓
Framebuffer
↓
Monitor

---

## Mesh

A mesh is a collection of vertices that define geometry.

Everything rendered by a GPU is ultimately represented as triangles.

Examples:

* Character
* Building
* Weapon
* Vehicle

---

## Texture

An image applied to geometry.

Provides:

* Color
* Surface details
* Visual appearance

Without textures:

Objects appear plain.

---

## Material

Defines how a surface reacts to light.

Examples:

* Metal
* Plastic
* Wood
* Glass

---

## Light

Provides illumination.

Examples:

* Sunlight
* Point Light
* Spotlight

---

## Camera

Defines what portion of the world is visible.

Equivalent to the player's eyes.

---

## GPU

Graphics Processing Unit.

Responsible for:

* Vertex Processing
* Rasterization
* Fragment Processing
* Shading

---

## Framebuffer

Memory containing the final rendered image before display.

---

# 7. Source Code To Executable Journey

Source Code:

Human-readable instructions.

Example:

int main()
{
return 0;
}

The CPU cannot execute source code directly.

Source code must be translated into machine code.

Pipeline:

Source Code
↓
Compiler
↓
Object Files
↓
Linker
↓
Executable

---

# 8. Compiler

Definition:

Software that converts source code into machine code.

Examples:

1. MSVC
2. GCC
3. Clang

---

## MSVC

Microsoft Compiler.

Most common on Windows.

Widely used in:

* Unreal Engine
* Game Development
* Graphics Programming

---

## GCC

Popular on Linux.

Mature and stable.

---

## Clang

Built on LLVM.

Known for:

* Better diagnostics
* Cleaner error messages

---

## LLVM

Compiler Infrastructure Framework.

Used to build compilers.

Clang is built using LLVM.

LLVM itself is not a compiler.

---

# 9. Object Files

Intermediate compiled files.

Examples:

main.obj
renderer.obj

Contain machine code but are incomplete programs.

Must be linked together.

---

# 10. Linker

Combines object files into a final executable.

Example:

main.obj
+
renderer.obj
+
camera.obj

↓

Game.exe

---

# 11. Executable

Final program produced after linking.

Examples:

Game.exe
Renderer.exe
Editor.exe

Contains machine code executable by the CPU.

---

# 12. Build Systems

Purpose:

Automate the build process.

Responsibilities:

* Compilation
* Linking
* Dependency management
* Project generation

Without build systems:

Large projects become unmanageable.

---

# 13. CMake

Definition:

Cross-platform build configuration system.

Important:

CMake does NOT compile code.

CMake generates build files.

Example:

CMake
↓
Visual Studio Project
↓
MSVC Compiler
↓
Executable

Think of CMake as:

Maven/Gradle equivalent for C++ project configuration.

---

## Common CMake Commands

project()

Defines project name.

set()

Sets configuration values.

add_executable()

Creates executable target.

add_library()

Creates library target.

target_include_directories()

Adds include paths.

target_link_libraries()

Links libraries.

---

# 14. Debug vs Release Builds

Debug Build:

Purpose:

Development.

Characteristics:

* Slower
* Extra debug information
* Easier debugging

---

Release Build:

Purpose:

Production.

Characteristics:

* Faster
* Compiler optimizations enabled
* Smaller executable

---

# 15. Version Control

Purpose:

Track code history.

Problems Solved:

* Accidental mistakes
* Collaboration
* Rollback
* Code history

---

# 16. Git

Distributed Version Control System.

Core Concepts:

Repository
Commit
Branch
Merge
Clone
Pull
Push

---

## Repository

Database of project history.

---

## Commit

Snapshot of project state.

Equivalent to a save point.

---

## Branch

Independent development timeline.

Allows experimentation without affecting main code.

---

## Merge

Combines branches.

---

## Clone

Downloads repository.

---

## Pull

Downloads latest changes.

---

## Push

Uploads local changes.

---

# 17. GitHub

Cloud platform for hosting Git repositories.

Uses:

* Portfolio
* Collaboration
* Open Source
* Backup

---

# 18. Why Graphics Programmers Use Git

Rendering projects can contain:

* Thousands of files
* Millions of lines of code

Git provides:

* History
* Recovery
* Collaboration

Professional requirement.

---

# 19. Professional Project Structure

HelloGraphics/

src/
include/
assets/
docs/
build/

README.md
CMakeLists.txt

---

## src

Implementation files.

Examples:

main.cpp
renderer.cpp

---

## include

Header files.

Examples:

renderer.h
camera.h

---

## assets

Resources.

Examples:

Textures
Models
Audio

---

## docs

Documentation.

Examples:

Study Notes
Architecture Notes

---

## build

Generated build artifacts.

Examples:

.exe
.obj
Cache Files

Never store source code here.

---

# 20. Visual Studio

Integrated Development Environment (IDE).

Provides:

* Code Editor
* Debugger
* Build Interface
* Project Management

Visual Studio is NOT the compiler.

---

# 21. MSVC

Microsoft Visual C++ Compiler.

Responsible for actual compilation.

Visual Studio uses MSVC.

---

# 22. Day 1 Toolchain

Source Code
↓
CMake
↓
Visual Studio Build Files
↓
MSVC Compiler
↓
Object Files
↓
Linker
↓
Executable

Git works independently:

Git
↓
Tracks Source Code History

---

# 23. Important Interview Questions

1. What is Graphics Programming?
2. What is a Compiler?
3. What is a Linker?
4. What is an Object File?
5. What is an Executable?
6. What is CMake?
7. Does CMake compile code?
8. Difference between Debug and Release?
9. What is Git?
10. What is a Commit?
11. What is a Branch?
12. What is a Repository?
13. What is the purpose of a build system?
14. What is the difference between Visual Studio and MSVC?
15. Why do professional projects separate src and include?

---

# 24. Day 1 Key Takeaways

1. Graphics Programming is the process of generating images efficiently.
2. Rendering is only one part of a larger software ecosystem.
3. CPUs cannot execute C++ directly.
4. Compilers translate source code into machine code.
5. Linkers combine object files into executables.
6. CMake generates build files but does not compile.
7. MSVC performs compilation.
8. Git tracks project history.
9. Professional projects require structured folders.
10. Every graphics engine starts with the same software engineering foundations learned on Day 1.
