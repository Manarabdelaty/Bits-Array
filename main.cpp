#include <iostream>
#include "BitsArr.h"
#include "OctetSet.h"

using namespace std;

int main() {

	BitsArr arr(32);
	OctetSet oct_set;

	cout << "Bit Array " << endl;

	arr.setBit(0, 1);               // Sets bit at indx 0 with value 1 
	arr.setBit(2, 1);
	arr.setBit(31, 1);
	arr.setBit(30, 1);
	cout << arr << endl;

	BitsArr arr_cpy(arr);
	cout << "Bits array copy is " << endl;
	cout << arr_cpy << endl;


	arr.setBit(2, 0);          
	arr.setBit(31, 0);
	
	cout << arr << endl;

	cout << "Bit at indx 0 is : " << arr.getBit(0) << endl;;     // returns bit at indx 0

	


	cout << "Octet set" << endl;

	oct_set.add(1);
	oct_set.add(22);
	oct_set.add(100);

	cout << oct_set << endl;

	oct_set.remove(100);
	cout << "Remove 100 " << endl;
	cout << oct_set << endl;

	if (oct_set.find(100)) 
		cout << "Found 100 in  the set" << endl;
	else cout << "Didn't find 100 in the set" << endl;

	if(oct_set.find(22))
		cout << "Found 22 in  the set" << endl;
	else cout << "Didn't find 22 in the set" << endl;
	
	OctetSet oct_set_cpy(oct_set);                    // Copy constructor
	cout << "Octet set copy " << endl;
	cout << oct_set_cpy << endl;

	system("pause");
}
