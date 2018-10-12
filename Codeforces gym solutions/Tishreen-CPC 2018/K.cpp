#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll OO = 1e9;
const int N = 1e6 + 100,M = 30;
int n , m , k;
int src , des;
bool p[N];
int lp[N];
vector<int>pf[N];
void sieve(){

	for(int i = 2;i<N;i++)
		lp[i]=i;
	p[0]=p[1] = 1;

	for(ll i = 2 ; i * i < N;i++){
		if(!p[i]){
			for(ll j = i * i;j<N;j+=i){
				if(lp[j] == j)
					lp[j] = i;
				p[j] = 1;
			}
		}
	}
}
ll dist[10001][101];
vector< vector< pair< ll ,pair< int , int > > > >g;
priority_queue< pair< ll  , pair< int  ,int > > , vector<pair< ll  , pair< int  ,int > > > , greater<pair< ll  , pair< int  ,int > > > >q;
void dijkstra(){
        //q.clear();

	memset(dist,63,sizeof dist);OO = dist[0][0];
	dist[src][0] = 0;

	q.push({0 , {src , 0 } });
	while(q.size()  > 0){
		auto cur = q.top();
		q.pop();

		if(cur . first > dist[cur.second.first][cur.second.second])
			continue;
		for(auto e : g[cur.second . first]){
			int u = cur.second . first , v = e.first;
			ll d = e.second.first;
			int pp = e.second.second;
			if(dist[v][ cur.second.second + e.second.second ] > cur.first + d && cur.second.second + e.second.second <= k){
				dist[v][ cur.second.second + e.second.second ] = cur.first + d;
				q.push({dist[v][ cur.second.second + e.second.second ]  , {v , cur.second.second + e.second.second}});
			}
		}
	}
}
int main() {
      std::ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      sieve();
      for(int i = 2;i<N;i++){
    	  int cur = i;
    	  int last = -1;
    	  while(cur != lp[cur]){
    		if(last != lp[cur])
    			pf[i].push_back(lp[cur]);
    		last = lp[cur];
    		cur/=lp[cur];
    	  }
    	  if(last != cur)
    		  pf[i].push_back(cur);
      }

      int t;
      cin>>t;
      while(t--){
    	 cin>>n>>m>>k;
    	 g.clear();
    	 g.resize(n);
    	 for(int i = 0 ; i < m ; i++){
    		 int u , v , w;
    		 cin>>u>>v>>w;
    		 u-- , v--;
    		 g[u].push_back({v , {w  ,0} });
    		  g[v].push_back({u , {w  ,0} });
    		 for(int j = 0 ; j < pf[w].size() ; j ++){
    			 g[u].push_back({v , {w/pf[w][j] + 2 * pf[w][j]  ,1} });
    			 g[v].push_back({u , {w/pf[w][j] + 2 * pf[w][j]  ,1} });
    		 }
    	 }
    	 cin>>src>>des;
    	 src-- , des--;
    	 dijkstra();
    	 ll mn = OO;
    	 for(int i=0;i<=k;i++){

    		 mn = min(mn,dist[des][i]);
    	 }
    	 if(mn == OO)
    		 cout<<-1<<endl;
    	 else {
    		 cout<<mn<<endl;
    	 }
      }


	return 0;
}