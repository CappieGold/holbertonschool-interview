# Algorithms

## Project 1 : Sandpiles

### Description
**Sandpiles** are a mathematical model used to demonstrate how small changes in a system can lead to cascading events or avalanches. In this project, we represent the sandpile as a two-dimensional grid (commonly 3×3) where each cell contains a certain number of sand grains.

- A cell is **stable** when it has at most 3 grains.  
- If a cell has 4 or more grains, it **topples**:
  - The cell loses 4 grains.
  - Each of its orthogonal neighbors (up, down, left, right) gains 1 grain.
- This can lead to a **chain reaction**: if a neighbor now exceeds 3 grains, it topples in turn, and so forth until the entire grid becomes stable.

The objective is to implement functions that:
1. **Add** two sandpile grids.
2. **Stabilize** the resulting grid so that no cell has more than 3 grains.

From a coding standpoint, sandpiles provide an interesting challenge involving:
- 2D array manipulation,
- Iterative or recursive toppling behavior,
- Ensuring termination conditions to reach a stable state.

All code here is compiled with `-Wall -Werror -Wextra -pedantic` to ensure clean, strict C code, and it follows the **Betty** style guidelines.
