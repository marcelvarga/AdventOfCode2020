#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read(int a[100], int *timestamp) {
    int n = 0;
    FILE *in = fopen("in.in", "r");
    char c[200];
    fgets(c,200,in);
    *timestamp = atoi(c);
    fgets(c,200,in);
    char *p = strtok(c,"x,");
    
    while(p) {
        a[n] = atoi(p);
        n++;
        p  = strtok(NULL,"x,");
    }
    fclose(in);
    return n;
}
int solve(int n, int a[], int time){
    int bus = 0;
    for(int i = 1; i < n; i++)
        if ( (a[i] - (time % a[i])) < (a[bus] - (time % a[bus])))  bus = i;
    return a[bus] * (a[bus] - (time % a[bus]));
}
int main() {
    int a[100], timestamp;
    int n = read(a, &timestamp);
    printf("%d\n", solve(n, a, timestamp));
    return 0;
}
