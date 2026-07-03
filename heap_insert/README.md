# Heap Insert

Insert a value into a Max Binary Heap.

## Data structures

Please use the following data structures and types for binary trees.

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Max Binary Heap

```c
typedef struct binary_tree_s heap_t;
```

## Tasks

### 0. New node

Write a function that creates a binary tree node:

- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- `parent` is a pointer to the parent node of the node to create
- `value` is the value to put in the new node
- When created, a node does not have any children
- Your function must return a pointer to the new node, or `NULL` on failure

**File:** [0-binary_tree_node.c](./0-binary_tree_node.c)

#### Example

```console
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```

## Files

| File                    | Description                              |
| ----------------------- | ----------------------------------------- |
| `binary_trees.h`        | Header file with data structures & prototypes |
| `0-binary_tree_node.c`  | Creates a binary tree node                |
| `binary_tree_print.c`   | Helper used only to visualise a tree (not required for correction) |
| `0-main.c`              | Example test program (not required for correction) |

## Compilation

All files are compiled on Ubuntu 14.04 LTS with `gcc 4.8.4`, using the flags
`-Wall -Wextra -Werror -pedantic`, and follow the Betty coding style.

```sh
gcc -Wall -Wextra -Werror -pedantic *.c -o 0-node
```

## Author

Holberton School - Interview preparation project.
