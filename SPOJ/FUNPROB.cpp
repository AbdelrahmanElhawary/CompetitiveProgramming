#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	int n, m;
	while (cin >> n >> m) {
		if (n + m == 0)return 0;
		if (n > m) { cout << 0. << endl; continue; }
		if (n == 0) { cout << 1. << endl; continue; }
		cout << (m - n + 1.) / (m + 1) << endl;
	}
	return 0;
}