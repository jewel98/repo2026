#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Insert a new key-value pair or update an existing key.
void Insert(unordered_map<int, string>& data,
            int key,
            const string& value) {
   // TODO
}

// Remove the key-value pair if the key exists.
void Remove(unordered_map<int, string>& data, int key) {
   // TODO
}

// Return the value associated with key.
// Return "null" if the key does not exist.
string Get(const unordered_map<int, string>& data, int key) {
   // TODO
   return "";
}

// Return true if the key exists; otherwise, return false.
bool Contains(const unordered_map<int, string>& data, int key) {
   // TODO
   return false;
}

// Return the number of key-value pairs.
int GetLength(const unordered_map<int, string>& data) {
   // TODO
   return 0;
}

int main() {
   unordered_map<int, string> data;
   int numOperations;

   cout << boolalpha;
   cin >> numOperations;

   for (int i = 0; i < numOperations; ++i) {
      string operation;
      cin >> operation;

      if (operation == "insert") {
         int key;
         string value;

         cin >> key >> value;
         Insert(data, key, value);
      }
      else if (operation == "remove") {
         int key;

         cin >> key;
         Remove(data, key);
      }
      else if (operation == "get") {
         int key;

         cin >> key;
         cout << Get(data, key) << endl;
      }
      else if (operation == "contains") {
         int key;

         cin >> key;
         cout << Contains(data, key) << endl;
      }
      else if (operation == "length") {
         cout << GetLength(data) << endl;
      }
   }

   return 0;
}

/*
Key C++ operations:
data[key] = value;                 // Insert or update
data.erase(key);                   // Remove
data.find(key);                    // Search
data.find(key) != data.end();      // Contains
data.size();                       // Number of pairs
*/
