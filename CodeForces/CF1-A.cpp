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
#define F first
#define S second
#define ll long long
using namespace std;
int main()
{
	double n, m, a; cin >> n >> m >> a;
	cout << (ll)(ceil(n / a)*ceil(m / a)) << endl;
	//system("pause");
	return 0;
}