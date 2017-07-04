class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr);
};


std::vector<std::pair <std::string, std::string>> PartList::partlist(std::vector<std::string> &arr)
{
  std::string strFirst, strSecond;
  std::vector<std::pair <std::string, std::string>> ans;
  
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 0; j < i; j++) {
      strFirst += arr[j] + " ";
    }
    for (int k = i; k < arr.size(); k++) {
      strSecond += arr[k] + " ";
    }
    // Delete last blank
    strFirst.pop_back();
    strSecond.pop_back();
    
    // Create pair and push to answer
    std::pair<std::string, std::string> toPushPair(strFirst, strSecond);
    ans.push_back(toPushPair);

    // Clear temp string
    strFirst.clear();
    strSecond.clear();
  }
  
  return ans;
}