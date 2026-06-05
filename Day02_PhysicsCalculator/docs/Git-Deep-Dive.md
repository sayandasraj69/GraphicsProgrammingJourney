# Git Deep Dive: Repository Migration & History Merging

## Why This Document Exists

During the Graphics Programming Journey, a real-world Git problem occurred:

* Day 1 project (`HelloGraphics`) had its own Git repository.
* Day 2 project (`PhysicsCalculator`) had its own Git repository.
* The goal was to create a single repository called:

```text
Graphics Programming/
├── Day01_HelloGraphics/
└── Day02_PhysicsCalculator/
```

while preserving the history of both projects.

This document explains all concepts learned during that process, from beginner Git to repository migration.

---

# 1. What Problem Does Git Solve?

Without Git, developers often create folders like:

```text
Project
Project_Final
Project_Final_2
Project_Final_ReallyFinal
```

Problems:

* No history
* No rollback
* No collaboration
* Easy to lose work

Git solves these by storing project history.

---

# 2. What Is Git?

Git is a Distributed Version Control System (DVCS).

Git stores:

* Files
* History
* Branches
* Relationships between commits

Git does NOT simply store files.

Git stores snapshots over time.

---

# 3. The .git Directory

Example:

```text
MyProject/
├── src/
├── docs/
└── .git/
```

Project files:

```text
src/
docs/
```

Repository metadata:

```text
.git/
```

The `.git` folder contains:

* Commit history
* Branches
* Tags
* Remote URLs
* Object database

Important:

Deleting `.git` does NOT delete project files.

It only removes Git history.

---

# 4. Working Directory, Staging Area, Commit

Git operates using three areas.

## Working Directory

Files currently on disk.

## Staging Area (Index)

Files prepared for the next commit.

## Commit

Permanent snapshot stored in Git history.

Workflow:

```text
Working Directory
       ↓
    git add
       ↓
 Staging Area
       ↓
  git commit
       ↓
     Commit
```

---

# 5. Commits

Many beginners think:

```text
Commit = Saved Files
```

A better model:

```text
Commit
=
Snapshot
+
Metadata
+
Parent Pointer
```

Example:

```text
A → B → C
```

Commit C contains:

```text
Parent = B
```

Git history is built from parent relationships.

---

# 6. Branches

A branch is simply a movable pointer.

Example:

```text
main
 ↓
A → B → C
```

After another commit:

```text
main
 ↓
A → B → C → D
```

The branch moves.

---

# 7. Remotes

Many beginners think:

```text
Remote = GitHub
```

Not true.

A remote is simply another Git repository.

Examples:

* GitHub repository
* Another developer's machine
* Local repository

Examples from this project:

```text
origin
physics
```

---

# 8. Fetch vs Pull vs Merge

## Fetch

```bash
git fetch physics
```

Fetch:

* Downloads commits
* Downloads trees
* Downloads blobs
* Updates remote tracking branches

Fetch does NOT:

* Modify current branch
* Merge changes
* Overwrite files

Key rule:

```text
Fetch != Merge
```

---

## Merge

Combines histories.

Example:

```bash
git merge branch-name
```

---

## Pull

Equivalent to:

```bash
git fetch
git merge
```

performed automatically.

---

# 9. Remote Tracking Branches

After fetch:

```text
physics/master
```

appeared.

This is not a normal branch.

It is a remote tracking branch.

Think of it as:

```text
Read-only bookmark
```

pointing to the latest commit known from the remote repository.

---

# 10. Commit Objects

Git internally stores objects.

Main types:

## Blob

Stores file contents.

## Tree

Stores folder structure.

## Commit

Stores:

* Snapshot reference
* Author
* Timestamp
* Parent commit(s)

Useful command:

```bash
git cat-file -t <hash>
```

Example output:

```text
commit
```

Meaning Git physically possesses that commit object.

---

# 11. Parent Pointers

Example:

```text
A → B → C
```

Commit C contains:

```text
parent = B
```

Commit B contains:

```text
parent = A
```

This chain creates history.

---

# 12. Merge Commits

Normal commit:

```text
Parent Count = 1
```

Merge commit:

```text
Parent Count = 2
```

Example:

```text
      M
     / \
    C   Y
```

Merge commit M contains:

```text
Parent 1 = C
Parent 2 = Y
```

This is how Git joins histories.

---

# 13. Unrelated Histories

Normally Git expects:

```text
A → B → C
       \
        D → E
```

with a common ancestor.

Our repositories looked like:

```text
A → B → C

X → Y
```

No common ancestor existed.

Git therefore refused to merge until we explicitly allowed it:

```bash
git merge physics/master --allow-unrelated-histories
```

---

# 14. Repository Migration Case Study

Initial state:

```text
HelloGraphics/.git
PhysicsCalculator/.git
```

Goal:

```text
Graphics Programming/
├── Day01_HelloGraphics/
└── Day02_PhysicsCalculator/
```

Process:

1. Move repository root.
2. Add Day2 repository as a remote.
3. Fetch Day2 history.
4. Verify commit objects.
5. Merge unrelated histories.
6. Reorganize files.
7. Create a unified repository.

---

# 15. Git Commands Learned

Basic:

```bash
git status
git add
git commit
git push
git pull
git clone
```

Intermediate:

```bash
git branch
git remote
git fetch
git log --graph
```

Advanced:

```bash
git cat-file
git ls-tree
git show
git remote show
git rev-parse
```

---

# 16. Graphics Programming Analogies

Git Commit Graph:

```text
A → B → C
```

resembles a Scene Graph:

```text
Root
├── Camera
├── Light
└── Mesh
```

Both are graph structures.

Similarly:

```text
Fetch
```

is like:

```cpp
#include "Physics.h"
```

The system becomes aware of another component.

And:

```text
Merge
```

is like connecting systems together.

---

# 17. Most Important Takeaways

Remember these:

1. `.git` stores history.
2. Fetch is not merge.
3. Commit = Snapshot + Parent Pointer.
4. Merge Commit = Two Parent Pointers.
5. Git tracks state, not intention.
6. Remotes are repositories, not necessarily GitHub.
7. History and current files are separate concepts.

---

# Career Perspective

Students usually need:

```bash
git init
git add
git commit
git push
```

Interns additionally need:

```bash
git branch
git merge
git fetch
```

Most professional developers need:

```bash
git rebase
git stash
git cherry-pick
```

The repository migration concepts in this document are closer to senior engineering, build systems, engine programming, DevOps, and large-scale software maintenance work.

The goal is not to memorize everything immediately.

The goal is to build a mental model that becomes stronger through repeated usage.
