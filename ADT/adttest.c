#include "linkedlist.h"
typedef enum {
    SIEBEN,
    OCHT,
    NEIN,
    ZEHN,
    UNTER,
    OBER,
    KINIG,
    ASS
}CardValue;
typedef enum {
    HERZ,OACHEL,SCHELL,LAB
}CardColour;
typedef struct {
    CardValue value;
    CardColour colour
}PlayingCard;
void print_playingcard(const void* card){
    PlayingCard *cardp = (PlayingCard*) card;
    printf("%d,%d",cardp->value,cardp->colour);
}
void print_int(const void* val){
    printf("%d",*(int*)val);
}
void print_double(const void* val){
    printf("%f",*(double *)val);
}
void test_list(void)
{
    LinkedList list = NewList(sizeof(double));
    PlayingCard arr[] = {
            {SIEBEN,SCHELL},
            {KINIG,OACHEL},
            {ASS,LAB},
            {UNTER,HERZ},
            {OBER,SCHELL},
    };
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        Append(&list,arr+i);
    }
    PrintList(&list,&print_playingcard);
    RemoveAt(&list,0);
    RemoveAt(&list,3);
    PrintList(&list,&print_playingcard);
    InsertAt(&list,1,arr);
    InsertAt(&list,list.node_cnt-1,arr);
    PrintList(&list,&print_playingcard);
    FreeList(&list);
}

int main(void)
{
    test_list();
    return 0;
}

