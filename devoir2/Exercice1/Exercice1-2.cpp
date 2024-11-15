#include <iostream>
#include "Exercice1-1.cpp"

using namespace std;

int main() {
    // Automatic object
    pile_entier pile1(10);

    // Dynamic object
    pile_entier* pile2 = new pile_entier(5);

    // Using the automatic object
    pile1.empiler(1);
    pile1.empiler(2);
    pile1.empiler(3);
    cout << "Depile from pile1: " << pile1.depiler() << endl;

    // Using the dynamic object
    pile2->empiler(10);
    pile2->empiler(20);
    cout << "Depile from pile2: " << pile2->depiler() << endl;

    // Clean up dynamic object
    delete pile2;

    return 0;
}