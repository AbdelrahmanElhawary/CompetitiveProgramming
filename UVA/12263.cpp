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
const int N = 505 + 50, M = 1e5 + 10, mod = 1e9+7;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
bool edg[505][505];
int ar[N],in[N];
int n, ans[N];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> ar[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				edg[ar[i]][ar[j]] = (j > i);
		int m; cin >> m;
		while (m--) {
			int u, v;
			cin >> u >> v;
			swap(edg[u][v], edg[v][u]);
		}
		queue<int>q;
		for (int i = 1; i <= n; i++){
			in[i] = 0;
			for (int j = j = 1; j <= n; j++)
				in[i] += edg[j][i];
			if (!in[i])
				q.push(i);
		}
		int c = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			ans[c++] = u;
			for (int i = 1; i <= n; i++) {
				if (edg[u][i]) {
					if(!(--in[i]))q.push(i);
				}
			}
		}
		if (c != n)cout << "IMPOSSIBLE\n";
		else for (int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i == n - 1];
	}
	return 0;
}