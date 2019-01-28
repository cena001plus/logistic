​
/*************************************************************************
	> File Name: logistic.c
	> Author: 
	> Mail: 
	> Created Time: 
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include"logistic.h"


float sigmoid(float fPara)
{
    fPara= 0-fPara;
    return 1.0/(1+pow(2.7182818, fPara));
}

void gradAscent(int M, int N, float fDataSet[24][4], float *pWeights)
{
    
    float alpha =0.001;
    int maxCycles =1500;
    int count=0;
    int num=0;
    int n=0;
    float sum[M];
    float fPrediction[M];
    float error[M];
    float temp[N];

    for(num=0;num<M;num++)
    {
        sum[num] =0;
        fPrediction[num] =0;
        error[num] =0;
    }

    for(n=0;n<N;n++)
    {
        temp[n] =0;
    }

    for(count=0; count<maxCycles; count++)
    {
        for(num=0;num<M;num++)
        {
            for(n=0;n<N;n++)
            {
                sum[num] += fDataSet[num][n]*(*(pWeights+n));
            }
            fPrediction[num] = sigmoid(sum[num]);
            //error[num] = fPrediction[num] - fDataSet[num][3];
            error[num] = fDataSet[num][3] - fPrediction[num] ;
            printf("error[%d]=%f\n",num,error[num]);
        }

        for(n=0;n<N;n++)
        {
            for(num=0;num<M;num++)
            {
                temp[n] += fDataSet[num][n]*error[num];
            }

            temp[n] =temp[n]/M;
        }
    
        printf("count=%d\n",count);
        for(n=0;n<N;n++)
        {
            *(pWeights+n)= *(pWeights+n) - alpha*temp[n];
            printf("pweights[%d]=%f\n",n,*(pWeights+n));
        }
    }
}

​