#include <String>
#include <iostream>
#include <vector>
using namespace std;

// -------------------------- Flerfaldigt arv --------------------------------------------------

// se upp med namnkonflikter! problem uppstår vid användning, anrop = tvetydigt.. 
//tvetydighet avgörs innan kompilatorn kollar skyddsgrad(private osv), problem uppstår alltså
// även om ena alternativet är publikt och andra privat.

//specificera vilken version av en överskuggad metod som ska användas genom att använda basklasen namn innan
// Ex:
// Foo::foobar() istället för bara foobar().

class Person {
public:
	Person(string s) : namn(s) {}
	string get_namn() const { return namn; }
	void talar() const { cout << "Bla bla.." << endl; }
private:
	string namn;
};

class Varg {
public:
	Varg(bool g) : grym(g) {}
	bool is_grym() const { return grym; }
	void ylar() const { cout << "Uuuuuu..." << endl; }
private:
	bool grym;
};

class Varulv : public Person, public Varg {
public:
	Varulv(string s, bool dödlig) : Person(s), Varg(true), dödlig(dödlig) {}
	bool is_dödlig() const { return dödlig; }
private:
	bool dödlig;
};


// --------------- Implementationsarv, private eller protected ----------------------------------


class Stack : private std::vector<int> {		//privat arv
public:
	void push(int value) {
		push_back(value);
	}
	int pop() {
		int val = back();
		pop_back();
		return val;
	}

	bool is_empty() const {
		return empty();
	}
private:
};



//--------------------------------------- PUBLIKT ARV -------------------------------------------

// 1: OBS! Objekt av klasser i klasshierarkier Bör hanteras genom pekare Och skapas dynamiskt
		// Detta p.g.a. slicing... Se Animal för exempel.

// 2: I klasshierarkier Ska man Alltid ha en virtual destruktor i rot-klassen! även om man inte behöver destruktion.


class Animal {	//innehåller "abstract metod", kan därför inte instantieras.
public:
	std::string get_name() const { return name; }
	virtual void moves() const { cout << "Springer";  }		// virtual = dynamisk bindning = överskuggningsbar
	virtual void talks() const = 0; // rent virtuell medlemsfunktion (javas abstract)
	virtual void show() { cout << name; }
	virtual ~Animal() {}
protected:
	Animal(std::string n) : name(n) {}
private:
	std::string name;
	Animal(const Animal&) = delete;	// Konvention - Copykonstruktor ska inte finnas 
				//Detta eftersom vi vill påtvinga dynamiskt skapade objekt.

	const Animal& operator= (const Animal&) = delete;	// Ta även bort tilldelningsoperator!
			//Alltså tas värdesemantiken för Animal bort. Det räcker att göra detta i rot-klassen.
};

class Wing {};	// införd för att visa varför man Alltid ska ha virtuella destruktorer

class Bird : public Animal {
public:
	static Bird* getInstance(string n, double ws);	// Istället för konstruktor
	double get_wingspan() const { return wingspan; }
	void moves() const { cout << "Flyger"; }	//överskuggar superklassens moves()
	void talks() const { cout << "Kvitter kvitter"; }
	void show() { Animal::show(); cout << wingspan; }
	~Bird() { delete left; delete right; }
protected:
	Bird(std::string n, double ws) :Animal(n), wingspan(ws) {} // Eftersom konstruktor = privat används getInstance
private:
	Wing * left, *right;
	double wingspan;
};

Bird* Bird::getInstance(string n, double ws) { return new Bird(n, ws); }	// Skapar objekt på heapen.

class Chicken : public Bird {
public:
	Chicken(string n, double w) : Bird(n, 0.3), weight(w) {}
	void show() { Animal::show(), cout << weight;  }
private: 
	double weight;
};


class Cat : public Animal {
public:
	static Cat* getInstance(string n, bool dom);
	int get_lives() const { return lives; }
	void talks() const { cout << "Mjau"; }
private:
	Cat(string n, bool dom) :Animal(n), lives(9), domestic(dom) {}
	int lives;
	bool domestic;
};

Cat* Cat::getInstance(string n, bool dom) { return new Cat(n, dom);  }		// Skapar objekt på heapen.

class Mask : public Animal {
public :
	//Mask(string name): Animal(name) {}	// akn va många lr krångliga
	using Animal::Animal;	//ARV av konstruktorer
	void moves() const { cout << "Kryper"; }
};


// ---------------------------------------- MAIN ------------------------------------------------


int main() {
	Animal *zoo[3];

	zoo[0] = Bird::getInstance("Goja", 0.82);
	zoo[1] = Cat::getInstance("Simba", false);
	zoo[2] = Bird::getInstance("Pippi", 3.2);

	std::string names[3];
	for (int i = 0; i < 3; i++) {
		names[i] = zoo[i]->get_name();
		cout << names[i] << endl;
	}

	vector<Animal*> zoo2;
	zoo2.push_back(Bird::getInstance("Pippe", 2.3));
	// massa fler djurr läggs till

	for (Animal* a : zoo2) {
		if (Bird* b = dynamic_cast<Bird*>(a))	// om ej legitimt, retrurnera null/0 och betrakta det som false
			cout << b ->get_wingspan();
	}

	//anrop av överskuggade metoder, även "super" i andra led, eller fler kanske?
	Chicken *ch = new Chicken("Pippo", 0.5);
	ch->show();
	ch->Animal::show();


	//Demonstration av virtuella destruktorer
	Animal *a = Bird::getInstance("Phenix", .5);
	delete a;
}