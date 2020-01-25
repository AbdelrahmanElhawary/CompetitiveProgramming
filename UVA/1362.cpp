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
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int vis[623][623];
int dp[623][623];
int vid;
int n;
string s;
int solve(int i,int j) {
	if (i == j)return 1;
	if (s[i] != s[j])return 0;
	int& ret = dp[i][j];
	if (vis[i][j] == vid)
		return ret;
	vis[i][j] = vid;
	ret = solve(i + 1, j - 1);
	for(int k=i+2;k<j;++k)
		ret = (ret + (1LL * solve(k, j) * solve(i + 1, k - 1)) % mod) % mod;
	return ret;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	while (cin>>s) {
		++vid;
		cout << solve(0, s.size()-1) << endl;
	}

	return 0;
}