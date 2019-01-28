​
/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include"logistic.h"
#define M 24
#define N 3


void main()
{    
  
    float TrainingData[24][4]={{1,5,0.7,1},{1,4,0.5,1},{1,3,1,1},{1,5.6,0.9,1},\
                        {1,3,1,1},{1,4.5,1.2,1},{1,3.5,1.1,1},{1,5.8,1.5,1},\
                        {1,2,1.55,1},{1,4,1.7,1},{1,5,1.6,1},{1,5.8,1.5,1},\
                        {1,6.1,0.8,1},{1,7,0.8,1},{1,8,0.9,1},{1,7.5,0.9,1},\
                        {1,6.5,1.2,0},{1,7,1.3,0},{1,7.5,1.4,0},{1,8,1.5,0},\
                        {1,7.5,2.2,0},{1,7,1.6,0},{1,6,2,0},{1,8,2.5,0}};

    float TestingData[8][3]={{1,5,0.5},{1,6,2.1},{1,4.5,1},{1,7.5,1.5},\
                       {1,4,1},{1,6.5,1.8},{1,5,0.8},{1,7,1.9}};
   

    float fPrediction[8]={0};
    float weights[3]={1,1,1};
    float *pWeights;
    pWeights= weights;
    int i,j;
    float temp[8]={0};
  
    //calc weights
    gradAscent(M,N,TrainingData, pWeights);
    for(i=0;i<3;i++)
    {
        printf("weights[%d]=%f\n",i,weights[i]);
    }
    
    //test
    for(i=0;i<8;i++)
    {
        for(j=0;j<3;j++)
        {
            temp[i]= TestingData[i][j]*weights[j];
        }
        fPrediction[i]= sigmoid(temp[i]);
    }

    for(i=0;i<8;i++)
    {
        printf("fPrediction[%d]=%f\n",i,fPrediction[i]);
    }
}
​