Learning Objectives
By completing this lab, you will practice:

Defining a Node struct and a LinkedList class
Inserting elements at the end of a list (building it up)
Traversing and printing a linked list
Inserting an element at a specific position
Removing an element from a specific position
Background
A singly linked list is a sequence of nodes where each node stores a value and a pointer to the next node. Unlike an array, a linked list doesn't need contiguous memory, and insertions/removals don't require shifting elements — just pointer updates.



head -> [10] -> [20] -> [30] -> [40] -> nullptr
Part 1: Build the list (Add four numbers)
Task: Create a LinkedList class with an insertEnd(int value) method. Use it to add the numbers 10, 20, 30, 40 to the list, in that order.

Expected internal state after this step:

10 -> 20 -> 30 -> 40

Part 2: Print the list
Task: Write a printList() method that traverses the list from head to the last node and prints each value separated by " -> ", ending with "NULL".

Expected output:

10 -> 20 -> 30 -> 40 -> NULL

Part 3: Insert an element
Task: Write a method insertAt(int value, int position) that inserts value at the given position. Use it to insert 25 at position 2 (i.e., between 20 and 30).

Expected output after insertion:

10 -> 20 -> 25 -> 30 -> 40 -> NULL

Part 4: Remove an element
Task: Write a method removeAt(int position) that removes the node at the given position. Use it to remove the element at position 3 (which should be 30 after Part 3).

Expected output after removal:

10 -> 20 -> 25 -> 40 -> NULL

Deliverable
Submit a program that:

Builds the list with 10, 20, 30, 40
Prints it
Inserts 25 at position 2, prints again
Removes the element at position 3, prints again
Output:

After building the list:

10 -> 20 -> 30 -> 40 -> NULL

After inserting 25 at position 2:

10 -> 20 -> 25 -> 30 -> 40 -> NULL

After removing element at position 3:

10 -> 20 -> 25 -> 40 -> NULL
