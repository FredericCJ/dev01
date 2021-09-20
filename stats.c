float min(float *notes, float max){
    if(*notes == -__FLT_MAX__)
        return __FLT_MAX__;
    int i = 0;
    while(*(notes+i) != -__FLT_MAX__){
        if(*(notes+i) <= max){
            max = *(notes+i);
        }
        i++;
    }
    return max;
}

float max(float *notes, float min){
    if(*notes == -__FLT_MAX__)
        return -__FLT_MAX__;
    int i = 0;
    while(*(notes+i) != -__FLT_MAX__){
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
    while(*(notes+i) != -__FLT_MAX__){
        moyenne = *(notes+i)+moyenne;
        i++;
    }
    moyenne = moyenne/(float)i;
    return moyenne;
}
