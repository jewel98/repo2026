**Learning Objectives**

**Implement insertion sort in C++.**

Sort an array/vector in ascending order.

Count element comparisons and shifts.

Observe how the initial order affects insertion-sort performance.


**Counting Rules**
**Comparison**

Increment comparisons each time the algorithm compares:

numbers[j] > key

Count only element-to-key comparisons. 

A convenient structure is:


while (j >= 0) {
    ++comparisons;

    if (numbers.at(j) <= key) {
        break;
    }

    // Shift the element
}

**Shift**

Increment shifts each time a larger element is copied one position to the right:

numbers[j + 1] = numbers.at(j);


**Input**

The input contains:

An integer n, representing the number of elements.

n integers to be sorted.

**Constraints**

1 <= n <= 1000

The values may include negative numbers and duplicates.

**Output**

Display the sorted values on one line, separated by single spaces. Then display the number of comparisons and shifts:

Sorted: value1 value2 value3 ...

Comparisons: count

Shifts: count


**Example 1**
Input

5

32 4 87 10 2

Output

Sorted: 2 4 10 32 87

Comparisons: 9

Shifts: 7


**Example 2: Already Sorted**

Input

5

1 2 3 4 5

Output

Sorted: 1 2 3 4 5

Comparisons: 4

Shifts: 0


**Example 3: Reverse Order**

Input

5

5 4 3 2 1

Output

Sorted: 1 2 3 4 5

Comparisons: 10

Shifts: 10


**Restrictions**

Do not use sort(), stable_sort(), or another library sorting function.

Do not use selection sort, bubble sort, or another sorting algorithm.
