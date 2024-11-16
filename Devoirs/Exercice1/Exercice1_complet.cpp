#include <iostream>

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

    pile_entier(const pile_entier& autre) : capacite(autre.capacite), sommet(autre.sommet) {
        pile = new int[capacite];
        for (int i = 0; i <= sommet; ++i) {
            pile[i] = autre.pile[i];
        }
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

int main() {
    pile_entier pile1(10);

    pile_entier* pile2 = new pile_entier(5);

    pile1.empiler(1);
    pile1.empiler(2);
    pile1.empiler(3);
    cout << "Depile from pile1: " << pile1.depiler() << endl;

    pile2->empiler(10);
    pile2->empiler(20);
    cout << "Depile from pile2: " << pile2->depiler() << endl;

    delete pile2;

    return 0;
}