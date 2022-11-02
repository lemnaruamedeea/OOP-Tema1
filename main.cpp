#include <iostream>
#include <vector>
using namespace std;

class Imbracaminte {
private:
    string culoare;
    string nume;
public:
    Imbracaminte(){}

    Imbracaminte(const Imbracaminte &ob) {
        culoare=ob.culoare;
        nume=ob.nume;
    }

    Imbracaminte(const string &culoare, const string &nume) : culoare(culoare), nume(nume) {}

    ~Imbracaminte() {}

    friend ostream &operator<<(ostream &os, const Imbracaminte &haina) {
        os << "Culoare: ";
        os << haina.culoare << "\n";
        os << "Nume: ";
        os << haina.nume << "\n";
        return os;
    }

    friend istream &operator>>(istream &is, Imbracaminte &haina) {
        cout << "Culoare: ";
        is >> haina.culoare;
        cout << "Nume: ";
        is >> haina.nume;
        return is;
    }

    Imbracaminte& operator=(const Imbracaminte& ob);

    const string &getCuloare() const {
        return culoare;
    }

    const string &getNume() const {
        return nume;
    }

    void setCuloare(const string &culoare) {
        Imbracaminte :: culoare = culoare;
    }

    void setNume(const string &nume) {
        Imbracaminte :: nume = nume;
    }

    bool operator==(const Imbracaminte &rhs) const;

    bool operator!=(const Imbracaminte &rhs) const;
};

Imbracaminte &Imbracaminte :: operator=(const Imbracaminte &ob) {
    culoare=ob.culoare;
    nume=ob.nume;
    return *this;
}

bool Imbracaminte :: operator==(const Imbracaminte &rhs) const {
    return culoare==rhs.culoare && nume==rhs.nume;
}

bool Imbracaminte :: operator!=(const Imbracaminte &rhs) const {
    return !(rhs==*this);
}


class MeniuInteractiv {
private:
    vector<Imbracaminte> imbracaminte;
public:
    MeniuInteractiv(){}

    MeniuInteractiv(const vector<Imbracaminte> &imbracaminte) : imbracaminte(imbracaminte) {}

    void Optiuni()  {
        cout << "1. Adauga o noua haina." << '\n';
        cout << "2 Modifica o haina." << '\n';
        cout << "3 Prezentare haine. "<< '\n';
        cout << "4 Iesire." << '\n';
    }

    int AlegeOptiune(int first, int last) {
        int option=-1;
        while (option < first || option > last) {
            cout << '\n';
            cout << "Pentru a rula comanda, alegeti un numar intre " << first << " si " << last << '\n';
            Optiuni();
            cout << "Alegere: ";
            cin >> option;
        }
        return option;
    }

    void option1() {
        Imbracaminte h;
        cout << "Haina noua: " << '\n';
        cin >> h;
        imbracaminte.push_back(h);
        cout << "Aici vom adauga o noua haina." << '\n';
    }

    void option2(){
        string culoare1, nume1;
        int index;
        cout << "index: ";
        cin >> index;
        if (index<0 || index>imbracaminte.size())
            cout << "Nu are ce sa modifice\n";
        else {
            cout << "Aici vom modifica datele uneia dintre hainele existente." << '\n';
            cout << "alta culoare: ";
            cin >> culoare1;
            cout << "alt nume: ";
            cin >> nume1;
            imbracaminte[index].setCuloare(culoare1);
            imbracaminte[index].setNume(nume1);
        }
    }
    void option3() {
        for (int i=0; i<imbracaminte.size(); i++)
            cout << imbracaminte[i] << '\n';
        cout << '\n';
    }

    void mainLoop() {
        while (true) {
            int option=AlegeOptiune(1, 4);
            if (option==1) {
                option1();
            }
            else if (option==2) {
                option2();
            }
            else if (option==3) {
                option3();
            }
            else if (option==4) {
                break;
            }
        }
        cout << '\n'
             << "---------------------------------"
             << '\n'
             << "Programul s-a incheiat cu success\n";
    }

};


int main() {
    MeniuInteractiv menu;
    menu.mainLoop();
}