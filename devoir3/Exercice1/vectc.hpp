#ifndef VECTC_HPP
#define VECTC_HPP

class vect{ 
    protected : // en prévision d'une éventuelle classe dérivée
     int nelem ; // nombre d'éléments  taille
     int * adr ; // adresse zone dynamique contenant les éléments
       
     public :
     vect(){}
     vect (int) ; // constructeur
    ~vect () ; // destructeur
     int & operator [ ] (int) ; // accès à un élément par son "indice"

} ;

vect::vect(int n){
    this->nelem = n;
     adr = new int[nelem];
}

vect::~vect(){
    delete[] adr;
}

int& vect::operator[](int indice){
      return this->adr[indice];
}


class vect_c:public vect{
     public:
       vect_c(int n):vect(n){}
       vect_c(vect_c&);   // constructeur par recopie
       vect_c & operator = (vect_c &); // surdéfinition de l'affectation de vec

       int & operator [] (int a){
            if (a >= 0 && a < nelem) {
                return vect::operator[](a);
            }
            return adr[0]; // Default return for invalid index
       }
       int taille(){
        return this->nelem;
       }

};

vect_c::vect_c(vect_c& obj){
      this->nelem = obj.nelem;
      this->adr = new int[obj.nelem]; 
      for(int i = 0; i < nelem; i++){
          adr[i] = obj.adr[i];
      }
}

 vect_c & vect_c::operator = (vect_c& obj){
      if(this != &obj){
          delete[] adr;
          this->nelem = obj.nelem;
          this->adr = new int[obj.nelem]; 
          for(int i = 0; i < nelem; i++){
              adr[i] = obj.adr[i];
          }
      }
      return *this;
 }

#endif