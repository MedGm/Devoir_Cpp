#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
class point
{ float x, y ;
public :
void initialise (float abs=0.0, float ord=0.0)
{ x = abs ; y = ord ;
}
void affiche ()
{ std::cout << "Point de coordonnées : " << x << " " << y << "\n" ;
}
float abs () { return x ; }
float ord () { return y ; }
};

#endif