#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> getInput(ssize_t sizeLimit)
{
    vector<string> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
    {
        tokenVector.push_back(token);
        if (tokenVector.size() >= sizeLimit)
        {
            break;
        }
    }
    return tokenVector;
}

bool compareMax(string first, string second)
{
    return (first + second) > (second + first);
}

bool compareMin(string first, string second)
{
    return (first + second) < (second + first);
}

int main(void)
{
    vector<string> numbers = getInput(10);

    string strMax;
    sort(numbers.begin(), numbers.end(), compareMax);
    for (int i = 0; i < numbers.size(); i++)
    {
        strMax += numbers[i];
    }

    string strMin;
    sort(numbers.begin(), numbers.end(), compareMin);
    for (int i = 0; i < numbers.size(); i++)
    {
        strMin += numbers[i];
    }

    std::string::size_type sz; // alias of size_t
    int nMax = std::stoi(strMax, &sz);
    int nMin = std::stoi(strMin, &sz);
    cout << nMax + nMin << endl;

    return 0;
}