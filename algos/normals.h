// Some normal functions defined for common usage
// in all algos programs

#define MAX_RAND_NUM 4098 // Max random number generator

struct DataOps{
    /* Returns -1,1,0 like thiss == that */
    int (*cmp)(void **thiss, void *that);
    int (*dataToInt)(void **data);
};

typedef struct DataOps DataOps;

// Function definations
void swap(int *a,int *b); // will swap two int
int *creatIntArray(int size); // will create array of int size
void printIntArray(int *A, int size); // will print the array
void deleteIntArray(int *A); // will delete Array

int defaultComp(void *thiss, void *that); // comp two data sets thiss == that
void dfaultDataToInt(void *data); // convert data
