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
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
	ll temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}
const int N = 1e6 + 1;
unordered_map<int, int>mp;
int arr[N];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<int>v(n);
	int l = 1, sz = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i], mp[v[i]]++;
	for (auto&x : mp)
	{
		for (int i = x.first; i <= m; i += x.first)
		{
			arr[i] += x.second;
			if (sz < arr[i])
				sz = arr[i], l = i;
		}
	}
	cout << l << " " << sz << endl;
	for (int i=0 ;i<n;i++)
		if (!(l%v[i]))cout << i+1 << " "; cout << endl;
	pause();
	return 0;
}