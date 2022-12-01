//Item 4: Make sure that objects are initialized before they’re used.
//Item 5: Know what functions C++ silently writes and calls.
//Item 6: Explicitly disallow the use of compiler generated functions you do not want

#include <iostream>
using namespace std;

class Vehicul{
	public:
		Vehicul(const string &id);
		string toString();
	private:
		string id;
};

//Item 4
Vehicul::Vehicul(const string &id) 
:id(id)
{
	cout<<"Vehicul constructor"<<endl;
}

string Vehicul::toString(){
	return "Vehiculul are ID-ul: "+id+"\n";
}

Vehicul& vehicul2()
{
	static Vehicul vehicul2("TMxxBMB");
	return vehicul2;
}

//Item 5
class Autovehicul{ 
};

class Parking{
	public:
		Parking(const string &address, const int capacity);
		Parking(const Parking&);
		Parking& operator=(const Parking& u);
		~Parking();
		string toString();
	
	private:
		string address;
		int capacity;
};

Parking::Parking(const string &address, const int capacity)
:address(address),
capacity(capacity){
	cout<<"Constructor Parking"<<endl;
}

Parking::Parking(const Parking& u){
	cout<<"Copy constructor Parking"<<endl;
	this->address = u.address;
	this->capacity = u.capacity;
}

Parking& Parking::operator=(const Parking& u){
	cout<<"Copy assignment operator Parking"<<endl;
	this->capacity = u.capacity;
	return *this;
}
Parking::~Parking(){
	cout<<"Destructor Parking"<<endl;
}

string Parking::toString(){
	return "Parcarea "+address;
}

//Item 6 
class Mall{
	public:
		Mall(const string &name, const string &address);
		~Mall();
		string toString();
	
	private:
		string name;
		string address;
		Mall(const Mall&);
		Mall& operator=(const Mall& u);
};

Mall::Mall(const string &name, const string &address)
:name(name),
address(address){
	cout<<"Constructor Mall"<<endl;
}

Mall::~Mall(){
	cout<<"Destructor Mall"<<endl;
}

string Mall::toString(){
	return "Mall-ul"+name+" se afla la adresa "+address+"\n";
}

int main()
{
	Vehicul v("TMxxXYZ");
	cout<< (v.toString()); 
	//default constructor
	Autovehicul auto1; 
	//default copy constructor 
	Autovehicul auto2(auto1);
	//default copy assignment operator 
	auto2 = auto1; 
	//constructor
	Parking p1("Str Paris nr. 1",200); 
	cout<< "Parcarea 1 "<<p1.toString();
	//copy constructor
	Parking p2(p1); 
	cout<< "Parcarea 2 "<<p2.toString();
	Parking p3("Calea Sagului nr. 100",2000);
	cout<< "Parcarea 3 "<<p3.toString();
	//copy assignment operator
	p3 = p1; 
	cout<< "Parcarea 3 "<<p3.toString();
	Mall u1("Iulius Town","Consiliul Europei");
	
	return 0;
}

