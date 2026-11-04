// 204. Count Primes
// Medium
// Given an integer n, return the number of prime numbers that are strictly less than n.

// this give time limit exceed for given problem

 class Solution {
public:
    bool isprime(int x, set<int>&st){
        for(auto it:st){
            if(it * it > x) break;
            if(x % it == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        set<int>st;
        for(int i = 2; i < n; i++){
            if(isprime(i,st)) {
                st.insert(i);
                ans++;
            }
        }
        return ans;
    }
};

// this will also give time linit exceed

class Solution {
public:
    bool isprime(int x){
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(isprime(i)) ans++;
        }
        return ans;
    }
};

// this is fine
class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n, true);

        if(n <= 2) return 0;

        prime[0] = false;
        prime[1] = false;

        for(int i = 2; i * i < n; i++) {

            if(prime[i]) {

                for(int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }

            }
        }

        int ans = 0;

        for(int i = 2; i < n; i++) {
            if(prime[i]) ans++;
        }

        return ans;
    }
};
