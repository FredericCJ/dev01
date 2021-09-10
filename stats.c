#include "sujet.h"

float min(float *notes, float max){
    int i = 0;
    if(*notes == 0xa)
        return 1e37;
    while(*(notes+i) != '\0'){
        if(*(notes+i) <= max){
            max = *(notes+i);
        }
        i++;
    }
    return max;
}

float max(float *notes, float min){
    if(*notes == 0xa)
        return -1e37;
    int i = 0;
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
