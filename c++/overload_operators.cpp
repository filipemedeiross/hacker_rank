#include<iostream>

using namespace std;

class Complex {
    public:
        int a, b;

        void input (string s) {
            int i = 0, v1 = 0, v2 = 0;

            while (s[i] != '+') {
                v1 = v1*10 + s[i] - '0';
                i++;
            }

            while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
                i++;

            while (i < s.length()) {
                v2 = v2*10 + s[i] - '0';
                i++;
            }

            a = v1;
            b = v2;
        }
};

Complex operator + (Complex &c1, Complex &c2) {
    Complex result;

    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
    
    return result; 
}

ostream& operator << (ostream &out, Complex &c) {
    cout << c.a << "+i" << c.b;
    
    return out;
}

int main () {
    Complex x, y, z;
    string s1, s2;

    cin >> s1 >> s2;

    x.input(s1);
    y.input(s2);

    z = x + y;

    cout << z << endl;
}