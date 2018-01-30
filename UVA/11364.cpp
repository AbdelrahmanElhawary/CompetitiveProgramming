#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include <utility>
#include<set>
#include<string.h>
#include <deque>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
		fast_in_out();
		//cout << fixed << setprecision(0);
		int t; cin >> t;
		while (t--) {
			int n; cin >> n;
			int mn = 1e9, mx = 0;
			for (int i = 0; i < n; i++)
			{
				int x; cin >> x;
				mn = min(x, mn);
				mx = max(x, mx);
			}
			cout << (mx - mn) * 2 << endl;
		}
		//system("pause");
	return 0;
}