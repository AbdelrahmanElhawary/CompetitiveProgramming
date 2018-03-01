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
int arr[102][102];
int main() {
	int n;
	while (cin >> n && n)
	{
		bool f1 = 0, f2 = 0,f3=0;
		int row, colum;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				sum += arr[i][j];
			}
			if (f1&&sum % 2)f3 = 1;
			if (sum % 2) { f1 = 1; row = i + 1; }
		}
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += arr[i][j];
			if (f2&&sum % 2)f3 = 1;
			if (sum % 2) { f2 = 1; colum = j + 1; }
		}
		if (!f1 && !f2) cout << "OK\n";
		else if (f3) cout << "Corrupt\n";
		else
		{
			cout << "Change bit (" << row << "," << colum << ")\n";
		}

	}
//system("pause");
	return 0;
}