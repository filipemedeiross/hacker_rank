#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void parseInts(string str, vector<int> &ints) {
    int i;
    char ch;
    
    stringstream ss(str);

    do {
        ss >> i >> ch;
        ints.push_back(i);
    } while (ss.eof() == 0);
}

int main() {
    string str;
    vector<int> integers;
    
    cin >> str;
    
    parseInts(str, integers);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << endl;
    }
    
    return 0;
}