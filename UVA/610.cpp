ifdef _MSC_VER
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
const int MAX_N = 1e3+3;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt;
vector<int>adj[MAX_N];
int n,m;
bool bridge[MAX_N][MAX_N];
set<pair<int, int>>s;
void mem()
{
	for (auto& v : adj)
		v.clear();
	memset(dfsl, -1, sizeof dfsl);
	memset(dfsn, -1, sizeof dfsn);
	dfscnt = 0;
	s.clear();
	memset(bridge, 0, sizeof bridge);
}
void dfs(int node, int p = -1) {
	dfsn[node] = dfsl[node] = dfscnt++;
	for (auto &e : adj[node]) {
		if (e == p) continue;
		if (dfsn[e] != -1)
			dfsl[node] = min(dfsl[node], dfsn[e]);
		else {
			dfs(e, node);
			dfsl[node] = min(dfsl[node], dfsl[e]);
			if (dfsl[e] > dfsn[node])
			{
				bridge[node][e] = bridge[e][node] = 1;
				s.insert({ e, node });
				s.insert({node, e});
			}
		}
	}
}
void dfs2(int u)
{
	for (auto &v : adj[u])
		if (!bridge[u][v] && !bridge[v][u])
			bridge[u][v] = 1, s.insert({ v, u }), dfs2(v);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int tt = 1;
	while (cin >> n >> m && (m || n))
	{
		mem();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
			dfs2(i);
		cout << tt++ << endl << endl;
		while (s.size())
		{
			auto u = *s.begin();
			s.erase(s.begin());
			cout << u.first << " " << u.second << endl;
		}
		cout << "#\n";
	}
	pause();
	return 0;
}
