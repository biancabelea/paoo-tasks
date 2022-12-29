//LINK GITHUB https://github.com/biancabelea/paoo-tasks

//Item 13: Use objects to manage resources.
//Item 14: Think carefully about copying behavior in resource-managing classes.

#include <iostream>
#include <memory.h>
using namespace std;

class Uncopyable{
    protected:
        Uncopyable(){}
        ~Uncopyable(){}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Vehicul:private Uncopyable{
    public:
        Vehicul(){}
        Vehicul(const string&Id, const string&Marca):Id(Id), Marca(Marca){}
        Vehicul(const Vehicul& vehicul):Id(vehicul.Id), Marca(vehicul.Marca){}
        ~Vehicul(){
            cout<<"Vehicul sters\n";
        }

        Vehicul& operator=(const Vehicul& vehicul){
            if(this == &vehicul){
                return *this;
            }
            this->Id=vehicul.Id;
            this->Marca=vehicul.Marca;
            return *this;
        }

        void afisareVehicul(){
            cout<<"Vehiculul cu numarul "<<this->Id<<" este marca "<<this->Marca<<"\n";
        };

        void lock(){
            cout<<"Vehiculul este parcat\n";
        };

        void unlock(){
            cout<<"Vehiculul nu mai este parcat\n";
        };
    private:
        string Id;
        string Marca;
};

class VehiculElectric:private Vehicul{
    public:
        VehiculElectric(){}
        VehiculElectric(const string&Id, const string&Marca, const int&Autonomie):Vehicul(Id, Marca), Autonomie(Autonomie){}
        VehiculElectric(const VehiculElectric& vehicul):Vehicul(vehicul), Autonomie(vehicul.Autonomie){
            cout<<"Copy constructor VehiculElectric";
        }
        ~VehiculElectric(){
            cout<<"VehiculElectric sters\n";
        }

        VehiculElectric& operator=(const VehiculElectric& vehicul){
            if(this == &vehicul){
                return *this;
            }
            Vehicul::operator=(vehicul);
            this->Autonomie=vehicul.Autonomie;
            return *this;
        }

        void afisareVehiculElectric(){
            Vehicul::afisareVehicul();
            cout<<"Autonomie vehicul: "<<this->Autonomie<<"\n";
        };
    private:
        int Autonomie;
};

class Parking: private Uncopyable{
    public:
        explicit Parking(Vehicul vehicul): vehicul(vehicul){
            vehicul.lock();
        }
        ~Parking() {
            vehicul.unlock();
        }
    private:
        Vehicul vehicul;
};

void f(){
    shared_ptr<Vehicul> pVehicul(new Vehicul());
}

int main(){
    Vehicul vehicul1("TMxxBMB", "Opel");
    vehicul1.afisareVehicul();

    Vehicul vehicul2(vehicul1);
    vehicul2.afisareVehicul();

    Vehicul vehicul3("ARxxBLK", "Ford");
    Vehicul vehicul4;
    vehicul4 = vehicul3;
    vehicul4.afisareVehicul();

    VehiculElectric vehicul5("CTxxOIB", "Audi", 100);
    VehiculElectric vehicul6;
    vehicul6=vehicul5;
    vehicul5.afisareVehiculElectric();
    vehicul6.afisareVehiculElectric();

    f();
    Parking parked1(vehicul1);
    Parking parked2(vehicul2);
    vehicul1 = vehicul2;

    return 0;
}