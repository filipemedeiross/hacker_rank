#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q, *x, y, *l;

    cin >> n;

    x = new int[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> y;

        l = lower_bound (x, x + n, y);

        cout << (*l == y ? "Yes" : "No") << " " << l - x + 1 << endl;
    }
      
    return 0;
}