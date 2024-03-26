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
    dev >> pers.nume >> pers.prenume >> pers.CNP >> pers.student;
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
