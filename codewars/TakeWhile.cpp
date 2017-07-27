std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    std::vector<int> result;
    
    std::for_each(arr.begin(), std::find_if_not(arr.begin(), arr.end(), pred), [&](int n){
      result.push_back(n);
    });
    
    return result;
}