class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

         int totalSum = 0;
        
        for(int i=1;i<=n;i++){
         int product = 9;
         int digit = 9;

            for(int j=1;j<=i-1;j++){
                product = product*digit;
                digit--;
            }

            totalSum += product;
        }

        return totalSum+1;
    }
};