#include<bits/stdc++.h>
using namespace std;
const int N = 40;
class DiceGames {
public:
	long long dp[N][N];
	vector<int>ve;
	int n;
	long long solve(int ind, int cur) {
		if (ind == n)return 1;
		long long& ret = dp[ind][cur];
		if (ret != -1)return ret;
		ret = 0;
		for (int j = cur; j <= ve[ind]; ++j)
			ret += solve(ind+1, j);
		return ret;
	}
	long long countFormations(vector<int>v) {
		memset(dp, -1, sizeof dp);
		sort(v.begin(), v.end());
		ve = v; n = v.size();
		return solve(0, 1);
	}
};