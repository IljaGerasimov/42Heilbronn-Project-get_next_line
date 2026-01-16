# get_next_line

A memory-safe, optimized C function that reads a file line by line.

### Implementation Details

The goal of this project is to read from a file descriptor until a newline is found.
A major technical challenge in this assignment is handling **large lines** (e.g., 10MB of text without a newline) efficiently.

**The Standard Approach vs. My Solution:**
Standard implementations often re-allocate memory linearly (adding fixed buffer sizes), which leads to **O(N²)** complexity and CPU timeouts on large files.

To solve this, I implemented **geometric capacity growth** (doubling the buffer size when full). This ensures the function runs with **amortized O(N)** complexity, making it instant even for massive files.

### Key Features

* **Performance:** Optimized buffer management (`cap * 2`) prevents timeouts.
* **Binary Safe:** Uses `memmove` instead of string functions, allowing it to read binary files containing null bytes (`\0`).
* **Memory Safety:** Includes a "nuke" mechanism that cleans up all static memory immediately if a `malloc` fails, ensuring no memory leaks or zombie pointers.
* **Multi-FD Support:** Can read from multiple file descriptors simultaneously (e.g., reading a log file while reading stdin).

### Performance Benchmark

| Metric | Usual Approach (strjoin) | My Implementation |
| :--- | :--- | :--- |
| **Complexity** | O(N²) (Quadratic) | **O(N) (Linear)** |
| **Allocation Strategy** | Linear (+BUFFER_SIZE) | **Geometric (x2)** |
| **10MB Line Test** | Timeout (> 10s) | **< 0.1s** |
| **Binary Files** | Fails on NULL bytes | **Supported** |

### Usage

This is a C library function. To use it, include the header in your C project.

Example: `main.c`

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("get_next_line.c", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Don't forget to free!
    }
    close(fd);
    return (0);
}
```
Define the BUFFER_SIZE flag during compilation:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

### ***Created as part of the 42 Curriculum*** 🌌
