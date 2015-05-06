#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    
    int compareVersion(string version1, string version2){
        if(version1.empty() && version2.empty()){
            return 0;
        }else if(version1.empty() && (!version2.empty())){
            return remainAllZero(version2)?0:(-1);
        }else if((!version1.empty()) && version2.empty()){
            return remainAllZero(version1)?0:1;
        }else {
        
        int version1TopLevel, version2TopLevel;
        version1TopLevel = splitLevel(version1);
        version2TopLevel = splitLevel(version2);
        if(version1TopLevel > version2TopLevel){
            return 1;
        } else if(version1TopLevel < version2TopLevel){
            return -1;
        } else {
            return compareVersion(version1, version2);
        }
    }
    }
    
    bool remainAllZero(string& version){
        if(version.empty()){
            return true;
        }else {
            if(0 != splitLevel(version)){
                return false;
            }else {
                return remainAllZero(version);
            }
        }
    }
    
    int splitLevel(string& version){
        std::size_t pos = version.find('.'); //it can be more extendible, split(string& version, string delimiter)
        int intTopLevel;
        if(pos != std::string::npos){
            intTopLevel = std::stoi(version.substr(0, pos));
            version.erase(version.begin(), version.begin()+pos+1);
            return intTopLevel;
        } else {
            intTopLevel = std::stoi(version);
            version.erase();
            return intTopLevel;
        }
    } 

};

bool testSplitLevel(){
    Solution testSolution;
    string test1 = "0001.002";
    int result1 = testSolution.splitLevel(test1);
    if(result1 !=1){
        cout<<"result1"<<result1<<endl;
        cout<<test1<<endl;
        return false;
    }
    string test2 = "13.12.11";
    testSolution.splitLevel(test2);
    int result2 = testSolution.splitLevel(test2);
    if(result2 != 12){
        cout<<"result2"<<result2<<endl;
        cout<<test2<<endl;
        return false;
    }
    cout<<testSolution.splitLevel(test2)<<endl;
    cout<<test1<<endl;
    cout<<test2<<endl;
    cout<<test2.empty()<<endl;
    cout<<"All tests pass---splitLevel"<<endl;

    return true;
}

bool testCompare(){
    Solution testSolution;
    bool result = true;
    string test1V1 = "1.0.0.1";
    string test1V2 ="1";
    if(testSolution.compareVersion(test1V1, test1V2) != 1)
    {
        result = false;
        cout<<"test1 failed"<<endl;
        cout<<test1V1<<endl;
        cout<<test1V2<<endl;
    } 
    string test2V1 = "10.0001.22";
    string test2V2 = "10.0003";
    if(testSolution.compareVersion(test2V1, test2V2) != -1)
    {
        result = false;
        cout<<"test2 failed"<<endl;
        cout<<test2V1<<endl;
        cout<<test2V2<<endl;
    }
    string test3V1 = "1";
    string test3V2 = "1.1";
    if(testSolution.compareVersion(test3V1, test3V2) !=-1)
    {
        result = false;
        cout<<"test2 failed"<<endl;
    } 
    if(result){
        cout<<"All tests passed--compare"<<endl;
        return result;
    }else {
        return result;
    }
}

int main()
{
   // testSplitLevel();
    testCompare();
    return 0;
}
