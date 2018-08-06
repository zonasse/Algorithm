class Solution {
public:
	void replaceSpace(char *str,int length) {
        int spaceNum = 0;
        for(int i=0; i<length; ++i){
            if(str[i] == ' '){
                spaceNum++;
            }
        }
        int newLen = length+2*spaceNum;
        int left = length-1;
        int right = newLen-1;
        while(left >= 0 && left < right){
            if(str[left] != ' '){
                str[right] = str[left];
                right--;
                left--;
            }else{
                str[right--] = '0';
                str[right--] = '2';
                str[right--] = '%';
                left--;
            }
        }

	}
};
