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
	int t; cin >> t;
	while (t--)
	{
		ll l, r;
		scanf("%lld%lld", &l, &r);
		if (l > r)swap(l, r);
		for (ll i = l; i <= r; i++)
		{
			if (i == 1)continue;
			bool f = 1;
			for(ll j=2;j*j<=i;j++)
				if (i%j == 0) { f = 0; break; }
			if (f)printf("%lld\n",i);

		}
		printf("\n");
	}
	//system("pause");
	return 0;
}