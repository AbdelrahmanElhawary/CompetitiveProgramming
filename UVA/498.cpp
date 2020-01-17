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
const int N = 1e6 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
ll ans[50001];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	string s;
	while (getline(cin, s)) {
		istringstream ss(s);
		vector<int>c;
		int y;
		while (ss >> y) {
			c.push_back(y);
		}
		reverse(c.begin(), c.end());
		getline(cin, s);
		vector<int>v;
		istringstream ss2(s);
		while (ss2 >> y) {
			v.push_back(y);
		}
		vector<ll>ans;
		for (auto e : v) {
			ll sum = 0;
			ll x = 1;
			for(int i=0;i<c.size();i++)
			{
				sum += c[i] * x;
				x *= e;
			}
			ans.emplace_back(sum);
		}
		for (int i = 0; i < ans.size(); i++) {
			if (i)cout << " ";
			cout << ans[i];
		}
		cout << endl;

		
	}
	return 0;
}