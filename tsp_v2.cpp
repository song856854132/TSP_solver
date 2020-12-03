#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <limits.h>

double min = INT_MAX;

double getDis(int current, double dis, double**a, bool*visited,int visited_num, int*returnpath ,int*shortpath,int n){

    int *bestpath;
    if(dis>min)
        return 0;
    if(visited_num == n){
        returnpath[visited_num] = 0;
        if(dis+a[current][0] < min){
            for(int i=0;i<=n;i++){
                shortpath[i]=returnpath[i];
            }
            min = dis+a[current][0];
        }
    }
    
    for(int i=0;i<n;i++){
        if(visited[i])
            continue;
        visited[i]=true;
        returnpath[visited_num] = i;
        getDis(i, dis+ a[current][i], a, visited, 
		visited_num+1, returnpath, shortpath, n);

        visited[i]=false;
    }
    
}

int main(){
    int n;
    double **a;
    double **pos;
    bool *visited;
    int current, visited_num;
    int *path,*shortpath;
    //scanf("%d", &n);
    n=11;
    a = (double**)malloc(sizeof(double*) * n);
    pos = (double**)malloc(sizeof(double*) * n);
    visited = (bool*)malloc(sizeof(bool)*n);
    path = (int*)malloc(sizeof(int)*(n+1));
    shortpath =(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++){
        a[i]=(double*)malloc(sizeof(double)*n);
        pos[i] = (double*)malloc(sizeof(double) * 2);
        visited[i] = false;
    }
    
    for(int i=0;i<n;i++){
        int city;
        scanf("%d", &city);
        scanf("%lf%lf", pos[city-1]+0, pos[city-1]+1);
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j)
                a[i][j] = INT_MAX;
            else
                a[j][i] = a[i][j] = sqrt(pow(pos[i][0]-pos[j][0],2) 
                        + pow(pos[i][1]-pos[j][1],2));
        }
    }
    
    current = 0;
    visited_num=1;
    visited[0] = true;
    path[0]=0;
    getDis(current, 0, a, visited, visited_num, path,shortpath,n);
    printf("Dis = %lf, path = ",min);
    for(int i=0;i<=n;i++){
        printf("%d ",shortpath[i]+1);
    }
    
} 
