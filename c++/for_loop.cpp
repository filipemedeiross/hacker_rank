#include <cstdio>
#include <string>

using namespace std;

int main() {
    unsigned int a, b;
    string numbers[] = {"one", "two", "three",
                        "four", "five", "six",
                        "seven", "eight", "nine"};
    
    scanf("%d %d", &a, &b);

    for (int i=a; i<=b; i++) {
        if (i <= 9)
            printf("%s\n", numbers[i-1].c_str());
        else if (i % 2 == 0)
            printf("even\n");
        else
            printf("odd\n");
    }
    
    return 0;
}