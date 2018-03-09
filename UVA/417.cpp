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
map<string, int>mp;
void generate()
{
	int c=1;
	for (char i = 'a'; i <= 'z'; i++)
	{
		string str; str += i;
		mp[str] = c++;
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		string str; str += i;
		for (char j = i+1; j <= 'z'; j++)
		{
			string str2; str2 += str;
			str2 += j;
			mp[str2] = c++;
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		string str; str += i;
		for (char j =i+1; j <= 'z'; j++)
		{
			string str2=str;
			str2 += j;
			for (char k = j + 1; k <= 'z'; k++)
			{
				string str3 = str2;
				str3 += k;
				mp[str3] = c++;
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		string str; str += i;
		for (char j = i + 1; j <= 'z'; j++)
		{
			string str2 = str;
			str2 += j;
			for (char k = j + 1; k <= 'z'; k++)
			{
				string str3 = str2;
				str3 += k;
				for (char l = k + 1; l <= 'z'; l++)
				{
					string str4 = str3;
					str4 += l;
					mp[str4] = c++;
				}
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		string str; str += i;
		for (char j = i + 1; j <= 'z'; j++)
		{
			string str2 = str;
			str2 += j;
			for (char k = j + 1; k <= 'z'; k++)
			{
				string str3 = str2;
				str3 += k;
				for (char l = k + 1; l <= 'z'; l++)
				{
					string str4 = str3;
					str4 += l;
					for (char m = l + 1; m <= 'z';m++)
					{
						string str5 = str4;
						str5 += m;
						mp[str5] = c++;
					}
				}
			}
		}
	}
}

int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	generate();
	string s;
	while (cin >> s)
	{
		cout << mp[s]<<endl;
	}
	//system("pause");
	return 0;
}
