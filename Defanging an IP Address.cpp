#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for(int i = 0; i<address.size(); i++){
            if(address[i] == '.'){ //看到.就將[.]加入result
                result.push_back('[');
                result.push_back('.');
                result.push_back(']');
            }
            else{ //否則加入原本的字元
                result.push_back(address[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    string testCase = "1.1.1.1";

    string answer = s.defangIPaddr(testCase);

    cout << answer;
}
