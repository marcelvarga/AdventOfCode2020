#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int preamble = 25;
const int InvalidNumber = 85848519;

typedef struct pair{
    int small,big;
}pair;

bool check(long long values[1001], int n){
    if (n <= preamble) return 1;
    for (int i = n - preamble - 1; i <= n-3; i++)
        for(int j = i+1; j <= n - 2; j++)
            if(values[i] + values[j] == values[n-1]) return 1;
    return 0;
}
void solve(){
    long long *values = malloc(1001 * sizeof(long long));
    int n = 0;
    char s[50];
    FILE *in = fopen("in.in", "r");
    fgets(s, 50, in);
    while (! feof(in)){
        sscanf(s, "%lld", values+n);
        n++;
        fgets(s, 50, in);
    }
    for (int i = 0; i < n-1; i++)
        {   
            int ANS = values[i];
            pair pair = {values[i],values[i]};
            for(int j = i + 1; j < n; j++){
                ANS +=  values[j];
                if(pair.big < values[j]) pair.big = values[j];
                if(pair.small > values[j]) pair.small = values[j];
                if(ANS == InvalidNumber){
                    printf("%d\n",pair.small + pair.big);
                    i = n;
                    j = n;
                }
                if(ANS > InvalidNumber)
                    j = n;
                
            } 
        }

    free(values);
    fclose(in);
}
int main(){
    solve();
    return 0;
}
