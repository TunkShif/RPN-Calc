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

## 词法解析

将可能出现的 Token 类型用枚举常量表示出来, 其中 `BASE` 是一个栈底标识符, `NUM` 代表数字, `LPAREN` 和 `RPAREN` 分别代表左右括号, 其余的分别为运算符, 其中又有 `ADD MINUS MUL DIV` 即加减乘除四个二元运算符, `POS NEG SIN COS LOG SQRT` 等一元运算符.

定义一个 Token 结构体, 分别存储 Token 的类型和具体的值, 同时形成一个类似链表的链式结构.

则只需要将输入的字符串形式的表达式先解析为 Token 流, 再对 Token 流进行中缀转后缀的操作得到新的 Token 流, 再直接根据新的 Token 流计算即可.

```c
typedef enum TokenType {
    BASE = 128, NUM, ADD, MINUS, MUL, DIV, POS, NEG,
    SIN, COS, LOG, SQRT, LPAREN, RPAREN
} TokenType;

typedef struct Token {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
    struct Token *next;
} Token;
```

### 实例

比如表达式 `3.14+27*sin(-5)` 将会解析为如下的 Token 流

|   NUM    |  ADD  |  NUM   |  MUL   |   SIN   | LPAREN |  NEG  |  NUM  | RPAREN |
| :------: | :---: | :----: | :----: | :-----: | :----: | :---: | :---: | :----: |
| **3.14** | **+** | **27** | **\*** | **sin** | **(**  | **-** | **5** | **)**  |

转为后缀表达式 `3.14 27 5 NEG sin * +` 后的 Token 流为

|   NUM    |  NUM   |  NUM  |  NEG   |   SIN   |  MUL  |  ADD  |
| :------: | :----: | :---: | :----: | :-----: | :---: | :---: |
| **3.14** | **27** | **5** | **-** | **sin** | **\*** | **+** |

[0]: https://github.com/TunkShif/RPN-Calc/tree/main
