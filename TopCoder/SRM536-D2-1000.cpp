#include<bits/stdc++.h>
using namespace std;
class MergersDivTwo {
public:
	double findMaximum(vector<int>rev, int k) {
		sort(rev.begin(), rev.end());
		int n = rev.size();
		for (int i = 1; i < n; ++i)
			rev[i] += rev[i - 1];
		vector<double>dp(n, 0);
		for (int i = 0; i < n; i++)
			dp[i] = 1.*rev[i] / (i + 1);
		for (int i = k-1; i < n; ++i) {
			for (int j = i + k - 1,sz=k; j < n; ++j,sz++) {
				dp[j] = max(dp[j], (dp[i] + rev[j] - rev[i]) / (sz));
			}
		}
		return dp[n - 1];
	}
};
