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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	int t; cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int>v(n+1);
		vector<int>dp[23];
		for (int i = 0; i < n; i++)
			cin >> v[i];
		dp[0].push_back(0);
		bool f = 0;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < dp[i].size(); j++)
			{
				if (dp[i][j] == m)f = 1;
				dp[i + 1].push_back(dp[i][j] + v[i]);
				dp[i + 1].push_back(dp[i][j]);
			}
			if (f)break;
		}
		if (f)cout << "Yes\n";
		else cout << "No\n";
	}
	
	
//	system("pause");
	return 0;
}