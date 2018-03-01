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

vector<int>v,vv;
int main() {
	int n;
	while (1)
	{
		v.clear(); vv.clear();
		cin >> n;
		if (!n)break;
		//Discarded cards: 1, 3, 5, 7, 4, 2
		if (n == 1)
		{
			cout << "Discarded cards:\n";
			cout << "Remaining card: 1\n";
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			if (i % 2)v.push_back(i + 1);
			else vv.push_back(i + 1);
		}
		cout << "Discarded cards:";
		for (int i = 0; i < vv.size()-1; i++)
			cout <<" "<< vv[i] <<',';
		cout << " " << vv[vv.size() - 1];
		int j = 0;
		if (n % 2)j = 1;
		bool f = 1;
		int c = v.size();
		for (j; j < v.size();)
		{
			if (c == 1)break;
			if (f&&v[j] != -1) { cout <<", "<< v[j]; c--; v[j] = -1; f = 0; }
			else if (v[j] != -1 && !f) { f = 1; }
			j++;
			j %= v.size();
		}
		cout << endl;
		for (int i = 0; i < v.size(); i++)
			if (v[i] != -1)cout<<"Remaining card: " << v[i] << endl;
	}
	//cout << endl;
	//system("pause");
	return 0;
}