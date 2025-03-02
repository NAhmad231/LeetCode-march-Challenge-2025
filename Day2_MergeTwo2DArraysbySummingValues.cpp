// ------- APPROACH - 1  [USING HASHMAP] --------
/* 
    ALGORITHM - 
    1. ITERATE OVER nums1 , INSERT KEY VALUE OF nums! IN THE MAP
    2. ITERATE OVER nums2,
        key   = nums2[i][0]
        value = nums2[i][1]  
        map[key] += value
    3. CREATE A NEW 2D VECTOR RESULT 
        result.push_back({p.first , p.second})  // ITERATING OVER THE MAP
    4. SORT THE RESULT VECTOR AND RETURN 

    COMPLEXITY -
    T.C = O(nlogn)
    S.C = O(n)
    
*/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        unordered_map<int , int>mp;

        for(int i=0 ; i<nums1.size() ; i++){ 
            mp[nums1[i][0]] = nums1[i][1];
        }

        for(int i=0 ; i<nums2.size()  ; i++){ 
            int key  =   nums2[i][0];
            int value = nums2[i][1];

            mp[key] += value;
        }

        vector<vector<int>>result;

        for(auto &p : mp){
            result.push_back({p.first  , p.second});
        }

        sort(result.begin() , result.end());

        return result;

    }
};

// ------- APPROACH - 2  [WITHOUT USING EXTRA SPACE]  (2-POINTERS)  --------
/* 
    ALGORITHM - 
    1. USING 2 POINTERS , i=0 j=0
    2. while(i < n1 && j < n2)
        if(nums1[i][0] < nums2[j][0]) result -> (nums1[i])  // pushing the whole row
        if(nums1[i][0] > nums2[j][0]) result -> (nums2[j])
        else result -> ({nums1[i][0] , nums1[i][1] + nums2[j][1])} // if both are same
    3. CHECK FOR THE REMAINING FOR BOTH VECTORS 
        PUSH THE REMANING IN VECTOR RESULT
    4. RETURN RESULT 

    COMPLEXITY -
    T.C = O(N1+N1) ~ O(N)
    S.C = O(1)
    
*/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();

        int i = 0;
        int j = 0;

        vector<vector<int>>result;

        while(i < N1 && j < N2){
            if(nums1[i][0] < nums2[j][0]){
                result.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i][0] > nums2[j][0]){
                result.push_back(nums2[j]);
                j++;
            }
            else {
                result.push_back({nums1[i][0]  , nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i < N1){
            result.push_back(nums1[i]);
            i++;
        }


        while( j < N2){
            result.push_back(nums2[j]);
            j++;
        }

        return result;

    }
};



