#include<iostream>

using namespace std;

template<class T, int N> 
class vect {
    T tab[N];  // Fixed size array of N elements
public:
    vect() { } // Constructor doesn't need size parameter anymore
    
    T& operator[](int i) {
        if (i < 0 || i >= N) {
            cerr << "indice non valide" << endl;
            exit(1);
        }
        return tab[i];
    }
};

int main() {
    vect<int, 3> v;
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    
    for (int i = 0; i < 3; i++) {
        cout << v[i] << endl;
    }
    return 0;
}