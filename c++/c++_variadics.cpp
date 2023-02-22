#include <iostream>

using namespace std;

template <typename=void>
int reversed_binary_value () {
    return 0;
}

template <bool d, bool... digits>
int reversed_binary_value () {
    return d + 2 * reversed_binary_value<digits...>();
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y) {
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues <0, digits...> {
  	static void check(int x, int y) {
    	int z = reversed_binary_value<digits...>();
    	cout << (z + 64*y == x);
  	}
};

int main() {
  	int t, x, y;
    
    cin >> t;

  	for (int i = 0; i != t; ++i) {
    	cin >> x >> y;

    	CheckValues<6>::check(x, y);
    	cout << endl;
  	}
}