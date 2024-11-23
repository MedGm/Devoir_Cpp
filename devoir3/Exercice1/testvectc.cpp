#include<iostream>
#include"vectc.hpp"

using namespace std;

int main (){
    vect_c v(10);
    for(int i = 0; i < 10; i++){
        v[i] = i;
    }
    for(int i = 0; i < 10; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
// pour complier en visual studio code terminal: g++ testvectc.cpp vectc.hpp
