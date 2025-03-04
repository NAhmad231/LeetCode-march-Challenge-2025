// APPROACH-1 [ NAIVE APPROACH  - RECURSION ]
/* 
  ALGORITHM - 
  -> EVERY TIME WHEN YOU PICK THE ELEMENT YOU HAVE TWO CHOICES [ PICK / NO PICK ]
    EITHER TO PICK THAT POWER // subtract it from n, and move to the next power.
    OR NOT PICK THE POWER // simply move to the next power without subtracting.

  COMPLEXITY -
  T.C = O(2 ^ log_3(n))  //  recursion forms a binary tree with a depth of O(log_3(n)) and each time we have two choice to pick or not pick
  s.C = o(log_3(n)) //  equal to the depth of the tree
  
*/
class Solution {
public:
bool check(int n , int p){
  if(n == 0 ) return true;
  if( pow(3,p) > n ) return false;

  bool pick = check(n - pow(3,p) , p+1);
  bool notpick = check(n , p+1);

  return pick || notpick; // if any of them return true -> return true 
}
    bool checkPowersOfThree(int n) {
        return check(n , 0 );
    }
};



// APPROACH - 2 [MATH]
/* 
  ALGORITHM - 
  1. Find the Maximum Power of 3
  2. Iterate Backward to Subtract Powers of 3
      ->  Start from the largest power 
      ->  if(n >= pow(3,p))  --> subtract 
      ->  If  n is still greater than or equal to  pow(3,p)  (meaning we need to use the same power again), return false (because we need distinct powers).
      ->  Decrease p and continue.
      -> At the last if false is not return, return true

  COMPLEXITY -
  T.C = O(log_3(n))
  s.C = o(1) 
  
*/
class Solution {
public:
bool check(int n , int p){
 // CALCULATE THE MAX POWER
  int p = 0;
  while(pow(3,p) <= n){
    p++;
  }

  while(n > 0){
    if(n >= pow(3,p)){
      n = n - pow(3,p);
    }
    if(n >= pow(3,p)){//If after subtracting, n is still greater than or equal to the same power, return false. -> ensure that same power is used twice
      return false;
    }
    p--;
  }
  return true; 
  }
};


/* 
APPROACH - 3
A number can be represented as a sum of distinct powers of 3 if and only if its base-3 representation consists of only 0s and 1s.
If any digit in the base-3 representation is 2, then n cannot be formed using distinct powers of 3.
*/

/* 
  ALGORITHM - 
1. Iterate while n is greater than 0
     -> Extract the last digit of n in base 3 using n % 3.
     -> If this digit is 2, return false (because we need distinct powers of 3 and 2 indicates repetition).
2.    Reduce n by performing integer division n /= 3 (this effectively shifts n in base 3).
3.    Return the result
     -> If the loop completes without finding 2, return true.

  COMPLEXITY -
  T.C = O(log_3(n)) // Each iteration divides n by 3
  s.C = o(1) 
  
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;  // If a digit in base 3 is 2, it's not possible
            n /= 3;
        }
        return true;
    }
};

