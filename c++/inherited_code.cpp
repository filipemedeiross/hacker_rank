#include <iostream>
#include <string>
#include <exception>

using namespace std;

class BadLengthException {
    private:
        int n;
    public:
        BadLengthException (int n) {
            this->n = n;
        }

        int what () {
            return n;
        }
};

bool check_username (string username) {
	int n = username.length();

	if (n < 5)
		throw BadLengthException (n);

	for (int i = 0; i < n-1; i++) {
		if (username[i] == 'w' && username[i+1] == 'w')
			return false;
	}

	return true;
}

int main () {
	int T;
    string username;

    cin >> T;

	while (T--) {
		cin >> username;

		try {
			if (check_username (username))
				cout << "Valid" << endl;
			else
				cout << "Invalid" << endl;

		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << endl;
		}
	}

	return 0;
}