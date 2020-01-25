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
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int vid;
int vis[10001][100];
bool dp[10001][100];
int ar[10001];
int n, k;
bool solve(int ind, int rem) {
	if (ind == n)
		return rem == 0;
	bool& ret = dp[ind][rem];
	if (vis[ind][rem] == vid)
		return ret;
	vis[ind][rem] = vid;
	ret = solve(ind + 1, ((rem + ar[ind]) % k + k) % k) | solve(ind + 1, ((rem - ar[ind]) % k + k) % k);
	return ret;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		++vid;
		if (solve(0, 0))
			cout << "Divisible\n";
		else cout << "Not divisible\n";
	}
	return 0;
}