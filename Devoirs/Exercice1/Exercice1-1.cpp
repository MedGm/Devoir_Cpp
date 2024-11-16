#include<iostream>

using namespace std;

class pile_entier {
private:
    int* pile;
    int capacite;
    int sommet;

public:
    pile_entier(int n) : capacite(n), sommet(-1) {
        pile = new int[n];
    }

    pile_entier() : capacite(20), sommet(-1) {
        pile = new int[20];
    }

    ~pile_entier() {
        delete[] pile;
    }

    void empiler(int n) {
        if (pleine()) {
            cout << "La pile est pleine." << endl;
            return;
        }
        pile[++sommet] = n;
    }

    int depiler() {
        if (vide()) {
            cout << "La pile est vide." << endl;
            return -1;
        }
        return pile[sommet--];
    }

    int pleine() {
        return sommet == capacite - 1;
    }

    int vide() {
        return sommet == -1;
    }
};