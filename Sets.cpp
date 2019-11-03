#include <iostream>
#include <set>

using namespace std;

int main()
{
	// Creating an empty set of type int
	set<int> s;

	// Inserting elements in a set. As we go on inserting automatically set sorts the elements
	s.insert(5);
	s.insert(9);
	s.insert(1);
	s.insert(3);

	// Searching in sets will require log(n) time and find returns const_iterator
	s.find(3);

	cout << "Printing all the elements of set : ";

	// Iterate over all elements of set
	set<int>::const_iterator itr;
	for (itr = s.cbegin(); itr != s.cend(); ++itr)
		cout << *itr << "  ";
	cout << endl;

	system("pause");
	return 0;
}

/*
Output

Printing all the elements of set : 1  3  5  9

*/
