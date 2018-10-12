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
#include <assert.h>
#include<complex>
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
const int MAX_N = 1e5+5;
int dfsl[MAX_N], dfsn[MAX_N];
int dfscnt;
vector<int>adj[MAX_N];
int cnty;
int cutpoint[MAX_N];
set<pair<int, int>>bridge;
void mem()
{
	for (auto& v : adj)
		v.clear();
	memset(dfsl, -1, sizeof dfsl);
	memset(dfsn, -1, sizeof dfsn);
	memset(cutpoint, 0, sizeof cutpoint);
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
			if (dfsl[e] >= dfsn[node] && p != -1)
				cutpoint[node]++;
			child++;
		}
	}
	if (p == -1 && child > 1)
		cutpoint[node]++;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(2);
	int n, m;
	while (cin >> n >> m && n)
	{
		int u, v;
		mem();
		while (cin >> u >> v)
		{
			if (u == -1)break;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if(dfsn[i]==-1)
			dfs(i);
		}
		vector<pair<int,int>>ans;
		for (int i = 0; i < n; i++)
			ans.push_back({ cutpoint[i]+1, -i });
		sort(ans.rbegin(), ans.rend());
		for (int i = 0; i < ans.size() && i < m; i++)
			cout << -ans[i].second << " " << ans[i].first << endl;
		cout << endl;
		
	}
	pause();
	return 0;
}