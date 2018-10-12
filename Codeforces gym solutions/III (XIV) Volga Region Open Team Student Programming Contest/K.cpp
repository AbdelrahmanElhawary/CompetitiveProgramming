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
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	string str[10];
	for (int i = 0; i < 9; i++)
		cin >> str[i];
	int cnt[8]{0};
	int ans[8]{ 12,8,6,8,7,4,9,7 };
	//cout << str[0].size() << endl;
	for (int i = 0; i <str[0].size(); i+=6)
	{
	//	cout << i + 1 << " ";
		cnt[2] += str[1][i] == 'x';
		cnt[1] += str[0][i + 1] == 'x';
		cnt[3] += str[1][i + 4] == 'x';
		cnt[4] += str[4][i + 1] == 'x';
		cnt[5] += str[5][i] == 'x';
		cnt[6] += str[5][i + 4] == 'x';
		cnt[7] += str[8][i + 1] == 'x';
	}
	//cout << endl;
	for (int i = 1; i <= 7; i++)
	{
		if (i > 1)cout << " ";
		if (cnt[i] == ans[i])
			cout << 0;
		else if (cnt[i] == 0)
			cout << -1;
		else cout << 1;
	//	cout << cnt[i];
	}
	cout << endl;
	pause();
	return 0;
}