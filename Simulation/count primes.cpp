Sieve of Erathostenes

Most optimal soln in terms of time complexity O(n log(log n)) SC -> O(N)

class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
      
        if(n <= 1) return 0;
        int cnt = 0;
        for(int i = 2; i *  i <= n; i++){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i) prime[j] = false;
            }
        }
        for(int i = 2; i < n + 1; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
        
    }
};
