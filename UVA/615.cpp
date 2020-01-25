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
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

}
//int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
//int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
const int N = 1e3+10, M = 1e4 + 5, mod = 1e9 + 7;
unordered_map<int,bool>in,vis;
map<int,vector<int>>adj;
bool okay = 1;
set<int>s;
int vid, nodes = 0;
void dfs(int u) {
	if (!okay)
		return;
	vis[u];
	nodes++;
	if (adj.find(u) == adj.end())return;
	for (auto e : adj[u]) {
		if (vis.find(e) != vis.end()) {
			okay = 0;
			return;
		}
		dfs(e);
	}

}
void solve() {
	bool danger = 0;
	for (auto e : adj) {
		if (in.find(e.first) == in.end()) {
			if (danger) {
				okay = 0; break;
			}
			dfs(e.first); danger = 1;
		}
	}
	if (nodes != s.size())okay = 0;
	if (okay)
		cout << "Case "<<++vid<<" is a tree.\n";
	else cout << "Case "<<++vid<<" is not a tree.\n";
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//kolo ray7 , ya 5raby
	int u, v;
	while (cin >> u >> v&&u>=0) {
		if (u == 0) {
		//	cout << "wtf is going on\n";
			solve();
			okay = 1;
			nodes = 0;
			in.clear();
			vis.clear();
			adj.clear();
			s.clear();
		}
		else {
			s.insert(u);
			s.insert(v);
			adj[u].push_back(v);
			in[v] = 1;
			if (u == v)okay = 0;
		}
	}
	return 0;
}