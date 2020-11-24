cmake_minimum_required(VERSION 3.17)
project(RPN_Calc C)

set(CMAKE_C_STANDARD 99)
add_executable(RPN_Calc main.c Utils.c Utils.h structures/Stack.h structures/Stack.c structures/LinkedList.h structures/LinkedList.c structures/Status.c structures/Status.h Parser.c Parser.h structures/LinkedStack.c structures/LinkedStack.h structures/String.c structures/String.h File.c File.h Calculator.c Calculator.h CLI.c CLI.h Config.c Config.h)