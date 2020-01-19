#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
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
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 100 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--) {
		int n; ll b;
		cin >> n >> b;
		map<string, vector<pair<ll,ll>>>mp;
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			ll x1, x2; cin >> x1 >> x2;
			mp[s1].push_back({ x2,x1 });
		}
		for (auto &e : mp) {
			sort(e.second.begin(),e.second.end());
			for (int i = e.second.size() - 2; i > -1; --i) {
				e.second[i].second = min(e.second[i].second, e.second[i + 1].second);
			}
		}
		ll s = 0, ee = 1000000000, ret = s;
		while (s <= ee) {
			ll mid = (s + ee) / 2;
			ll prc = 0;
			bool ok = 1;
			for (auto e : mp) {
				if (e.second[e.second.size() - 1].first < mid) { ok = 0; break; }
				int l = 0, r = e.second.size() - 1, ind = r;
				while (l <= r) {
					int md = (l + r) / 2;
					if (e.second[md].first >= mid) { ind = md; r = md - 1; }
					else l = md + 1;
				}
				prc += e.second[ind].second;
			}
			if (ok && prc <= b)
				s = mid + 1, ret = mid;
			else ee = mid - 1;
		}
		cout << ret << endl;
	}
	return 0;
}