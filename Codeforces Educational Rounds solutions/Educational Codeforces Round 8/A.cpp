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
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int ar[] = {2,4,8,16,32,64,128,256,512 };
	int n, b, q;
	cin >> n >> b >> q;
	int x = 0, y = n*q;
	for (int i = 8; i >= 0; i--)
	{
		if (n < ar[i])
			continue;
		int k = ar[i];
		//cout << k << endl;
		n = n - k; n += k / 2; i++;
		k = k * b + (k / 2);
		//cout << k << " " << x << endl;
		x += k;
	}
	cout << x << " " << y  << endl;
	pause();
	return 0;
}