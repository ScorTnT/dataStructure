#include <stdio.h>
#include <string.h>

int main() {
    FILE* traceFile = fopen("memory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 0;
    }
    char buffer[20];
    while(!feof(traceFile)){
        fgets(buffer,20,traceFile);
        printf("%s",buffer);
    }

    fclose(traceFile);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 32
#define BLOCK_SIZE 4
#define ADDRESS_BITS 7

int main() {
    FILE* traceFile = fopen("memory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 0;
    }

    int totalLoads = 0;
    int totalStores = 0;
    int loadHits = 0;
    int loadMisses = 0;
    int storeHits = 0;
    int storeMisses = 0;
    int totalCycles = 0;

    while (!feof(traceFile)) {
        

    }

    fclose(traceFile);

    printf("Total loads: %d\n", totalLoads);
    printf("Total stores: %d\n", totalStores);
    printf("Load hits: %d\n", loadHits);
    printf("Load misses: %d\n", loadMisses);
    printf("Store hits: %d\n", storeHits);
    printf("Store misses: %d\n", storeMisses);
    printf("Total cycles: %d\n", totalCycles);


    return 0;
}
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

int totalLoads = 0;
int totalStores = 0;
int loadHits = 0;
int loadMisses = 0;
int storeHits = 0;
int storeMisses = 0;
int totalCycles = 0;
void cacheS() {

}
char* split(const char* str, int start, int length) {
    int strLength = strlen(str);
    if (start >= strLength || length <= 0) {
        return NULL;
    }
    int end = start + length;
    if (end > strLength) {
        end = strLength;
    }
    char* result = (char *)malloc(length + 1);
    strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}
int main() {
    int flag = 0;
    FILE* traceFile = fopen("memory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 0;
    }
    char buffer[50],oper;
    while (!feof(traceFile)) {
        oper = fgetc(traceFile);
        fgets(buffer, sizeof(buffer), traceFile);
        strtok(buffer, "\n");
        strtok(buffer, " ");
        char* cutStr = split(buffer, 3, strlen(buffer) - 3);
        if (cutStr != NULL) {
            printf("%s|||%c\n", cutStr, oper);
            free(cutStr);
        }
    }
    printf("Total loads: %d\n", totalLoads);
    printf("Total stores: %d\n", totalStores);
    printf("Load hits: %d\n", loadHits);
    printf("Load misses: %d\n", loadMisses);
    printf("Store hits: %d\n", storeHits);
    printf("Store misses: %d\n", storeMisses);
    printf("Total cycles: %d\n", totalCycles);
    fclose(traceFile);
    return 0;
}
//////////////////////////////////////////////////////////////////////