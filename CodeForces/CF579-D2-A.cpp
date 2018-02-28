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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
ll po[32];
void generate()
{
	po[0] = 1;
	for (int i = 1; i < 32; i++)
		po[i] = po[i - 1] * 2;
}
int main() {
	generate();
	ll n,c=0;
	cin >> n;
	for (int i = 31; i >= 0&&n; i--)
	{
		if (po[i] > n)continue;
		if (po[i] <= n) { c++; n -= po[i]; }
	}
	cout << c << endl;
	
//	system("pause");
	return 0;
}