#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char key[8][4] = {"byr","iyr","eyr","hgt","hcl","ecl","pid","cid"};
const int max = 200;
bool newperson(FILE *in){
    char s[max];
    bool present[8] = {0,0,0,0,0,0,0,0};
    fgets(s,200,in);
    while (strcmp(s,"\n") && !feof(in)){
        for (int i = 0; i < 8; i++)
            if(strstr(s,key[i])) present[i] = 1;
        fgets(s,200,in);
    }
    bool valid = 1;
    for(int i = 0; i < 7; i++)
        if(!present[i]) valid = 0;
    return valid;
}
int solve(){
    FILE *in = fopen("in.in", "r");

    int ANS = 0;
    while(! feof(in))
    ANS += newperson(in);
    fclose(in);
    return ANS;
}

int main(){
    int ANS = solve();
    printf("%d\n", ANS);
    return 0;
}
