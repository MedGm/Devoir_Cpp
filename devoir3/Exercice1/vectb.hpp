#ifndef VECTB_HPP
#define VECTB_HPP
class vect{ 
    int nelem ; // nombre d'éléments
    int * adr ; // adresse zone dynamique contenant les éléments
public :
    vect (int) ; // constructeur (précise la taille du vecteur)
    ~vect () ; // destructeur
    int & operator [] (int) ; // accès à un élément par son "indice"
};

vect::vect(int n){
    nelem = n;
    adr = new int[nelem];
}

vect::~vect(){
    delete[] adr;
}

int & vect::operator[](int i){
    return adr[i];
}

class vectB : public vect{
    int sup;
    int inf;
public:
    vectB(int, int, int);
    int & operator[](int);
};

vectB::vectB(int n, int sup, int inf = 0) : vect(sup - inf){
    this->inf = inf;
    this->sup = sup;
}

int & vectB::operator[](int i){
    return vect::operator[](i - inf);
}

#endif