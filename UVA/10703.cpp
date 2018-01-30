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
bool vis[501][501];
int main()
{
	int w, h, n;
	while (cin >> w >> h >> n)
	{
		if (!w && !h && !n)break;
		memset(vis, 0, sizeof vis);
		for (int k = 0; k < n; k++) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)swap(x1, x2); if (y1 > y2)swap(y1, y2);
			for (int i = x1-1; i < x2; i++)
				for (int j = y1-1; j < y2; j++)
					vis[i][j] = 1;
		}
		int ans = 0;
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				if (!vis[i][j])ans++;
		if(!ans )cout << "There is no empty spots.\n";
		else if (ans == 1)
			cout << "There is one empty spot.\n";
		else
			cout << "There are " << ans << " empty spots.\n";
	}
	
	//system("pause");
	return 0;
}