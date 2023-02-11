#include <iostream>

#define N 5

using namespace std;

class Student {
    private:
        int scores[N];
    public:
        void input () {
            for (int i = 0; i < N; i++)
                cin >> scores[i];
        }

        int calculateTotalScore () {
            int sum = 0;

            for (int i = 0; i < N; i++)
                sum += scores[i];

            return sum;
        }
};

int main() {
    int n, kristen_score, count, total;
    Student *s;

    cin >> n;  // number of students
    
    s = new Student[n];  // an array of n students
    
    for (int i = 0; i < n; i++)
        s[i].input();

    kristen_score = s[0].calculateTotalScore();  // kristen's score

    // Determine how many students scored higher than kristen
    count = 0; 
    for(int i = 1; i < n; i++){
        total = s[i].calculateTotalScore();

        if(total > kristen_score)
            count++;
    }

    // Print result
    cout << count;
    
    return 0;
}