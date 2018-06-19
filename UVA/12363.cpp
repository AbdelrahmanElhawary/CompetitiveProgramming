#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
const int MAX_N = 1e4+5;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt;
vector<int>adj[MAX_N];
int cnty;
set<pair<int, int>>bridge;
int parent[10005], rnk[10005];
void mem()
{
	for (auto& v : adj)
		v.clear();
	memset(dfsl, -1, sizeof dfsl);
	memset(dfsn, -1, sizeof dfsn);
	bridge.clear();
	dfscnt = 0;
}
void dfs(int node, int p = -1) {
	dfsn[node] = dfsl[node] = dfscnt++;
	int child = 0;
	for (auto &e : adj[node]) {
		if (e == p) continue;
		if (dfsn[e] != -1)
			dfsl[node] = min(dfsl[node], dfsn[e]);
		else {
			dfs(e, node);
			dfsl[node] = min(dfsl[node], dfsl[e]);
			if (dfsl[e] > dfsn[node])
				bridge.insert({ node, e });
		}
	}
}
int find(int ind)
{
	if (parent[ind] == ind) return ind;
	return find(parent[ind]);
}

void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);

	if (rnk[xRoot] > rnk[yRoot])
		parent[yRoot] = xRoot;
	if (rnk[xRoot] < rnk[yRoot])
		parent[xRoot] = yRoot;
	if (rnk[xRoot] == rnk[yRoot])
	{
		parent[xRoot] = yRoot;
		rnk[yRoot]++;
	}
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n, m, q;
	while (cin >> n >> m >> q)
	{
		if (!n && !m && !q)break;
		mem();
		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i, rnk[i] = 1;
			if (dfsn[i] == -1)
				dfs(i);
		}
		while (bridge.size())
		{
			auto u = *bridge.begin();
			bridge.erase(bridge.begin());
			merge(u.first, u.second);
		}
		for (int i = 0; i < q; i++)
		{
			int u, v; cin >> u >> v;
			if (find(u) == find(v))
				cout << "Y\n";
			else cout << "N\n";
		}
		cout << "-\n";
	}
	pause();
	return 0;
}