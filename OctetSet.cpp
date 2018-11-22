#include "OctetSet.h"

 std::ostream & operator<< (std::ostream & o, const OctetSet & oct_set) {
	 o << "{"; 
	 for (int i = 0; i < FULLOCTET; i++)
		 if (oct_set.bytes.getBit(i))
			      o << i << ",";
	 o << "}";
	 return o;
}


OctetSet::OctetSet() {
	 BitsArr barr(FULLOCTET);
	 bytes = BitsArr(barr);
}
// Copy Constructor
OctetSet::OctetSet(const OctetSet & oct_set): bytes(oct_set.bytes) {
}


void OctetSet::add( int val) {
	bytes.setBit(val, 1);
}
void OctetSet::remove(int val) {
	bytes.setBit(val, 0);
}
bool OctetSet::find(int val) {
	return(bytes.getBit(val));
}

