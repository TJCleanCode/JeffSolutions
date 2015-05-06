#include <iostream>
#include <string>
#include <vector>

class Solution{
public:
    int compareVersion(std::string version1, std::string version2){
        std::vector<int> version1TwoLevel = splitTwoLevel(version1);
        std::vector<int> version2TwoLevel = splitTwoLevel(version2);
        if(version1TwoLevel[0] > version2TwoLevel[0]){
            return 1;
        } else if(version1TwoLevel[0] < version2TwoLevel[0]){
            return -1;
        } else {
            if(version1TwoLevel[1] > version2TwoLevel[1]){
                return 1;
            } else if(version1TwoLevel[1] < version2TwoLevel[1]){
                return -1;
            } else {
                return 0;
            }   
        }     

    }
    std::vector<int> splitTwoLevel(std::string version){
        std::size_t pos = version.find('.');
        int firstLevel, secondLevel;
        std::vector<int> twoLevel = {0, 0};
        if(pos!=std::string::npos){
            firstLevel = std::stoi(version.substr(0,pos));
            secondLevel = std::stoi(version.substr(pos+1));
            twoLevel[0] = firstLevel;
            twoLevel[1] = secondLevel;
            return twoLevel;
        } else {
            firstLevel = std::stoi(version);
            secondLevel = 0;
            twoLevel[0] = firstLevel;
            twoLevel[1] = secondLevel;
            return twoLevel;
        }
    }


};

int main()
{
    Solution test;
    std::cout<<test.compareVersion("1.0","1.1")<<std::endl;
    std::cout<<test.compareVersion("001.001","1.1")<<std::endl;
    std::cout<<test.compareVersion("00010.3","10.37")<<std::endl;
    std::cout<<test.splitTwoLevel("10.37")[0]<<std::endl;
    std::cout<<test.splitTwoLevel("10.37")[1]<<std::endl;
    return 0;
}
