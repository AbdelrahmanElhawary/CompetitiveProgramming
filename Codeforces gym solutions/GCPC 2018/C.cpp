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
vector<pair<int,ll>>adj[N];
int n, m;
int in[N];
ll sub[N];
bool vis[N];
void dfs(int u) {
	vis[u] = 1;
	ll sum = 0;
	//cout << u << endl;
	for (auto e : adj[u]) {
		if (!vis[e.first]) {
			//cout << "into : ";
			dfs(e.first);
			//cout << e.first << " " << sub[e.first] + e.second << endl;
			//cout << "back : \n";
		}
		sum = max(sum, e.second + sub[e.first]);
	}
	sub[u] = sum;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		in[v]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]&&!in[i]) {
			dfs(i);
		}
		ans = max(ans, sub[i]);
	}
	cout << ans << endl;
	return 0;
}