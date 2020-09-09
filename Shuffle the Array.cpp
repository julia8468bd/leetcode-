#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int count = 0;
        vector<int> result(n*2); //創建大小為2n的新空矩陣

        for (int i = 0; i < result.size(); i++) {
            for (int j = i; j < result.size() && count < result.size() ; j = j + n) { //從0開始跳n格取值、1跳n格取值...
                result[count] = nums[j];
                count = count + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> testCase = {2,5,1,3,4,7};
    int n = 3;

    vector<int> answer = s.shuffle(testCase, n);

    cout << "[";
    for(int i=0; i<testCase.size(); i++){
        cout << answer[i];
        if(i!=testCase.size()-1){
            cout << ", ";
        }
    }
    cout << "]";
}
