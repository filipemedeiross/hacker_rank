#include <iostream>

using namespace std;

int main() {
    unsigned int n, q, k, i_, j_;
    int **A;

    cin >> n >> q;

    A = new int*[n];
    for (int i=0; i<n; i++) {
        cin >> k;

        A[i] = new int[k];
        for (int j=0; j<k; j++)
            cin >> A[i][j];
    }
    
    for (int i=0; i<q; i++) {
        cin >> i_ >> j_;

        cout << A[i_][j_] << endl;
    }
       
    return 0;
}