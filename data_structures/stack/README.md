Write a C++ program that implements a stack of integers using a fixed-size array.
The stack capacity is 5 elements. Do not use vector, list, or the C++ stack library.

Use the following class structure:

class ArrayStack {

private:

   int elements[MAX_SIZE];

   int top;



public:

   ArrayStack();

   bool IsEmpty() const;

   bool IsFull() const;

   void Push(int value);

   void Pop();

   void Peek() const;

   void Display() const;

};

**Supported Commands**

**Command**	**Description**

PUSH value	Adds value to the top

POP	Removes and prints the top value

PEEK	Prints the top value without removing it

DISPLAY	Prints the stack from top to bottom


**Output Rules**
A successful PUSH produces no output.

If PUSH is attempted on a full stack, print:
Stack overflow

A successful POP prints:
Popped: value

If POP is attempted on an empty stack, print:
Stack underflow

A successful PEEK prints:
Top: value

If PEEK is attempted on an empty stack, print:
Stack is empty

DISPLAY prints the elements from top to bottom:
Stack: value1 value2 value3

If the stack is empty, print:

Stack: empty


**Input Format**
The first line contains the number of commands, N.

The next N lines contain stack commands.

**Sample Input**
15

PUSH 10

PUSH 20

PUSH 30

PUSH 40

PUSH 50

PUSH 60

PEEK

DISPLAY

POP

POP

DISPLAY

POP

POP

POP

POP

**Sample Output**

Stack overflow

Top: 50

Stack: 50 40 30 20 10

Popped: 50

Popped: 40

Stack: 30 20 10

Popped: 30

Popped: 20

Popped: 10

Stack underflow

**Complexity**

**Operation**	**Time complexity**

Push()	O(1)

Pop()	O(1)

Peek()	O(1)

IsEmpty()	O(1)

IsFull()	O(1)

Display()	O(n)

