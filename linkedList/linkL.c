// #include <stdio.h>
// #include <stdlib.h>

// typedef struct set {
//     int element;
//     struct set* nextptr;
// }set;
// typedef struct sets {
//     int index;
//     set* SetHead;
//     struct sets* nextptr;
// }sets;
// sets *MAINsetsHead;                  //warn to make fuction for MAINsetsHead add change.
// int setCnt = 0, indexCnt = 1;
// void delallel(set * SETHEADALL);
// void letSet();                   //let Set.
// void delSet();                   //delete Set.
// void prtSets();                 //print setlist.
// int emptyset(set * w);          //if Set is empty return 0, else return 1.
// int main() {
//     letSet();
//     prtSets();
//     letSet();
//     prtSets();
//     delSet();
//     prtSets();
//     return 0;
// }
// void prtSets(){
//     sets *r=MAINsetsHead;
//     while(r->SetHead!=NULL){
//         printf("%3d", r->index);
//         r=r->nextptr;
//     }
// }
// void letSet() {
//     sets *r, *p, *newsets=(sets*)malloc(sizeof(sets));
//     set *newset=(set*)malloc(sizeof(set));
//     newset->nextptr=NULL;
//     newset->element = 0;
//     newsets->index=indexCnt;
//     indexCnt++;
//     setCnt++;
//     newsets->SetHead=newset;
//     r=p=MAINsetsHead;
//     for (int k = 1; k < setCnt; k++) {
//         r = MAINsetsHead;
//         MAINsetsHead->nextptr;
//     }
//     newsets->nextptr = MAINsetsHead;
//     r->nextptr = newsets;
//     MAINsetsHead = p;
// }
// void delallel(set *SETHEADALL) {
//     set* delel,*HEAD;
//     HEAD = SETHEADALL;
//     while (emptyset(HEAD) != 0) {
//         delel = HEAD;
//         HEAD = HEAD->nextptr;
//         free(delel);
//     }
//     free(HEAD);
// }
// void delSet() {
//     int ind=99;
//     scanf("%d",&ind);
//     sets* p=MAINsetsHead->nextptr,*r=MAINsetsHead, *HEADSETS=MAINsetsHead;
//     set *setH,*delel;
//     if (MAINsetsHead->index == ind) {
//         MAINsetsHead = MAINsetsHead->nextptr;
//         setH = r->SetHead;
//         delallel(setH);
//     }
//     else {
//         while (p->index != ind) {
//             p = p->nextptr;
//             r = r->nextptr;
//         }
//         r->nextptr = p->nextptr;
//         setH = p->SetHead;
//         delallel(setH);
//     }
// }
// int emptyset(set *w) {
//     if (w->nextptr == NULL) return 0;
//     else return 1;
// }