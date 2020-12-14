#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 100

typedef struct memory{
    int address;
    unsigned long long value;
}memory;

unsigned long long masked(unsigned long long value, char mask[40]) {
    for (int i = 35; i >=0; i--) {
        if (mask[i] == '0' && ( (value >> (35 - i) | 0) != 0)){
            unsigned long long newmask = 0xFFFFFFFFFFFFFFFF & ~(1ull << (35-i));
            value = value & newmask;
        } 
        if (mask[i] == '1' && ( (value >> (35 - i) & 0) == 0)) {
            unsigned long long newmask = 1ull << (35-i);
            value = value | newmask;
        }
    }
    return value;
}

void newvalue(char line[N], memory a[100], int *n, unsigned long long *sum, char mask[40]) {
    unsigned long long value = strtoull(strchr(line, '=')+1, NULL, 10);
    int address = strtol(line + 4, NULL, 10);
    value = masked(value, mask);
    bool found = 0;
    for (int i = 0; i < *n && !found; i++) 
        if (a[i].address == address) {
            found = 1;
            *sum -= a[i].value;
            a[i].value = value;
            *sum += a[i].value;
        }
    
    if (!found) {
        a[*n].address = address;
        a[*n].value = value;
        *sum += value;
        *n = *n + 1;
    }
}

unsigned long long solve(){
    memory a[5*N];
    char mask[40], line[N];
    int n = 0;
    unsigned long long sum = 0;
    int i = 0;
    FILE *in = fopen("in.in", "r");
    fgets(line, N, in);
    while(!feof(in)) {
        i++;
        if (line[1] == 'a') strcpy(mask, line + 7);
        if (line[1] == 'e') newvalue(line, a, &n, &sum, mask);
        fgets(line, N, in);
    }
    fclose(in);
    return sum;
}

int main() {
    unsigned long long ANS = solve();
    printf("%llu\n", ANS);
}
