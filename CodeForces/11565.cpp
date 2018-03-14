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
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int a, b, c;
bool check(int x,int y,int z)
{
	if ((x + y + z) != a)return 0;
	if ((x*y*z) != b)return 0;
	if ((x*x + y * y + z * z) != c)return 0;
	return 1;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		bool f = 0;
		for (int x = -100; x < 101; x++)
		{
			for (int y = x+1; y < 101; y++)
			{
				for (int z = y+1; z < 101; z++)
				{
					if (check(x, y, z)) { f = 1; cout << x << " " << y << " " << z << endl; break; }
				}
				if (f)break;
			}
			if (f)break;
		}
		if (f)continue;
		cout << "No solution.\n";
	}


	//system("pause");
	return 0;
}