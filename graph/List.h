typedef struct {
    int count;
    int size;
    int *buffer;
} List;

void initList(List *list, int size);
int isEmptyList(List *list);
void insertList(List *list, int x);
int extractList(List *list);
int valueList(List *list, int i);
void printList(List *list);
void freeList(List *list);
