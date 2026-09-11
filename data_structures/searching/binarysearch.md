* Implement the binary search algorithm in C++.
* Search a sorted vector for a target value.
* Return the target’s index or `-1` if it is absent.
* Count how many middle elements are examined.
* Observe the \(O(\log n)\) behavior of binary search.

## Program Requirements

Write the following function:

```cpp
int BinarySearch(const vector<int>& numbers, int target, int& comparisons);
```

The function must:

1. Use **iterative binary search**.
2. Set `comparisons` to `0` before beginning the search.
3. Increment `comparisons` once each time a middle element is examined.
4. Return the index of `target` if it is found.
5. Return `-1` if `target` is not found.

Use the following calculation to determine the middle index:

```cpp
mid = low + (high - low) / 2;
```

## Input

The input contains:

1. An integer `n`, representing the number of elements.
2. `n` distinct integers in increasing order.
3. An integer representing the target value.

### Constraints

```text
1 <= n <= 1000
```

The input values are guaranteed to be sorted in ascending order.

## Output

If the target is found, output:

```text
Found target at index index.
Comparisons: count
```

If the target is not found, output:

```text
target was not found.
Comparisons: count
```

Indexes begin at `0`.

Do not display input prompts such as `Enter a value:` because zyBooks compares the program’s output exactly.

## Example 1

### Input

```text
8
2 4 7 10 11 32 45 87
10
```

### Output

```text
Found 10 at index 3.
Comparisons: 1
```

## Example 2

### Input

```text
8
2 4 7 10 11 32 45 87
17
```

### Output

```text
17 was not found.
Comparisons: 3
```

The middle elements examined are:

```text
10 → 32 → 11
```

## Example 3

### Input

```text
8
2 4 7 10 11 32 45 87
87
```

### Output

```text
Found 87 at index 7.
Comparisons: 4
```
