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
const int MAX_N = 1e3;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt,n,m;
vector<int>adj[MAX_N];
set<string>cutpoint;
string str[MAX_N];
void mem()
{
	for (auto& v : adj)
		v.clear();
	memset(dfsl, -1, sizeof dfsl);
	memset(dfsn, -1, sizeof dfsn);
	cutpoint.clear();
	dfscnt = 0;
}
void dfs(int node, int p = -1) {
	dfsn[node] = dfsl[node] = dfscnt++;
	int child = 0;
	//cout << "holla\n";
	for (auto &e : adj[node]) {
		if (e == p) continue;
		if (dfsn[e] != -1)
			dfsl[node] = min(dfsl[node], dfsn[e]);
		else {
			dfs(e, node);
			dfsl[node] = min(dfsl[node], dfsl[e]);
			if (dfsl[e] >= dfsn[node] && p != -1)
				cutpoint.insert(str[node]);
			child++;
		}
	}
	if (p == -1 && child > 1)
		cutpoint.insert(str[node]);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int tt = 1;
	while (cin >> n && n)
	{
		if (tt > 1)cout << endl;
		int node = 1;
		map<string, int>mp;
		mem();
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			str[node] = s;
			mp[s] = node++;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int u = mp[s1], v = mp[s2];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			if(dfsn[i]==-1)dfs(i);
		cout << "City map #" << tt++ << ": " << cutpoint.size() << " camera(s) found\n";
		while (cutpoint.size())
		{
			cout <<*cutpoint.begin()<<endl;
			cutpoint.erase(cutpoint.begin());
		}
	}
	pause();
	return 0;
}