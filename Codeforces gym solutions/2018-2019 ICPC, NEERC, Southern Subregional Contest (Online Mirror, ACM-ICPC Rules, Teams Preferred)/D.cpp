#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int MLOG = 35;
const int MAX = 2 * 100 * 1000 + 5;
int n, k;
ll a[MAX];
int main(){
	fast();
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll ans = 0;
	if (n == 1){
		return cout << ((a[0] + k - 1) / k) << "\n", 0;
	}

	for (int i = 1; i < n - 1; i++){
		int w = a[i] + a[i - 1];
		ans += (w / k);

		if (w % k <= a[i]){
			a[i] = w%k;
		}
		else{
			ans++;
			a[i] = 0;
		}
	}
	cout << ans + (a[n - 1] + a[n - 2] + k - 1) / k << endl;
	return 0;
}