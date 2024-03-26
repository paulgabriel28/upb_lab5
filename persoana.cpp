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


