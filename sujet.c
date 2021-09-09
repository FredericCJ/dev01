#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRENOM_MAXLEN 100
#define PRENOMS_MAXLEN 1000
#define NOTE_MAXLEN 10
#define NOTES_MAXLEN 100

float min(float *);
float max(float *);
float moyenne(float *);

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
            while((notes[i]<0 || notes[i]>20) || notes[i] == '\0'){
                printf("Saisir note : ");
                fgets(note,NOTE_MAXLEN,stdin);
                sscanf(note,"%f",(notes+i));
            }
        }
        i++;
    }
    printf("min : %.2f\nmax : %.2f\nmoyenne : %.2f\n",min(notes),max(notes),moyenne(notes));
    return EXIT_SUCCESS;
}

float min(float *notes){
    int i = 0;
    float max = 22;
    while(*(notes+i) != '\0'){
        if(*(notes+i) <= max){
            max = *(notes+i);
        }
        i++;
    }
    return max;
}

float max(float *notes){
    int i = 0;
    float min = 0;
    while(*(notes+i) != '\0'){
        if(*(notes+i) >= min){
            min = *(notes+i);
        }
        i++;
    }
    return min;
}

float moyenne(float *notes){
    int i = 0;
    float moyenne = 0.0;
    while(*(notes+i) != '\0'){
        moyenne = *(notes+i)+moyenne;
        i++;
    }
    moyenne = moyenne/(float)i;
    return moyenne;
}