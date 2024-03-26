#include <iostream>
#include <string>
#include "persoana.h"

using namespace std;

Persoana::Persoana() {
    nume = "";
    prenume = "";
    CNP = "";
    student = false;
}

Persoana::Persoana(string new_nume, string new_prenume, string new_CNP, bool new_student) {
    nume = new_nume;
    prenume = new_prenume;
    CNP = new_CNP;
    student = new_student;
}

ostream& operator<<(ostream &dev, const Persoana &pers) {
    dev << pers.nume << " " << pers.prenume << " " << pers.CNP << " " << pers.student << endl;
    return dev;
}

istream& operator>>(istream &dev, Persoana &pers) {
    // cout<<"Nume: ";
    dev >> pers.nume;

    // cout<<"Prenume: ";
    dev >> pers.prenume;

    // cout<<"CNP: ";
    dev >> pers.CNP;

    // cout<<"Student (0 / 1): ";
    dev >> pers.student;
    
    return dev;
}

bool Persoana::eStudent() const {
    return student;
}

string Persoana::getDataNastere() const {
    return CNP.substr(1, 6);
}

bool Persoana::eFemeie() const {
    if(CNP[0] == '2' || CNP[0] == 6) {
        return true;
    }
    return false;
}

bool Persoana::eCNPValid() const {
    if(CNP.size() == 13) {
        return true;
    }
    return false;
}

int Persoana::getNrPrenume() const {
    int nr = 0;
    for(int i = 0; i < prenume.size(); i++) {
        if(prenume[i] == '-') {
            nr++;
        }
    }
    return nr + 1;
}

string* Persoana::getPrenumeList() const {
    string *list = new string[getNrPrenume()];
    int nr_list = 0;
    for(int i = 0; i < prenume.size(); i++) {
        if(prenume[i] == '-') {
            nr_list++;
        } else {
            list[nr_list] += prenume[i];
        }
    }
}

string Persoana::getNumePrenume() const {
    return string(nume + " " + prenume);
}

void Persoana::setNumePrenume(string str) {
    int space = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            space = i;
            break;
        }
    }

    nume = str.substr(0, space);
    prenume = str.substr(space + 1, str.size());
}