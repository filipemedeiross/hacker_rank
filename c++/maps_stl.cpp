#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int q, type, y;
    string x;
    map<string, int> m;
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> type >> x;

        if (type == 1) {
            cin >> y;

            if (m.find(x) == m.end())
                m.insert(make_pair(x, y));
            else
                m[x] += y;
        }
        else if (type == 2)
            m.erase(x);
        else if (type == 3)
            cout << (m.find(x) != m.end() ? m[x] : 0) << endl;
    }
        
    return 0;
}