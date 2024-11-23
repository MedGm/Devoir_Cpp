#include<iostream>
#include"vectb.hpp"
using namespace std;

int main(){
    vectB v(10, 5, 2);
    for(int i = 0; i < 10; i++){
        v[i] = i;
    }
    for(int i = 0; i < 10; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

// pour complier en visual studio code terminal: g++ testvectb.cpp vectb.hpp