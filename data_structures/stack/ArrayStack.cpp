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
