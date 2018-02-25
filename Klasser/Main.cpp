#include "Text.h"
#include <iostream>
using namespace std;

void funk(const Text& t2) {
		// gör "nåt" med texten...
	cout << "funk()" << endl;
	cout << t2[2];
}

void skriv(const Text& t) {	// constvarianter = överlagrade i headerfil
	//alt1
	for (int i = 0; i < t.length(); i++) {	//anropar const variant
		std::cout << t[i];
	}

	//alt2
	for (int i = 0; i < const_cast<Text&>(t).length(); i++) { //anropar icke const variant
		std::cout << const_cast<Text&>(t)[i];
	}

	std::cout << std::endl;
}

int main() {
	Text t1("Johan");
	Text t5("Stefan");

	Text t3 = t1; //anropar kopieringskonstruktor
	//Text t3(t1); // kopieringskonstruktor samma som ovan, annan notation

	Text t4;	//kräver en defaultkonstruktor

	t5 = t1; //tilldelning.. inte så bra p.g.a ovan	pekar ut samma sträng + andra problem
	// lösning -> TILLDELNINGSOPERATOR !

	for (int i = 0; i < t3.length(); i++) {
		std::cout << t3[i];		//#include?
	}
	std::cout << std::endl;


	funk(t1);	// när man anropar funktioner med värdeargument, så kopieras objektet till funktionen...
	// det kopieras medlem för medlem... Detta är INTE bra! Resultatet blir att de 2 objekten pekar ut samma sträng.
	// inte bra bl.a. för att när funktionen är klar så anropas destruktorn som städar bort det dynamiskt allokerade
	//utrymmet, och då säger stackars t1 " VAR ÄR MIN STRÄNG ??? :'( " 
	// Åtgärd = Värdesemantik! -> närkopiering sker vill man att även innehållet i strängen kopieras.->
	// -> KOPIERINGSKONSTRUKTOR

	//----------------------------föreläsning 8----------------------------------------

	Text namn1("Jozef Swiatycki");
	Text namn2("Stefan Möller");

	namn2 = namn1;
	skriv(namn2);

	//typomvandlingar
	double d;
	int i = int(d);
	void* vptr;
	typedef char* Charstar;
	char* cptr = Charstar(vptr);

	//bra sätt, typomvandlingar
	int i2 = static_cast<int>(d);	//kompilatorn castar

	char* cptr2 = reinterpret_cast<char*>(&i2);		//tolkar om bytevärdet


	funk(Text("Swiatycki"));		// explicit typkonvertering

	//de implicita konverteringarna funkar inte p.g.a 'explicit' konstruktor
	//funk("Swiatycki");			// implicit kompilatorn letar rätt på en passande konstruktor
									//kan skapa problem... 

	//t4 = "OJ";						// som här... för att förbjuda implicit typkonvertering, kan konstruktorn 
									// deklareras med keywordet 'explicit'.

}

std::ostream& operator<< (std::ostream os, const Text& t) {
	for (int i = 0; i < t.size; i++)
		os << t.cptr[i];
	return os;
}

class K {
private:
	string *x;
public:
	K(const string* y) {
		x = const_cast<string*>(y);
	}


};

//----------------------- nån annan föreläsning? övning.. --------------------------------
/*
int main() {
	Coord c1, c2;

	c1.x = 3; c1.y = 5;
	c2 = c1;
	c2.x = 7;
	c2.move(3, 3);

//----------------------- ny övning---------------------------------------

	Coord2 c2_1(3, 2), c2_2(0, 0), c2_3(0, 0);
	c2_2 = c2_2;
	c2_2.move(3, 3);
	c2_3 = invertCoord(c2_2);
}
*/
struct Coord {
	int x, y;

	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}
};

//------------------------------------
class Coord2 {
public:
	Coord2(int xx, int yy) {		//konstruktor
		x = xx;
		y = yy;
	}

	//-------------- medlemsfunktioner ------------------------
	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

private:
	int x, y;

};// klass Coord2

Coord2 invertCoord(Coord2 co) {
	Coord2 temp(co.getY(), co.getX());
	return temp;
}


