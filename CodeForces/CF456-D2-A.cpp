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
using namespace std;
int main()
{
	int n; cin >> n; bool f = 0;
	for(int i=0;i<n;i++)
	{
		int x, y; cin >> x >> y;
		if (x != y)f = 1;
	}
	if (f)cout << "Happy Alex\n"; else cout << "Poor Alex\n";
	//system("pause");
	return 0;
}