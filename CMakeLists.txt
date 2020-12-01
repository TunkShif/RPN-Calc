cmake_minimum_required(VERSION 3.17)
project(RPN_Calc C)

set(CMAKE_C_STANDARD 99)
add_executable(RPN_Calc source/main.c source/Utils.c include/Utils.h include/Stack.h source/Stack.c include/LinkedList.h source/LinkedList.c source/Status.c include/Status.h source/Parser.c include/Parser.h source/LinkedStack.c include/LinkedStack.h source/String.c include/String.h source/File.c include/File.h source/Calculator.c include/Calculator.h source/CLI.c include/CLI.h)