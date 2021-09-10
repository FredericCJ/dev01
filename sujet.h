#ifndef SUJET_H
#define SUJET_H

#define PRENOM_MAXLEN 100
#define NOTE_MAXLEN 100
#define NOTES_MAXLEN 100
#define NOTE_MAX 20.0
#define NOTE_MIN 0.0
#define PRENOM_STOP "X AE A-XII"

float min(float *, float);
float max(float *, float);
float moyenne(float *);
int findlf(char *);

#endif