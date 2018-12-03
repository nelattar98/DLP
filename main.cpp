#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
long int SQandMULT(long int a, long int x, long int p)
{
    long int r = 1;  // r = 1 for initial
    
    a = a % p;  // make sure a is in the range of p
    
    while (x >= 1) //make sure than x = 0 is not being checked since
        //it is not in the range
    {
        if (x % 2 == 1) //if x is odd, then you must perform the MULT of the alg.
            r = (r*a) % p;
        
        a = (a*a) % p; //otherwise SQ (every step must square)
        x = x/2; //this step is the binary step to check if we must multiply or not
        
    }
    return r;
}
long int DLP(long int a, long int b, long int p){
    for(long int i = 1; i < p ; i++){
        long int val = SQandMULT(a, i, p);
        if(val == b){
                return i;
        }
    }
    return -1; //if no i was found
}
int main() {
    // insert code here...
    /*
     Write a program (in your favorite computer programming language) that computes the discrete logarithm in Z*p by brute-force exhaustive search.
     DLP: β = αx mod p
     Search x = logα β = log106 (12375) in Z24691
     */
    //vector<int> Z;
    //int phi = createCyclicField(p, Z);
    long int a = 106, b = 12375, p = 24691;
    
    cout << DLP(a, b, p) << endl;
    return 0;
}
