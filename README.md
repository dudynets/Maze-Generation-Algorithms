<a href="https://github.com/dudynets/Maze-Generation-Algorithms">
  <img align="right" src="https://user-images.githubusercontent.com/39008921/191470114-c074b17f-1c88-4af3-b089-1b14418cabf5.png" alt="Oleksandr Dudynets logo" width="128"/>
</a>

# Maze Generation Algorithms

<p>
<img src="https://img.shields.io/github/actions/workflow/status/dudynets/Maze-Generation-Algorithms/.github/workflows/codeql.yml?style=flat-square" alt="GitHub workflow status">
<img src="https://img.shields.io/github/last-commit/dudynets/Maze-Generation-Algorithms?style=flat-square" alt="Last commit">
<img src="https://img.shields.io/github/commit-activity/m/dudynets/Maze-Generation-Algorithms?style=flat-square" alt="Commit activity">
<img src="https://img.shields.io/github/repo-size/dudynets/Maze-Generation-Algorithms?style=flat-square" alt="Repository size">
<img src="https://img.shields.io/tokei/lines/github/dudynets/Maze-Generation-Algorithms?style=flat-square" alt="Lines of code">
</p>

This repository contains C++ implementations of various maze generation algorithms. These algorithms generate random mazes and distribute checkpoints throughout the maze. Additionally, a shortest path that passes through all the checkpoints is generated using the Held-Karp algorithm. The repository provides multiple implementations, including multithreaded and single-threaded versions of the Held-Karp algorithm, as well as a brute force algorithm for solving the maze.

## Table of Contents

- [Showcase](#showcase)
- [Installation](#installation)
- [Contributors](#contributors)
- [License](#license)

## Showcase

![mga](https://github.com/dudynets/Maze-Generation-Algorithms/assets/39008921/eee7c5d2-f0de-4e2f-8cc9-dbb3dbe46b07)

## Installation

To use the MGA library, follow these steps:

1. Clone the repository:

   ```
   git clone https://github.com/dudynets/Maze-Generation-Algorithms.git
   ```

2. Navigate to the repository directory:

   ```
   cd Maze-Generation-Algorithms
   ```

3. Build the project using CMake:

   ```
   cmake -S . -B build
   ```

4. Compile the project:

   ```
   cmake --build build
   ```

5. Run the executable:

   ```
   cd build
   ./mga
   ```

**Note:** Make sure you have the SFML library installed on your system before building the project.

Feel free to explore the codebase and experiment with different options to generate and solve mazes!

## Contributors

This project was made possible thanks to the contributions of the following individuals:

- [Oleksandr Dudynets](https://github.com/dudynets)
- [Yehor Furman](https://github.com/YehorFur)
- [Rostyslav Urdeichuk](https://github.com/Rostyslavkoo)
- [Valya Dudchak](https://github.com/ValyaDudchak)
- [Artur Kushnir](https://github.com/ArturKushnir)

A big thank you to all the contributors for their valuable input and efforts in developing the MGA project!

## License

The Maze Generation Algorithms is released under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use and modify the code according to your needs. See the [LICENSE](LICENSE) file for more details.
