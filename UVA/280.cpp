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
vector<int>adj[102];
bool vis[102];
int viss[102];
void dfs(int node)
{
	if (vis[node])return;
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		viss[adj[node][i]] = 1;
		dfs(adj[node][i]);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	while(	cin >> n&&n)
	{
	bool f = 0;
	int x, m = 0;
	while (cin >> x)
	{
		if (!f && !x)break;
		if (!x&&f) { f = 0; continue; }
		if (x&&f) { adj[m].push_back(x); }
		if (x && !f) { f = 1; m = x; }
	}
	int q; cin >> q;
	for (int j = 0; j < q; j++)
	{
		cin >> x;
		dfs(x);
		vector<int>v1, v2;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			if (!viss[i]) { sum++; v1.push_back(i); }
			viss[i] = 0;
		}
		cout << sum;
		for (int i = 0; i <v1.size(); i++)
			cout << " " << v1[i]; cout << endl;	
	}
	for (auto& v : adj) {
		v.clear();
	}
}
	pause();
	return 0;
}