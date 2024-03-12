#include<stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>



struct Matrix{
    int row,column;
    double *array;
};

struct Matrix Create_Matrix(int row,int column){
    struct Matrix res;
    res.row=row,res.column=column;
    res.array=(double*)malloc(row*column*sizeof(double));
    memset(res.array,0,row*column*sizeof(double));
    return res;
}

void Transpose(struct Matrix* a){
    int temp[(a->row)*(a->column)];
    for(int i=0;i<a->row;i++){
        for(int j=0;j<a->column;j++)
            temp[i*(a->row)+j]=a->array[i*(a->row)+j];
    }
    for(int i=0;i<a->row;i++){
        for(int j=0;j<a->column;j++)
            a->array[j*(a->column)+i]=temp[i*(a->row)+j];
    }
    for(int i=0;i<a->row;i++){
        for(int j=0;j<a->column;j++)
            printf("%g ",a->array[i*a->row+j]);
        printf("\n");
    }
    printf("\n");
}


void Add(struct Matrix a,struct Matrix b){
    struct Matrix res=Create_Matrix(a.row,b.column);
    for(int i=0;i<(a.row)*(a.column);i++)
        res.array[i]=a.array[i]+b.array[i];
    for(int i=0;i<res.row;i++){
        for(int j=0;j<res.column;j++)
            printf("%g ",res.array[i*res.row+j]);
        printf("\n");
    }
    printf("\n");
}

void Multiply(struct Matrix a,struct Matrix b){
    struct Matrix res=Create_Matrix(a.row,b.column);
    for(int i=0;i<a.row;i++)
        for(int j=0;j<b.column;j++)
            for(int k=0;k<b.row;k++)
                res.array[i*(a.row)+j] += a.array[i*(a.row)+k] * b.array[k*(b.row)+j];
    for(int i=0;i<res.row;i++){
        for(int j=0;j<res.column;j++)
            printf("%g ",res.array[i*res.row+j]);
        printf("\n");
    }
    printf("\n");
}


int main(){
    srand(time(NULL));
    int m1,n1,m2,n2;
    printf("陣列的列和行=(方陣)");
    scanf("%d",&m1);
    n1=m1;
    m2=m1;
    n2=m1;

    struct Matrix a=Create_Matrix(m1,n1);
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++)
            a.array[i*a.row+j]=rand()%11;
    }

    struct Matrix b=Create_Matrix(m2,n2);
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++)
            b.array[i*b.row+j]=rand()%11;
    }
    printf("\n\n");
    printf("陣列1:\n");
    Transpose(&a);
    printf("陣列2:\n");
    Transpose(&b);
    printf("陣列相加:\n");
    Add(a,b);
    printf("陣列相乘:\n");
    Multiply(a,b);
}