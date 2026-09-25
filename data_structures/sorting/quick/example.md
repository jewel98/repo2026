A complete Lomuto partition example using the last element of each subarray as the pivot.

The bracketed result after every partition has this form:

[values ≤ pivot] [pivot] [values > pivot]

**Initial Array**

[32  4  87  10  2  45  11  7]

**Phase 1: Partition the Entire Array**

Subarray: [32  4  87  10  2  45  11  7]

Pivot:                                             7

Scan from left to right:

32 > 7    → no immediate action

4  ≤ 7    → swap 4 and 32


[4  32  87  10  2  45  11  7]


87 > 7    → no immediate action

10 > 7    → no immediate action

2  ≤ 7    → swap 2 and 32


[4  2  87  10  32  45  11  7]


45 > 7    → no immediate action

11 > 7    → no immediate action


Finally, swap the pivot 7 with the first element of the greater-than section, 87:

[4  2  7  10  32  45  11  87]


Bracketed partition:

[4  2]  [7]  [10  32  45  11  87]


The pivot 7 is now in its final position.


**Phase 2: Sort the Left Partition**

Subarray: [4  2]

Pivot:         2

4 > 2 → no immediate action


Swap the pivot 2 with 4:

[2  4]


Bracketed partition:

[]  [2]  [4]

Complete array:

[2  4  7  10  32  45  11  87]


**Phase 3: Sort the Right Partition of 7**


Subarray: [10  32  45  11  87]

Pivot:                         87

Every value is less than 87, so every value remains on the left:

[10  32  45  11]  [87]  []

Complete array remains:

[2  4  7  10  32  45  11  87]


**Phase 4: Sort the Partition Before 87**

Subarray: [10  32  45  11]

Pivot:                    11

Scan the subarray:

10 ≤ 11   → remains on the left

32 > 11   → no immediate action

45 > 11   → no immediate action

Swap the pivot 11 with the first greater element, 32:

[10  11  45  32]

Bracketed partition:

[10]  [11]  [45  32]

Complete array:

[2  4  7  10  11  45  32  87]


**Phase 5: Sort the Final Partition**

Subarray: [45  32]

Pivot:         32

45 > 32 → no immediate action

Swap the pivot 32 with 45:

[32  45]

Bracketed partition:

[]  [32]  [45]


**Final Sorted Array**

[2  4  7  10  11  32  45  87]

Complete Partition Sequence

[32  4  87  10  2  45  11  7]

[4  2] [7] [10  32  45  11  87]

[2] [4] [7] [10  32  45  11] [87]

[2] [4] [7] [10] [11] [45  32] [87]

[2] [4] [7] [10] [11] [32] [45] [87]
