class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> num_set;
        if(length <= 0 || numbers == NULL){
            return false;
        }
        bool valid = false;
        for(int i=0; i<length; ++i){
            if(num_set.find(numbers[i]) == num_set.end()){
                num_set.insert(numbers[i]);
            }else{
                valid = true;
                duplication[0] = numbers[i];
                break;
            }
        }
        return valid;
    }
};
