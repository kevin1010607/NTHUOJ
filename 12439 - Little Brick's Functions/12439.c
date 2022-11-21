#include <stdio.h>
int gcd(int a, int b) {
    return (b==0 ? a : gcd(b, a%b));
}
int lcm(int a, int b) {
    return a*b/gcd(a, b);
}
int power(int a, int b) {
    if(b == 1) return a;
    if(b%2 == 0) return power(a, b/2)*power(a, b/2);
    if(b%2 == 1) return a*power(a, b/2)*power(a, b/2);
}
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", gcd(lcm(power(a, b), c), d));
	printf("%d\n", gcd(power(lcm(a, b), c), d));
	printf("%d\n", lcm(gcd(power(a, b), c), d));
	printf("%d\n", lcm(power(gcd(a, b), c), d));
	printf("%d\n", power(gcd(lcm(a, b), c), d));
	printf("%d\n", power(lcm(gcd(a, b), c), d));
	return 0;
}
