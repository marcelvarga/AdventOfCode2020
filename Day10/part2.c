#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X>Y) ? X : Y)
#define N 102
#define MD 3 //max jolt diff

long long ways[N];

long long calculateways(int a[N], int index){
    if(ways[index]) return ways[index];
    long long ANS = 0;
    if (a[index] - a[index-1] <= MD) ANS += calculateways(a, index-1);
    if (a[index] - a[index-2] <= MD) ANS += calculateways(a, index-2);
    if (a[index] - a[index-3] <= MD) ANS += calculateways(a, index-3);

    ways[index] = ANS;
    return ANS;
}

int compare(const void *p, const void *q){
    const int *a = (int *) p;
    const int *b = (int *) q;
    return *a>*b;
}

int read(int a[N]){
    int n = 0, ma = 0;;
    FILE *in = fopen("in.in","r");
    char line[50];
    a[n] = 0; n++;
    fgets(line,50,in);

    while (!feof(in)){
        sscanf(line,"%d", &a[n]);
        ma = MAX(a[n],ma);
        n++;
        fgets(line,50,in);
    }
    fclose(in);
    a[n] = ma + 3;
    n++;
    return n;
}

int main(){
    int a[N];
    int n = read(a);
    qsort(a, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) ways[i] = 0;
    ways[0] = 1;
    ways[1] = 1;
    if(a[2] <= MD) ways[2] = 2; else ways[2] = 1;

    calculateways(a, n-1);
    printf("%lld\n", ways[n-1]);
    return 0;
}
