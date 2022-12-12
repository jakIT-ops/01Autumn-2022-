#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
    int count;
    for (int a = 2; a < 1000000000; a++) {
        bool prime = true;

        for (int c = 2; c*c <= a; c++) {
             if(a % c == 0) {
                 prime = false;
                 break;
             }

         }

         //if(piime) cout << a << " ";
    }

    return 0;
}

