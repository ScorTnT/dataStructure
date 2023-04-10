#include <stdio.h>
#include <stdlib.h>

typedef struct set {
    int element;
    struct set* nextptr;
}set;
typedef struct sets {
    int index;
    set* SetHead;
    struct sets* nextptr;
}sets;
sets *setsHead;                  //warn to make fuction for setsHead add change.
int setCnt = 0, indexCnt = 1;
void letSet();                   //let Set.
void delSet();                   //delete Set.
void prtSets();                 //print setlist.
int emptyset(set* head);          //if Set is empty return 0, else return 1.
int main() {
    letSet();
    prtSets();
    letSet();
    prtSets();
    delSet();
    prtSets();
    return 0;
}
void prtSets(){
    sets *r=setsHead;
    while(r->SetHead!=NULL){
        printf("%d", r->index);
        r=r->nextptr;
    }
}
void letSet() {
    sets *r, *p, *newsets=(sets*)malloc(sizeof(sets));
    set *newset=(set*)malloc(sizeof(set));
    newset->nextptr=NULL;
    newset->element = 0;
    newsets->index=indexCnt;
    indexCnt++;
    setCnt++;
    newsets->SetHead=newset;
    r=p=setsHead;
    for (int k = 1; k < setCnt; k++) {
        r = setsHead;
        setsHead->nextptr;
    }
    newsets->nextptr = setsHead;
    r->nextptr = newsets;
    setsHead = p;
}
void delallel(set* SETHEAD) {
    set* delel,*HEAD;
    HEAD = SETHEAD;
    while (emptyset(HEAD) != 0) {
        delel = HEAD;
        HEAD = HEAD->nextptr;
        free(delel);
    }
    free(HEAD);
}
int emptyset(set * w) {
    if (w->nextptr == NULL) return 0;
    else return 1;
}
void delSet() {
    int ind=99;
    scanf("%d",&ind);
    sets* p=setsHead->nextptr,*r=setsHead, *HEADSETS=setsHead;
    set *setH,*delel;
    if (setsHead->index == ind) {
        setsHead = setsHead->nextptr;
        setH = r->SetHead;
        delallel(setH);
    }
    else {
        while (p->index != ind) {
            p = p->nextptr;
            r = r->nextptr;
        }
        r->nextptr = p->nextptr;
        setH = p->SetHead;
        delallel(setH);
    }
}