#include <iostream>
#include <vector>
using namespace std;
class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		int countl = 0;
		int countr = 0;
		int sum = 0;
		int tmp0 = 0;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 && right[i] != 0)
			{
				tmp0++;
				countr += right[i];
			}
			else if (right[i] == 0 && left[i] != 0)
			{
				tmp0++;
				countl += left[i];
			}
			else if (left[i] == 0 && right[i] == 0)
			{
				tmp0++;
				countr += right[i];
				countl += left[i];
			}
		}
		countl += 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n - i - 1; j++)
			{
				if (right[j - 1] > right[j])
				{
					int tmp = right[j - 1];
					right[j - 1] = right[j];
					right[j] = tmp;
				}
			}
		}
		vector<int> vi;
		for (int i = 0; i < n; i++)
		{
			if (right[i] != 0 && left[i] != 0)
			{
				vi.push_back(right[i]);
			}
		}
		
		if (vi.size() > 1)
		{
			for (int i = 0; i < n - tmp0 - 1; i++)
			{
				countr += vi[i];
			}
			countr += 1;
		}
		
		sum = countl + countr;
		return sum;
	}
};
int main()
{
	Gloves g;
	vector<int> left = { 1, 2, 0, 1, 3, 1 };//7
	vector<int> right = { 0, 0, 0, 2, 0, 1 };//2
	int tmp = g.findMinimum(6, left, right);
	cout << tmp;
	return 0;
}