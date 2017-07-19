using namespace std;

double money_value(const string &s)
{
    std::string temp;
    
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || s[i]=='.' || isdigit(s[i])) {
            temp.push_back(s[i]);
        }
    }
    
    return atof(temp.c_str());
}