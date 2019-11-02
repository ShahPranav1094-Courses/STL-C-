#include <algorithm>
#include <functional>
#include <iostream>
#include <stddef.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Creating a default vector
    vector<int> v;

    // Adding Elements to the end of the array
    v.push_back(33);
    v.push_back(22);
    v.push_back(11);

    // v[5] = 55; 
    // This will compile but it will cause undefined behavior i.e. it can crash, silently kill etc.

    // Print elements of vector in traditional way
    cout << "Printing the elements of vector in traditional way : ";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << "  ";
    cout << endl;

    // Print elements of vector using Iterator (Recommended to use iterators)
    vector<int>::iterator itr;
    cout << "Printing the elements of vector using iterators : ";
    for (itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << "  ";
    cout << endl;

    // Sort the elements of vector using sort algorithm
    sort(v.begin(), v.end());
    cout << "Printing the elements of vector using iterators after performing sort : ";
    for (itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << "  ";
    cout << endl;

    int arr[5]{ 55,33,22,11,44 };
    int* begin = &arr[0];   // or = arr
    int* end = &arr[0] + 5; // here if we directly give &arr[5] then it will cause undefined behavior
    sort(begin, end);
    cout << "Printing the elements of array using raw pointers after performing sort : ";
    for (int* p = begin; p != end; ++p)
        cout << *p << "  ";
    cout << endl;

    v.clear();

    vector<string> m;
    m.push_back("cat");
    m.push_back("antelope");
    m.push_back("puppy");
    m.push_back("bear");

    sort(m.begin(), m.end());
    cout << "Printing the elements of vector using iterators after performing sort on strings : ";
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << *i << "  ";
    cout << endl;

    // Reversing the order of sort
    sort(m.begin(), m.end(), greater<string>());
    cout << "Printing the elements of vector using iterators after performing sort on strings in descending order : ";
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << *i << "  ";
    cout << endl;

    // Sorting based on size of string using lambda
    sort(m.begin(), m.end(),
        [](const string & left, const string & right)
        {
            return left.size() < right.size();
        }
    );
    cout << "Printing the elements of vector using iterators after performing sort on strings in order of their sizes : ";
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << *i << "  ";
    cout << endl;

    m.push_back("dog");
    // Stable sorting based on size of string using lambda
    stable_sort(m.begin(), m.end(),
        [](const string & left, const string & right)
        {
            return left.size() < right.size();
        }
    );
    cout << "Printing the elements of vector using iterators after performing stable sort on strings in order of their sizes : ";
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << *i << "  ";
    cout << endl;

    m.clear();

    system("pause");
    return 0;
}

/*
Output

Printing the elements of vector in traditional way : 33  22  11

Printing the elements of vector using iterators : 33  22  11

Printing the elements of vector using iterators after performing sort : 11  22  33

Printing the elements of array using raw pointers after performing sort : 11  22  33  44  55

Printing the elements of vector using iterators after performing sort on strings : antelope  bear  cat  puppy

Printing the elements of vector using iterators after performing sort on strings in descending order : puppy  cat  bear  antelope

Printing the elements of vector using iterators after performing sort on strings in order of their sizes : cat  bear  puppy  antelope

Printing the elements of vector using iterators after performing stable sort on strings in order of their sizes : cat  dog  bear  puppy  antelope

*/
