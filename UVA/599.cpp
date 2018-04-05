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
int n;
vector<int>adj[27];
bool vis[27];
void dfs(int node)
{
	if (vis[node])return;
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
		dfs(adj[node][i]);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--)
	{
		string s;
		while (cin >> s)
		{
			if (s[0] == '*')break;
			adj[s[1] - 'A'].push_back(s[3] - 'A');
			adj[s[3] - 'A'].push_back(s[1] - 'A');
		}
		cin >> s;
		map<int, bool>mp;
		for (int i = 0; i < s.size(); i += 2)
			mp[s[i]-'A'] = 1;
		int cnt1=0,cnt2=0;
		for (int i = 0; i < 26; i++)
		{
			if (!mp[i])continue;
			if (!vis[i])
			{
				if (adj[i].size() == 0) { cnt2++; continue; }
				cnt1++;
				dfs(i);
			}
		}
		cout << "There are "<<cnt1<<" tree(s) and "<<cnt2<<" acorn(s).\n";
		memset(vis, 0, sizeof vis);
		for (auto& v : adj)
			v.clear();
	}
	pause();
	return 0;
}