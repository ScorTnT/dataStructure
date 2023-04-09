#include <stdio.h>
#include <stdlib.h>
#define UNISET 10
typedef struct set{
    int element;
    struct set *nextptr;
}set;
typedef struct sets{
    int index;
    set *SetHead;
    struct sets *nextptr;
}sets;
sets setsHead;                  //do not make function change value setsHead address.
int setCnt=0,indexCnt=0;
void letSet();                   //let Set.
int delSet();                   //delete Set.
int insElement();                //insert element in Set.
int delElement();                 //delete element in Set.
int prtSet(set *prt);           //print all of element in Set.
void prtSets();                 //print setlist.
int empty(set *head);           //if Set is empty return 0, else return 1.
void AndGate();                   //And Gate A with B 
void OrGate();                    //Or Gate A with B
void complementSet();           //compliment Set.
int main(){
    int command=6;
    printf("what do you want?\n(letSet:0, delSet:1, insElement:2, delElement:3, AndGate:4, OrGate:5, ComplementGate:6): ");
    scanf("%d",&command);
    printf("\n");
    if(command>6) {
        printf("wrong order.");
        main();
    }else{
        switch (command){
        case 0://let Set
            letSet();
            main();
        break;
        case 1://del Set
            delSet();
            main();
        break;
        case 2://ins element
            insElement();
            main();
        break;
        case 3://del element
            delElement();
            main();
        break;
        case 4://and gate
            AndGate();
            main();
        break;
        case 5://or gate
            OrGate();
            main();
        break;
        case 6://complement gate
            complementSet();
            main();
        break;
        default:
            break;
        }
    }
    return 0;
}
int empty(set *head){
    if(head->element==7777&&head->nextptr==NULL) {
        return 0;
    }else return 1;
}
int prtSet(set *ptr){
    if(empty(ptr)==0) {
        printf("Empty Set.\n");
        return 0;
    }
    printf("Print set's element:");
    while(empty(ptr)!=0){
        printf(" %d",ptr->element);
        ptr = ptr->nextptr;
    }
    printf("\n");
    return 0;
}
void prtSets(){
    sets *setlist=setsHead.nextptr;
    if(setCnt==0){
        printf("Nothing Set.");
    }else{
        printf("We have index of set:");
        for(int k=0;k<setCnt;k++){
            printf(" %d",setlist->index);
            setlist=setlist->nextptr;
        }
    }
    printf("\n");
}
void letSet(){
    prtSets();
    setCnt++;
    indexCnt++;
    set *newSet=(set *)malloc(sizeof(set));
    newSet->element=7777;
    newSet->nextptr=NULL;
    sets *makeptr=(sets *)malloc(sizeof(sets));
    makeptr->index=indexCnt;
    makeptr->SetHead=newSet;
    makeptr->nextptr=NULL;
    sets *q,*p;
    p=&setsHead;
    q=p->nextptr;
    while(q!=NULL){
        p=p->nextptr;
        q=p->nextptr;
    }
    q=makeptr;
    p->nextptr=q;
    printf("after make set!\n");
    
    prtSets();
}
int delSet(){
    if(setCnt==0) {
        printf("Nothing Set.\n");
        return 0;
    }
    int ind=9;
    printf("what number of set's index you want to delete?\n");
    prtSets();
    scanf("%d",&ind);
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    if(setCnt==1){
        if(setsHead.index==ind){
            setsHead=*setsHead.nextptr;
            prtSets();
        }
    }else{
        for(int k=0;k<setCnt;k++){
            if(p->index==ind){
                q->nextptr=p->nextptr;
                break;
            }
            q=p;
            p=p->nextptr;
        }
    }
    setCnt--;
    prtSets();
    return 0;
}
int insElement(){
    int ind=9,ele=1,ord=0;
    set *insSet,*newele,*r;
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    printf("what number of set's index you want to insert element?\n");
    prtSets();
    scanf("%d",&ind);
    for(int k=0;k<setCnt;k++){
        if(p->index==ind){
            insSet=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    prtSet(insSet);
    newele=(set *)malloc(sizeof(set));
    printf("what is number of element?\n");
    scanf("%d",&ele);
    newele->element=ele;
    r=insSet;
    if(empty(insSet)==0){
        newele->nextptr=insSet;
        insSet=newele;
    }else{
        do{
            if(r->element==ele){
                printf("reduplication element.\n");
                return 0;
            }
            r=r->nextptr;
        }while((empty(r))==1);
        printf("order :");
        scanf("%d",&ord);
        if(ord==1){
            newele->nextptr=insSet;
            insSet=newele;
        }else{
            r=insSet;
            for(int k=1;k<ord-1;k++){
                insSet=insSet->nextptr;  
            }
            newele->nextptr=insSet->nextptr;
            insSet->nextptr=newele;
            insSet=r;
        }
    }
    p->SetHead=insSet;          //save result
    prtSet(insSet);
    return 0;
}
int delElement(){
    int ind=99,ele=99;
    set *delSet,*r;
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    printf("what number of set's index you want to delete element?\n");
    prtSets();
    scanf("%d",&ind);
    for(int k=0;k<setCnt;k++){
        if(p->index==ind){
            delSet=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    prtSet(delSet);
    printf("what is number of element?\n");
    scanf("%d",&ele);
    r=delSet;
    if(empty(delSet)!=1){
        printf("set is empty.\n");
        return 0;
    }else{
        if(delSet->element==ele){
            p->SetHead=p->SetHead->nextptr;
            printf("delete success.\n");
            free(delSet);
            delSet=p->SetHead;
            prtSet(delSet);
            return 0;
        }else{
            delSet=delSet->nextptr;
            do{
                if(delSet->element==ele){
                    r->nextptr=delSet->nextptr;
                    free(delSet);
                    printf("delete success.\n");
                    delSet=p->SetHead;
                    prtSet(delSet);
                    return 0;
                }
                r=r->nextptr;
                delSet=delSet->nextptr;
            }while(empty(delSet)==1);
        }
        printf("there are not exist %d\n",ele);
    }
}
void AndGate(){
    int addind=0;
    set *AndSet=(set *)malloc(sizeof(set)),*newAnd;     //store 1,2 -> 중복 제거
    set *find,*HEAD,*r;
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    prtSets();
    printf("Select index of set A and B.\n");
    printf("A: ");
    scanf("%d",&addind);
    // a집합 andset에 담기
    for(int k=0;k<setCnt;k++){
        if(p->index==addind){
            find=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    prtSet(find);           //a 찾음.
    newAnd=(set *)malloc(sizeof(set));
    newAnd->element=find->element;
    if(find->nextptr==NULL){
        newAnd->nextptr=NULL;
        AndSet->element=newAnd->element;
        AndSet->nextptr=NULL;
        HEAD=AndSet;
    }else{
        find=find->nextptr;
        AndSet->element=newAnd->element;
        HEAD=AndSet;
        while(empty(find)!=0){
            newAnd=(set *)malloc(sizeof(set));
            newAnd->element=find->element;
            AndSet->nextptr=newAnd;
            AndSet=AndSet->nextptr;
            find=find->nextptr;
        }
    }
    printf("B: ");
    scanf("%d",&addind);
    // b집합 andset에 담기
    q=&setsHead;
    p=setsHead.nextptr;
    for(int k=0;k<setCnt;k++){
        if(p->index==addind){
            find=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    prtSet(find);           //b 찾음.
    
    newAnd=(set *)malloc(sizeof(set));
    newAnd->element=find->element;
    if(find->nextptr==NULL){
        newAnd->nextptr=NULL;
        AndSet->nextptr=newAnd;
    }else{
        find=find->nextptr;
        AndSet->nextptr=newAnd;
        AndSet=AndSet->nextptr;
        while(empty(find)!=0){
            newAnd=(set *)malloc(sizeof(set));
            newAnd->element=find->element;
            AndSet->nextptr=newAnd;
            AndSet=AndSet->nextptr;
            find=find->nextptr;
        }
    }
    newAnd=(set *)malloc(sizeof(set));
    newAnd->element=find->element;
    newAnd->nextptr=NULL;
    AndSet->nextptr=newAnd;
    AndSet=HEAD;
    // andset 중복 제거
    find=AndSet;
    while (empty(find)!=0){
        while(empty(AndSet)!=0){
            r=AndSet;
            AndSet=AndSet->nextptr;
            if(AndSet->element==find->element){
                r->nextptr=AndSet->nextptr;
            }
        }
        find=find->nextptr;
        AndSet=find;
    }
    AndSet=HEAD;
    printf("And Gate set.\n");
    prtSet(AndSet); 
    free(AndSet);
}
void OrGate(){
    int orind1=0,orind2=0;
    set *OrSet=(set *)malloc(sizeof(set)),*newor,*tmp;      //select insert 
    set *check,*s,*HEAD,*t;
    HEAD=OrSet;
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    prtSets();
    printf("Select index of set A and B.\n");
    printf("A: ");
    scanf("%d",&orind1);
    for(int k=0;k<setCnt;k++){
        if(p->index==orind1){
            s=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    prtSet(s);
    printf("B: ");
    scanf("%d",&orind2);
    q=&setsHead;
    p=setsHead.nextptr;
    for(int k=0;k<setCnt;k++){
        if(p->index==orind2){
            t=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }                           //s= set A, t= set B
    prtSet(t);
    OrSet->element=7777;
    OrSet->nextptr=NULL;
    if(empty(s)==0||empty(t)==0){
    }else{
        tmp=t;
        while(empty(s)!=0){
            while(empty(t)!=0){ 
                if(s->element=t->element){
                    newor=(set *)malloc(sizeof(set));
                    newor->element=s->element;
                    if(HEAD==OrSet) newor->nextptr=OrSet;
                    else newor->nextptr=HEAD;
                    HEAD=newor;
                }
                t=t->nextptr;
            }
            t=tmp;
            s=s->nextptr;
        }
    }
    OrSet=HEAD;
    prtSet(OrSet);
    free(OrSet);
}
void complementSet(){
    int ind=0;
    set *Uni=(set *)malloc(sizeof(set)),*comSet;
    Uni->element=7777;
    Uni->nextptr=NULL;
    set *tmp,*del;
    for(int k=UNISET;k>0;k--){
        tmp = (set*)malloc(sizeof(set));
        tmp->element=k;
        tmp->nextptr=Uni;
        Uni=tmp;
    }
    printf("Universe Set.\n");
    prtSet(Uni);
    printf("What set do you want to do computing the complement?\n");
    prtSets();
    scanf("%d",&ind);
    sets *p,*q;
    q=&setsHead;
    p=setsHead.nextptr;
    for(int k=0;k<setCnt;k++){
        if(p->index==ind){
            comSet=p->SetHead;
            break;
        }
        q=p;
        p=p->nextptr;
    }
    printf("Before.\n");
    prtSet(comSet);
    del=tmp;
    if(tmp->element==comSet->element){
        Uni=Uni->nextptr;
        del=del->nextptr;
        tmp=tmp->nextptr;
        comSet=comSet->nextptr;
    }
    while(empty(comSet)!=0){ 
        if(tmp->element==comSet->element){
            Uni=Uni->nextptr;
            del=del->nextptr;
            tmp=tmp->nextptr;
            comSet=comSet->nextptr;
        }
        while(empty(tmp)!=0){
            del=del->nextptr;
            if(del->element==comSet->element){
                tmp->nextptr=del->nextptr;
                del=tmp;
                del=del->nextptr;
            }
            tmp=tmp->nextptr;
        }
        tmp=Uni;
        del=Uni;
        comSet=comSet->nextptr;
    }
    printf("After : ");
    prtSet(Uni);
    free(Uni);
}