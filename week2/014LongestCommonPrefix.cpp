#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
class Solution{
public:
    string getCommonPrefix(string& a, string& b){
        if(!(a.length()*b.length())){
            return "";
        }
        string result = "";
        unsigned int minLength = std::min(a.length(), b.length());
        for(unsigned int i = 0;i < minLength;++i){
            if(a[i] == b[i]){
                result += a[i];
            }else{
                break;
            }
        }
        return result;
    }

    
    string longestCommonPrefix(vector<string>& strs) {
       string longestPrefix = strs[0]; 
       for(unsigned int i = 1;i < strs.size(); ++i){
           longestPrefix = getCommonPrefix(longestPrefix, strs[i]);
           if(!longestPrefix.length()){
               return "";
           }
        }

        return longestPrefix;
    }
    



}; // class Solution

void testSolution(){
    freopen("014test.txt","r",stdin);
    int testNum, stringNum;
    cin>>testNum;
    Solution testSolution;
    for(int i = 0;i<testNum;i++){
        cout<<"Test "<<i<<": "<<endl;
        vector<string> strs;
        string eachStr;
        cin>>stringNum;
        for(int j = 0;j<stringNum;++j){
            cin>>eachStr;
            strs.push_back(eachStr);
        }
        string ans;
        cin>>ans;
        //TODO: can't input an empty string by this method
        assert(ans == testSolution.longestCommonPrefix(strs));
    }

    cout<<"All tests passed"<<endl;
}

int main(){
    testSolution();

    return 0;
}

