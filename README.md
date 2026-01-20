# 🔄 Push_swap

A highly efficient stack sorting algorithm implemented in C as part of the 42 curriculum.

![42 Badge](https://img.shields.io/badge/42-push__swap-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen)

> ⚠️ **Warning:** This repository is for educational purposes only. If you're a 42/1337 student, do not copy this code. Cheating will get you flagged and you won't learn anything. Build your own solution!

## 📖 Description

**Push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using two stacks (`a` and `b`) with a limited set of operations, aiming for the **lowest possible number of moves**.

This implementation uses the **Chunks Algorithm** for optimal sorting performance.

## 🎯 Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate stack A (first becomes last) |
| `rb` | Rotate stack B (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## 🚀 Installation

```bash
# Clone the repository
git clone https://github.com/paraganaryt-tech/push_swap.git
cd push_swap

# Compile the mandatory part
make

# Compile the bonus checker
make bonus
```

## 💻 Usage

### Mandatory - push_swap
```bash
./push_swap 2 1 3 6 5 8
```

### Bonus - checker
```bash
./checker 2 1 3 6 5 8
```
Then input operations manually, or pipe from push_swap:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## 📊 Performance

| Stack Size | Max Operations | Target |
|------------|----------------|--------|
| 3 | ≤ 3 | ✅ |
| 5 | ≤ 12 | ✅ |
| 100 | < 700 | ✅ |
| 500 | < 5500 | ✅ |

## 📁 Project Structure

```
push_swap/
├── push_swap.c          # Main entry point
├── push_swap.h          # Header file
├── parsing.c            # Argument parsing
├── parsing_utils.c      # Parsing utilities
├── algo.c               # Main sorting algorithm
├── algo_2.c             # Algorithm helpers
├── algo_helpers.c       # Algorithm utility functions
├── instruction_a.c      # Stack A operations (sa, pa, ra, rra)
├── instruction_b.c      # Stack B operations (sb, pb, rb, rrb)
├── helpers.c            # General utility functions
├── Makefile             # Build automation
└── bonus/
    ├── checker.c        # Bonus checker main
    ├── checker.h        # Checker header
    ├── get_next_line.c  # GNL for reading input
    └── ...              # Other bonus files
```

## 🛠️ Algorithm

This project implements the **Chunks Algorithm**:
1. Divide stack A into chunks based on indexed values
2. Push chunks to stack B in a specific order
3. Push back to stack A in sorted order

## 👤 Author

**mjabri** - 1337 Student
