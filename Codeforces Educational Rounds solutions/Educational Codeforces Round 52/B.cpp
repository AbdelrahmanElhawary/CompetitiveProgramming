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
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	ll n, m;
	cin >> n >> m;
	ll mn = (n + 1) / 2;
	if (mn <= m)
		mn = 0;
	else 
			mn = n - (m * 2);	
	ll s = 1, e = n, ret;
	if(m)while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (mid*(mid - 1) / 2 >= m)
		{
			ret = n - mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	else ret = n;
	cout << mn << " " << ret << endl;


	pause();
	return 0;
}