# RPN-Calc

本项目是一个用 C 语言实现的简易的逆波兰表达式 (_Reverse Polish Notation_) 求值程序.

## 项目进度

- 数据结构
  - [x] 功能较为完善的链表 LinkedList
  - [x] 基于链表实现的栈 LinkedStack
  - [x] 自定义的字符串类型 String
- 软件逻辑
  - [x] 工具函数 Utils
  - [ ] 文件读写操作 Files
  - [x] 表达式解析 Parser (有待完善)
  - [x] 表达式计算 Calculator (有待完善)

## Bugs

- 不能解析表达式中的负数
- 表达式稍微复杂一点内存莫名其妙地会爆 =_=||

<details>
<summary>点击查看以往内容</summary>

## 前言

### 需要的知识储备

<details>
<summary>点击展开内容</summary>

#### C 语言

- 所有 C 语言的基础知识
- 熟练使用指针和结构体
- 动态内存分配管理
- 文件流的读写操作
- 宏的使用
  - 定义常量
  - 包括其他头文件
  - 条件编译

#### 其他

- 熟悉 `stack` 和 `linked list` 两种数据类型及其实现
- 了解逆波兰表示法
- 遵守约定的代码规范

</details>

### 参考资料

<details>
<summary>点击展开内容</summary>

- 一本靠谱的 C 语言教材
- [菜鸟教程 - C 语言][c-tutorial]

</details>

---

### 栈和链表

完成本程序设计需要自己实现简易的栈和链表这两种数据结构, 可以自己在网上查找资料学习, 也可以参考我自己写的笔记.

- [简易的栈的实现](https://tunkshif.one/posts/c-learning-notes-advance-data-representation/#%E6%A0%88-stack)
- [简易的链表的实现](https://tunkshif.one/posts/c-learning-notes-advance-data-representation/#%E9%93%BE%E8%A1%A8-linked-list) (咕咕咕, 还在写)

### 什么是逆波兰表达式

#### 波兰表示法

[波兰表示法][wikipedia-pn] (_Polish Notation_), 是一种用来标记算术表达式的方法, 其特点是将运算操作符置于被运算的数的前面, 例如数学中的 `3 + 4` 用波兰表示法表示为 `+ 3 4`, 因此该表示法又叫做前缀表示法, 而数学中的常见表达方法可以叫做中缀表达式. 其好处是在被运算数的个数是有限个的时候, 可以不使用括号而不产生歧义.

#### 逆波兰表示法

[逆波兰表示法][wikipedia-rpn] (_Reverse Polish Notation_), 其特点是将运算操作符置于被运算的数的后面, 因此可以叫做后缀表达式. 此种表示法便于我们使用栈来实现表达式求值.

##### 示例

|  中缀表达式   | 后缀表达式  |
| :-----------: | :---------: |
|    `3 + 4`    |   `3 4 +`   |
|  `3 - 4 * 5`  | `3 4 5 * -` |
| `(3 - 4) * 5` | `3 4 - 5 *` |

---

## 分工

- 链表和栈的实现: 实现两种数据结构
- 词法分析: 将所输入的字符串中的数字和运算符提取出来并转化成逆波兰式, 将数字字符串转换成相应的数
- 表达式计算: 根据已经转换好的逆波兰式计算求值
- 文件读写: 从文本文件中读取表达式并求值
- 交互设计: 实现三种方式:
  - 运行程序后连续多次输入表达式求值
  - 使用命令行传参单次运行
  - 从文本文件中输入表达式进行批量计算
- 数据测试: 给出大量正确或错误的数据进行测试, 观察程序是否按照预期运行
- 后续优化:
  - 支持三角函数等常用数学函数
  - 实现通用栈
  - 基于链表实现栈

</details>

[wikipedia-pn]: https://zh.wikipedia.org/wiki/%E6%B3%A2%E5%85%B0%E8%A1%A8%E7%A4%BA%E6%B3%95
[wikipedia-rpn]: https://zh.wikipedia.org/wiki/%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E7%A4%BA%E6%B3%95
[my-note]: https://tunkshif.one/posts/c-learning-notes-advance-data-representation/
[c-tutorial]: https://www.runoob.com/cprogramming/c-tutorial.html
[zhihu-stack]: https://zhuanlan.zhihu.com/p/164529705
