class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() < 2){
            return;
        }

        //方法1.空间换时间
        vector<int> odd;
        vector<int> even;
        for(int i=0; i<array.size(); ++i){
            if(array[i] % 2 == 0){
                even.push_back(array[i]);
            }else{
                odd.push_back(array[i]);
            }
        }
        for(int i=0; i<odd.size(); ++i){
            array[i] = odd[i];
        }
        for(int i=0; i<even.size(); ++i){
            array[odd.size()+i] = even[i];
        }

        //方法2：冒泡排序思想你的输出为:

        for(int i=0; i<array.size(); ++i){
            for(int j=array.size()-1; j>i; --j){
                if(array[j] % 2 == 1 && array[j-1] % 2 == 0){
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                }
            }
        }
    }
};
