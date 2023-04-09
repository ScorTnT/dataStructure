// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #define maxStu 40
// #define stuCount 20

// int main(){
//     printf("총 학생수를 정확히 입력해주세요\n");
//     printf("학생수 : %d\n",stuCount);                  // 학생수를 20명이라고 가정했습니다.
//     if (stuCount > maxStu) {
//         printf("학생 수 설정이 잘못되었습니다.");
//         return 0;
//     }

//     typedef struct StudentInfo{
//         char code[10];
//         char name[10];
//         int midExam;
//         int finalExam;
//     }Stu;
//     Stu *classP;
//     classP = (Stu *)malloc(sizeof(Stu)*stuCount);
    
//     char buffer[2000], *token;
//     FILE* fp = fopen("student.txt", "r");
//     if (fp==NULL){
//         printf("file read error.");
//         return 0;
//     }
//     int i=0;
//     int tmp=0;
//     while(!feof(fp)){
//         i=0;
//         fgets(buffer, 2000, fp);
//         token = strtok(buffer, "+");
//         while(token != NULL){
//             if(i==0){
//                 strcpy(classP[tmp].code, token);
//             }else if(i==1){
//                 strcpy(classP[tmp].name, token);
//             }else if(i==2){
//                 classP[tmp].midExam = atoi(token);
//             }else if(i==3){
//                 classP[tmp].finalExam = atoi(token);
//             }
//             i++;
//             token = strtok(NULL, "+");
//         }
//         tmp++;
//     }
//     fclose(fp);
    
//     printf("|---학번---||--이름--||중간점수||기말점수||한학기 평균|\n");
//     float averageStu[stuCount] = {0};
//     for(int k = 0; k < stuCount; k++){
//         averageStu[k] = ( (float)classP[k].midExam + classP[k].finalExam ) / 2 ;
//         printf("|%10s||%8s||%8d||%8d||%11.1f|\n",classP[k].code, classP[k].name, classP[k].midExam, classP[k].finalExam,averageStu[k]);
//     }

//     float wholeAveStu = 0;
//     float wholeStandDev = 0;

//     for(int k=0; k<stuCount; k++)
//     wholeAveStu += averageStu[k];
    
//     wholeAveStu = wholeAveStu / stuCount ;

//     for(int k=0; k<stuCount; k++)
//     wholeStandDev = wholeStandDev + (pow(((float)averageStu[k]-wholeAveStu),2.0));

//     wholeStandDev = sqrt(wholeStandDev / stuCount) ; 

//     printf("전체 평균은 : %0.2f , 표준편차는 : %0.2f", wholeAveStu, wholeStandDev);
//     free(classP);
//     return 0;
// }