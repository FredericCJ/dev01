#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sujet.h"

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
        notes[j] = '\0';
    for(int j=0; j<NOTE_MAXLEN; j++)
        note[j] = '\0';
    for(int j=0; j<PRENOM_MAXLEN; j++){
        prenom[j] = '\0';
        best[j] = '\0';
        worst[j] = '\0';
    }

    while(strcmp(prenom,PRENOM_STOP)){
        printf("Saisir prenom : ");
        fgets(prenom,100,stdin);
        if(feof(stdin))
            break;
        prenom[findlf(prenom)] = '\0';
        
        if(strcmp(prenom,PRENOM_STOP)){                                             
            while((notes[i]<NOTE_MIN || notes[i]>NOTE_MAX) || notes[i] == '\0'){
                printf("Saisir note : ");
                fgets(note,NOTE_MAXLEN,stdin);
                if(feof(stdin))
                    break;
                sscanf(note,"%f",(notes+i));
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
    system("clear");

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