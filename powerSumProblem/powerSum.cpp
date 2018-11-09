
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;


int sumVec(vector<int> nums, int power){
    int sum=0;
    for(auto a : nums){
        sum += pow(a,power);
    }
    return sum;
}

void printVec(vector<int> nums){
    cout << "Vec = {";
    for(auto a : nums){
        cout << a << ", ";
    }
    cout << "}";
    //std::this_thread::sleep_for (std::chrono::seconds(1));
}
bool flag = false;

int helper(vector<int> allNums, int index, int target, int power){
    if(sumVec(allNums, power)>=0 && sumVec(allNums, power)<target)
    {
        vector<int> copy;
        copy = allNums;
        allNums.push_back(index);
        //printVec(allNums);
        //if(index>10){
           // return 0;
        //}
        if(sumVec(allNums, power)>target){
            return -2;
        }
        if(sumVec(allNums, power) == target){
            cout << "**************)FOUND(**********";
            for(auto a: allNums){
                cout << a << "\t";
            }
	    flag = true;
            cout << "*************************";
            return -1;
        }
        helper(allNums, index+1, target, power);
        helper(copy, index+1, target, power);
    }    
}

int powerSum(int N, int p){
    vector<int> allNums= {};
    
    return helper(allNums, 1, N, p);

}





int main(int argc, char* argv[])
{

    if(argc < 3){
        std::cerr << "Usage: " << argv[0] << " [Target Num] " << " [Exponent]" << endl;
        return 0;
    }
    int x = stoi(argv[1]);
    int y = stoi(argv[2]);
    powerSum(x, y);
    if(flag==false){
	cout << "Unable to find a solution :/ \n";
    }
    return 0;
}
