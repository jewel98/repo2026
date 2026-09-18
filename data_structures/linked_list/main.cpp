int main() {
    LinkedList list;

    // Part 1: Add four numbers
    list.InsertEnd(10);
    list.InsertEnd(20);
    list.InsertEnd(30);
    list.InsertEnd(40);

    // Part 2: Print the list
    cout << "After building the list:" << endl;
    list.PrintList();

    // Part 3: Insert 25 at position 2
    list.InsertAt(25, 2);
    cout << "After inserting 25 at position 2:" << endl;
    list.PrintList();

    // Part 4: Remove the element at position 3 (should be 30)
    list.RemoveAt(3);
    cout << "After removing element at position 3:" << endl;
    list.PrintList();

    return 0;
}
