//
// Created by 钟奇龙 on 2019-04-14.
//

#include <vector>
#include <stack>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int maxRecFromBottom(vector<int> height){
    int maxArea = 0;
    stack<int> s;
    for (int i = 0; i < height.size(); ++i) {
        while(s.empty() == false && height[s.top()] >= height[i]){
            int j = s.top();
            s.pop();
            int k = s.empty() == true ? -1:s.top();
            maxArea = max(maxArea,(i-k-1)*height[j]);
        }
        s.push(i);
    }
    while(s.empty() == false){
        int j = s.top();
        s.pop();
        int k = s.empty() == true ? -1:s.top();
        maxArea = max(maxArea,(height.size()-1-k-1)*height[j]);
    }
    return maxArea;
}

int getMaxArea(vector<vector<int> > map){
    if(!map[0].size() || !map.size()){
        return 0;
    }
    int maxArea = 0;
    vector<int> height(map[0].size(),0);
    for (int i = 0; i < map.size(); ++i) {
        for(int j=0; j<map[0].size(); ++j){
            height[j] = map[i][j] == 0 ? 0:(height[j]+1);
        }
        maxArea = max(maxRecFromBottom(height),maxArea);
    }
    return maxArea;
}

int main(){
    vector<vector<int> > map = {{1,0,1,1},{1,1,1,1},{1,1,1,0}};
    printf("%d",getMaxArea(map));

    return 0;
}