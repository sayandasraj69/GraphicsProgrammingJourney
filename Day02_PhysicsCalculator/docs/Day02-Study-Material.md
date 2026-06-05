# Day 02 - Variables, Functions, Scope and Multi-File C++ Projects

## Date

Day 02 of Graphics Programmer Roadmap

---

# Objective

The goal of Day 02 was not to learn C++ syntax.

The goal was to understand how real software systems are built from:

* Data
* Functions
* Modules

and how these concepts eventually scale into graphics engines.

---

# Big Picture

A graphics engine is ultimately a collection of systems.

Examples:

* Camera System
* Renderer System
* Texture System
* Shader System
* Material System

Every system can be viewed as:

```text
Data + Functions
```

Examples:

```cpp
float positionX;
float positionY;
float positionZ;
```

represent data.

```cpp
MoveForward();
Rotate();
RenderFrame();
```

represent behavior.

Mental model:

```text
Engine
↓
Systems
↓
Data + Functions
↓
Variables + Code
↓
Memory
```

---

# Variables

A variable is a named location in memory.

Example:

```cpp
int health = 100;
```

Variables give meaning to memory.

Without variables:

```cpp
100
50
25
```

have no context.

With variables:

```cpp
playerHealth = 100;
enemyHealth = 50;
ammo = 25;
```

the data becomes understandable.

---

# Primitive Types

## int

Used for whole numbers.

Examples:

```cpp
int width = 1920;
int height = 1080;
```

Typical graphics usage:

* Screen dimensions
* Vertex counts
* Triangle counts

---

## float

Used for decimal values.

Examples:

```cpp
float speed = 3.5f;
float lightIntensity = 0.8f;
```

Graphics uses float extensively because most real-world quantities contain decimals.

Examples:

* Positions
* Rotations
* Camera movement
* Lighting
* Animation
* Physics

---

## double

Higher precision floating point type.

Advantages:

* More precision

Disadvantages:

* More memory
* More bandwidth

Most rendering calculations typically use float.

---

## bool

Represents:

```cpp
true
false
```

Used for:

* State
* Visibility
* Input
* System flags

---

# Floating Point Numbers

Graphics programming relies heavily on floating point calculations.

Examples:

```cpp
float position;
float speed;
float rotation;
float intensity;
```

Important observation:

Floating point values are not exact.

Example:

```cpp
0.1f + 0.2f
```

may not equal:

```cpp
0.3f
```

exactly.

Professional rule:

Avoid direct float comparisons.

Instead compare using a small tolerance (epsilon).

---

# Constants

## const

Represents a value that cannot be modified after creation.

Example:

```cpp
const float gravity = 9.81f;
```

---

## constexpr

Represents a value known at compile time.

Example:

```cpp
constexpr int MAX_LIGHTS = 128;
```

Current understanding:

```text
const
=
Fixed after creation

constexpr
=
Known during compilation
```

More advanced usage will be learned later.

---

# Functions

A function is a reusable block of code that performs a task.

Example:

```cpp
float CalculateVelocity(float distance,
                        float time)
{
    return distance / time;
}
```

Functions exist to:

* Reduce repetition
* Improve organization
* Improve maintainability
* Create abstraction

---

## Parameters vs Arguments

Function definition:

```cpp
float CalculateVelocity(float distance,
                        float time)
```

Parameters:

```text
distance
time
```

Function call:

```cpp
CalculateVelocity(100.0f, 5.0f);
```

Arguments:

```text
100.0f
5.0f
```

---

## Return Values

Example:

```cpp
return distance / time;
```

The function gives a result back to the caller.

---

## Void Functions

Example:

```cpp
void PrintMessage()
{
    std::cout << "Hello";
}
```

Returns no value.

---

# Scope

Scope determines where a variable can be accessed.

Important realization:

Scope is fundamentally about:

* Visibility
* Lifetime
* Ownership

---

## Local Variables

Example:

```cpp
void Update()
{
    int score = 100;
}
```

Characteristics:

* Exists only inside the function
* Destroyed when scope ends
* Easier to reason about
* Preferred in most cases

---

## Global Variables

Example:

```cpp
int score = 100;
```

Characteristics:

* Accessible from many places
* Long lifetime
* Harder to debug
* Can create hidden dependencies

Professional guideline:

Prefer local variables whenever possible.

---

# Resource Lifetime Insight

One important lesson from today's discussion:

Graphics programming is not only about code.

It is also about resource management.

Examples:

* Textures
* Meshes
* Shaders
* GPU Buffers

Graphics resources can consume significant memory.

Therefore graphics programmers constantly think about:

```text
Who owns this resource?

How long does it live?

When should it be destroyed?
```

Scope helps control lifetime.

---

# Header Files and Source Files

## Header File (.h)

Contains declarations.

Example:

```cpp
float CalculateVelocity(float distance,
                        float time);
```

Think:

```text
Promise
```

---

## Source File (.cpp)

Contains definitions.

Example:

```cpp
float CalculateVelocity(float distance,
                        float time)
{
    return distance / time;
}
```

Think:

```text
Implementation
```

---

# Declaration vs Definition

Declaration:

```cpp
float CalculateVelocity(float distance,
                        float time);
```

Tells the compiler something exists.

Definition:

```cpp
float CalculateVelocity(float distance,
                        float time)
{
    return distance / time;
}
```

Provides the actual implementation.

Mental model:

```text
Declaration
=
Promise

Definition
=
Fulfillment
```

---

# Build Process

High-level build pipeline:

```text
Source Files
↓
Preprocessor
↓
Compiler
↓
Object Files
↓
Linker
↓
Executable
```

---

## Compiler

Processes individual source files.

Checks syntax and generates object files.

---

## Linker

Connects object files together.

Example:

```text
main.cpp
calls

CalculateVelocity()

defined in

Physics.cpp
```

The linker resolves the connection.

---

# Preprocessor

Runs before compilation.

Handles directives such as:

```cpp
#include
#define
#ifndef
#endif
```

---

## #include

Conceptually:

```text
Copy this file here
```

before compilation.

---

# Header Guards

Purpose:

Prevent multiple inclusion of the same header.

Example:

```cpp
#ifndef PHYSICS_H
#define PHYSICS_H

...

#endif
```

Modern alternative:

```cpp
#pragma once
```

---

# Practical Project

Project:

Physics Calculator

Structure:

```text
PhysicsCalculator/

├── CMakeLists.txt
├── main.cpp
├── Physics.h
├── Physics.cpp
└── docs/
```

Implemented:

```cpp
CalculateVelocity()
CalculateDistance()
CalculateAcceleration()
```

---

# Important Lessons Learned

1. Graphics engines are built from systems.
2. Systems are built from data and functions.
3. Variables represent data.
4. Functions represent behavior.
5. Scope controls visibility and lifetime.
6. Local variables are generally safer than globals.
7. Header files contain declarations.
8. Source files contain definitions.
9. Compilation and linking are separate stages.
10. Resource lifetime becomes increasingly important in graphics programming.

---

# Key Mental Shift

When seeing a graphics-related class such as:

```cpp
class Camera
{
};
```

Do not think:

```text
Graphics Magic
```

Instead think:

```text
Software System

Containing:

Data
Functions
Lifetime
Ownership
Organization
```

This mindset will be important throughout the remainder of the roadmap.

---

# Status

Day 02: Complete

Ready for Day 03:

* Loops
* Arrays
* std::vector
* Collections of Data
* Scaling from one object to many objects

```
```
