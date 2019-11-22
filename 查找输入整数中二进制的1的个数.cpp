#include <iostream>
using namespace std;

int main1()
{
	int count = 0;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 32; i++)
		{
			if (n & (1 << i))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}