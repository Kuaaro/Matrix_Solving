#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double *list;
    int m, n;
}matrix;

matrix *make_matrix(FILE *in){

    int i;
    matrix *exit = malloc(sizeof(*exit));

    if(fscanf(in, "%d %d", &(exit->m), &(exit->n))!=2){
        free(exit);
        return NULL;
    }

    if((exit->list=malloc(exit->m * exit->n * sizeof(double)))==NULL){
        free(exit);
        free(exit->list);
        return NULL;
    }

    if((exit->solutions=malloc(exit->n * sizeof(double)))==NULL){
        free(exit);
        free(exit->solutions);
        free(exit->list);
        return NULL;
    }

    for(i=0; i<exit->m * exit->n; i++)
        if(fscanf(in, "%lf", &exit->list[i])!=1){
            free(exit);
            free(exit->solutions);
            free(exit->list);
            return NULL;
        }

    for(i=0; i<exit->n; i++)
        if(fscanf(in, "%lf", &exit->solutions[i])!=1){
            free(exit);
            free(exit->list);
            free(exit->solutions);
            return NULL;
        }

    return exit;
}

void free_matr(matrix *in){
    free(in->list);
    free(in->solutions);
    free(in);
}
