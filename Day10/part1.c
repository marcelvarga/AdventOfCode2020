#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X>Y) ? X : Y)
#define N 102
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
    int joltdiff[3] = {0,0,0};
    qsort(a, n, sizeof(int), compare);

    for (int i = 1; i < n; i++) joltdiff[a[i]-a[i-1]-1]++;
    printf("%d\n",joltdiff[0] * joltdiff[2]);
    return 0;
}
