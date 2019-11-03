#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> foo()
{
	unique_ptr<int> ret;
	return ret;
	/* Here as the return type is unique pointer and copy constructor is not allowed
	   visual studio automatically calls move on ret object to transfer the ownership of it.
	*/
}

unique_ptr<int> bar(unique_ptr<int> p)
{
	return p;
}

int main()
{
	// Creating a new unique pointer
	unique_ptr<int> u{ new int{34} };

	// Dereferencing unique pointer
	cout << *u << endl;

	// Transferring the ownership of unique pointer u to u2
	unique_ptr<int> u2 = move(u);

	// After transferring ownership, u should be nullified and all its contents should be transferred to u2
	if (u != nullptr)
		cout << "Not working as expected" << endl;
	else
		cout << "working as expected" << endl;

	cout << *u2 << endl;

	// unique_ptr<int> u3{ u2 }; This won't work as unique pointers are not copy constructible.
	// unique_ptr<int> u3 = u2; This also won't work as unique pointers are not copy assignable

	unique_ptr<int> u3 = foo();

	// Use of move to pass the ownership to called function parameter
	u3 = bar(move(u3)); // Here u3 = bar((u3)); will give compilation error about unique_ptr being explicitly deleted.

	// Use of make_unique
	unique_ptr<int> u4 = make_unique<int>(34);

	// Getting raw pointer from unique_ptr
	int* p = u4.get();

	// Getting raw pointer as well as the ownership from unique_ptr
	int* pt = u4.release();  // In this case u4 will be made to point to nullptr

	// Delete the owned object
	u3.reset();

	// To assume ownership from raw pointer
	u4.reset(pt); // Now u4 will regain the ownership

	system("pause");
	return 0;
}
