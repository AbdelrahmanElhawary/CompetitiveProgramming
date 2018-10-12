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
const int N = 1e6 + 1;
bool mp[N], mp2[N];
int arr[N];
int n, k;
int dp[N];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	cin >> n >> k;
	int mn = 1e9, mx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}
	for (int i = 0; i < n; i++)
		arr[i] -= mn;
	mx -= mn; mx *= k; mn *= k;
	sort(arr, arr + n);
	mp2[mn] = 1;
	for(int cost = 1; cost <= mx;cost++) {
		dp[cost] = 1e9;
		for (int i = 0; i < n; i++)
			if (cost - arr[i] >= 0)
				dp[cost] = min(dp[cost], dp[cost - arr[i]] + 1);
			//else break;
		if (dp[cost] <= k) mp2[cost + mn] = 1;
	}
	for (int i = 1; i < N; i++)
		if (mp2[i])
			cout << i << " "; cout << endl;
	pause();
	return 0;
}