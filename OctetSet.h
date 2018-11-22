#ifndef OCTETSET_H
#define OCTETSET_H

#include "BitsArr.h"

# define FULLOCTET 256

class OctetSet {

	BitsArr bytes;

public:
	OctetSet();
	OctetSet(const  OctetSet & oct_set);         // Copy Constructor

	void add(int val);
	void remove(int val);
	bool find(int val);

	~OctetSet() {  };

	friend std::ostream & operator<< (std::ostream & o, const OctetSet & oct_set);

};
#endif // !OCTETSET_H