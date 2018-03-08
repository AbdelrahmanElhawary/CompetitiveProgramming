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
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
struct node {
	ll sum, s, e,num;
	bool f;
};
int arr[16];
vector<node>dp[17];
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	node temp;
	temp.sum = 0; temp.s = 1e10; temp.e = 0; temp.num = 0,temp.f=0;
	dp[0].push_back(temp);
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			temp = dp[i][j];
			temp.sum += arr[i];
			temp.s = min(temp.s, (ll)arr[i]);
			temp.e = max(temp.e, (ll)arr[i]);
			temp.num +=1;
			temp.f = 0;
			dp[i + 1].push_back(temp);
			if (dp[i][j].sum >= l && dp[i][j].sum <= r && abs(dp[i][j].e - dp[i][j].s) >= k&& (dp[i][j].num >= 2)&&dp[i][j].f==0) { dp[i][j].f = 1; dp[i + 1].push_back(dp[i][j]);ans++; }
			else dp[i + 1].push_back(dp[i][j]);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}
