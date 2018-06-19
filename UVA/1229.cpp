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
const int N = 1e3 + 2;
int n, m, component[N], cur_index;
int inde[N], low[N],num;
bool instack[N];
vector<int> stk, adj[N];
vector< vector<int> > comps;
string str[N];
void tarjan(int ind)
{
	inde[ind] = cur_index;
	low[ind] = cur_index;
	cur_index++;
	stk.pb(ind);
	instack[ind] = 1;
	for (int i = 0; i<adj[ind].size(); i++)
	{
		int j = adj[ind][i];
		if (inde[j] == -1)
		{
			tarjan(j);
			low[ind] = min(low[ind], low[j]);
		}
		else if (instack[j]) low[ind] = min(low[ind], inde[j]);
	}
	if (inde[ind] == low[ind])
	{
		vector<int> temp;
		while (stk.back() != ind)
		{
			temp.push_back(stk.back());
			instack[stk.back()] = 0;
			component[stk.back()] = comps.size();
			stk.pop_back();
		}
		temp.push_back(stk.back());
		instack[stk.back()] = 0;
		component[stk.back()] = comps.size();
		stk.pop_back();
		if(temp.size()>1)comps.push_back(temp);
	}
	return;
}

void SCC()
{
	memset(inde, -1, sizeof inde);
	memset(low, 0, sizeof low);
	comps.clear(); cur_index = 0;
	for (int i = 1; i <= num; i++)
		if (inde[i] == -1) tarjan(i);
	return;
}
vector<string>ans;
bool vis[N];
void dfs(int u)
{
	ans.push_back(str[u]);
	vis[u] = 1;
	for (auto&v : adj[u])
		if (!vis[v])
			dfs(v);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n;
	while (cin >> n && n)
	{
		for (auto &v : adj)
			v.clear();
		map<string, int>mp;
		cin.ignore();
		num = 1;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			int u;
			if (!mp[s])
				mp[s] = num++;
			u = mp[s];
			str[u] = s;
			getline(cin, s);
			istringstream st(s);
			s = "";
			while (st >> s)
			{
				int v;
				if (!mp[s])
					mp[s] = num++;
				v = mp[s];
				str[v] = s;
				adj[u].push_back(v);
			}
		}
		SCC();
		ans.clear();
		memset(vis,0,sizeof vis);
		for (auto &v:comps)
					dfs(v[0]);
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size() - 1; i++)
			cout << ans[i] << " "; cout << ans[ans.size() - 1] << endl;
	}
	pause();
	return 0;
}