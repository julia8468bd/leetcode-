#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max = -1; //初始化max
        for (int i=0; i<candies.size(); i++){ //找出糖果最大值
            if (candies[i] > max){
                max = candies[i];
            }
        }

        for (int i=0; i<candies.size(); i++){
            //如果加上額外糖果>=max，將true加入result，否則加入false
            if (candies[i] + extraCandies >= max){
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> testcase = {2,3,5,1,3};
    int extra = 3;

    vector<bool> answer = s.kidsWithCandies(testcase, extra);

    cout << "[";
    for(int i=0; i<testcase.size(); i++){
        if(answer[i] == 1){
            cout << "true";
        }
        else{
            cout << "false";
        }
        if(i!=testcase.size()-1){
            cout << ", ";
        }
    }
    cout << "]";
}
