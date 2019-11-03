#include <iostream>
#include <memory>

using namespace std;


int main()
{
	// Creating a new shared pointer
	shared_ptr<int> sp{ new int{18} };

	// Shared pointer can be copy assignable or copy constructible
	shared_ptr<int> sp2{ sp };
	shared_ptr<int> sp3 = sp;


	// Dereferrencing all the shared_pointers
	cout << *sp << endl;
	cout << *sp2 << endl;
	cout << *sp3 << endl;

	// To check reference count value
	cout << sp.use_count() << endl;

	// Use of make_shared
	shared_ptr<int> sp4 = make_shared<int>(18);

	// Use of unique method which checks if the use_count is 1
	// Meaning that the shared_ptr exclusively has the ownership
	if (sp4.unique())
		cout << "sp4 exclusively owns the shared_ptr" << endl;

	cout << *sp4 << endl;

	// Getting raw pointer from shared_ptr
	int* ptr = sp4.get();

	system("pause");
	return 0;
}
