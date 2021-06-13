/*
    Generate all subarrays of a given array.

    Iterative method - O(n^3)
    Recursive method - O(n^2)
*/

#include <iostream>
#include <vector>

using namespace std;

void iterative(int arr[], int n) {
    int i, j ,k;
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            for(k=i; k<=j; k++)
                cout<< arr[k] << " ";
            cout<< endl;
        }
    }
}

void recursive(int arr[], int n, int start, int end) {
    if(start == n) 
        return;
    else if(end == n)
        recursive(arr, n, start+1, 0);
    else {
        cout<< endl;
        for(int i=start; i <= end; i++) {
            cout<< arr[i] << " ";
        }
        
        recursive(arr, n, start, end+1);
    }
}

int main() {
    int i, n;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];
    // iterative(arr, n);
    recursive(arr, n, 0, 0);
    return 0;
}