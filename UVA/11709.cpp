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
		comps.push_back(temp);
	}
	return;
}

void SCC()
{
	memset(inde, -1, sizeof inde);
	memset(low, 0, sizeof low);
	comps.clear(); cur_index = 0;
	for (int i = 1; i <= n; i++)
		if (inde[i] == -1) tarjan(i);
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	while (cin >> n>>m && (n||m))
	{
		for (auto &v : adj)
			v.clear();
		map<string, int>mp;
		cin.ignore();
		num = 1;
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			str[num] = s;
			mp[s] = num++;
		}
		for (int i = 0; i < m; i++)
		{
			string s1, s2;
			getline(cin, s1); getline(cin, s2);
			//cout << mp[s1] << " " << mp[s2] << endl;
			adj[mp[s1]].push_back(mp[s2]);
		}
		SCC();
		cout << comps.size() << endl;
	}
	pause();
	return 0;
}