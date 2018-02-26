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
	ll a=0,b=0,x,ans=0;
	for(int i=0;i<3;i++)
	{
		cin >> x; a += x;
	}
	for (int i = 0; i<3; i++)
	{
		cin >> x; b += x;
	}
	int n; cin >> n;
	ans += a / 5;
	ans += b / 10;
	if (a % 5)ans++; if (b % 10)ans++;
	if (ans <= n)cout << "YES\n"; else cout << "NO\n";
	//system("pause");
	return 0;
}