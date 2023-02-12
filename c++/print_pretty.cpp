#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int T;
    double A, B, C;
    
    cin >> T;
	
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
	
    while(T--) {
        cin >> A;
        cin >> B;
	cin >> C;

        cout << showbase << setbase(16) << left << nouppercase;
        cout << (long long) A << endl;

        cout << showpos << noshowbase << setbase(10) << right << fixed << setprecision(2) << setfill('_') << setw(0xf);
        cout << B << endl;

        cout << noshowpos << noshowbase << scientific << uppercase << setprecision(9);
        cout << C << endl;
	}

	return 0;
}
