#include <iostream>

using namespace std;

class A {
    int callA;

    void inc () {
        callA++;
    }

    public:
        A () {callA = 0;}

        int getA () {
            return callA;
        }

    protected:
        void func (int& a) {
            a = a * 2;
            inc ();
        }
};

class B {
    int callB;

    void inc () {
        callB++;
    }

    public:
        B () {callB = 0;}

        int getB () {
            return callB;
        }
    protected:
        void func (int& a) {
            a = a * 3;
            inc ();
        }
};

class C {
    int callC;

    void inc () {
        callC++;
    }

    public:
        C () {callC = 0;}

        int getC () {
            return callC;
        }
    protected:
        void func(int& a) {
            a = a * 5;
            inc ();
        }
};

class D : public A, public B, public C {
	int val;

	public:
		D () {val = 1;}  // initially val is 1

	    void update_val (int new_val) {
            while (new_val % 2 == 0) {
                new_val = new_val / 2;
                A::func (val);
            }

            while (new_val % 3 == 0) {
                new_val = new_val / 3;
                B::func (val);
            }

            while (new_val % 5 == 0) {
                new_val = new_val / 5;
                C::func (val);
            }
		}
		 
		void check (int);  // for Checking Purpose
};

void D::check (int new_val) {
    update_val (new_val);

    cout << "Value = " << val << endl <<
            "A's func called " << getA() << " times" << endl <<
            "B's func called " << getB() << " times" << endl <<
            "C's func called " << getC() << " times" << endl;
}

int main () {
    int new_val;
    D d;
    
    cin >> new_val;
    
    d.check(new_val);
}