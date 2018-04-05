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
void pause(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int n,m;
vector<int>adj[101];
bool vis[101],grid[101][101];
int ans;
void dfs(int node)
{
	for (int i = 0; i < n;i++)
	{
		if (vis[i]||!grid[node][i])continue;
		vis[i] = 1;
		dfs(i); 
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	cin >> n>>m;
	int cnt1 = 0;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x)cnt1++;
		for (int j = 0; j < x; j++)
		{
			int u; cin >> u;
			adj[u - 1].push_back(i);
		}
	}
	if (!cnt1)cout << n << endl;
	else
	{

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = j + 1; k < adj[i].size(); k++)
				{
					grid[adj[i][j]][adj[i][k]] = 1;
					grid[adj[i][k]][adj[i][j]] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				if(i)ans++;
				dfs(i);
			}
		}
		cout << ans << endl;
	}
	pause();
	return 0;
}