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
map<int, int>mp;
set<int>s[100001];
vector<int>v;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	cin >> n >> m;
	int mxr = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> mp[i+1];
		v.push_back(mp[i + 1]);
		mxr = max(mxr, mp[i + 1]);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		if (mp[u] == mp[v])continue;
		s[mp[u]].insert(mp[v]);
		s[mp[v]].insert(mp[u]);
	}
	int ans = 0,clr=1e9;
	for (int i = 0; i < n; i++)
	{
		if (ans < s[v[i]].size())
		{
			ans = s[v[i]].size();
			clr = v[i];
		}
		if (ans == s[v[i]].size() && clr > v[i])
		{
			clr = v[i];
		}
	}
	cout << clr << endl;
	pause();
	return 0;
}