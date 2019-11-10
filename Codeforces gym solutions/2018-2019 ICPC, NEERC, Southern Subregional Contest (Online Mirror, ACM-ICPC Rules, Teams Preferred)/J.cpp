?#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 30000 + 20;
int frq[26];
int dp[26][26][N];
int vis[26][26][N];
int n, m, k;
int id;
int solve(int idx, int s, int who){
	if (s > n)
		return 1e9;
	if (idx == 26){
		int rem_n = max(0, n- s);
		int hv = (k - frq[who] - s);
		int rem_m = max(0,m - hv);
		if (rem_m + rem_n > frq[who])
			return 1e9;
		return rem_n * rem_m;
	}
	int &ret = dp[idx][who][s];
	if (vis[idx][who][s] == id){
		return ret;
	}
	vis[idx][who][s] = id;
	ret = solve(idx + 1, s, who);
	if (idx != who){
		ret = min(ret, solve(idx + 1, s + frq[idx], who));
	}
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		clr(frq, 0);
		++id;
		for (int i = 0; i < k; i++){
			char ch;
			scanf(" %c", &ch);
			frq[ch - 'A']++;
		}
		int ans = 1e9;
		for (int i = 0; i < 26; i++){
			ans = min(ans, solve(0, 0, i));
		}
		printf("%d\n", ans);
	}
}