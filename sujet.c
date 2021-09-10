#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sujet.h"

int main(int argc, char *argv[]){
    int i = 0;
    char prenom[PRENOM_MAXLEN];
    char prenoms[PRENOMS_MAXLEN];
    float notes[NOTES_MAXLEN];
    char note[NOTE_MAXLEN];
    
    for(int j=0; j<NOTES_MAXLEN; j++)
        notes[j] = '\0';
    for(int j=0; j<PRENOM_MAXLEN; j++)
        prenom[j] = '\0';
    for(int j=0; j<PRENOMS_MAXLEN; j++)
        prenoms[j] = '\0';
    for(int j=0; j<NOTE_MAXLEN; j++)
        note[j] = '\0';

    while(strcmp(prenom,"X AE A-XII\n") != 0){
        printf("Saisir prenom : ");
        fgets(prenom,100,stdin);
        strcat(prenoms,prenom);
        if(strcmp(prenom,"X AE A-XII\n")){
            while((notes[i]<NOTE_MIN || notes[i]>NOTE_MAX) || notes[i] == '\0'){
                printf("Saisir note : ");
                fgets(note,NOTE_MAXLEN,stdin);
                sscanf(note,"%f",(notes+i));
            }
        }
        i++;
    }
    printf("min : %.2f\nmax : %.2f\nmoyenne : %.2f\n",
        min(notes, NOTE_MAX),max(notes, NOTE_MIN),moyenne(notes));
    return EXIT_SUCCESS;
}
