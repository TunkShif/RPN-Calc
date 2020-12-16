cmake_minimum_required(VERSION 3.17)
project(Calc C)

set(CMAKE_C_STANDARD 99)

add_executable(Calc source/main.c source/Calculator.c include/Calculator.h source/Stack.c include/Stack.h source/Lexer.c include/Lexer.h source/LinkedList.c include/LinkedList.h source/LinkedStack.c include/LinkedStack.h)
target_link_libraries(Calc m)