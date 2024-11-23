#include<iostream>

using namespace std;

struct element // structure d'un élément de liste
{ 
    element * suivant ; // pointeur sur l'élément suivant
    void * contenu ; // pointeur sur un objet quelconque
};

class liste { 
    element * debut ; // pointeur sur premier élément
// autres membres données éventuels
public:
    liste(); // constructeur
    ~liste(); // destructeur
void ajoute (void *); // ajoute un élément en début de liste
void* premier () ; // positionne sur premier élément
void * prochain () ; // positionne sur prochain élément
int fini () ;
};
//-------------------partie i)---------------------------------------------
liste::liste() {
    debut = nullptr;
}

liste::~liste() {
    element *courant = debut;
    while (courant != nullptr) {
        element *suivant = courant->suivant;
        delete courant;
        courant = suivant;
    }
}

void liste::ajoute(void *info) {
    element *nouveau = new element;
    nouveau->contenu = info;
    nouveau->suivant = debut;
    debut = nouveau;
}

void* liste::premier() {
    if (debut == nullptr) return nullptr;
    return debut->contenu;
}

void* liste::prochain() {
    if (debut == nullptr || debut->suivant == nullptr) return nullptr;
    debut = debut->suivant;
    return debut->contenu;
}

int liste::fini() {
    return (debut == nullptr);
}
//-------------------partie ii)---------------------------------------------
class point{
    int x, y ;
public:
    point (int abs=0, int ord=0) { x=abs ; y=ord ; }
    void affiche () { cout << "Coordonnées : " << x << " " << y << "\n" ; }
};

class liste_points : public liste, public point {
public:
    liste_points() : liste(), point() {}
    
    void ajoute_point(int x, int y) {
        point* p = new point(x, y);
        ajoute(p);
    }
    
    void affiche() {
        point* p = (point*)premier();
        while (p != nullptr) {
            p->affiche();
            p = (point*)prochain();
        }
    }
};

//-------------------partie iii)---------------------------------------------
int main() {
    liste_points lp;
    
    lp.ajoute_point(1, 2);
    lp.ajoute_point(3, 4);
    lp.ajoute_point(5, 6);
    
    cout << "La liste des points :" << endl;
    lp.affiche();
    
    return 0;
}

