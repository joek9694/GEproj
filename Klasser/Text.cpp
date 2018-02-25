#include "Text.h"
#include <cstring>
#include <stdexcept>

int Text::counter = 1;

Text::Text(): size(0), cptr(nullptr){	//Initiering ist�llet f�r tilldelning -> mycket bra! 
	// d� g�rs f�rst�s inte tilldelning i konstruktorkroppen

	//size = 0;			<- Java aktigt se ovan
	//cptr = nullptr;
}


//inte default konstruktor
Text::Text(const char* str) : size (std::strlen(str)+1), cptr(new char[size]) // Initiering  igen!
{	
	// nedan st�r Java aktiga notationen

	//size = std::strlen(str) + 1; //1 f�r nulltecknet som avslutar en c-string
	//cptr = new char[size];
	//std::strcpy(cptr, str); 
	 strcpy_s(cptr, size, str);
}	//default konstruktor

//------------- Nedan borde anv�nda intiering ist�llet f�r tilldelning i alla konstruktorer -----------

Text::Text(const Text& other) {	// Kopieringskonstruktor
	size = other.size;
	cptr = new char[size];
	strcpy_s(cptr, size, other.cptr);
}	// Kopieringskonstruktor


const Text& Text::operator=(const Text& other) {		//Tilldelnings-operator, best�r oftast av 2 delar: 1 ser ut som 
	// destruktor 2 ser ut som kopieringskonstruktor
	// Ett par som B�r f�ljas konventioner:
	//konv 1: Fixa m�jligheten att sj�lv-tilldela -> allts� if sats... 
	//konv 2: ska kunna kedjas... allts� returnera samma typ som st�r som argument till operatorn

	if (this != &other) {		// this = pekare if sats f�r att tillgodose konvention 1.
		delete[] cptr;	 //del 1

		size = other.size;	//del 2
		cptr = new char[other.size];
		strcpy_s(cptr, size, other.cptr);
	}	

	return *this; // this �r bara pekaren som pekar ut objektet. Objektet sj�lv heter *this...
	//allts� samma v�rde som finns i mig sj�lv.
}



Text::Text(Text&& other) { //MOVE- konstruktor  -> inte s� viktigt p� denna kurs... optimering fr�n c++11
	size = other.size;
	cptr = other.cptr;
	other.cptr = nullptr;
	other.size = 0;
}


Text::~Text()		//destruktorer be�ver inte st�da bort det som finns i objekten...  -> MEN d�remot <- 
// det som finns runt om objektet M�STE st�das bort (det som allokerats dynamiskt, t.ex.).
{
	delete[] cptr;
}

char& Text::operator[](int pos) {	// char& ist�llet f�r char f�r 
	// m�jligheten att tilldela! allts� �ndra en bokstav p� ett visst index.
	if (pos < 0 || pos >= size)	//brukar inte g�ras i c++11		kollar indexoutofbounds p� pos
		throw std::out_of_range("Text index out of bounds");
		
		return cptr[pos];
}

int Text::length() const {
	return size == 0 ? 0 : size - 1;
}




