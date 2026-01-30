# Tree Visualizer

A tool for visualizing the folder structure as a tree.

## Quick Start

1. Clone the repository:

   ```bash
   git clone https://github.com/SaidKamol0612/tree-visualizer.git
   ```

2. Compile the code using Makefile:

   ```bash
   make
   ```

3. Run the program with a specified directory:

   ```bash
   ./tree-visualizer /path/to/directory
   ```

   or To set name to root directory use `-r` flag:

   ```bash
    ./tree-visualizer /path/to/directory -r <root_name>
   ```

    Write output to file use `>` operator:

    ```bash
    ./tree-visualizer /path/to/directory > output.txt
    ```
