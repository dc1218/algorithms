/*
两数之和

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例：
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
		static vector<int> TwoSum(vector<int>& numbers,const int target)
		{
			map<int, int> answers;
			auto key = 0;
			for (auto index = 0;index < numbers.size();++index)
			{
				key = target - numbers.at(index);
				if (answers.find(key) != answers.end())
				{
					vector<int> callBack;
					callBack.emplace_back(index);
					callBack.emplace_back(answers[key]);
					return callBack;
				}
				answers[numbers.at(index)] = index;
			}
			return vector<int>();
		}
};

int main()
{
	Solution solution;
	vector<int>m={ 2, 3, 7, 9, 10 };
	for (auto num : solution.TwoSum(m, 9))
		cout << num << " ";
	return 0;
}