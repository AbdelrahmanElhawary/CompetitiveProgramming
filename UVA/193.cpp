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
int col[N];
vector<vector<int>>adj;
int in[N];
int n, m;
vector<int>ans,temp;
bool check(int u) {
	for(auto e : adj[u])
		if (col[e])return 0;
	return 1;
}
void solve(int u) {
	if (u == n + 1) {
		if (ans.size() < temp.size())ans = temp;
		return;
	}
	if (check(u)) {
		temp.emplace_back(u); col[u] = 1;
		solve(u + 1);
		temp.pop_back(); col[u] = 0;
	}
	solve(u + 1);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		adj.clear();
		adj.resize(n + 1);
		memset(col, 0, (n + 1) * sizeof col[0]);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		ans.clear();
		solve(1);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			if (i)cout << " ";
			cout << ans[i];
		}cout << endl;

	}
	return 0;
}