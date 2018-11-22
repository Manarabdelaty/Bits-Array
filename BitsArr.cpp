#include "BitsArr.h"

std::ostream & operator<< (std::ostream & o, const  BitsArr &bits_arr) {
	int octets = int(bits_arr.size / BitsArr::bitsInChar);
	for (int i = octets - 1; i >= 0; i--) {
		for (int j = BitsArr::bitsInChar - 1; j >= 0; j--)
			o << unsigned int((bits_arr.arr[i] >> j) & (0x1));
		o << " ";
	}
	return o;
}

// Default Constructor
BitsArr::BitsArr(int s) {

	if (checkSize(s)) {
		size = unsigned int (s);
		octets = unsigned int (size / bitsInChar) +  ( (size % bitsInChar)? 1 :0);
		arr = new unsigned char[octets]();
	}
};
// Copy Constructor
BitsArr::BitsArr(const BitsArr & barr) : size(barr.size), octets(barr.octets) { 
		arr = new unsigned char[barr.octets];
		for (int i = 0; i < barr.octets; i++)
			arr[i] = barr.arr[i];
};
// Move Constructor
BitsArr::BitsArr(BitsArr && barr): size(barr.size) ,octets(barr.octets), arr(barr.arr){
	if (this != &barr) {
		barr.size = 0;
		barr.arr = nullptr;
		barr.octets = 0;
	}
}

void BitsArr::setSize(int s){
	if (checkSize(s)) {
		size = unsigned int(s);
		octets = unsigned int(size / bitsInChar) + ((size % bitsInChar) ? 1 : 0);
		arr = new unsigned char[octets]();
	}
}

void BitsArr::setBit(int indx, int val) {
	
	if (val != 0 && val != 1) throw("Bit value has to be zero or one");

	if (checkBounds(indx)) {
		unsigned int octet_indx = unsigned int(indx / bitsInChar);
		unsigned int bit_indx = indx % (bitsInChar);
		arr[octet_indx] = (!val) ? arr[octet_indx] & ~(1 << bit_indx) : arr[octet_indx] | (1 << bit_indx);
	}
}

int BitsArr::getBit(int indx) const{
	if (checkBounds(indx)) {
		unsigned int octet_indx = unsigned int(indx / bitsInChar) ;
		unsigned int bit_indx = indx % (bitsInChar);
		unsigned int bit_val = (unsigned int)(arr[octet_indx] >> bit_indx) & 0x1;
		
		return bit_val;
	}
}

BitsArr& BitsArr::operator=(const BitsArr & bit_arr) {
	if (this != &bit_arr) {
		size = bit_arr.size;
		octets = bit_arr.octets;
		arr = new unsigned char[octets];
		for (int i = 0; i < octets; i++)
			arr[i] = bit_arr.arr[i];
	}
	return *this;
}



