#include <stdio.h>
#include <string.h>

int solve(FILE *in){
    char s[50];
    int ANS = 0;
    fgets(s,50,in);
    int n = strlen(s) - 1;
    int row = 0;

    while(! feof(in)){
        if (s[row] == '#') ANS++;
        row += 3;
        row %= n;
        fgets(s,50,in);
    }
    return ANS;
}
int main(){
    FILE *in = fopen("in.in", "r");
    int ANS = solve(in);
    printf("%d\n",ANS);
    return 0;
}
