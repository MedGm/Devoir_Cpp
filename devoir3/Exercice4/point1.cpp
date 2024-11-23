#include<iostream>

using namespace std;

template <class T> class point
{ 
    T x, y ; // coordonnees
public :
    point (T abs, T ord) { x = abs ; y = ord ; }
    void affiche (){ cout << "Coordonnees : " << x << " " << y << "\n" ; }
};

//----------------i)---------------------------------
template<class T> class pointcol : public point<T>
{
    T couleur;
public:
    pointcol(T abs, T ord, T col) : point<T>(abs, ord) { couleur = col; }
    void affiche() { point<T>::affiche(); cout << "Couleur : " << couleur << "\n"; }
};

//----------------ii)--------------------------------
template<class U> class pointcol2 : public pointcol<U>
{
    U couleur2;
public:
    pointcol2(U abs, U ord, U col, U col2) : pointcol<U>(abs, ord, col) { couleur2 = col2; }
    void affiche() { pointcol<U>::affiche(); cout << "Couleur2 : " << couleur2 << "\n"; }
};

//----------------iii)--------------------------------

class pointcol3 {
    int x, y;
    short couleur3;
public:
    pointcol3(int abs, int ord, short col) { x = abs; y = ord; couleur3 = col; }
    void affiche() { cout << "Coordonnees3 : " << x << " " << y << "\n" << "Couleur3 : " << couleur3 << "\n"; }
};

int main()
{
    point<int> p1(2, 3);
    p1.affiche();
    pointcol<int> p2(2, 3, 4);
    p2.affiche();
    pointcol2<int> p3(2, 3, 4, 5);
    p3.affiche();
    pointcol3 p4(2, 3, 4);
    p4.affiche();
    return 0;
}