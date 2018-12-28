#include <iostream>
#include <cmath>

using namespace std;

double Square(double input) {return pow(input,2);}
double Cube(double input) {return pow(input,3);}
double Root(double input) {return pow(input,0.5);}


int main()
{
    double (*someFunct) (double);
    someFunct = Square;
    cout << "Square of 2 is " << someFunct(2) << endl;
    someFunct = Cube;
    cout << "Cube of 2 is " << someFunct(2) << endl;
    someFunct = Root;
    cout << "Square root of 2 is " << someFunct(2) <<
    endl;
    return 0;
}
