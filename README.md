# RPN-Calc

本项目是一个用 C 语言实现的简易的逆波兰表达式 (_Reverse Polish Notation_) 求值程序.

## 使用方法

```bash
Calc.exe # 进入交互界面
Calc.exe -e <expression> # 计算表达式
Calc.exe -f <filename> # 从文件中批量计算
```

## 项目进度

最开始的版本保留在 [main][0] 分支当中, 在简单了解了一点点编译原理的基础知识后, 进行重构写了当前这个最终版本, 所有预计的功能都已经实现辣.

- 数据结构
  - [x] 功能较为完善的链表 LinkedList
  - [x] 基于链表实现的栈 LinkedStack
  - [x] 通用类型的栈 Stack

- 软件逻辑
  - [x] 词法解析 Lexer
  - [x] 表达式计算 Calculator
  - [x] 简单的错误提示 Exception
  
  [0]: https://github.com/TunkShif/RPN-Calc/tree/main
