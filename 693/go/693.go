package main
func hasAlternatingBits(n int) bool {
    x := n^(n>>1)
    return x&(x+1)==0
}

func main() {
	println(hasAlternatingBits(5))
}