#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int arr[1000];
int main()
{
	int n, p1 = 0,x=0,y=0;
	cin >> n; int p2 = n - 1;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		if (i % 2)
		{
			if (arr[p1] > arr[p2]) x += arr[p1++];
			else x += arr[p2--];
		}
		else
		{
			if (arr[p1] > arr[p2]) y += arr[p1++];
			else y += arr[p2--];
		}
	}
	cout << y << " " << x << endl;
	//system("pause");
	return 0;

}