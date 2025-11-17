#pragma once
#include <string>
#include <stack>

using namespace std;

inline bool DetermineXml(const string& input)
{
    stack<string> st;
    int n = input.size();

    for (int i = 0; i < n;)
    {
        if (input[i] == '<')
        {
            int j = input.find('>', i + 1);
            if (j == string::npos)
                return false; // no closing '>'

            if (input[i + 1] == '/') // "</tag>"
            {        
                string tagName = input.substr(i + 2, (j - 1) - (i + 2) + 1);

                if (st.empty() || st.top() != tagName)
                    return false;

                st.pop();
            }
            else 
            {
                string tagName = input.substr(i + 1, j - (i + 1));
                st.push(tagName);
            }

            i = j + 1; // move past '>'
        }
        else
        {
            if (input[i] == '>')
                return false;
            i++;
        }
    }

    return st.empty();
}
