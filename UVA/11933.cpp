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
ll po(int k, int f)
{
	if (!f)return 1;
	for (int i = 1; i < f; i++)
		k *= 2;
	return k;
}
int main() {
	int n;
	while (cin >> n && n)
	{
		int nn = n;
		string s = "";
		while (n)
		{
			s += (char)((n % 2) + '0');
			n /= 2;
		}
		int n1 = 0, n2=0;
		int c1 =0;
		bool f = 0;
		for (int i = 0; i < s.size(); i ++)
		{
			if (!f&& s[i] == '1') { n1 += po(2, c1); f = 1; }
			else if (f&& s[i] == '1') { n2 += po(2, c1); f = 0;}
			c1++; 
		}
		
		cout << n1 << " " << n2 << endl;
	}
	//system("pause");
	return 0;
}