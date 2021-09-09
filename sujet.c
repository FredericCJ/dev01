#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float min(float *);
float max(float *);
float moyenne(float *);

int main(int argc, char *argv[]){
    int i = 0;
    char prenom[100];
    char prenoms[1000];
    float notes[13] = {0};
    char note[10];
    
    for(int j=0; j<13; j++)
        notes[j] = '\0';
    for(int j=0; j<100; j++)
        prenom[j] = '\0';
    for(int j=0; j<1000; j++)
        prenoms[j] = '\0';
    for(int j=0; j<10; j++)
        note[j] = '\0';

    while(strcmp(prenom,"X AE A-XII\n") != 0){
        printf("Saisir prenom : ");
        fgets(prenom,100,stdin);
        strcat(prenoms,prenom);
        if(strcmp(prenom,"X AE A-XII\n")){
            while((notes[i]<0 || notes[i]>20) || notes[i] == '\0'){
                printf("Saisir note : ");
                fgets(note,5,stdin);
                sscanf(note,"%f",(notes+i));
            }
        }
        i++;
    }
    printf("%.2f\n",min(notes));
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
/*
float max(float *notes){
    int i = 0;
    int min = 0;
    while(notes[i] != '\0'){
        if(notes[i] >= min){
            min = notes[i];
        }
    }
    return min;
}
*/