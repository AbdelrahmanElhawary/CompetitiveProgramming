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
	//	cout << fixed << setprecision(4);
		int t,tt=1; cin >> t;
		while (t--) {
			ll n; cin >> n; n %= (ll)(1e9 + 7);
			cout << (n * n)%(ll)(1e9+7) << endl;
		
		}
		//system("pause");
	return 0;
}