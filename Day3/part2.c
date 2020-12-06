#include <stdio.h>
#include <string.h>

long long solve(FILE *in){
    char s[50];
    fgets(s,50,in);
    int n = strlen(s) - 1;
    int row[5] = {0,0,0,0,0}, line = 0;
    long long ANS[5] = {0,0,0,0,0};
    int rowadd[5] = {1,3,5,7,1};

    while(! feof(in)){
        for(int i = 0; i < 5; i++){
            if (s[row[i]] == '#' && i != 4) ANS[i]++;
            if (i == 4 && s[row[i]] == '#' && line % 2 == 0) ANS[i]++;
            if(i != 4 || (i == 4 && line %2 ==0))
            row[i] += rowadd[i];
            row[i] %= n;
        }
        fgets(s,50,in);
        line++;
    }
    return ANS[0] * ANS[1] * ANS[2] * ANS[3] * ANS[4];
}
int main(){
    FILE *in = fopen("in.in", "r");
    long long ANS = solve(in);
    printf("%lld\n",ANS);
    return 0;
}
