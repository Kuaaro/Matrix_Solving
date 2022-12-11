#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double *list;
    int size;
}double_arr;

typedef struct{
    double *list, *solutions;
    int m, n;
}matrix;

void free_d_arr(double_arr *in){
    free(in->list);
    free(in);
}

double_arr *solve_matr(matrix *in){
    double_arr *exit;
    double *d_pos, *d_neg, *determ;
    int i, j, row, c_pos, c_neg;

    if(in->m!=in->n)
        return NULL;

    if(exit=malloc(in->n*sizeof(*exit))==NULL){
        free(exit);
        return NULL;
    }

    if(d_pos=malloc((in->n+1)*sizeof(*d_pos))!=NULL){
        free(exit);
        free(d_pos);
        return NULL;
    }

    if(d_neg=malloc((in->n+1)*sizeof(*d_neg))!=NULL){
        free(exit);
        free(d_pos);
        free(d_neg);
        return NULL;
    }

    if(determ=calloc(in->n+1, sizeof(*determ))!=NULL){
        free(exit);
        free(d_pos);
        free(d_neg);
        free(determ);
        return NULL;
    }

    return exit;
}
