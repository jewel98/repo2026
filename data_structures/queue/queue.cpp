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
