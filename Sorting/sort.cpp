#include <bits/stdc++.h>
#include"sort.h"
using namespace std;
int main(){
	int arr[6] = {1, 2, 8, 7, 5, 10};
	int n = 6;
	printf("not sorting arr\n");
	printArr(arr,n);

	//Types Sorting
	//bubbleS(arr, n);
	selectionS(arr,n);
	//insertionS(arr,n);
	//mergeS(arr, 0, n-1);
	//quickS(arr, 0, n-1);
	printf("sorted arr\n");
	printArr(arr,n);
	
	//Vector Func Sort Available
	vector<int> g1;
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end vector: ";
	for (vector<int>::iterator i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend vector: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";
	cout << "\n";

	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	sort(v.begin(),v.end());
	cout << "Sap xep vector tang dan\n";
	for (auto x : v)
		cout << x << " ";

	sort(v.begin(),v.end(), greater<int>());
	cout << "\nSap xep vector giam dan\n";
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
	
	//Array Func Sort Available
	sort(arr, arr + 6);
	cout << "Sap xep mang tang dan\n";
	printArr(arr,n);
	sort(arr, arr + 6, greater<int>());
	cout << "Sap xep mang giam dan\n";
	printArr(arr,n);

	//STL-array Func Sort Available
	array<int,9> array = {1,2,9,3,8,6,7,4,5};
	cout << array.at(2) << "\n";// prints 3
	cout << array.at(4) << "\n";// prints 5

	cout << "Output of begin and end array: ";
	for (auto i = array.begin(); i != array.end(); ++i)
		cout << *i << " ";
	cout << "\nOutput of rbegin and rend array: ";
	for (auto ir = array.rbegin(); ir != array.rend(); ++ir)
		cout << *ir << " ";
	cout << "\n";

	sort(array.begin(),array.end());
	cout << "Sap xep mang tang dan\n";
	for (auto x : array)
		cout << x << " ";

	sort(array.begin(),array.end(), greater<int>());
	cout << "\nSap xep mang giam dan\n";
	for (auto x : array)
		cout << x << " ";
	cout << "\n";

	return 0;
}
