class Solution {
public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
            if(n%i==0) return false;
        return true;
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size()-1;
        while(i<=j)
        {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int primePalindrome(int n) 
    {
        if(n <= 2) return 2;
        if(n >= 9989900) return 100030001;
        if(n <= 11 and isPrime(n)) return n;

        for(int i=n+1;i<=2e8+5;i++)
        {
            if(isPrime(i) and isPalindrome(to_string(i)))
                return i;
        }
        return -1;
    }
};