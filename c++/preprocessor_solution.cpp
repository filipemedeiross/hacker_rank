#include <iostream>
#include <vector>

#define foreach(v, i) for (int i = 0; i < v.size(); i++)
#define io(v) cin >> v
#define FUNCTION(f, o) void f (int& a, int b) {if (b o a) a = b;};
#define toStr(a) #a
#define INF 100000000

using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main () {
	int n, mn = INF, mx = -INF, ans;
    
    cin >> n;
	
    vector<int> v (n);

	foreach(v, i) {
		io(v)[i];
	}
	
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}

	ans = mx - mn;

	cout << toStr(Result =) << ' ' << ans;
	
    return 0;
}