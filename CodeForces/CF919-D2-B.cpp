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
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int dig(int n)
{
	int c = 0;
	while (n)
	{
		c += n % 10;
		n /= 10;
	}
	return c;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n; cin >> n;
	for (int i = 19;; i++)
	{
		if (dig(i) == 10) n--;
		if (n == 0) { cout << i << endl; break; }
	}
		
	//	system("pause");
		return 0;
}