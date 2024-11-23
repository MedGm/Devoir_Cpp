#include<iostream>

using namespace std;

template<class T> 
class vect {
    T *tab;
    int taille;
public:
    vect(int n) {
        taille = n;
        tab = new T[n];
    }
    ~vect() {
        delete[] tab;
    }
    T& operator[](int i) {
        if (i < 0 || i >= taille) {
            cerr << "indice non valide" << endl;
            exit(1);
        }
        return tab[i];
    }
};

int main() {
    vect<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    for (int i = -1; i < 3; i++) {
        cout << v[i] << endl;
    }
    return 0;
}