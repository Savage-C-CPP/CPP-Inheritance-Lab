<h1 align="center">
    VSCode C/C++ + Cmake project bootstrap
</h1>

# Requirements
- [CMake](https://cmake.org/download/)
- [CMake tools for VSCode](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [C/C++ tools for VSCode](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- Compilers and debuggers
  - Visual Studio (To run its build tools and debugger) on windows, or MinGW or...
  - GCC / Clang or whatever cmake can be configured and work with

# Step by step

1. Open the project in code
2. In command palette run `>cmake:configure`
  - Choose a kit (`Visual Studio Community 2019 Release` for Windows)
3. Build target with `>cmake:build`
4. Debug and Run with `>cmake:debug` or `>cmake:Run without debugging`

Look at the bottoms statusbar and learn
