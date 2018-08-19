class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while(i < words.size()){
            int j = i;
            int rowLen = 0;
            while(j < words.size() && rowLen + words[j].size() + j-i <= maxWidth){
                rowLen += words[j++].size();
            }
            int spaceNum = maxWidth - rowLen;
            string line = "";
            for(int k=i; k < j; ++k){
                line += words[k];
                if(spaceNum > 0){
                    int temp;
                    if(j == words.size()){
                        if(j-k-1 == 0){
                            temp = spaceNum;
                        }else{
                            temp = 1;
                        }
                    }else{
                        if(j-k-1 > 0){
                            if(spaceNum % (j-k-1) == 0){
                                temp = spaceNum/(j-k-1);
                            }else{
                                temp = spaceNum/(j-k-1) + 1;
                            }
                        }else{
                            temp = spaceNum;
                        }

                    }
                    line.append(temp,' ');
                    spaceNum -= temp;
                }

            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};
