#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	// Create a map: name -> phone number
	unordered_map<string, string> contacts;

	// Add two items
	contacts["Alice"] = "555-1200";
	contacts["Bob"] = "555-2300";

	// Display the items
	cout << "Alice: " << contacts["Alice"] << endl;
	cout << "Bob: " << contacts["Bob"] << endl;

	return 0;
}
