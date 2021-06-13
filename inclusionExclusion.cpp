/*
    Find the count of numbers divisible by 2 numbers within a given range
*/
#include <iostream>
using namespace std;

int divisible(int num, int n1, int n2) {
    int c1 = num/n1;
    int c2 = num/n2;
    int c3 = num/(n1*n2);
    return(c1+c2-c3);
}

int main() {
    int n, n1, n2;
    cin>> n;
    cin>> n1 >> n2;
    cout<< divisible(n, n1, n2);
}