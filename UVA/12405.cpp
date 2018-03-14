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
#define dong long
#define endl '\n'

using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t,tt=1; cin >> t;
	while (t--)
	{
		int n,ans=0; string s;
		cin >> n >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '#')continue;
			if (s[i] == '.'&&s[i + 2] == '.')
			{
				ans++;
				i += 2;
				continue;
			}
			if (s[i] == '.'&&s[i + 1] == '.')
			{
				ans++; i++;
				continue;
			}
			ans++;
		}



		
		cout <<"Case "<<tt++<<": "<< ans << endl;
	}
	//system("pause");
	return 0;
}