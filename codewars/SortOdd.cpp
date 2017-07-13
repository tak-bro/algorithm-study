#include<algorithm>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
      std::vector<int> odd = std::vector<int>();
      
      // find odd
      for (int i = 0; i < array.size(); i++) {
        if (array[i] %2 == 1)
          odd.push_back(array[i]);
      }
      
      // sort less
      std::sort(odd.begin(), odd.end(), [](int a, int b) {
         return b < a;   
      });
      
      // merge
      for (int i = 0; i < array.size(); i++) {
        if (array[i] %2 == 1) {
            array[i] = odd.back();
            odd.pop_back();
        }
      }
      
      return array;
    }
};