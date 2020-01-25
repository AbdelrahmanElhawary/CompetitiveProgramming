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
int m, w, c;
int vis[101][101];
int vid;
ld p1, p2;
ld dp[101][101];
ld solve(int ind,int tok) {
	if (ind == c)
		return tok % 2 == 0;
	ld& ret = dp[ind][tok];
	if (vis[ind][tok]==vid)return ret;
	vis[ind][tok] = vid;
	return ret= p1* solve(ind + 1, tok + 1) + p2 * solve(ind + 1, tok);
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(7);
	while (cin>>m>>w>>c) {
		if (m + w == 0)return 0;
		++vid;
		p1 = 1. * m / (m + w);
		p2 = 1. * w / (m + w);
		cout << solve(0, 0) << endl;
	}
	return 0;
}