#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int *);
int max(int *); 

int main(int argc, char *argv[]){
    int i = 0;
    int notes[13] = {0};
    
    for(int j=0; j<13; j++){
        notes[j] = 21;
    }
    
    char prenom[13];
    
    while(strcmp(prenom,"X AE A-XII\n")){
        printf("Saisir prenom : ");
        fgets(prenom,sizeof(prenom),stdin);
        while(notes[i]<0 || notes[i]>20){
            printf("Saisir note : ");
            scanf("%d",&notes[i]);
        }
        i++;
        printf("%s\n",prenom);
    }
    printf("%d\n%d\n",min(notes),max(notes));
    return EXIT_SUCCESS;
}

int min(int *notes){
    int i = 0;
    int max = 22;
    while(*(notes+i) != '\0'){
        if(*(notes+i) <= max){
            max = *(notes+i);
        }
        i++;
    }
    return max;
}

int max(int *notes){
    int i = 0;
    int min = 0;
    while(notes[i] != '\0'){
        if(notes[i] >= min){
            notes[i] = min;
        }
    }
    return min;
}