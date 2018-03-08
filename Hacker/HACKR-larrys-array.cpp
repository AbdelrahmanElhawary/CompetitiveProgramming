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
int arr[1001];
ll solve2(int s, int mid, int e)
{
	ll ret = 0;
	vector<int>l, r;
	int c = s;
	while (c <= mid)
		l.push_back(arr[c++]);
	while (c <= e)
		r.push_back(arr[c++]);
	for (int i = 0, j = 0; i < l.size() || j < r.size();)
	{
		if (i >= l.size()) { arr[s++] = r[j++]; continue; }
		if (j >= r.size()) { arr[s++] = l[i++]; continue; }
		if (l[i] <= r[j]) { arr[s++] = l[i++]; continue; }
		ret += l.size() - i;
		arr[s++] = r[j++];
	}
	return ret;
}
ll solve(int s, int e)
{
	ll ret = 0;
	if (s < e)
	{
		int mid = (s + e) / 2;
		ret = solve(s, mid) + solve(mid + 1, e) + solve2(s, mid, e);
	}
	return ret;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		bool f = 1;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		if (solve(0, n - 1)&1)cout << "NO\n";
		else cout << "YES\n";
	}
//	system("pause");
	return 0;
}
