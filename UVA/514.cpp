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
int arr[1002],stk[1002];
vector<string>v;
int main() {
	int n;
	while (1)
	{
		cin >> n;
		if (!n)break;
		while (1) {
			cin >> arr[0];
			if (!arr[0]) { cout << endl; break; }
			for (int j=1; j < n; j++)
				cin >> arr[j];
			int stk_cnt = 0, x = 0;
			for(int i=1;i<=n;i++)
			{
				stk[stk_cnt++] = i;
				while (stk_cnt&&stk[stk_cnt - 1] == arr[x])
				{
					stk_cnt--;
					x++;
					if (x >= n)break;
				}
			}

			if (!stk_cnt)cout << "Yes" << endl;
			else cout << "No"<<endl;
		}
	}
//system("pause");
	return 0;
}