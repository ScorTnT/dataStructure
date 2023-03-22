#include <stdio.h>

int findNum(int data[]);
int main(){
    int data[10]={0};
    int i=0;
    while(i<10){
        printf("%d order of input data:",i+1);
        scanf("%d",&data[i]);
        i++;
    }
    printf("data in array :");
    for(int k = 0 ; k<10 ; k++)
    printf("%d ",data[k]);
    findNum(data);
    return 0;
}
int findNum(int data[]){
    int a=1;
    printf("\nWhat number do you want to know the order of? :");
    scanf("%d",&a);
    if(a==0){
        printf("shutdown program.");
        return 0;
    }
    else{
        int tmp=0;
        for(tmp; tmp<10 ; tmp++){
            if(data[tmp]==a){
                printf("The order of %d is %d.",a,tmp+1);
                break;
            }
        }
            if(tmp==10)
            printf("No exist!!!");
        return findNum(data);
    }
}