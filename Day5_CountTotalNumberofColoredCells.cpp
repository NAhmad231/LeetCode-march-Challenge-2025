// APROACH - 1 (Using simulation)
/* 
  INTITUTION -

    TIME   COLORED CELLS                    RESULT 
     1          1                              1
     2          1 + (4*1)                      5
     3          1 + (4*1) + (4*2)              12
     4          1 + (4*1) + (4*2) + (4*3)      25
     
     cells += 4*(t-1)  [RESULT]

  COMPLEXITY -
  
     T.C = O(N)
     S.C = O(1)
     
*/
class Solution {
public:
    long long coloredCells(int n) {
      int time = 1;
      long long colorCells = 1;
      while(time <= n){
        colorCells += 4*(time-1);
        time++;
    }
      return colorCells;
};

// APPROACH - 2 (Using Mathematical derivation)

/*
INTITUTION -

n = 8
coloredCells = 1 + (4*1) + (4*2) + (4*3)
               1 + 4(1+2+3+....)
               1 + 4(sum of n-1 natural number)
               1 + 4((n-1)(n-1+1))/2   /// here n = n-1
               1 + 2(n-1)*n

RESUULT = 1 + 2(n-1)*n

 COMPLEXITY -
  
     T.C = O(1)
     S.C = O(1)
     
*/
class Solution {
public:
    long long coloredCells(int n) {
       return 1 + (2* (long long)(n-1) * n);
    }
};
