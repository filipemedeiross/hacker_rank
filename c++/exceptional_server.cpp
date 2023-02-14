#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Server {
    private:
	    static int load;
    public:
        static int compute(long long A, long long B) {
            load += 1;

            if (A < 0) {
                throw std::invalid_argument("A is negative");
            }

            int real = -1, cmplx = sqrt(-1), ans;
            vector<int> v(A, 0);
            
            if (B == 0) throw 0;

            real = (A / B) * real;
            ans = v.at(B);
            
            return real + A - B*ans;
        }

        static int getLoad() {
            return load;
        }
};

int Server::load = 0;

int main() {
	int T;
    long long A, B;
    
    cin >> T;
	
    while(T--) {
		cin >> A >> B;

		try {
            cout << Server::compute (A, B) << endl;
        }
        catch (bad_alloc) {
            cout << "Not enough memory" << endl;
        }
        catch (exception& e) {
            cout << "Exception: " << e.what() << endl;     
        }
        catch (...) {
            cout << "Other Exception" << endl;
        }
	}

	cout << Server::getLoad() << endl;
	
    return 0;
}