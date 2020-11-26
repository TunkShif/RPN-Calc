cmake_minimum_required(VERSION 3.17)
project(RPN_Calc C)

set(CMAKE_C_STANDARD 99)
add_executable(RPN_Calc src/main.c src/Utils.c include/Utils.h include/Stack.h src/Stack.c include/LinkedList.h src/LinkedList.c src/Status.c include/Status.h src/Parser.c include/Parser.h src/LinkedStack.c include/LinkedStack.h src/String.c include/String.h src/File.c include/File.h src/Calculator.c include/Calculator.h src/CLI.c include/CLI.h src/Config.c include/Config.h)