class Solution {
    public boolean hasAlternatingBits(int n) {
        int x = n^(n>>1);
        return (x&(x+1))==0;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.hasAlternatingBits(5)); // true
        System.out.println(sol.hasAlternatingBits(7)); // false
        System.out.println(sol.hasAlternatingBits(11)); // false
        System.out.println(sol.hasAlternatingBits(10)); // true
    }
}

