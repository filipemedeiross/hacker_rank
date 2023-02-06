#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int d;
    string numbers[] = {"one", "two", "three",
                        "four", "five", "six",
                        "seven", "eight", "nine"};

    cin >> d;

    if (d > 9)
        cout << "Greater than 9" << endl;
    else
        cout << numbers[d-1] << endl;

    return 0;
}