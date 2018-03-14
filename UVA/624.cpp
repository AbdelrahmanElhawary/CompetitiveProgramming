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
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
struct node {
	vector<ll>v;
	ll sum = 0;
};
bool operator < (node a, node b)
{
	if (a.sum != b.sum)return a.sum > b.sum;
	return a.v.size()> b.v.size();
}
int arr[21];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int n, m;
	while (cin>>m>>n)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector<node>dp[22];
		node temp;
		dp[0].push_back(temp);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < dp[i].size(); j++)
			{
				temp = dp[i][j];
				dp[i + 1].push_back(temp);
				if (temp.sum + arr[i] > m)continue;
				temp.sum += arr[i];
				temp.v.push_back(arr[i]);
				dp[i + 1].push_back(temp);
			}
		}
		node ans=dp[n][0];
		for (int i = 0; i < dp[n].size(); i++)
			ans = min(ans, dp[n][i]);
		for (int i = 0; i < ans.v.size(); i++)
			cout << ans.v[i] << " ";
		cout << "sum:" << ans.sum << endl;
	}
	//system("pause");
	return 0;
}