# 🪖 PUSH_SWAP — TURK ALGORITHM ROADMAP
### 42 School Project | Military-Grade Execution Plan

---

> **MISSION BRIEF:** Master the Turk Algorithm and deliver a fully functional, norm-compliant `push_swap` project.
> **TOTAL DURATION:** 21 Days
> **COMMITMENT:** 3–5 hours/day minimum
> **NO EXCUSES. NO SKIPPING. EXECUTE.**

---

## 📋 TABLE OF CONTENTS

1. [Project Overview](#project-overview)
2. [Phase 1 — Intelligence Gathering (Days 1–3)](#phase-1)
3. [Phase 2 — Training Camp (Days 4–7)](#phase-2)
4. [Phase 3 — Algorithm Implementation (Days 8–14)](#phase-3)
5. [Phase 4 — Optimization & Testing (Days 15–18)](#phase-4)
6. [Phase 5 — Final Push (Days 19–21)](#phase-5)
7. [Checkpoints & Progress Tracker](#checkpoints)
8. [Resources](#resources)

---

## 🎯 PROJECT OVERVIEW

### What is push_swap?
Sort a stack of integers using two stacks (`a` and `b`) with a limited set of operations. The goal is to sort with the **minimum number of moves**.

### Available Operations
| Operation | Description |
|-----------|-------------|
| `sa` | Swap top 2 elements of stack a |
| `sb` | Swap top 2 elements of stack b |
| `ss` | `sa` + `sb` simultaneously |
| `pa` | Push top of b to a |
| `pb` | Push top of a to b |
| `ra` | Rotate a upward (top goes to bottom) |
| `rb` | Rotate b upward |
| `rr` | `ra` + `rb` simultaneously |
| `rra` | Reverse rotate a (bottom goes to top) |
| `rrb` | Reverse rotate b |
| `rrr` | `rra` + `rrb` simultaneously |

### What is the Turk Algorithm?
A greedy algorithm developed by a 42 student. It pushes all elements to stack `b` strategically, then pulls them back to `a` in sorted order — optimizing every push/pull with the cheapest rotation cost.

### Scoring Targets (5 stack)
| Stack Size | Max Moves (Full Score) |
|------------|------------------------|
| 3 numbers | ≤ 3 |
| 5 numbers | ≤ 12 |
| 100 numbers | ≤ 700 |
| 500 numbers | ≤ 5500 |

---

## PHASE 1 — INTELLIGENCE GATHERING (Days 1–3) {#phase-1}
> **Objective:** Understand the project completely before writing a single line of code.

---

### 📅 DAY 1 — Brief & Rules
**Time:** 3 hours

**Tasks:**
- [ ] Read the subject PDF top to bottom. Twice.
- [ ] Understand what is allowed and what is not (norm, no global variables, memory leaks = 0)
- [ ] Set up your project directory and git repo
- [ ] Create your `Makefile` skeleton (just rules, no code yet)
- [ ] Create files: `push_swap.c`, `push_swap.h`, `operations/`

**End of Day Check:**
> Can you explain push_swap to someone in 2 minutes without notes? ✅ / ❌

---

### 📅 DAY 2 — Understand Stacks & Operations
**Time:** 4 hours

**Tasks:**
- [ ] Code your stack data structure (linked list recommended)
- [ ] Implement ALL 11 operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)
- [ ] Test each operation manually in a `main()` — print the stack after each operation
- [ ] Implement error handling: duplicate numbers, non-integer inputs, overflow

**Compile & Test:**
```bash
gcc -Wall -Wextra -Werror *.c && ./a.out "3 1 2"
```

**End of Day Check:**
> All 11 operations work without memory leaks (run `valgrind`)? ✅ / ❌

---

### 📅 DAY 3 — Study the Turk Algorithm (Theory Day)
**Time:** 4 hours

**Tasks:**
- [ ] Read at least 3 articles/repos about Turk Algorithm (see resources below)
- [ ] Draw the algorithm on paper — step by step
- [ ] Understand the concept of **"cheapest move"** (cost calculation)
- [ ] Understand index normalization
- [ ] Watch at least 1 YouTube video visualizing push_swap

**Algorithm Core Concept (write this in your notes):**
```
TURK OVERVIEW:
1. Handle edge cases (sorted, 2, 3 elements)
2. Push all elements from a to b EXCEPT last 3 in a
3. Sort the 3 remaining in a
4. For each element in b:
   - Find its "target" in a (where it fits)
   - Calculate cost to bring it to top of b
   - Calculate cost to bring target to top of a
   - Combine costs using rr/rrr when possible
5. Execute cheapest move
6. Push from b to a
7. Rotate a until min is on top
```

**End of Day Check:**
> Can you explain the Turk algorithm step by step without reading notes? ✅ / ❌

---

## PHASE 2 — TRAINING CAMP (Days 4–7) {#phase-2}
> **Objective:** Build all utility functions and foundations before the main algorithm.

---

### 📅 DAY 4 — Index Normalization & Utility Functions
**Time:** 4 hours

**Why normalize?** Instead of working with raw values (e.g., -450, 3, 999), assign each element an index (0, 1, 2...) based on sorted position. This simplifies cost calculations enormously.

**Tasks:**
- [ ] Implement `normalize()` — assigns index to each node based on sorted rank
- [ ] Implement `find_min()` and `find_max()` on a stack
- [ ] Implement `stack_size()` — count nodes
- [ ] Implement `is_sorted()` — check if stack a is sorted ascending
- [ ] Implement a debug print function (you'll thank yourself later)

**End of Day Check:**
> Does `normalize()` correctly assign ranks to a shuffled list? ✅ / ❌

---

### 📅 DAY 5 — Sort 2 & Sort 3
**Time:** 3 hours

**Tasks:**
- [ ] Implement `sort_two()` — only needs `sa` at most
- [ ] Implement `sort_three()` — at most 3 operations, 6 possible cases
- [ ] Test `sort_three()` exhaustively on ALL possible 3-element permutations

**Sort 3 Cases:**
```
[1,2,3] → already sorted
[1,3,2] → sb
[2,1,3] → sa
[2,3,1] → rra → sa  OR  ra → ra → sa
[3,1,2] → ra
[3,2,1] → sa → ra  OR  rra → rra → sa
```

**End of Day Check:**
> `sort_three()` handles all 6 cases correctly in ≤ 3 moves? ✅ / ❌

---

### 📅 DAY 6 — Cost Calculation (Core of Turk)
**Time:** 5 hours
> This is the hardest conceptual part. Take your time.

**The Cost Formula:**

For each node in `b`, you need to calculate:
1. **Cost to bring node to top of b** → either `rb` (rotate) or `rrb` (reverse rotate)
2. **Cost to bring its target in `a` to top of a** → either `ra` or `rra`
3. **Total cost** = combine them (use `rr` or `rrr` if both rotate the same direction)

```
If both need forward rotation:
  total_cost = max(cost_b, cost_a)  ← they run simultaneously with rr

If both need reverse rotation:
  total_cost = max(cost_b, cost_a)  ← they run simultaneously with rrr

If directions differ:
  total_cost = cost_b + cost_a  ← must be done separately
```

**Tasks:**
- [ ] Implement `find_target_in_a(node_b, stack_a)` — finds where node_b should be inserted in a
- [ ] Implement `calculate_cost(node_b, stack_a, stack_b)` — fills cost fields for a node
- [ ] Implement `calculate_all_costs(stack_a, stack_b)` — iterates all b nodes
- [ ] Implement `find_cheapest(stack_b)` — returns node with lowest total cost

**End of Day Check:**
> Does `find_cheapest()` correctly identify the least-cost move? ✅ / ❌

---

### 📅 DAY 7 — Execute the Move
**Time:** 4 hours

**Tasks:**
- [ ] Implement `execute_move(cheapest, stack_a, stack_b)`:
  - Rotate a and b simultaneously where possible
  - Then handle remaining individual rotations
  - Push from b to a with `pa`
- [ ] Implement `rotate_a_to_min()` — at the end, rotate a so min is on top

**End of Day Check:**
> Does `execute_move()` work without crashing on edge cases? ✅ / ❌

---

## PHASE 3 — ALGORITHM IMPLEMENTATION (Days 8–14) {#phase-3}
> **Objective:** Bring it all together into a working push_swap.

---

### 📅 DAY 8 — Main Algorithm Structure
**Time:** 4 hours

**Tasks:**
- [ ] Write `push_swap()` main function:
```c
void push_swap(t_stack **a, t_stack **b)
{
    if (is_sorted(*a))
        return ;
    if (stack_size(*a) == 2)
        sort_two(a);
    else if (stack_size(*a) == 3)
        sort_three(a);
    else
        turk_sort(a, b);
}
```
- [ ] Write `turk_sort()`:
```c
void turk_sort(t_stack **a, t_stack **b)
{
    // Push all but 3 to b
    while (stack_size(*a) > 3)
        pb(a, b);
    sort_three(a);
    // Pull back one by one
    while (*b)
    {
        calculate_all_costs(*a, *b);
        execute_move(find_cheapest(*b), a, b);
    }
    // Rotate min to top
    rotate_a_to_min(a);
}
```
- [ ] Compile and run basic test

**End of Day Check:**
> Does the program sort 5 numbers consistently in ≤ 12 moves? ✅ / ❌

---

### 📅 DAY 9 — Bug Hunt Day
**Time:** 5 hours

**Tasks:**
- [ ] Run 1000 random tests with a bash script:
```bash
#!/bin/bash
for i in $(seq 1 1000); do
    ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')")
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    if [ "$RESULT" != "OK" ]; then
        echo "FAILED: $ARG"
    fi
done
echo "Done"
```
- [ ] Fix ALL bugs found
- [ ] Test edge cases: already sorted, reverse sorted, one element, two elements

**End of Day Check:**
> 1000/1000 tests pass for small stacks? ✅ / ❌

---

### 📅 DAY 10 — Scale to 100 Numbers
**Time:** 4 hours

**Tasks:**
- [ ] Test with 100 random numbers
- [ ] Check your move count — aim for ≤ 700
- [ ] Profile which step is most expensive
- [ ] Fix any crashes or infinite loops

```bash
ARG=$(python3 -c "import random; l=list(range(-50,50)); random.shuffle(l); print(*l)")
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
```

**End of Day Check:**
> Average move count for 100 elements is ≤ 700? ✅ / ❌

---

### 📅 DAY 11 — Scale to 500 Numbers
**Time:** 4 hours

**Tasks:**
- [ ] Test with 500 random numbers
- [ ] Check your move count — aim for ≤ 5500
- [ ] Run 100 tests, log min/max/average moves

```bash
#!/bin/bash
TOTAL=0
for i in $(seq 1 100); do
    ARG=$(python3 -c "import random; l=list(range(-250,250)); random.shuffle(l); print(*l)")
    COUNT=$(./push_swap $ARG | wc -l)
    TOTAL=$((TOTAL + COUNT))
    echo "Test $i: $COUNT moves"
done
echo "Average: $((TOTAL / 100))"
```

**End of Day Check:**
> Average move count for 500 elements is ≤ 5500? ✅ / ❌

---

### 📅 DAY 12 — Norm Compliance
**Time:** 4 hours

> The cleanest algorithm fails if it breaks the norm.

**Tasks:**
- [ ] Run `norminette` on every `.c` and `.h` file
- [ ] Fix ALL norm errors (max 25 lines per function, max 5 functions per file, etc.)
- [ ] Ensure no global variables
- [ ] Ensure all functions are declared in the header

**End of Day Check:**
> `norminette *.c *.h` returns zero errors? ✅ / ❌

---

### 📅 DAY 13 — Memory Leak Check
**Time:** 4 hours

**Tasks:**
- [ ] Run `valgrind --leak-check=full ./push_swap "3 1 2"`
- [ ] Run valgrind on edge cases: empty input, one number, error inputs
- [ ] Free all memory at exit AND on error
- [ ] Check that error cases print `Error\n` to stderr and exit cleanly

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap "5 3 1 4 2"
```

**End of Day Check:**
> Zero memory leaks on all test cases? ✅ / ❌

---

### 📅 DAY 14 — Buffer Day (Catch Up / Polish)
**Time:** 4 hours

**This day belongs to whatever is not done. No new features. Only fixing.**

- [ ] Re-run all tests from Days 9–13
- [ ] Polish error messages
- [ ] Ensure Makefile has: `all`, `clean`, `fclean`, `re`
- [ ] Ensure `make` compiles with `-Wall -Wextra -Werror` with no warnings

**End of Day Check:**
> Project compiles clean, sorts correctly, no leaks, no norm errors? ✅ / ❌

---

## PHASE 4 — OPTIMIZATION & TESTING (Days 15–18) {#phase-4}
> **Objective:** Get every point possible. Squeeze out moves. Harden against edge cases.

---

### 📅 DAY 15 — Optimize: Smart Push to B
**Time:** 4 hours

Instead of blindly pushing everything to b, push strategically — push elements that are closest to their target position in b first (descending chunks). This reduces total cost significantly.

**Tasks:**
- [ ] Research "chunk-based push to b" optimization
- [ ] Implement or tweak push order to b to target descending sorted placement
- [ ] Re-benchmark 100 and 500 tests

**End of Day Check:**
> Move count improvement visible vs. Day 11 results? ✅ / ❌

---

### 📅 DAY 16 — Stress Test Suite
**Time:** 4 hours

Build a proper test harness:

```bash
#!/bin/bash
echo "=== Testing 3 numbers ==="
for i in $(seq 1 500); do
    ARG=$(python3 -c "import random; l=list(range(1,4)); random.shuffle(l); print(*l)")
    R=$(./push_swap $ARG | ./checker_linux $ARG)
    [ "$R" != "OK" ] && echo "FAIL: $ARG"
done

echo "=== Testing 5 numbers ==="
for i in $(seq 1 500); do
    ARG=$(python3 -c "import random; l=list(range(1,6)); random.shuffle(l); print(*l)")
    MOVES=$(./push_swap $ARG | wc -l)
    R=$(./push_swap $ARG | ./checker_linux $ARG)
    [ "$R" != "OK" ] && echo "FAIL: $ARG"
    [ "$MOVES" -gt 12 ] && echo "TOO MANY MOVES ($MOVES): $ARG"
done

echo "=== All done ==="
```

**Tasks:**
- [ ] Run full stress test suite
- [ ] Fix any failures

**End of Day Check:**
> 100% pass rate across all stack sizes? ✅ / ❌

---

### 📅 DAY 17 — Edge Cases & Error Handling
**Time:** 3 hours

**Test every edge case:**
```bash
./push_swap ""              # → Error
./push_swap                 # → (no output, no crash)
./push_swap "1"             # → (no output, already sorted)
./push_swap "1 1"           # → Error (duplicate)
./push_swap "2147483648"    # → Error (overflow)
./push_swap "abc"           # → Error
./push_swap "1 2 3"         # → (no output, already sorted)
./push_swap "3 2 1"         # → valid output
```

**Tasks:**
- [ ] Verify all above cases behave correctly
- [ ] Ensure `Error` goes to `stderr` (fd 2), not stdout

**End of Day Check:**
> All edge cases handled correctly? ✅ / ❌

---

### 📅 DAY 18 — Peer Review Simulation
**Time:** 4 hours

> Treat this like a real defense.

**Tasks:**
- [ ] Ask a peer (or yourself) to test your binary with random inputs
- [ ] Explain your algorithm out loud — can you defend every design choice?
- [ ] Re-read the subject — did you miss anything?
- [ ] Check bonus: do you need to implement `checker`? If yes — start today.

**End of Day Check:**
> Ready to hand this to a peer evaluator right now? ✅ / ❌

---

## PHASE 5 — FINAL PUSH (Days 19–21) {#phase-5}
> **Objective:** Clean, submit, defend.

---

### 📅 DAY 19 — Bonus: checker (if required)
**Time:** 4 hours

The `checker` program reads operations from stdin and verifies if the stack ends up sorted.

```c
// checker reads ops line by line and applies them
// at the end: if sorted → "OK", else → "KO"
```

**Tasks:**
- [ ] Implement `checker` binary
- [ ] Test: `./push_swap "3 1 2" | ./checker "3 1 2"` → OK

---

### 📅 DAY 20 — Final Clean Pass
**Time:** 3 hours

**Tasks:**
- [ ] `norminette` → zero errors
- [ ] `valgrind` → zero leaks
- [ ] `make` → zero warnings
- [ ] `make fclean && make` → clean rebuild
- [ ] Git: meaningful commit messages, clean history
- [ ] Remove all debug prints and `printf` left in code

**End of Day Check:**
> Submitted to the repo? ✅ / ❌

---

### 📅 DAY 21 — Defense Prep
**Time:** 2 hours

**Study these questions:**
- How does the Turk algorithm work?
- Why did you choose a linked list over an array?
- What is the time complexity of your solution?
- What happens with duplicate numbers?
- How do you handle integer overflow?
- What is index normalization and why is it needed?
- What is your worst-case move count for 500 numbers?

**You are ready. Submit. Defend. Pass.**

---

## ✅ CHECKPOINTS & PROGRESS TRACKER {#checkpoints}

```
PHASE 1 — INTELLIGENCE GATHERING
[ ] Day 1:  Project setup, git repo, Makefile skeleton
[ ] Day 2:  All 11 operations working, error handling
[ ] Day 3:  Turk algorithm understood (theory)

PHASE 2 — TRAINING CAMP
[ ] Day 4:  Normalization + utility functions
[ ] Day 5:  sort_two() and sort_three() working
[ ] Day 6:  Cost calculation implemented
[ ] Day 7:  execute_move() and rotate_to_min()

PHASE 3 — ALGORITHM IMPLEMENTATION
[ ] Day 8:  Full turk_sort() working on small inputs
[ ] Day 9:  1000 tests passing on small stacks
[ ] Day 10: 100-element sort ≤ 700 moves ✓
[ ] Day 11: 500-element sort ≤ 5500 moves ✓
[ ] Day 12: Norminette → 0 errors
[ ] Day 13: Valgrind → 0 leaks
[ ] Day 14: Full integration — all green

PHASE 4 — OPTIMIZATION & TESTING
[ ] Day 15: Move count optimized
[ ] Day 16: Stress test suite passing
[ ] Day 17: All edge cases handled
[ ] Day 18: Peer review simulation passed

PHASE 5 — FINAL PUSH
[ ] Day 19: Bonus checker implemented (if needed)
[ ] Day 20: Final clean pass — submitted to repo
[ ] Day 21: Defense prepared
```

---

## 📚 RESOURCES {#resources}

### Turk Algorithm References
- [Medium — Turk Algorithm Explained (Jamie Dawson)](https://medium.com/@jamierobertdawson/push-swap-the-least-number-of-moves-with-two-stacks-d1e76a71789a)
- [42 Docs Push Swap Visualization](https://github.com/o-reo/push_swap_visualizer)
- [Push Swap Visualizer](https://github.com/p-baleine/push-swap-visualizer)

### Tools
```bash
# Get the official checker binaries from your 42 intra or use:
# https://github.com/gemartin99/Push-Swap-Tester
# https://github.com/LeoFu9487/push_swap_tester

# Quick test one-liner (Linux):
ARG="3 1 4 1 5 9 2 6"; ./push_swap $ARG | ./checker_linux $ARG
```

### Useful Commands
```bash
# Count moves
./push_swap "3 2 1 5 4" | wc -l

# Verify correctness
./push_swap "3 2 1 5 4" | ./checker_linux "3 2 1 5 4"

# Norminette check
norminette *.c *.h

# Memory check
valgrind --leak-check=full ./push_swap "5 3 1 4 2"

# Batch test 100 numbers (requires python3)
for i in $(seq 1 20); do
  ARG=$(python3 -c "import random; l=list(range(-50,50)); random.shuffle(l); print(*l)")
  echo "Moves: $(./push_swap $ARG | wc -l) | $(./push_swap $ARG | ./checker_linux $ARG)"
done
```

---

## 🪖 RULES OF ENGAGEMENT

1. **No skipping days.** If you fall behind, add extra hours the next day.
2. **Commit every day.** Even small progress. Your git history should reflect daily work.
3. **Test before moving forward.** Never build on broken foundation.
4. **Read the error messages.** They tell you exactly what's wrong.
5. **Ask peers, not ChatGPT, for code.** Understand every line you write.
6. **The algorithm is not magic.** It's just math. Break it into pieces.

---

*Good luck, soldier. The stack will be sorted.* 🫡