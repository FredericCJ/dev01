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
