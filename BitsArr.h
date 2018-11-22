#ifndef BITSARR_H
#define BITSARR_H
#include <iostream>
#include <math.h>  

#define MAX_SIZE 256
#define bitsPerByte 8


class BitsArr {
	static const unsigned int bitsInChar = bitsPerByte * sizeof(unsigned char);
	bool checkBounds(int& indx) const { if (indx <= size && indx >= 0) return true;
	                             else throw("Index is out of the array bounds");
	};
	bool checkSize(int& s) const { if (s >= 0 && s <= MAX_SIZE) return true;
	                        else throw("Invalid Value size ");
	}
	unsigned char * arr;
	unsigned int size;                     // Number of bits
	unsigned int octets;                  // Number of Octets in the array

public: 
	BitsArr() :size(0) {};                // Default Constructor
	BitsArr(int s);                       
	BitsArr(const BitsArr & barr);       // Copy Constructor
	BitsArr(BitsArr && barr);           // Move Constructor
	~BitsArr() { delete [] arr; }         // Destructor
	
	void setSize(int s);

	void setBit(int indx, int val);
	int getBit(int indx) const;

	friend std::ostream & operator<< (std::ostream & o, const  BitsArr &bits_arr);

	BitsArr & operator =(const BitsArr &);

};

#endif



