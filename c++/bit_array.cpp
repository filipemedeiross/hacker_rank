#include <iostream>
#include <cmath>

using namespace std;

int main () {
    uint_fast32_t a_prev, a_cur;
    uint_fast32_t n, s, p, q, mod, c;
    bool v;
    
    cin >> n >> s >> p >> q;
    
    mod = pow(2, 31);

    a_cur = s % mod;

    v = true;
    c = 1;
    for (int i = 1; i < n && v; i++) {
        a_prev = a_cur;
        a_cur = (a_prev * p + q) % mod;

        if (a_cur == a_prev)
            v = false;
        else
            c++;
    }
    
    cout << c << endl;

    return 0;
}