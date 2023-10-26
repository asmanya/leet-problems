#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        string str, temp;
        while (i < s.length())
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else
            {
                while (i < s.length() && s[i] != ' ')
                {
                    temp += s[i];
                    i++;
                }
                str = temp + ' ' + str;
                temp = "";
            }
        }

        // remove the spaces at the back
        if (!str.empty() && str.back() == ' ')
        {
            str.pop_back();
        }

        return str;
    }
};