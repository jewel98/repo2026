#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void Print(const unordered_map<int, string>& data) {
    for (const auto& item : data) {
        cout << item.first << ": " << item.second << endl;
    }
}

int main() {
    unordered_map<int, string> fruitMap;

    fruitMap[5] = "apple";
    fruitMap[6] = "banana";
    fruitMap[10] = "grapefruit";

    Print(fruitMap);

    return 0;
}
