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
const int MAX_N = 1e5+5;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt;
vector<int>adj[MAX_N];
int cnty;
set<int>cutpoint;
set<pair<int, int>>bridge;
void mem()
{
	for (auto& v : adj)
		v.clear();
	memset(dfsl, -1, sizeof dfsl);
	memset(dfsn, -1, sizeof dfsn);
	bridge.clear();
	cutpoint.clear();
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
				bridge.insert({ min(node,e), max(e,node) });
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n;
	bool f = 0;
	while (cin >> n)
	{
		mem();
		for (int i = 0; i < n; i++)
		{
			int u; cin >> u;
			string s; int m=0;
			cin >> s; 
			for (int j = 1; j < s.size() - 1; j++)
				m *= 10, m += s[j] - '0';
			for (int j = 0; j < m; j++)
			{
				int v; cin >> v;
				adj[u].push_back(v);
			}
		}
		for (int i = 0; i < n; i++)
			if (dfsn[i] == -1)dfs(i);
		cout << bridge.size() << " critical links\n";
		while (bridge.size())
		{
			auto u = *bridge.begin();
			bridge.erase(bridge.begin());
			cout << u.first << " - " << u.second << endl;
		}
		cout << endl;

	}
	pause();
	return 0;
}