#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sujet.h"

int main(int argc, char *argv[]){
    int i = 0;
    char prenom[PRENOM_MAXLEN];
    char best[PRENOM_MAXLEN];
    char worst[PRENOM_MAXLEN];
    //char prenoms[PRENOMS_MAXLEN];
    float notes[NOTES_MAXLEN];
    char note[NOTE_MAXLEN];
    float mini;
    float maxi;
    
    for(int j=0; j<NOTES_MAXLEN; j++)
        notes[j] = '\0';
    /*for(int j=0; j<PRENOMS_MAXLEN; j++)
        prenoms[j] = '\0';*/
    for(int j=0; j<NOTE_MAXLEN; j++)
        note[j] = '\0';
    for(int j=0; j<PRENOM_MAXLEN; j++){
        prenom[j] = '\0';
        best[j] = '\0';
        worst[j] = '\0';
    }

    while(strcmp(prenom,"X AE A-XII\n") != 0){
        printf("Saisir prenom : ");
        fgets(prenom,100,stdin);
        //strcat(prenoms,prenom);
        mini = min(notes,NOTE_MAX);
        maxi = max(notes, NOTE_MAX);
        if(strcmp(prenom,"X AE A-XII\n")){
            while((notes[i]<NOTE_MIN || notes[i]>NOTE_MAX) || notes[i] == '\0'){
                printf("Saisir note : ");
                fgets(note,NOTE_MAXLEN,stdin);
                sscanf(note,"%f",(notes+i));
            }
        }
        if(notes[i] < mini)
            strcpy(worst,prenom);
        if(notes[i] > maxi)
            strcpy(best, prenom);
        i++;
    }
    printf("min : %s\t %.2f\nmax : %s\t %.2f\nmoyenne : %.2f\n",
        worst,
        min(notes, NOTE_MAX),
        best,
        max(notes, NOTE_MIN),
        moyenne(notes));

    return EXIT_SUCCESS;
}
