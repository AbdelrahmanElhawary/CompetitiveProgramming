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
string ss = ".!?,";
bool chk(char ch)
{
	for (int i = 0; i < ss.size(); i++)
		if (ch == ss[i])return 1;
	return 0;
}
int main()
{
	fast_in_out();
	ll n,x,ans=0;
	ll s = 1e9;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x % 2)s = min(s, x);
		 ans += x;
	}
	if (ans % 2)ans -= s;
	cout << ans << endl;
	//system("pause");
	return 0;
}