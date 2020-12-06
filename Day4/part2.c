#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

const char key[8][4] = {"byr","iyr","eyr","hgt","hcl","ecl","pid","cid"};
const int max = 200;

bool check(char *c, int i){
    if (i == 0) return (strcmp(c,"1920") >= 0 && (strcmp(c,"2002") <= 0));
    if (i == 1) return (strcmp(c,"2010") >= 0 && (strcmp(c,"2020") <= 0));
    if (i == 2) return (strcmp(c,"2020") >= 0 && (strcmp(c,"2030") <= 0));
    if (i == 3){
        int n = strlen(c);
        int x = 0;
        int i = 0;
        while(i < n && c[i] >= '0' && c[i] <= '9'){
            x *= 10;
            x += c[i] - '0';
            i++;
        }
        if (i+1 < n){
            if ((c[i] == 'c' && c[i+1] == 'm') && (x >= 150 && x <= 193)) return 1;
            if ((c[i] == 'i' && c[i+1] == 'n') && (x >= 59 && x <= 76)) return 1;
        }
        return 0;
    }
    
    if (i == 4){
        if (c[0] != '#') return 0;
        int n = strlen(c);
        if (n != 7) return 0;
        for (int i = 1; i < n; i++) if(!(c[i] >= '0' && c[i] <= '9') && !(c[i] >= 'a' && c[i] <= 'f')) return 0;
        return 1;
    }
    if (i == 5) return (!strcmp(c,"amb") || !strcmp(c,"blu") 
                     || !strcmp(c,"brn") || !strcmp(c,"gry") 
                     || !strcmp(c,"grn") || !strcmp(c,"hzl") 
                     || !strcmp(c,"oth"));
    if (i == 6){
        int n = strlen(c);
        if (n != 9) return 0;
        for (int i = 0; i < n; i++) if(c[i] > '9' || c[i] <'0') return 0;
        return 1;
    }
    if (i == 7) return 1;
    return 0;
}
bool validate(char *c, int i){
    char p[50];
    int n = strlen(c);
    int j =0;
    while(j < n && c[j] != '\n' && c[j] != ' '){
        p[j] = c[j];
        j++;
    }
    p[j] = '\0';
    return check(p,i);
}

bool newperson(FILE *in){
    char s[max];
    bool present[8] = {0,0,0,0,0,0,0,0};
    fgets(s,200,in);
    while (strcmp(s,"\n") && !feof(in)){
        for (int i = 0; i < 8; i++){
            char *p = strstr(s,key[i]);
            if(p && validate(p+4, i)) present[i] = 1;
            
        }
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
void testcheck(){
    assert(check("1920",0) == 1);
    assert(check("2002",0) == 1);
    assert(check("2003",0) == 0);
    assert(check("2010",1) == 1);
    assert(check("2020",1) == 1);
    assert(check("2050",1) == 0);
    assert(check("150cm",3) == 1);
    assert(check("193cm",3) == 1);
    assert(check("194cm",3) == 0);
    assert(check("59in",3) == 1);
    assert(check("76in",3) == 1);
    assert(check("58in",3) == 0);
    assert(check("#602927",4) == 1);
    assert(check("#60297",4) == 0);
    assert(check("#6029227",4) == 0);
    assert(check("amb",5) == 1);
    assert(check("#602e27",5) == 0);
    assert(check("000000001",6) == 1);
    assert(check("0123456789",6) == 0);
    printf("All tests pass!\n");
}
int main(){
    int ANS = solve();
    printf("%d\n", ANS);
    testcheck();
    return 0;
}
