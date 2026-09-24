**Initial Vector**

[32, 4, 87, 10, 2]


**Pass 1: Insert 4**

Sorted portion: [32]

Key: 4

Comparison 1

32 > 4 → true


Shift 32 one position right:

[32, 32, 87, 10, 2]


Comparisons: 1

Shifts: 1

Insert 4 at index 0:

[4, 32, 87, 10, 2]

The insertion of 4 is not counted as a shift.


**Pass 2: Insert 87**

Sorted portion: [4, 32]

Key: 87

Comparison 2

32 > 87 → false


No shifting is required. 87 remains at index 2:

[4, 32, 87, 10, 2]

Pass comparisons: 1

Pass shifts: 0

Cumulative comparisons: 2

Cumulative shifts: 1


**Pass 3: Insert 10**

Sorted portion: [4, 32, 87]

Key: 10

Comparison 3

87 > 10 → true

Shift 87 right:

[4, 32, 87, 87, 2]

Comparison 4

32 > 10 → true

Shift 32 right:

[4, 32, 32, 87, 2]


Comparison 5

4 > 10 → false

Stop shifting and insert 10 after 4:

[4, 10, 32, 87, 2]

Pass comparisons: 3

Pass shifts: 2

Cumulative comparisons: 5

Cumulative shifts: 3


**Pass 4: Insert 2**

Sorted portion: [4, 10, 32, 87]

Key: 2

Comparison 6

87 > 2 → true

Shift 87 right:

[4, 10, 32, 87, 87]

Comparison 7

32 > 2 → true

Shift 32 right:

[4, 10, 32, 32, 87]

Comparison 8

10 > 2 → true

Shift 10 right:

[4, 10, 10, 32, 87]

Comparison 9

4 > 2 → true

Shift 4 right:

[4, 4, 10, 32, 87]

Insert 2 at index 0:

[2, 4, 10, 32, 87]

Pass comparisons: 4

Pass shifts: 4

Cumulative comparisons: 9

Cumulative shifts: 7



|      Pass | Key | Comparisons | Shifts | Result         |
| --------: | --: | ----------: | -----: | -------------- |
|         1 |   4 |           1 |      1 | `4 32 87 10 2` |
|         2 |  87 |           1 |      0 | `4 32 87 10 2` |
|         3 |  10 |           3 |      2 | `4 10 32 87 2` |
|         4 |   2 |           4 |      4 | `2 4 10 32 87` |
| **Total** |     |       **9** |  **7** |                |



Therefore:

Sorted: 2 4 10 32 87
Comparisons: 9
Shifts: 7
