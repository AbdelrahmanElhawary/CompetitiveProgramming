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
const int N = 2e5 + 100;
int arr[N];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr[x]++;
	}
	for (int i = N - 2; i > -1; i--)
		arr[i] += arr[i + 1];
	ll cut = 0,cnt=0;
	for (int i = N - 1; i > -1; i--)
	{
		if (arr[i] == n) {
			if (cnt)
				cut++;
			break;
		}
		if (cnt + arr[i] > k)
		{
			cut++;
			cnt = 0;
			i++;
		}
		else cnt += arr[i];
	}
	cout << cut << endl;
	pause();
	return 0;
}