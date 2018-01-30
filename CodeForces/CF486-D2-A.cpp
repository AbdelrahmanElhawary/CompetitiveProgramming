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
		ll n; cin >> n;
		if (n % 2 == 0)cout << n / 2 << endl;
		else cout << -1 * ((n + 1) / 2) << endl;
	//	system("pause");
	return 0;
}