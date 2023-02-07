#include <iostream>

using namespace std;

int main() {
    unsigned short N, *A;

    cin >> N;
    
    A = new unsigned short[N];
    for (int i=0; i<N; i++)
        cin >> A[i];
        
    for (int i=N-1; i>=0; i--)
        cout << A[i] << " ";
    
    return 0;
}