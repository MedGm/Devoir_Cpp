#include<iostream>
#include<cmath>
#include "point.hpp" // on inclut le fichier d'en-tête de la classe point

using namespace std;

class pointB : public point {
    public :
    void rho() {
        float x = abs();
        float y = ord();
        float rho = sqrt(x*x + y*y);
        cout << "rho = " << rho << endl;
    }
};

int main(){
    point p;
    p.initialise(3, 4);
    p.affiche();
    pointB pB;
    pB.initialise(3, 4);
    pB.rho(); // sqrt(3^2 + 4^2) = 5
}