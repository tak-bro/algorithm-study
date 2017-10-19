/*
You have a secret message for your friends. You want to mail it to them. But, you are well aware that each of their mail carriers reads their mail before delivering it. So, instead of sending the entire message, you only send some characters to each of them.

If you have n friends, friend 1 gets character 1, n + 1, 2n + 1, etc. And friend 2 gets character 2, n + 2, 2n + 2, etc. All other characters are replaced with dashes.
                                                
Example:  3 friends, message: I think you are all sexy
Friend 1 receives: I--h--k--o--a-- --l--e--
Friend 2 receives: - --i-- --u--r--a-- --x-
Friend 3 receives: --t--n--y-- --e--l--s--y
Treat null messages as empty strings (C#, JavaScript). If your number of friends is greater than the length of your message, some friends will simply receive all dashes. If you have zero friends (or less than zero), return null (empty vector for C++);
*/
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include <vector>
#include "../catch.hpp"

using namespace std;

std::vector<std::string> splitMessage(std::string message, int count)
{
    if (count <= 0) 
        return {};
        
    std::vector<std::string> result(count, std::string(message.length(), '-'));
    for(int i = 0; i < message.length(); ++i)
      result[i % count][i] = message[i];
    
    return result;
}

TEST_CASE( "Collaboration Station", "[splitMessage]" ) {
    std::vector<std::string> expected =
        {
            "I--h--k--o--a-- --l--e--",
            "- --i-- --u--r--a-- --x-",
            "--t--n--y-- --e--l--s--y"
        };
    std::vector<std::string> actual = splitMessage("I think you are all sexy", 3);

    REQUIRE ( actual == expected );
}