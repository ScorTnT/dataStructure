#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int main() {
    int i = 0, data[MAX] = { 0 };
    FILE* fpR = fopen("data.txt", "r");
    FILE* fpW = fopen("dataOut.txt", "w");
    if (fpR == NULL)printf("read error");
    if (fpW == NULL)printf("write error");
    char buffer[20] = { 0 };
    while (!feof(fpR)) {
        fgets(buffer, MAX, fpR);
        printf("%s", buffer);
        data[i] = atoi(buffer);
        i++;
    }
    fclose(fpR);
    printf("\n");
    int tmp;
    for (int l = 0; l < MAX - 1; l++){
        for (int m = 0; m < MAX - 1 - l; m++){
            if (data[m] > data[m + 1]){
                tmp = data[m];
                data[m] = data[m + 1];
                data[m + 1] = tmp;
            }
        }
    }
    for(int l=0;l<MAX;l++){
        printf("%d ",data[l]);
        sprintf(buffer,"%d",data[l]);
        strcat(buffer, "\n");
        fputs(buffer, fpW);
    }
    fclose(fpW);

    return 0;
}