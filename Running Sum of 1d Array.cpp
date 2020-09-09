#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i;
        vector<int> result = nums;
        for(i = 1; i < nums.size(); i++){ //�s�x�}�����Ƶ���nums���e�@�Ӽƥ[�ۤv
            result[i] = result[i-1] + result[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> testCase = {1,2,3,4};

    vector<int> answer = s.runningSum(testCase);

    cout << "[";
    for(int i=0; i<testCase.size(); i++){
        cout << answer[i];
        if(i!=testCase.size()-1){
            cout << ", ";
        }
    }
    cout << "]";
};
