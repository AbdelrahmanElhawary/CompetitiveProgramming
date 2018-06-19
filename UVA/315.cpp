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
const int MAX_N = 1e3;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt;
vector<int>adj[MAX_N];
bool vis[MAX_N],viss[MAX_N];
int cnty;
void dfs(int v, int p = -1) {
	vis[v] = 1;
	dfsn[v] = dfsl[v] = dfscnt++;
	int child = 0;
	for (auto &to:adj[v]) {
		if (to == p) continue;
		if (vis[to])
			dfsl[v] = min(dfsl[v], dfsn[to]);
		else {
			dfs(to, v);
			dfsl[v] = min(dfsl[v], dfsl[to]);
			if (dfsl[to] >= dfsn[v] && p != -1)
				if (!viss[v])
					viss[v] = 1, cnty++;
			child++;
		}
	}
	if (p == -1 && child > 1)
		if (!viss[v])
			viss[v] = 1, cnty++;
}

int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n;
	while (cin >> n&&n)
	{
		int u;
		while (cin >> u&&u)
		{
			string s;
			getline(cin, s);
			int v = 0;
			for (int i = 1; i < s.size(); i++)
			{
				if (s[i] == ' ')
				{
					if (!v)continue;
					adj[u].push_back(v);
					adj[v].push_back(u);
					v = 0;
				}
				else
				{
					v *= 10;
					v += s[i] - '0';
				}
			}
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1);
		cout << cnty << endl;
		for (auto& v : adj)
		v.clear();
		memset(vis, 0, sizeof vis);
		memset(viss, 0, sizeof(viss));
		memset(dfsl, 0, sizeof dfsl);
		memset(dfsn, 0, sizeof dfsn);
		cnty = 0;
		dfscnt = 0;
	}

	pause();
	return 0;
}