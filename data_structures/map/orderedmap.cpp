#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
   map<int, string> fruitMap;

   fruitMap[10] = "grapefruit";
   fruitMap[5] = "apple";
   fruitMap[6] = "banana";

   for (const auto& item : fruitMap) {
      cout << item.first << ": " << item.second << endl;
   }

   return 0;
}

/*
5: apple
6: banana
10: grapefruit
*/
