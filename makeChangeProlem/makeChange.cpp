#include<iostream>
#include<vector>
#include<string>
#include <map>
#include <algorithm>


using namespace std;


class Ways{
    
    
    public:
    long ways=0;
    map <vector<long>, long> mapOfNums;

    
    long getPoop(){
        return Ways::ways;
    }
    
    long sumVec(vector<long> nums){
        long sum=0;
        for(auto a : nums){
            sum += a;
        }
        return sum;
    }
    
    long helper(vector<long> currNums, long currSum, vector<long> allNums, long target){
        if(currSum >= 0 && currSum < target){
            //cout << "first";
            vector<long> copyCurrNums = {};
            copyCurrNums = currNums;
            for(int i=0; i<allNums.size(); i++){
                currNums = copyCurrNums;
                currNums.push_back(allNums[i]);
                currSum = sumVec(currNums);
                helper(currNums, currSum, allNums, target);
            }
        }
        if(currSum>target){
            //cout << "second";
            return -1;
        }
        if(currSum==target){
            sort(currNums.begin(), currNums.end());
            if(Ways::mapOfNums.find(currNums) == Ways::mapOfNums.end()){
                Ways::mapOfNums[currNums] = sumVec(currNums);
                cout << "Ways of doing: ";
                for(auto a : currNums){
                    cout << a << '\t';
                }
                cout << "\n";
                Ways::ways++;
            }
            else{
                return -1;
            }
            
        }
        return 0;
    }
       
};
    
    // Complete the getWays function below.
long getWays(long n, vector<long> c) {
    vector<long> currNums;
    long target = n;
    vector<long>allNums = c;
    long currSum=0;
    long ways=0;
    
    Ways poop;
    poop.helper(currNums, currSum, allNums, target);    
    return poop.getPoop();
}



int main(){
    cout << "This is the coin change solution! Enter the target value and the given set of change\n";
    cout << "Input the Target:";
    int target;
    cin >> target;
    cout << "Input number of values: ";
    int n;
    cin >> n;
    vector<long> nums;
    for(int i=0; i<n; i++){
        int num=0;
        cout << i+1 << " number: ";
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    cout << "Total Number of ways: " << getWays(target,nums) << endl;
    //cout << " WAYSSSSSSSSSSSSSSSS::::::::" << getWays(4, {1,2,3});
    return 1;
}

    

