#!/bin/bash

# Script to compile and run a C++ program with g++
echo "Compiling C++ program with g++"

# Read user file name
echo "Enter your file name: "
read source_file

# Compile the C++ program
g++ -std=c++11 "$source_file".cpp -o "$source_file".exe

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled binary
  echo "Compilation successful. Running $source_file..."
  ./"$source_file".exe
else
  echo "Compilation failed."
fi
