#include "Text.h"
#include <cstring>
#include <stdexcept>

int Text::counter = 1;

Text::Text(): size(0), cptr(nullptr){	//Initiering istället för tilldelning -> mycket bra! 
	// då görs förstås inte tilldelning i konstruktorkroppen

	//size = 0;			<- Java aktigt se ovan
	//cptr = nullptr;
}


//inte default konstruktor
Text::Text(const char* str) : size (std::strlen(str)+1), cptr(new char[size]) // Initiering  igen!
{	
	// nedan står Java aktiga notationen

	//size = std::strlen(str) + 1; //1 för nulltecknet som avslutar en c-string
	//cptr = new char[size];
	//std::strcpy(cptr, str); 
	 strcpy_s(cptr, size, str);
}	//default konstruktor

//------------- Nedan borde använda intiering istället för tilldelning i alla konstruktorer -----------

Text::Text(const Text& other) {	// Kopieringskonstruktor
	size = other.size;
	cptr = new char[size];
	strcpy_s(cptr, size, other.cptr);
}	// Kopieringskonstruktor


const Text& Text::operator=(const Text& other) {		//Tilldelnings-operator, består oftast av 2 delar: 1 ser ut som 
	// destruktor 2 ser ut som kopieringskonstruktor
	// Ett par som Bör följas konventioner:
	//konv 1: Fixa möjligheten att själv-tilldela -> alltså if sats... 
	//konv 2: ska kunna kedjas... alltså returnera samma typ som står som argument till operatorn

	if (this != &other) {		// this = pekare if sats för att tillgodose konvention 1.
		delete[] cptr;	 //del 1

		size = other.size;	//del 2
		cptr = new char[other.size];
		strcpy_s(cptr, size, other.cptr);
	}	

	return *this; // this är bara pekaren som pekar ut objektet. Objektet själv heter *this...
	//alltså samma värde som finns i mig själv.
}



Text::Text(Text&& other) { //MOVE- konstruktor  -> inte så viktigt på denna kurs... optimering från c++11
	size = other.size;
	cptr = other.cptr;
	other.cptr = nullptr;
	other.size = 0;
}


Text::~Text()		//destruktorer beöver inte städa bort det som finns i objekten...  -> MEN däremot <- 
// det som finns runt om objektet MÅSTE städas bort (det som allokerats dynamiskt, t.ex.).
{
	delete[] cptr;
}

char& Text::operator[](int pos) {	// char& istället för char för 
	// möjligheten att tilldela! alltså ändra en bokstav på ett visst index.
	if (pos < 0 || pos >= size)	//brukar inte göras i c++11		kollar indexoutofbounds på pos
		throw std::out_of_range("Text index out of bounds");
		
		return cptr[pos];
}

int Text::length() const {
	return size == 0 ? 0 : size - 1;
}




