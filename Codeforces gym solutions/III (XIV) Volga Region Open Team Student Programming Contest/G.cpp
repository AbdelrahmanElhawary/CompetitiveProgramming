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
const int MAX = 3 * 1000 * 100 + 5;
pair<int,int> a[MAX];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int mn = 1e9+5;
	pair<int, int>idx;
	for (int i = 1; i < n; i++) {
		if (mn > (a[i].first ^ a[i - 1].first)) {
			mn = a[i].first ^ a[i - 1].first;
			idx = { a[i].second  , a[i - 1].second };
		}
	}
	cout << idx.first << " " << idx.second << endl;
	pause();
	return 0;
}