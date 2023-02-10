#include <iostream>
#include <deque>
#include <algorithm>

#define N 10000

using namespace std;

void print_k_max (int arr[], int n, int k) {
    int t, max;
    deque<int> v (arr, arr + k);

    max = *max_element (v.begin(), v.end());
    cout << max << " ";

    for (int i = k; i < n; i++) {
        t = v.front();

        v.pop_front();
        v.push_back(arr[i]);

        if (max == t)
            max = *max_element (v.begin(), v.end());
        else if (max < arr[i])
            max = v.back();

        cout << max << " ";
    }

    cout << endl;
}

int main(){
	int t, n, k, i, arr[N];
    
	cin >> t;
	
    while (t > 0) {
    	cin >> n >> k;

    	for(i = 0; i < n; i++)
      		cin >> arr[i];

    	print_k_max (arr, n, k);

    	t--;
  	}

  	return 0;
}