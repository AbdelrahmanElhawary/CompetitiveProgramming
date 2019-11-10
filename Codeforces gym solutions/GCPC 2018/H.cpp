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
ll mx = 1e16;
ll po(ll s, ll n) {
	ll c = s;
	for (int i = 1; i < n; i++) {
		if ((mx / c) + 1 < s)
			return -1;
		s *= c;
	}
	return s;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	ll m;
	cin >> m;
	for (int n = 3; n <= 56; n++) {
		ll sum = 0;
		for (ll s = 1; sum < m; s++) {
			ll x = po(s, n-1);
			//cout << n << " " << s << " " << x<<" "<<sum << endl;
			if (x == -1)break;
			sum += x;
			if (sum == m) {
				cout << n << " " << s << endl;
				return 0;
			}
		}
	}
	cout << "impossible\n";
	return 0;
}