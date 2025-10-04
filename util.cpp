#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    // create a set which will be returned, tempStr
    std::set<std::string> tempSet;
    string tempStr = "";
    // trim the rawWords
    rawWords = trim(rawWords);
    for (int i = 0; i < rawWords.length(); i++)
    {
        // see if the char is a num or letter
        if ((rawWords[i] >= 'a' && rawWords[i] <= 'z') || (rawWords[i] >= 'A' && rawWords[i] <= 'Z') || (rawWords[i] >= '0' && rawWords[i] <= '9'))
        {
            tempStr += rawWords[i];
        }
        else
        {
            if (tempStr.length() >= 2)
            {
                tempSet.insert(convToLower(tempStr));
            }
            tempStr = "";
        }
    }
    // the last word has to be put into the set
    if (tempStr.length() >= 2)
    {
        tempSet.insert(convToLower(tempStr));
    }
    return tempSet;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
