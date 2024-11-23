#include <iostream>
using namespace std;
class pile_entier
{
    int dim; // nombre maximal d'éléments de la pile
    int * adr; // adresse du tableau représentant la pile
    int n_elem; // nombre d'éléments courant de la pile
public :
    pile_entier (int n);
    ~pile_entier ();


//i)
    // Fonction membre pour ajouter un élément à la pile
    void operator<(int n) {
        if (n_elem < dim) {
            adr[n_elem++] = n; //ajoute n au pile et increment nombre elem;
        } else {
            cerr << "Erreur" << endl;
        }
    }


    // Fonction membre pour retirer un élément de la pile
    void operator>(int &n) {
        if (n_elem > 0) {
            n = adr[--n_elem];
        } else {
            cerr << "Erreur" << endl;
        }
    }


//ii)
    // Fonction amie pour ajouter un élément à la pile
    friend void operator<(pile_entier &p, int n) {
        if (p.n_elem < p.dim) {
            p.adr[p.n_elem++] = n;
        } else {
            cerr << "Erreur" << endl;
        }
    }






// Fonction amie pour retirer un élément de la pile
    friend void operator>(pile_entier &p, int &n) {
        if (p.n_elem > 0) {
            n = p.adr[--p.n_elem];
        } else {
            cerr << "Erreur" << endl;
        }
    }
};
