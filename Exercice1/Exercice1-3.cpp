// Constructeur de recopie
    pile_entier(const pile_entier& autre) : capacite(autre.capacite), sommet(autre.sommet) {
        pile = new int[capacite];
        for (int i = 0; i <= sommet; ++i) {
            pile[i] = autre.pile[i];
        }
    }
