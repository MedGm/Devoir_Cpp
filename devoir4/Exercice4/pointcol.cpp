#include<iostream>

using namespace std;

template <class T>class pointcol {
    T x, y;
    int couleur;
    public:
        pointcol(T a, T b, int c) : x(a), y(b), couleur(c) {}
        
        void affiche() const {
            cout << "Point(" << x << "," << y << ") de couleur " << couleur << endl;
        }
};

class Position {
    int pos;
public:
    Position(int p) : pos(p) {}
    friend ostream& operator<<(ostream& os, const Position& p) {
        return os << p.pos;
    }
};

int main() {
    // La classe Position peut être utilisée car elle:
    // 1. A un constructeur accessible
    // 2. Définit l'opérateur << pour l'affichage
    pointcol<Position> p(Position(1), Position(2), 3);
    p.affiche();
    return 0;
}
