#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sujet.h"

#define PRENOM_MAXLEN 100
#define NOTE_MAXLEN 100
#define NOTES_MAXLEN 100
#define NOTE_MAX 20.0
#define NOTE_MIN 0.0
#define PRENOM_STOP "X AE A-XII"

int findlf(char *);

int main(){
    int i = 0;
    char prenom[PRENOM_MAXLEN];
    char best[PRENOM_MAXLEN];
    char worst[PRENOM_MAXLEN];
    float notes[NOTES_MAXLEN];
    char note[NOTE_MAXLEN];
    float mini;
    float maxi;
    
    for(int j=0; j<NOTES_MAXLEN; j++)
        notes[j] = -__FLT_MAX__;
    for(int j=0; j<NOTE_MAXLEN; j++)
        note[j] = '\0';
    for(int j=0; j<PRENOM_MAXLEN; j++){
        prenom[j] = '\0';
        best[j] = '\0';
        worst[j] = '\0';
    }

    while(strcmp(prenom,PRENOM_STOP)){
        
        for(int j=0; j<PRENOM_MAXLEN; j++)
            prenom[j] = '\0';

        while(*prenom == '\n' || *prenom == '\0'){
            printf("Saisir prenom : ");
            fgets(prenom,100,stdin);
            if(feof(stdin))
                break;
            printf("%s",prenom);
            prenom[findlf(prenom)] = '\0';
        }

        if(feof(stdin))
            break;
        
        if(strcmp(prenom,PRENOM_STOP)){
            while((notes[i]<NOTE_MIN || notes[i]>NOTE_MAX) || notes[i] == -__FLT_MAX__){
                printf("Saisir note : ");
                fgets(note,NOTE_MAXLEN,stdin);
                if(feof(stdin))
                    break;
                sscanf(note,"%f",(notes+i));
                printf("%s",note);
            }
        }

        mini = min(notes,NOTE_MAX);
        maxi = max(notes, NOTE_MIN);

        if((notes[i] <= mini) && strcmp(prenom,PRENOM_STOP))
            strcpy(worst,prenom);
        if(notes[i] >= maxi)
            strcpy(best, prenom);
        i++;
    }

    printf("\n");

    printf("min : %s = %.2f\nmax : %s = %.2f\nmoyenne : %.2f\n",
        worst,
        min(notes, NOTE_MAX),
        best,
        max(notes, NOTE_MIN),
        moyenne(notes));

    return EXIT_SUCCESS;
}

int findlf(char *str){
    int i = 0;
    while(*(str+i) != '\n'){
        i++;
    }
    return i;
}