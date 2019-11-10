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
#include <assert.h>
#include<complex>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
// Returns the length of the longest increasing subsequence of the array.
// O(n.log(n))
const int N = 2e5 + 100;
int n, a[N];
int getLIS() {
	int len = 0;
	vector<int> LIS(n, 1e9);
	for (int i = 0; i < n; ++i) {
		// To get the length of the longest non decreasing subsequence
		// replace function "lower_bound" with "upper_bound" 
		int idx = upper_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
		LIS[idx] = a[i];
		len = max(len, idx);
	}
	return len + 1;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	//freopen("input.txt", "r", stdin);
	int t; cin >> t;
	int tt = 1;
	while (t--)
	{
		cin >> n;
		map<int, int>mp;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			mp[x] = i;
		}
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			a[i] = mp[x];
		}
		int ans = getLIS();
		//cout << ans << endl;
		cout <<"Case "<<tt++<<": "<< 2*(n - ans) << endl;
	}
	pause();
	return 0;

}