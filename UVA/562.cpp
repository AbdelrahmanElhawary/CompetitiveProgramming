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
string s1, s2;
int vis[101][50001];
int dp[101][50001];
int vid;
int n, sum;
int ar[101];
int solve(int ind, int tot) {
	if (ind == n) 
		return abs((sum - tot) - tot);
	int& ret = dp[ind][tot];
	if (vis[ind][tot] == vid)
		return ret;
	vis[ind][tot] = vid;
	ret = min(solve(ind + 1, tot), solve(ind + 1, tot + ar[ind]));
	return ret;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]); sum += ar[i];
		}
		++vid;
		printf("%d\n", solve(0, 0));
	}
	return 0;
}