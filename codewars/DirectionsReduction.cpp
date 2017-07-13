#include <map>

class DirReduction
{
	public:
		static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};


std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr)
{
	std::vector<std::string> stack;
	std::map<std::string, std::string> opposite;
	opposite["WEST"] = "EAST";
	opposite["EAST"] = "WEST";
	opposite["NORTH"] = "SOUTH";
	opposite["SOUTH"] = "NORTH";

	stack.push_back(arr[0]);	// add first index

	for (int i = 1; i < arr.size(); i++) {
		if (stack[stack.size()-1] == opposite[arr[i]])	// check isOpposite
			stack.pop_back();
		else 
			stack.push_back(arr[i]);
	}

	return stack;
}
