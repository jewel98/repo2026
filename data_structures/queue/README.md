**Implement a Queue Using a Circular Array**

Implement a queue that stores integers using a circular array. A queue follows FIFO (First In, First Out): the first value inserted is the first value removed.

The array has a capacity of 5. Use these variables:

Variable -	Purpose -	Initial value

front	-Index of the first queued element when nonempty-	0

rear	-Index of the last queued element when nonempty-	-1

count	-Number of elements currently in the queue-	0


**Requirements**

Complete the following member functions. Do not modify main().

1. IsEmpty(): Return true if the queue is empty; otherwise, return false.
2. IsFull(): Return true if the queue contains 5 elements; otherwise, return false.
3. Enqueue(int value):
   - If full, throw runtime_error("Queue is full").
   - Advance rear, wrapping around when necessary.
   - Store value and update count.
4. Dequeue():
   - If empty, throw runtime_error("Queue is empty").
   - Save the front value, advance front, and update count.
   - Return the saved value.
5. Peek():
   - If empty, throw runtime_error("Queue is empty").
   - Return the front value without removing it.
6. Display():
   - Print the elements from front to rear on one line.
   - Begin with Queue (front to rear): .
   - Print one space between elements, with no trailing space.
   - End with a newline.
  
     
Use the modulo operator to wrap an index around the array:

index = (index + 1) % CAPACITY;


**Starter code**


#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {
private:
    static const int CAPACITY = 5;
    int items[CAPACITY];

    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    bool IsEmpty() const {
        // TODO: Complete this function.
    }

    bool IsFull() const {
        // TODO: Complete this function.
    }

    void Enqueue(int value) {
        // TODO: Complete this function.
    }

    int Dequeue() {
        // TODO: Complete this function.
    }

    int Peek() const {
        // TODO: Complete this function.
    }

    void Display() const {
        // TODO: Complete this function.
    }
};

// Do not modify main().
int main() {
    Queue q;

    cout << boolalpha;
    cout << "Initially empty: " << q.IsEmpty() << '\n';

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    cout << "Queue full: " << q.IsFull() << '\n';

    try {
        q.Enqueue(60);
    }
    catch (const runtime_error& error) {
        cout << error.what() << '\n';
    }

    cout << "Removed: " << q.Dequeue() << '\n';
    cout << "Removed: " << q.Dequeue() << '\n';

    // Reuse the freed positions at indices 0 and 1.
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display();

    cout << "Front: " << q.Peek() << '\n';

    // Remove all remaining elements.
    while (!q.IsEmpty()) {
        int value = q.Dequeue();
        cout << "Removed: " << value << '\n';
    }

    cout << "Queue empty: " << q.IsEmpty() << '\n';

    try {
        q.Dequeue();
    }
    catch (const runtime_error& error) {
        cout << error.what() << '\n';
    }

    try {
        q.Peek();
    }
    catch (const runtime_error& error) {
        cout << error.what() << '\n';
    }

    // Verify that the queue can be used again after becoming empty.
    q.Enqueue(80);
    q.Enqueue(90);
    q.Display();

    return 0;
}
