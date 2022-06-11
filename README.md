# Quaternion-module in C++

A module that defines the type of quaternions and arithmetic operators on these quaternions.
The operation that the Quaternion class support are the following:
- Sum: as a binary infix operator with the symbol +, capable of operate with other quaternions and float or int numbers
- Conjugate: as a unary prefix operator with the symbol ~
- Multiplication: as a binary infix operator with the symbol *, capable of operate with other quaternions and float or int numbers
- Norm: as a unary prefix operator with the symbol &

The module has integrated unit tests, to run the test is necesary gtest from the Google Test suit and cmake, use cmake to create the make file a compile the test file using make and then run the program to see the test.

The module can be used in the main file, to see the operations supported, compile this main with the Quaternion module with g++ compiler
