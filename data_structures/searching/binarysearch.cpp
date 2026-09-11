#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(const vector<int>& numbers, int target,
                 int& comparisons) {
    // TODO: Implement iterative binary search.

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers.at(i);
    }

    int target;
    cin >> target;

    int comparisons = 0;
    int index = BinarySearch(numbers, target, comparisons);

    if (index != -1) {
        cout << "Found " << target
             << " at index " << index << "." << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }

    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
