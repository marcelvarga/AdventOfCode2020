#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count(char c, char *s){
    int n = 0;
    char *p = strchr(s,c);
    while(p != NULL){
        p++;
        n++;
        p = strchr(p,c);
    }
    return n;
}
void getnumbers(int *a, int *b, char *c){
    int i = 0;
    while (c[i] != '-') i++;
    for(int j = 0; j < i; j++){
        *a *= 10;
        *a += c[j]-'0';
    }
    int n = strlen(c);
    for(int j = i+1; j < n; j++){
        *b *= 10;
        *b += c[j]-'0';
    }
}

int solve(FILE *in){
    int n = 0;
    char s[100];
    char numbers[50],letter[4],str[50];
    int a=0,b=0;
    fgets(s,100,in);
    while(! feof(in)){
        sscanf(s, "%s %s %s", numbers, letter, str);
        a=0;b=0;
        getnumbers(&a,&b,numbers);
        int x = count(letter[0],str);
        if(x >= a && x <= b) n++;
        fgets(s,100,in);
    }
    fclose(in);
    return n;
}
int main(){
    int ANS = 0;
    FILE *in = fopen("in.in", "r");
    ANS = solve(in);
    printf("%d\n",ANS);
    return 0;

}
