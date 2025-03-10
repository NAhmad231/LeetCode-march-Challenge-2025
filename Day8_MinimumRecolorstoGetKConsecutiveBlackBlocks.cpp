// APPROACH - 1 [BRUTE FORCE]
/*
ALGORITHM-
INTIALIZE A RESULT VARIABLE WITH MAX VALUE OR K
ITERATE i (0 -> n-k)
        int opr = 0;
          j(i -> (j-i+1 <= k))
            if(block[j] == 'w') opr++; 
      RESULT = MIN (opr, RESULT);
RETURN RESULT;


COMPLEXITY :-
T.C = O(N*K);
S.C = O(1);
*/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int result = INT_MAX;
        int n = blocks.size();
        for(int i=0 ; i<=n-k ; i++){
            int oper = 0;
            for(int j=i ; j-i+1 <= k ; j++){
                if(blocks[j] == 'W') oper++;
            }
            result = min(result, oper);

        }
        return result;
    }
};

// APPROACH - 2 [SLIDING WINDOW]

/*
ALGORITHM-


COMPLEXITY :-
T.C = O(N);
S.C = O(1);
*/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        int result = k;
        int n = blocks.size();
        int W = 0;
        while(j<n){
            if(blocks[j] == 'W') W++;
            if(j-i+1 == k){
                result = min(result, W);
                if(blocks[i] == 'W'){
                    W--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
