#include <bits/stdc++.h>

using namespace std;

class Box {
    private:
        int l {0};
        int b {0};
        int h {0};
        
    public:
        Box () {}
        
        Box (int length, int breadth, int height) {
            l = length;
            b = breadth;
            h = height;
        }
        
        Box (Box& B) {
            l = B.l;
            b = B.b;
            h = B.h;
        }

        int getLength () {
            return l;
        }

        int getBreadth () {
            return b;
        }

        int getHeight () {
            return h;
        };
        
        long long CalculateVolume () {
            return (long long) l * b * h;
        }

        bool operator< (Box& B) {
            bool result = false;

            if (l < B.l)
                result = true;
            else if (l == B.l && b < B.b)
                result = true;
            else if (l == B.l && b == B.b && h < B.h)
                result = true;

            return result;
        }
        
        friend ostream& operator<< (ostream& out, Box& B) {
            out << B.l << " " << B.b << " " << B.h;

            return out;
        }
};

void check2 () {
	int n, type, l, b, h;
    Box temp;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> type;

		if (type == 1) {
			cout << temp << endl;
		} else if (type == 2) {
			cin >> l >> b >> h;

			Box NewBox(l, b, h);

			temp = NewBox;

			cout << temp << endl;
		} else if (type == 3) {
			cin >> l >> b >> h;
			
            Box NewBox(l, b, h);

			if (NewBox < temp)
				cout << "Lesser" << endl;
			else
				cout << "Greater" << endl;
		} else if(type == 4) {
			cout << temp.CalculateVolume() << endl;
		} else if (type == 5) {
			Box NewBox(temp);
			
            cout << NewBox << endl;
		}
	}
}

int main() {
	check2 ();

    return 0;
}