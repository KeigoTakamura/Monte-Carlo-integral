#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include<vector>
#include<cmath>
#include<random>
#include<vector>
#define N 100
#define NN (int)10E+8


double function(double x);
int main(){
    
    std::random_device rn;
    std::mt19937 st_ran(rn());
    std::uniform_real_distribution<> rand_pi(0.0,M_PI);
    //std::vector<double>  ans_array(NN,0.0);
    double a=0,b=M_PI,x,sum=0.0,ans=0.0;
    int i;
    //FILE *FP[10];
    int  count_pi=0 , count_size = N;


  for(count_pi=0; count_pi < 8 ;count_pi++ ){
    #pragma omp parallel for reduction(+:sum) 
    for( i=0; i < count_size;i++){
          sum+=function(rand_pi(st_ran));//乱数を積分する関数に代入
    }
    ans= M_PI*sum/(double)count_size;
    printf("%5.20g %d \n",ans,count_size);

    count_size*=100;
    sum=0.0;
    ans=0.0;
  }
    return 0;
}


double function(double x){
  return sin(x);
}
