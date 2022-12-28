//Item 10: Have assignment operators return a reference to *this.
//Item 11: Handle assignment to self in operator=.
//Item 12: Copy all parts of an object.

#include <iostream>
using namespace std;

class Vehicul{
	public:
		Vehicul(const string &id);
		string toString();
	private:
		string id;
};

//Item 10
// Vehicul& operator=(const Vehicul& rhs) {
//     Id = rhs.id;
//     cout<<"Returnare a referintei la obiect, conform item 10"<<endl;
//     return *this;
// }

// class Parking{
// 	public:
// 		Parking(const string &address, const int capacity);
// 		Parking(const Parking&);
// 		Parking& operator=(const Parking& u);
// 		~Parking();
// 		string toString();
	
// 	private:
// 		string address;
// 		int capacity;
// };

// Parking& Parking::operator=(const Parking& u){
// 	cout<<"Returnare a referintei la obiect, conform item 10"<<endl;
// 	this->capacity = u.capacity;
// 	return *this;
// }

//Item 11
Vehicul& operator=(const Vehicul& rhs) {
    Vehicul aux(rhs);
    this->swap(aux);
    return *this;
}

//Item 12
class ParkedVehicul:public Vehicul {
    public:
        ParkedVehicul(const ParkedVehicul& rhs);
        ParkedVehicul& operator=(const ParkedVehicul& rhs);

        ParkedVehicul(const string& id, const int locParcare);

        string toString () {
            return Vehicul::toString() + "parcat in locul: " + to_string(locParcare);
        }

    private:
        int locParcare;
}

ParkedVehicul::ParkedVehicul(const string& id, const int locParcare)
:Vehicul(id),
locParcare(loc) {
}

ParkedVehicul::ParkedVehicul(const ParkedVehicul& rhs) 
:Vehicul(rhs),
locParcare(rhs.locParcare) {
    cout<<"ParkedVehiul copy constructor, conform Item 12"<<endl;
}

ParkedVehicul& ParkedVehicul::operator=(const ParkedVehicul& rhs) {
    cout<<"ParkedVehicul copy assignment operator, conform Item 12"<<endl;
    Vehicul::operator=(rhs);
    locParcare=rhs.locParcare;
    return *this;
}

int main () {
    Vehicul v1("TMxxXYZ");
    Vehicul v2("BxxxABC");
    Vehicul v3("TMxxBMB");
	cout<<(v1.toString())<<endl;

    //Item 10
    // v2=v1=v3;
    // cout<<(v2.toString())<<endl; //v2 trebuie sa aiba acceasi valoare ca v3

    //Item 11
    Vehicul veh("TMxxVEH");
    veh = veh;  //self assignment
    cout<<(veh.toString())<<endl;

    //Item 12
    ParkedVehicul pv1 = ParkedVehicul("ARxxIVK");
    cout<<(pv1.toString())<<endl;

    ParkedVehicul pv2 = ParkedVehicul("ARxxIBU");
    cout<<(pv2.toString())<<endl;

    pv2=pv1;
    cout<<(pv2.toString())<<endl;
}