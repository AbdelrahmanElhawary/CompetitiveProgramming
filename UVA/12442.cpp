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
vector<int>adj[50001];
bool vis[50001];
int viss[50001];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int tt = 1, t; cin >> t;
	while (t--)
	{
		memset(viss, 0, sizeof viss);
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
		}
		int ans = 0,ansy=0,qrqr=1;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				queue<int>q;
				q.push(i);
				int cnt = 0;
				while (q.size())
				{
					cnt++;
					int cur = q.front();
					q.pop();
					vis[cur] = 1;
					viss[cur] = qrqr;
					for (int j = 0; j < adj[cur].size(); j++)
						if(viss[adj[cur][j]]!=qrqr)q.push(adj[cur][j]);
				}
				qrqr++;
				if (ansy < cnt)
				{
					ans = i + 1;
					ansy = cnt;
				}
			}
		}
		cout << "Case "<<tt++<<": " << ans << endl;
		for (auto& v : adj) {
			v.clear();
		}
		
	}
	
	pause();
	return 0;
}