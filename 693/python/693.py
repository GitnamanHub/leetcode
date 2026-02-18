class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = n^(n>>1)
        return x&(x+1)==0
    
if __name__ == "__main__":
    s = Solution()
    print(s.hasAlternatingBits(5)) # true
    print(s.hasAlternatingBits(7)) # false
    print(s.hasAlternatingBits(11)) # false
    print(s.hasAlternatingBits(10)) # true