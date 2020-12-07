#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const int linemax = 300;
typedef struct bag{
    char Name[30];
    struct bag *ContainedBags[20];
    long long Quantity[20];
    int ContainedBagsNo;
}bag;

//gets bag name out of line string
void GetBag(char line[linemax], char newbag[50]){
    int i = 0, len = strlen(line), spaces=0;
    while (i < len && spaces < 2){
        if (line[i] == ' ') spaces++;
        if (spaces < 2) newbag[i] = line[i];
        i++;
    }
    newbag[i-1] = '\0';
}
void GetContainedBags(char *s, int index, bag *currentbag, bag bags[1000], int *n){
    s += strlen("contain ");
    if (s[0] != 'n')
    do{
        if (s[0] == ',') s += 2;
        int value = s[0] - '0';

        int i = 0, len = strlen(s), spaces=0;
        char newbag[50];
        s += 2;
        while (i < len && spaces < 2){
            if (s[i] == ' ') spaces++;
            if (spaces < 2) newbag[i] = s[i];
            i++;
        }
        newbag[i-1] = '\0';

        bool found = 0;
        for (int i = 0; i < *n && !found; i++)
            if (!strcmp(bags[i].Name,newbag)){
                found = 1;
                bags[index].ContainedBags[bags[index].ContainedBagsNo] = &bags[i];
                bags[index].Quantity[bags[index].ContainedBagsNo] = value;
                bags[index].ContainedBagsNo++;
            }
    
        if (!found){
        *n = *n +1;
        strcpy(bags[*n-1].Name, newbag);
        bags[*n-1].ContainedBagsNo = 0;
        
        bags[index].ContainedBags[bags[index].ContainedBagsNo] = &bags[*n-1];    
        bags[index].Quantity[bags[index].ContainedBagsNo] = value;
        bags[index].ContainedBagsNo++;

        }
        
        s = strchr(s+1,',');
    }while(s);
}

//reads lines and manipulates data
int read(FILE *in, bag bags[1000]){
    char line[linemax];
    int n = 0;
    fgets(line,linemax,in);

    while(! feof(in)){
    char newbag[50];

    GetBag(line, newbag);

    bool found = 0;
    bag *currentbag = NULL;
    int index = -1;
    for (int i = 0; i < n && !found; i++)
        if (!strcmp(bags[i].Name,newbag)){
            found = 1;
            currentbag = &bags[i];
            index = i;
        }
    
    if (!found){
        n++;
        currentbag = &bags[n-1];
        index = n-1;
    }

    strcpy(currentbag->Name, newbag);
    currentbag->ContainedBagsNo = 0;

    char *p = strstr(line,"contain");
    GetContainedBags(p, index, currentbag, bags, &n);

    fgets(line,linemax,in);
    }
    fclose(in);
    return n;

}
int DFS(bag *CurrentBag){
    int ANS = 0;

    for (int i = 0; i < CurrentBag -> ContainedBagsNo; i++)
        ANS += CurrentBag -> Quantity[i] * DFS(CurrentBag -> ContainedBags[i]);
    return ANS + 1;
}

int main(){
    FILE *in = fopen("in.in", "r");
    bag bags[1000];
    int n = read(in, bags);

    int ShinyGoldIndex = -1;
    for (int i = 0; i < n; i++){
       if (!strcmp(bags[i].Name,"shiny gold")){
           ShinyGoldIndex = i;
           i = n;
       }
    }

    int ANS = 0;
    ANS = DFS(&bags[ShinyGoldIndex]);
    printf("%d\n",ANS - 1);

    return 0;
}
