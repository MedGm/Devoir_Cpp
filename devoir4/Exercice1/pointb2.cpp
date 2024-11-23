#include<iostream>
#include<cmath>
#include "point2.hpp" // on inclut le fichier d'en-tête de la classe point

using namespace std;

class pointB : public point {
    public :
    pointB() : point() {} // Introduire un constructeur dans la classe point-B.
    void rho() {
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

/* Question iv)
Les fonctions membres utilisables pour un objet de type pointB sont:

1. Héritées de la classe point:
    - initialise(float abs, float ord) : Initialise les coordonnées x et y
    - affiche() : Affiche les coordonnées du point

2. Propres à la classe pointB:
    - pointB() : Constructeur par défaut 
    - rho() : Calcule et affiche la distance du point à l'origine (racine carrée de x²+y²)

Note: Les membres x et y sont accessibles dans pointB car ils sont déclarés protected dans la classe point
*/

