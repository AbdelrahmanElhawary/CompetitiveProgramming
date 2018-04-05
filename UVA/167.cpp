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
int arr[9][9],vis[8],vis2[16],vis3[16],ans;
void solve(int r,int sum)
{
	if (r == 8) {ans = max(ans, sum); return;}
	for (int i = 0; i < 8; i++)
	{
		if (!vis[i] && !vis2[r - i + 8] && !vis3[i + r])
		{
			vis[i] = 1; vis2[r - i + 8] = 1; vis3[i + r] = 1;
			solve(r + 1, sum+arr[r][i]);
			vis[i] = 0; vis2[r - i + 8] = 0; vis3[i + r] = 0;
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--)
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		solve(0,0);
		cout << setw(5) << ans << '\n';
		ans = 0;
	}
//	system("pause");
	return 0;
}