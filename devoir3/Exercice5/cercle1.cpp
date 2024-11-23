#include<iostream>

using namespace std;

template <class T> class point
{ T x, y ; // coordonnees
public:
    point (T abs, T ord) { x = abs ; y = ord ; }
    void affiche (){ cout << "Coordonnees : " << x << " " << y << "\n" ;}
};

template <class T> class cercle : public point<T>
{ T rayon;
public:
    cercle (T abs, T ord, T r=0) : point<T>(abs, ord) { rayon = r ; }
    void affiche (){ point<T>::affiche() ; cout << "Rayon : " << rayon << "\n" ;}
};

int main () {
    cercle<int> c(3,4,5);
    c.affiche();
    return 0;
}