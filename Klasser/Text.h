#pragma once
#include <iostream>

class Text
{	//klass definition
public:

	// -------------- THE BIG 3 --------------------

	Text();		//defaultkonstruktor
	explicit Text(const char* str);		//inte default konstruktor ! p.g.a parameterlista
	Text(const Text& other); //Kopieringskonstruktor
	const Text& operator=(const Text& other); //Tilldelnings-operator
	//---------------- THE BIG 3 end ----------------

	Text(Text&& other); // MOVE-konstruktor anropas OM den anropas med ett temporärt objekt.

	//För att komma åt enskilda tecken...
	inline char& operator[] (int pos); // Indexeringsoperator		//explicit inline utan bra anledning... :)
	char& operator[] (int pos) const { return cptr[pos]; } // Indexeringsoperator	//implicit inline p.g.a 
			//medlemsfunktion som definierats inne i klassdefinitionen
	//int length();
	int length() const;

	~Text();	//destruktor

	static int counter;
private:
	int size;
	char* cptr;
	friend std::ostream& operator<<(std::ostream, const Text&);
};




