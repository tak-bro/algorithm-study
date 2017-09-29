using namespace std;

int nthSmallest(std::vector<std::vector<int>> arr, int n)
{
    vector<int> bag;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            bag.push_back(arr[i][j]);
        }
    }
    sort(bag.begin(), bag.end());   
    return bag[n-1];
}