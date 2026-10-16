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

