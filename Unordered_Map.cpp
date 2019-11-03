#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	// Creating a unordered_map with key of type int and value of type string
	unordered_map<int, string> u;

	// Inserting elements in to the unordered_map
	u[1] = "one";  // Here operator [] returns reference of string i.e string&
	u[2] = "two";
	u[4] = "four";
	u[3] = "three";

	cout << endl << "Printing all the keys along with their values" << endl;

	// Iterating over a unordered_map
	unordered_map<int, string>::const_iterator itr; // here we can use unordered_map<t1,t2>::iterator as well.
	for (itr = u.cbegin(); itr != u.cend(); ++itr)
		cout << "(" << itr->first << ", " << itr->second << ")" << endl;

	cout << "Printing the load factor : " << u.load_factor() << endl;
	system("pause");
	return 0;
}

/*
Output

Printing all the keys along with their values
(1, one)
(2, two)
(4, four)
(3, three)

Printing the load factor : 0.5

*/
