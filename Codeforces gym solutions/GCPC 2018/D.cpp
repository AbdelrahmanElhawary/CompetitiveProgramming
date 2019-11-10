/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
 
 ICPC DREAM
 */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 1e3 + 100;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n;
	cin >> n;
	vector<ll>v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	ll last = 0;
	ll mn1 = 1e9, mn2 = 0;
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			mn1 = min(mn1, v[i] - last);
			last = v[i] - last;
		}
		else {
			mn2 = min(mn2, v[i] - last);
			last = v[i] - last;
		}
	}
	mn2 *= -1;
	cout << max(0LL, mn1 - mn2 + 1) << endl;
	return 0;
}