//source for modInverse algorithm https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int read(int a[N], int b[N], long long *product) {
    int n = 0;
    *product = 1;
    FILE *in = fopen("in.in", "r");
    char c[200];
    fgets(c,200,in);
    char *p = strtok(c,",");
    int val = 0;
    while(p) {
        if(p[0] != 'x') {
            a[n] = atoi(p);
            *product *= a[n];
            b[n] =  (a[n] - val) % a[n] ;
            n++;
        }
        val++;
        p  = strtok(NULL,",");
    }

    fclose(in);
    return n;
}
long long gcdExtended(long long a, long long b, long long* x, long long* y); 
  
long long modInverse(long long a, long long m) {
    long long x, y; 
    gcdExtended(a, m, &x, &y); 
    long long res = (x % m + m) % m; 
    return res; 
} 
  
long long gcdExtended(long long a, long long b, long long* x, long long* y) {
    if (a == 0)  
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    long long x1, y1; 
    long long gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    *x = y1 - (b / a) * x1; 
    *y = x1; 

    return gcd; 
} 
  
long long solve(int n, int bus[], int offset[], long long products[], long long product) {
    long long ANS = 0;
    for (int i = 0; i < n; i++) 
        ANS += offset[i] * products[i] * modInverse(products[i], bus[i]);
    ANS -= product;
    return ANS % product;
}

int main() {
    int bus[N], offset[N];
    long long product = 1, products[N];
    int n = read(bus, offset, &product);

    for (int i = 0; i < n; i++) products[i] = product / bus[i];
    long long ANS = solve(n, bus, offset, products, product);
    printf("%lld\n", ANS);
    
    return 0;
}
