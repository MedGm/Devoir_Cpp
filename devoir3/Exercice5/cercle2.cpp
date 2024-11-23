#include<iostream>

using namespace std;

template <class T> class point
{ T x, y ; // coordonnees
public:
    point (T abs, T ord) { x = abs ; y = ord ; }
    void affiche (){ cout << "Coordonnees : " << x << " " << y << "\n" ;}
};

template <class T> class cercle
{
    point<T> centre;
    T rayon;
public:
    cercle(T x, T y, T r) : centre(x, y), rayon(r) {}
    void affiche() {
        centre.affiche();
        cout << "Rayon : " << rayon << endl;
    }
};

int main () {
    cercle<int> c(3,4,5);
    c.affiche();
    return 0;
}