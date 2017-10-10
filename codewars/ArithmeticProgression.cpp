using namespace std;

static long findMissing(vector<long> list)
{
  long diff = list[1] - list[0];        // Finding the difference and assigning it to a variable
  long missing;
  for(int x = 1; x < list.size(); x++)  // Run through the entire list (Starting from index 1)
  {
    if(list[x] - list[x - 1] != diff)   // Check the difference of the current and previous index element
    {                                   // If the difference does not equal the difference we found earlier...
      missing = list[x - 1] + diff;     // The missing number is the sum of the previous index and the difference
    }
  }
  return missing;
}