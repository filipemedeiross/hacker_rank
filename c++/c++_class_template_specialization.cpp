#include <iostream>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <>
struct Traits <Color> {
    static string name (int i) {
        if (i == (int) Color::red)
            return "red";
        if (i == (int) Color::green)
            return "green";
        else if (i == (int) Color::orange)
            return "orange";
        else
            return "unknown";
    }
};

template <>
struct Traits <Fruit> {
    static string name (int i) {
        if (i == (int) Fruit::apple)
            return "apple";
        else if (i == (int) Fruit::orange)
            return "orange";
        else if (i == (int) Fruit::pear)
            return "pear";
        else
            return "unknown";
    }
};

int main () {
	int t = 0, index1, index2;
    
    cin >> t;

    for (int i = 0; i != t; ++i) {
        cin >> index1;
        cin >> index2;
        
        cout << Traits<Color>::name(index1) << " "
             << Traits<Fruit>::name(index2) << endl;
    }
}