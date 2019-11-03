#include <iostream>
#include <map>
#include <string>

using namespace std;

void foo(const map<int, string>& m)
{
	// m[7] = "seven"; This is invalid as we are calling non-const member function [] on a const reference m
	// cout << m[3] << endl; Even this is invalid as map will perform a lookup for three and return reference assuming that we are modifying

	// Search or retrieve an element from a map
	map<int, string>::const_iterator itr = m.find(3); // find returns const_iterator so that we don't attempt to modify

	cout << endl << "Retrieve key 3 using find method" << endl;

	// If the key is not found then find returns end iterator
	if (itr != m.end())
		cout << "(" << itr->first << ", " << itr->second << ")" << endl;
}

int main()
{
	// Creating a map with key of type int and value of type string
	map<int, string> m;

	// Inserting elements in to the map
	m[1] = "one";  // Here operator [] returns reference of string i.e string&
	m[2] = "two";
	m[4] = "four";
	m[3] = "three";

	// Updating the value of an element in a map
	m[2] = "TWO!";

	cout << endl << "Printing all the keys along with their values" << endl;

	// Iterating over a map
	map<int, string>::const_iterator itr; // here we can use map<t1,t2>::iterator as well.
	for (itr = m.cbegin(); itr != m.cend(); ++itr)
		cout << "(" << itr->first << ", " << itr->second << ")" << endl;

	foo(m);

	//Creating a map by passing comparator operator to sort in reverese order
	map<int, string, greater<int>> p;

	// Inserting elements in to the map
	p[1] = "one";  // Here operator [] returns reference of string i.e string&
	p[2] = "two";
	p[4] = "four";
	p[3] = "three";

	cout << endl << "Printing all the keys along with their values" << endl;

	// Iterating over a map
	map<int, string>::const_iterator it; // here we can use map<t1,t2>::iterator as well.
	for (it = p.cbegin(); it != p.cend(); ++it)
		cout << "(" << it->first << ", " << it->second << ")" << endl;

	system("pause");
	return 0;
}

/*
Output

Printing all the keys along with their values
(1, one)
(2, TWO!)
(3, three)
(4, four)

Retrieve key 3 using find method
(3, three)

Printing all the keys along with their values
(4, four)
(3, three)
(2, two)
(1, one)

*/
