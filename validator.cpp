#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

       int n = inf.readInt(1, 100000, "n");
        inf.readSpace();
        int m = inf.readInt(0, (n * (n - 1) / 2 , 100000), "m");
        inf.readSpace();
        int x = inf.readInt(0, 100, "x"); 
        inf.readEoln();

        inf.readInts(n, 0, 100, "g");
        inf.readEoln();

 
        for (int i = 0; i < m; i++) {
            inf.readInt(1, n, "u");
            inf.readSpace();
            inf.readInt(1, n, "v");
            inf.readSpace();
            inf.readInt(0, 200000, "t");
            inf.readEoln();
        }
        
    
    inf.readEof();
}