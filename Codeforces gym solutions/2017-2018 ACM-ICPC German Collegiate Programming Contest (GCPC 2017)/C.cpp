#include <bits/stdc++.h>
#include<complex>
using namespace std;

#define ll long long
#define endl "\n"
typedef complex<long double> point;
#define cross(a,b) ((conj(a)*(b)).imag())
#define len(v) ((long double) hypot((v).imag(),(v).real()))
int n,m,t;
vector<vector<int>>adj(10000);
int vis[1001][1001];
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int x; cin>>x;
	cin>>n>>m>>t;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<pair<int,int>>nodes(n+1);
	for(int i=1;i<=n;i++){
		cin>>nodes[i].first>>nodes[i].second;
	}
	memset(vis,63,sizeof vis);
	bool f=0; int ans=1e9;
	queue<pair<int,int>>q;
	q.push({1,nodes[1].first});
	vis[1][nodes[1].first]=nodes[1].second;
	if(nodes[1].first==x)
		ans=nodes[1].second,f=1;
	while(q.size())
	{
		auto cur=q.front();
		q.pop();
		int node = cur.first;
		int cost = vis[cur.first][cur.second];
		int time_cost = cur.second;
		int cur_time = nodes[cur.first].first;
		if(time_cost == x && node == 1){
			f=1;
			ans=min(ans,cost);
			continue;
		}
		if(cur_time + time_cost<=x&&cost + nodes[node].second<vis[node][cur_time + time_cost])
		{
			vis[node][cur_time + time_cost] = cost + nodes[node].second;
			q.push({node , cur_time + time_cost});
		}

		for(int i=0;i<adj[node].size();i++)
		{
			int u=adj[node][i];
			int tim=t+nodes[u].first;

			if(tim+time_cost<=x&&cost + nodes[u].second<vis[u][tim + time_cost])
			{
				vis[u][tim + time_cost] = cost + nodes[u].second;

				q.push({u,tim+time_cost});
			}
		}
	}

	if(f)cout<<ans<<endl;
	else cout<<"It is a trap."<<endl;
}