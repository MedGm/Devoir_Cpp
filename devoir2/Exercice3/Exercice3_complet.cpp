#include <iostream>
#include <cstring>


using namespace std;


class chaine {
private:
    int longueur;
    char* contenu;


public:
    // on declare chaine() : initialise une chaîne vide ;
    chaine() : longueur(0), contenu(nullptr) {}


    // chaine (char*) : initialise la chaîne avec la chaîne (au sens du C) dont on fournit l'adresse en argument ;
    chaine(const char* str) {
        longueur = strlen(str);
        contenu = new char[longueur];
        memcpy(contenu, str, longueur);
    }


    // chaine (chaine&) : constructeur de recopie.
    chaine(const chaine& autre) : longueur(autre.longueur) {
        contenu = new char[longueur];
        memcpy(contenu, autre.contenu, longueur);
    }


    // Destructeur ~chaine() (pas demandé dans l’exercice mais on l’ajoute pour éviter les fuites mémoire)


    ~chaine() {
        delete[] contenu;
    }


    // Opérateur d'affectation
    chaine& operator=(const chaine& autre) {
        if (this == &autre) return *this; // Vérification d'auto-affectation


        delete[] contenu; // Libérer la mémoire existante


        longueur = autre.longueur;
        contenu = new char[longueur];
        memcpy(contenu, autre.contenu, longueur);
		 // Copie des données de l'autre objet dans le nouvel objet
        return *this;
    }


    // Opérateur d'égalité
    bool operator==(const chaine& autre) const {
        if (longueur != autre.longueur) return false;
        return memcmp(contenu, autre.contenu, longueur) == 0;
		// memcmp renvoie 0 si les données sont identiques
    }


    // Opérateur de concaténation (on va pas modifier l’état du l’objet “autre”)
    chaine operator+(const chaine& autre) const {
        chaine resultat;
        resultat.longueur = longueur + autre.longueur;
        resultat.contenu = new char[resultat.longueur];
        memcpy(resultat.contenu, contenu, longueur);
        memcpy(resultat.contenu + longueur, autre.contenu, autre.longueur);
        return resultat;
    }










    // Opérateur de souscription ou d’indexation (les affectations de la forme a[i] = 'x')


    char& operator[](int index) {
        if (index < 0 || index >= longueur) {
            throw out_of_range("Index hors limites");
        }
        return contenu[index];
    }


    // Fonction d'affichage
    void afficher() const {
        for (int i = 0; i < longueur; ++i) {
            cout << contenu[i];
        }
        cout << endl;
    }
};


int main() {
    // Tester la classe chaine
    chaine ch1("Bonjour");
    chaine ch2("Monde");
    chaine ch3 = ch1 + ch2;


    ch1.afficher(); // Sortie: Bonjour
    ch2.afficher(); // Sortie: Monde
    ch3.afficher(); // Sortie: BonjourMonde


    if (ch1 == chaine("Bonjour")) {
        cout << "ch1 est égal à 'Bonjour'" << endl;
    }


    ch1[3] = 's';
    ch1[5] = 'i';
    ch1.afficher(); // Sortie: Bonsoir


    return 0;
}