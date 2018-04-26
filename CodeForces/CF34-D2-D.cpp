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
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
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
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int>adj[50002];
int ans[50002];
void dfs(int node, int par)
{
	ans[node] = par;
	for (int i = 0; i < adj[node].size(); i++)
		if (adj[node][i] != par)
			dfs(adj[node][i], node);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	for (int i = 1; i <= n; i++)
	{
		if (i == r1)continue;
		int u; cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	dfs(r2,0);
	for(int i=1;i<=n;i++)
		if (i != r2)
		cout << ans[i] << " ";
	pause();
	return 0;
}