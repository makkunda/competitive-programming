/*
answer off by hundred correct answer 21124 we are getting 21224                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string x = "onetwothreefourfivesixseveneightnine";
    int n1 = x.length();
    n1 = 9*n1;
    string x2 = "teneleventwelvethirteenfourteenfivteensixteenseventeeneighteennineteen";
    int n2 = x2.length();
    string x3 = "twentythirtyfourtyfiftysixtyseventyeightyninety";
    int n3 = x3.length();
    n3 = n3*10;
    int n4 = n1+n2+n3;
    n4 = 10*n4;
    int n5 = 3*891;
    int n6 = 7*900;
    int n7 = n1*100/9;
    cout<<n4 + n5 + n6 + n7 + 11;
    return 0;
}