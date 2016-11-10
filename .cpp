//
//  main.cpp
//  Minimum Jumps to Reach End
//
//  Created by Zijian Xie on 2016/11/10.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class MinimumJumps{
private:
    vector<int> jumps;
public:
    MinimumJumps(vector<int>& jumps){
        this->jumps = jumps;
    }
    
    int DP(){
        vector<int> dp(jumps.size(),INT_MAX);//to store the minimum steps
        dp[0] = 0;
        vector<int> index(jumps.size(),-1);//to store the trace of jump.
        for(int i = 1; i < (int)jumps.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(jumps[j] + j >= i){
                    if(dp[j] + 1 < dp[i]){
                        dp[i] = dp[j] + 1;
                        index[i] = j;
                    }
                }
            }
        }
        int k = index[(int)jumps.size()-1];
        string trace = to_string(jumps.size()-1);
        while(k != -1){
            trace += "<-" + to_string(k);
            k = index[k];
        }
        cout<<"The jump trace is: " <<trace<<endl;
        cout<<"The minimum jumps is: "<<dp[jumps.size()-1]<<endl;
        return dp[jumps.size()-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> jumps = {2,3,1,1,2,4,2,0,1,1};
    MinimumJumps* test = new MinimumJumps(jumps);
    test->DP();
    return 0;
}
