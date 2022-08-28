// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/count-primes/
// Date: 28th August, 2022
// Tags: math, number-theory, array, prime

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(max(n,2),1);
        isPrime[0]=0;
        isPrime[1]=0;
        
        for(long long i=2;i<n;i++)
        {
            if(isPrime[i])
            {
                long long j;
                for(j=i*i;j<n;j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        return accumulate(isPrime.begin(),isPrime.end(),0);
    }
};
