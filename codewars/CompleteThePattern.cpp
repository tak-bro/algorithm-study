#include <algorithm>
#include <string>

std::string pattern(int n)
{
				std::string result;

				if (n <= 0)
				{
								return result;
				}

				for(int i = 1; i <= n; i++)
				{
								std::string spaces = std::string(n - i, ' ');

								std::string leftNums;
								std::string rightNums;
								for(int j = 1; j <= i - 1; j++)
								{
												leftNums += std::to_string(j%10);
												rightNums += std::to_string(j%10);
								}
								std::reverse(rightNums.begin(),rightNums.end());

								result += spaces + leftNums + std::to_string(i%10) + rightNums + spaces;

								if (i != n)
								{
												result += '\n';
								}
				}

				return result;
}
