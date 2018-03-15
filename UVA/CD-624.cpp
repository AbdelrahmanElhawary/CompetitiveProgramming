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
int n, m;
int arr[21];
bool operator < (node a, node b)
{
	if (a.sum != b.sum)return a.sum > b.sum;
	return a.v.size()> b.v.size();
}
node solve(node ans,int i)
{
	if (i == n)return ans;
	node option1 = solve(ans, i + 1);
	node option2;
	if (ans.sum + arr[i] <= m)
	{
		ans.sum += arr[i];
		ans.v.push_back(arr[i]);
		option2 = solve(ans, i + 1);
	}
	return min(option1, option2);
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	while (cin >> m >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		node temp;
		temp.sum = 0;
		node ans = solve(temp, 0);
		for (int i = 0; i < ans.v.size(); i++)
			cout << ans.v[i] << " ";
		cout << "sum:" << ans.sum << endl;
	}
	//system("pause");
	return 0;
}