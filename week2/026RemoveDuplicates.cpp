#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        for(unsigned int i = 0;i+1<nums.size();i++){
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i+1);
            }
        }

        return nums.size();
    }
};

void testSolution(){
    Solution testSolution;
    vector<int> testVec = {1,1,2,2,3,3,3};
    vector<int> testVec2 = {1,2,3,4,5,6};
    vector<int> testVec3 = {};
    assert(testSolution.removeDuplicates(testVec) == 3);
    assert(testSolution.removeDuplicates(testVec2) ==6);
    assert(testSolution.removeDuplicates(testVec3) ==0);
    cout<<"All tests passed"<<endl;
}

int main(){
    testSolution();
    return 0;
}
