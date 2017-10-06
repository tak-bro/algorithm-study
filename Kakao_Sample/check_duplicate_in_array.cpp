#include<vector>
#include<algorithm>

using namespace std;

bool solution(vector<int> arr)
{
    bool answer = true;

    sort (arr.begin(), arr.end()); 
    for (int i=1; i < arr.size()+1; i++) {
        if (arr[i] != i) {
            return false;
        }
    }

    return answer;
}
