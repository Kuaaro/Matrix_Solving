#include <stdio.h>
#include <stdlib.h>

#include "mat_io.h"

typedef struct{
    double *list;
    int size;
}double_arr;

void free_d_arr(double_arr *in){
    free(in->list);
    free(in);
}

double_arr *solve_matr(matrix *in){
    double_arr *exit;
    double *d_pos, *d_neg;
    int i, j, n, row, c_pos, c_neg;

    if(in->m!=in->n)
        return NULL;

    if(exit=malloc(sizeof(*exit))==NULL){
        free(exit);
        return NULL;
    }
    exit.size = n+1;
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

    if(exit->list=calloc((in->n+1)*sizeof(*(exit->list)))==NULL){
        free(exit->list);
        free(exit);
        free(d_pos);
        free(d_neg);
        return NULL;
    }

    exit->size = in->n+1;

    for(i=0; i<=in->m; i++){
        d_neg[i]=1;
        d_pos[i]=1;
    }

    for(j=0; j<in->m; j++){
        for(i=0; i<in->m; i++){

            row = i*in->m;

            c_pos = (j+i)%in->m;
            c_neg = (j-i+in->m)%in->m;

            for(n=0; n<=in->m; n++){
                if(c_pos==n)
                    d_pos[n] *= in->solutions[i];
                else
                    d_pos[n] *= in->list[row+c_pos];

                if(c_neg==n)
                    d_pos[n] *= in->solutions[i];
                else
                    d_pos[n] *= in->list[row+c_neg];
            }

        }
        for(n=0; n<=in->m; n++){
            exit->list[n]+=d_pos[n]-d_neg[n];
            d_pos[n]=1;
            d_neg[n]=1;
        }
    }

    free(d_pos);
    free(d_neg);
    return exit;
}
