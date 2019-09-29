#include "iostream"
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> GetNarcissisticNumbers(const int bit,const bool needAll)
	{
		m_allNum.clear();
		if (bit >= 1)
		{
			vector<int>bit1 = { 9,8,7,6,5,4,3,2,1,0 };
			if (bit == 1)// 一位数的水仙花数就是自己
				return bit1;
			else if (bit > 2)
			{
				// 两位数没有水仙花数
				// 三位数以上的水仙花数
				auto condition = bit;
				do
				{
					for (auto number = pow(10, condition)-1; number >= pow(10, condition - 1); --number)
					{
						auto sum = 0;
						for (int tmp = number;tmp > 0;tmp = tmp / 10)
						{
							sum += pow((tmp % 10), condition);
						}
						if (number == sum)
            {
							if (count(m_allNum.begin(), m_allNum.end(), number) == 0)
								m_allNum.emplace_back(number);
						}
					}
					if(!needAll)
						break;
					condition--;
				} while (condition > 2);
        if (needAll) 
			  {
				  //加入三位数以前的所有水仙花数
				  m_allNum.insert(m_allNum.end(), bit1.begin(), bit1.end());
			  }
			}
		}
		return m_allNum;
	}
private:
	vector<int> m_allNum;
};
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: ./program number";
		return -1;
	}
	auto const  bit = atoi(argv[1]);
	Solution solution;
	for (auto it : solution.GetNarcissisticNumbers(bit,true))
		cout << it << " ";
	return 0;
}


