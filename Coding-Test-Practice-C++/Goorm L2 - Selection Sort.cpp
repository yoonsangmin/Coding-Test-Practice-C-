#include <iostream>
#include <vector>

using namespace std;
int main() {
	int size, level;
	vector<int> nums;
	cin >> size >> level;

	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	for (int i = 0; i < level; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (nums[i] > nums[j])
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << " ";
	}

	return 0;
}