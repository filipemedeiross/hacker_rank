#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, a, b;

    cin >> n;

    vector<int> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i]; 

    cin >> a;
    v.erase(v.begin() + a - 1);

    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    cout << v.size() << endl;
    for (auto v_i : v)
        cout << v_i << " ";

    return 0;
}