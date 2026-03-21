*This project has been created as part of the 42 curriculum by shrajan.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.
The goal is to sort a list of integers using two stacks (`A` and `B`) and a limited set of stack operations.

The program receives a sequence of integers as arguments and outputs the smallest possible list of operations required to sort them in ascending order.

The project focuses on:

* Algorithm optimization
* Efficient stack manipulation
* Memory management in C
* Writing clean and modular code

Two stacks are used:

* **Stack A** – contains the initial numbers
* **Stack B** – used as auxiliary storage

Allowed operations include swaps, pushes, rotations, and reverse rotations.

The objective is to produce the **least number of operations possible** while sorting the input numbers.

---

## Features

- Handles both quoted and unquoted inputs  
  (`./push_swap "3 2 1"` and `./push_swap 3 2 1`)
- Detects and handles invalid inputs
- Prevents duplicate values
- Optimized sorting for small input sizes (≤ 5 numbers)
- Chunk-based sorting strategy for larger datasets
- Memory-safe implementation (no leaks)

---

## Chunking Strategy

For larger inputs, the program uses a technique called **chunking** to improve efficiency.

Instead of sorting all numbers at once, the list is divided into smaller groups called *chunks*. Each chunk represents a range of values.

### How it works:

1. **Normalize values**
   - All numbers are mapped to their index in the sorted order  
   (e.g., smallest = 0, next = 1, etc.)

2. **Divide into chunks**
   - The range of values is split into fixed-size groups  
   (e.g., 0–15, 16–30, etc.)

3. **Push to stack B**
   - Numbers in the current chunk are pushed from stack A to stack B  
   - Smaller values are rotated in stack B to keep them deeper in the stack

4. **Repeat**
   - Continue until all elements are moved to stack B

5. **Rebuild sorted stack**
   - The largest values are pushed back from stack B to stack A  
   - Before pushing, stack B is rotated to bring the maximum value to the top

### Why this works:

- Reduces the number of operations compared to naive sorting
- Keeps stack B partially organized
- Makes it faster to rebuild stack A in sorted order

---

## Instructions

### Compilation

Clone the repository and compile the program using `make`:

```bash
git clone https://github.com/<your_login>/push_swap.git
cd push_swap
make
```

This will generate the executable:

```
push_swap
```

---

### Usage

Run the program with integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

Example output:

```
pb
pb
sa
pa
pa
```

Each line corresponds to a stack operation performed to sort the numbers.

---

### Allowed Operations

| Operation | Description                        |
| --------- | ---------------------------------- |
| sa        | swap first two elements of stack A |
| sb        | swap first two elements of stack B |
| ss        | sa and sb simultaneously           |
| pa        | push from B to A                   |
| pb        | push from A to B                   |
| ra        | rotate stack A                     |
| rb        | rotate stack B                     |
| rr        | ra and rb simultaneously           |
| rra       | reverse rotate A                   |
| rrb       | reverse rotate B                   |
| rrr       | rra and rrb simultaneously         |

---



## Resources

The following resources were used to understand the concepts behind this project:

* 42 Project Subject (push_swap)
* Stack data structure documentation
* Sorting algorithm references
* Algorithm optimization techniques

Useful references:

* https://en.wikipedia.org/wiki/Sorting_algorithm
* https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
* https://visualgo.net/en/sorting

---

## Use of AI

Artificial Intelligence tools were used during this project for the following tasks:

* Explaining sorting algorithms and stack operations
* Understanding optimization strategies for small input sizes
* Reviewing and improving code structure
* Debugging logic and edge cases

AI assistance was used **as a learning aid**, while all code implementation and final decisions were made by the author.

---
