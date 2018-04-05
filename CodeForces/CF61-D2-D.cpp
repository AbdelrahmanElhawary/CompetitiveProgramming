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
vector<int>adj[100001];
vector<int>cost[100001];
ll dfs(int node, int par)
{
	ll ret = 0;
	for (int i = 0; i < adj[node].size();i++)
	{
		if (adj[node][i] == par)continue;
			ret = max(ret, dfs(adj[node][i], node) + cost[node][i]);
	}
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	cin >> n; ll ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[y].push_back(x);
		cost[x].push_back(z);
		cost[y].push_back(z);
		ans += (z * 2);
	}
	cout << ans - dfs(1,0)<<endl;
	pause();
	return 0;
}