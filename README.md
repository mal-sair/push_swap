*This project has been created as part of the 42 curriculum.*

# Push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations.

## Description

Push_swap is a 42 school project that challenges you to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, while minimizing the number of operations used.

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack a |
| `sb` | Swap the first 2 elements at the top of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element from b and put it on top of a |
| `pb` | Take the first element from a and put it on top of b |
| `ra` | Rotate stack a upwards (first element becomes last) |
| `rb` | Rotate stack b upwards (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last element becomes first) |
| `rrb` | Reverse rotate stack b (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Compilation

```bash
# Compile the main program
make

# Compile the bonus checker
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## Usage

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Check if the operations sort correctly
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Count the number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

## Algorithm

The project uses different sorting strategies based on the input size:
- **2 elements**: Simple swap if needed
- **3 elements**: Optimized hardcoded solution
- **4-5 elements**: Push minimum elements to stack b, sort remaining 3
- **6+ elements**: Radix sort using binary representation of indices

## Error Handling

The program displays "Error" on stderr for:
- Non-integer arguments
- Integer overflow/underflow
- Duplicate values

## Performance

| Input Size | Operations |
|------------|------------|
| 100 numbers | ~1100 |
| 500 numbers | ~6800 |

## Bonus: Checker

The checker program reads operations from stdin and verifies if they correctly sort the stack:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK (if sorted) or KO (if not sorted)
```

## Files

- `push_swap.c` - Main program and sorting algorithm
- `checker.c` - Bonus checker program
- `parsing.c` - Argument parsing and validation
- `utils.c` - Utility functions
- `stack_op.c` - Stack operations
- `operations_*.c` - Push_swap operations (swap, push, rotate, reverse rotate)
- `push_swap.h` - Header file

## Author

mal-sair - 42 student
