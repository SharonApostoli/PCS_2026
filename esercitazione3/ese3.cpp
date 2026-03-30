#include <iostream>
#include "ese3.h"

int main(){

    rational<int> r1(10,2);
    rational<int> r2(5,4);
    rational<int> r4(0, 8);
    rational<int> r5(9,6);
    rational<int> r6(0,0);
    rational<int> m2(1, 10);
    rational<int> d2(5,9);
    rational<int> n1(3,-5);

    rational<int> r3 = r1 + r2;
    rational<int> m1 = r1 * r3;
    m2 *= r6;
    rational<int> d1 = r5 / r1;
    d2 /= m2;
    n1 -= d1;

    std::cout << "r1: " << r1 << "\n";
    std::cout << "r3: " << r3 << "\n";
    std::cout << "r4: " << r4 << "\n";
    std::cout << "r5: " << r5 << "\n";
    std::cout << "r6: " << r6 << "\n";
    std::cout << "m1: " << m1 << "\n";
    std::cout << "m2: " << m2 << "\n";
    std::cout << "d1: " << d1 << "\n";
    std::cout << "d2: " << d2 << "\n";
    std::cout << "n1: " << n1 << "\n";


    return 0;
}