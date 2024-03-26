#include <iostream>
#include <string>
#include <fstream>
#include "persoana.h"

using namespace std;

// 040728
void sortare_data_nastere(Persoana* vec, const int &dim) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if(vec[j].getDataNastere() > vec[i].getDataNastere()) {
                Persoana aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux; // creare operator=
            }
        }
    }
}

int mai_multe_prenume(Persoana *vec, const int &dim) {
    int nr = 0;
    fstream f("MaiMultePrenume.txt", ios::app);
    for(int i = 0; i < dim; i++) {
        if(vec[i].getNrPrenume() > 1) {
            f << vec[i];
            nr ++;
        }
    }

    return nr;
}


int main()
{
    // 1. 
    // done in persoana.cpp & persoana.h

    // 2.
    int n;
    cout << "Dimensiune vector: ";
    cin >> n;

    Persoana *vec_2 = new Persoana[n];
    for(int i = 0; i < n; i++) {
        cin >> vec_2[i];
    }
    
    fstream f("persoane.txt", ios::app);
    for(int i = 0; i < n; i++) {
        f << vec_2[i];
    }
    f.close();

    // 3.
    Persoana *vec = new Persoana[n];
    f.open("persoane.txt", ios::in);
    for(int i = 0; i < n; i++) {
        f >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        if(vec[i].eStudent() == false) {
            cout<<vec[i];
        }
    }

    // 4.
    cout<<"Vector sortat dupa data nasterii: \n";
    sortare_data_nastere(vec, n);
    for(int i = 0; i < n; i++)
        cout<<vec[i];

    // 5.
    cout << "Sunt " << mai_multe_prenume(vec, n) << " persoane cu mai multe prenume, iar acestea au fost scrise in fisierul MaiMultePersoane.txt";


    return 0;
}