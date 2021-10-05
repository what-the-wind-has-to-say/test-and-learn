#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() + 1,vector<int>(word2.size() + 1));
        //dp含义字符串word1的下标0-i-1，转换为word2的下标0-j-1需要的最少操作数
        for(int i = 0;i <= word1.size();i++)
        {
            dp[i][0] = i;//删除word1
        }
        for(int j = 0;j <= word2.size();j++)
        {
            dp[0][j] = j;//copyword2
        }
        for(int i = 1;i <= word1.size();i++)
        {
            for(int j = 1;j <= word2.size();j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    //增，删，替换
                    dp[i][j] = min({dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};