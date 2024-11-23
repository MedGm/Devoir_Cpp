#include <iostream>

class point {
protected:
    int x, y;
public:
    point(int abs = 0, int ord = 0) : x(abs), y(ord) {}
    friend int operator==(point, point);
};

int operator==(point a, point b) {
    return a.x == b.x && a.y == b.y;
}

class pointcol : public point {
    int cl;
public:
    pointcol(int abs = 0, int ord = 0, int coul = 0) : point(abs, ord), cl(coul) {}
};

int main() {
    pointcol a(1, 2, 3);
    pointcol b(1, 2, 4);
    point p(1, 2);

    // Test des différentes comparaisons
    std::cout << "Test des comparaisons :" << std::endl;

    // Instruction 1 : Compare deux pointcol (utilise l'opérateur== de point)
    if (a == b) std::cout << "a == b" << std::endl;
    
    // Instruction 2 : Compare un pointcol avec un point
    if (a == p) std::cout << "a == p" << std::endl;
    
    // Instruction 3 : Compare un point avec un pointcol
    if (p == a) std::cout << "p == a" << std::endl;

    /* Note: Les instructions 4 et 5 (if (a == 5) et if (5 == a)) sont invalides
       car il n'existe pas de conversion implicite entre int et pointcol */

    return 0;
}