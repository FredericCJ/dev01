#include <stdio.h>
#include <stdlib.h>

char min(char *);
char max(char *); 

int main(int argc, char *argv[]){
    int i = 0;
    char notes[13] = {0};
    
    for(unsigned char j=0; j<13; j++){
        notes[j] = (char)21;
    }
    
    char prenom[10];
    char cas_terminant[10] = "X AE A-XII";
    
    while(prenom != cas_terminant){
        printf("Saisir prenom : ");
        scanf("%s",prenom);
        while(notes[i]<0 || notes[i]>20){
            printf("Saisir note : ");
            scanf("%c",&notes[i]);
        }
        i++;
        printf("%s\n",prenom);
        printf("%d\n%d\n",min(notes),max(notes));
    }
    return EXIT_SUCCESS;
}

char min(char *notes){
    char i = 0;
    char max = 20;
    while(*(notes+i) != '\0'){
        if(*(notes+i) <= max){
            *(notes+i) = max;
        }
    }
    return max;
}

char max(char *notes){
    char i = 0;
    char min = 0;
    while(*(notes+i) != '\0'){
        if(*(notes+i) >= min){
            *(notes+i) = min;
        }
    }
    return min;
}