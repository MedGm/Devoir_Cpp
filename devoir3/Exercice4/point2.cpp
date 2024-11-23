#include <iostream>

using namespace std;

template <class T> class point
{
T x, y ; // coordonnees
public :
point (T abs, T ord) { x = abs ; y = ord ; }
void affiche ()
{ cout << "Coordonnees : " << x << " " << y << "\n" ;
}
} ;

template <> void point<char>::affiche()
{
    cout << "Caracteres : " << (int)x << " " << (int)y << "\n";
}

template<class T> class pointcol : public point<T>
{
    int couleur;
public:
    pointcol(T abs, T ord, int c) : point<T>(abs, ord) { couleur = c; }
    void affiche()
    {
        point<T>::affiche();
        cout << "Couleur : " << couleur << "\n";
    }
};

int main()
{
    point<int> p1(2, 3);
    p1.affiche();
    point<char> p2('a', 'b');
    p2.affiche();
    pointcol<int> p3(4, 5, 6);
    p3.affiche();
    pointcol<char> p4('c', 'd', 7);
    p4.affiche();
    return 0;
}