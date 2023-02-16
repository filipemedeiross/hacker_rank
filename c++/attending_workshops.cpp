#include<bits/stdc++.h>

using namespace std;

struct Workshop {
    int st;
    int d;
    int et;
};

bool operator < (Workshop& w1, Workshop& w2) {
    return (w1.et < w2.et) ? true : false;
}

struct Available_Workshops {
    int n;
    Workshop* works;
};

Available_Workshops* initialize (int st[], int d[], int n) {
    Available_Workshops* w = new Available_Workshops{n, new Workshop[n]};
    
    for (int i = 0; i < n; i++)
        w->works[i] = {st[i], d[i], st[i] + d[i]};

    return w;
}

int CalculateMaxWorkshops (Available_Workshops* w) {
    int time = 0, max_workshops = 0;

    sort(w->works, w->works + w->n);

    for (int i = 0; i < w->n; i++) {
        if (time <= w->works[i].st) {
            max_workshops++;

            time = w->works[i].et;
        }
    }

    return max_workshops;
}

int main (int argc, char *argv[]) {
    int n;  // number of workshops
    int *start_time, *duration;
    Available_Workshops *ptr;
    
    cin >> n;
    
    // Create arrays of unknown size n
    start_time = new int[n];
    duration = new int[n];

    for (int i = 0; i < n; i++)
        cin >> start_time[i];

    for (int i = 0; i < n; i++)
        cin >> duration[i];

    ptr = initialize (start_time, duration, n);

    cout << CalculateMaxWorkshops(ptr) << endl;

    return 0;
}