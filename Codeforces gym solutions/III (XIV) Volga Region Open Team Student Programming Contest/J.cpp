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
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
int vis[(int)1e5 + 20];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = 0,cur=1;
	for (int k = 1; k <= min(d,1000); k++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int m = k / v[i];
			if (k%v[i]) {
				if (vis[m + 1]!=cur)
					cnt++;
				vis[m + 1]=cur;
			}
			if (vis[m]!=cur)
				cnt++;
			vis[m]=cur;
		}
		ans = max(ans, cnt);
		cur++;
	}
	int cnt = 0;
	for (int k = d;k&&cnt++<1000 ; k--)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int m = k / v[i];
			if (k%v[i]) {
				if (vis[m + 1] != cur)
					cnt++;
				vis[m + 1] = cur;
			}
			if (vis[m] != cur)
				cnt++;
			vis[m] = cur;
		}
		ans = max(ans, cnt);
		cur++;
	}
	cout << ans << endl;
	pause();
	return 0;
}