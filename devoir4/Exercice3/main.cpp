#include <iostream>

using namespace std;

template <class T, int n> class essai { 
    T tab [n] ;
public :
    essai (T) ; // constructeur
    essai(const essai&); // constructeur de recopie
};

template <class T, int n> essai<T,n>::essai (T x) {
    for (int i=0; i<n; i++) tab[i] = x ;
}

template <class T, int n> essai<T,n>::essai(const essai& e) {
    for (int i=0; i<n; i++) tab[i] = e.tab[i] ;
}

int main() {
    essai<int, 5> e1(3);
    essai<int, 5> e2(e1);
    return 0;
}