// -------APPROACH - 1 [USING EXTRA SPACE]---------
/* 

ALGORITHM 
-> CREATE 3 EXTRA VECTOR (LESS , EQUAL , GREATER)
-> IF nums[i] < pivot  ---> LESS.PUSH_BACK(nums[i])
   ELSE IF nums[i] > pivot  ---> GREATER.PUSH_BACK(nums[i])
   ELSE IF nums[i] == pivot  ---> EQUAL.PUSH_BACK(nums[i])
-> CREATE A FINAL RESULT VECTOR
-> INSERT ALL THE THREE VECTOR IN ORDER(LESS , EQUAL , MORE) IN RESULT VECTOR
-> RETURN RESULT VECTOR

COMPLEXITY 
T.C = O(N)
S.C = O(N)

*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less;
        vector<int>equal;
        vector<int>greater;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] < pivot ){
                less.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                equal.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
            }
        }
        vector<int>result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());
        return result;
    }
};

// -------APPROACH - 2 [OPTIMIZED]---------
/* 

ALGORITHM 
-> INITIALIZE A RESULT VECTOR OF SIZE(nums.size())
-> INITIALIZE LEFT = 0 AND EQUALCOUNT = 0 ( COUNT THE TOTAL BO OF ELEMENTS EQUAL TO THE PIVOT) 
// FIRST FILL SMALLER ELEMENTS THAN PIVOT
-> IF nums[i] < pivot  ---> RESULT[LEFT++] = nums[i]
   ELSE IF nums[i] == pivot  ---> EQUALCOUNT++
// FILL ELEMENTS EQUAL TO THE PIVOT
-> 0 -> EQUALCOUNT    ----> RESULT[LEFT++] = PIVOT
// FILL ELEMENTS GREATER THEAN THE PIVOT
-> IF nums[i] > pivot  --->  RESULT[LEFT++] = nums[i]
-> RETURN RESULT VECTOR

COMPLEXITY 
T.C = O(N)
S.C = O(1) (OTHER THAN EXTRA SPACE)

*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>result(nums.size());
        int left = 0;
        int equalCount = 0;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            if(nums[i] < pivot){
                result[left] = nums[i];
                left++;
            }
            else if(nums[i] == pivot) equalCount++;
        }

        for(int i=0 ; i<equalCount ; i++){
            result[left] = pivot;
            left++;
        }

        for(int i=0 ; i<n ; i++){
            if(nums[i] > pivot){
                result[left] = nums[i];
                left++;
            }
        }

        return result;
    }
};
