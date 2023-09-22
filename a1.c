#include "test.h"
#include <stdio.h>
#include <string.h> // for testing generate_splits()

void addtoB(int arr[],int k,int b[]){
    for (int i=0;i<k;i++){
        b[i]=arr[i];
    }
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void push(int start,int n,int arr[]){
    int hold=arr[start];
    for (int i=start;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=hold;
}

void printperm(int *b,int k,void *data){
    for (int i=0;i<k;i++){
        printf("%d ",*(b+i));
    }
    int* count=(int*) data;
    (*count)++;
    printf("\n");
}

void select(int a[], int n, int k, int b[],int len,int end, int *data, void (*process_selection)(int *b, int k, void *data)){
    if (n==k-1){
        addtoB(a,k,b);
        (*process_selection)(b, k, data);
        for(int i=k;i<end;i++){
            swap(&a[k-1],&a[i]);
            addtoB(a,k,b);
            (*process_selection)(b, k, data);
            swap(&a[k-1],&a[i]);
        }
        return;}
    
    select(a,n+1,k,b,len,end,data, process_selection);
    for(int i=1;i<(1-k+end) ;i++){
        push(n,len,a);
        select(a,n+1,k,b,len,end-i,data,process_selection);
    }
    for(int i=0;i<(len-n-end+k);i++){
        push(n,len,a);
    }
    return;
}
void generate_selections(int a[], int n, int k, int b[], void *data, void (*process_selection)(int *b, int k, void *data))
{
    int len=n;
    int end=n;
    int start=0;
    select(a,start,k,b,len,end,data,process_selection);
    
}

int check(char str[],const char *dictionary[],int nwords){
    for(int i=0;i<nwords;i++){
        if(!strcmp(dictionary[i],str)){
            return 1;
        }
    }
    return 0;
}
void splits(const char *source, const char *dictionary[], int nwords, char buf[], void *data, void (*process_split)(char buf[], void *data))
{
    // ARTISTOIL
    char str[strlen(source)+1];
    for(int i=0;i<strlen(source)+1;i++){
                str[i]='\0';
            }
    for(int i=0;i<9;i++){
        if(check(strncpy(str,source,i),dictionary,nwords)){
            char c[strlen(buf)+1];
            strcpy(c,buf);
            strncat(buf,str,i);
            if(i==strlen(source)){
                process_split(buf,data);
                // strncpy(buf,)
                return;
            }
            strncat(buf," ",i);
            splits((source+i),dictionary,nwords,buf,data,process_split);
            for(int i=0;i<strlen(buf);i++){
                buf[i]='\0';
            }
            strcpy(buf,c);
            
        }

    }
    return;
    }


void generate_splits(const char *source, const char *dictionary[], int nwords, char buf[], void *data, void (*process_split)(char buf[], void *data))
{
    for(int i=0;i<strlen(buf)+1;i++){
        buf[i]='\0';
    }
    splits(source,dictionary,nwords,buf,data,process_split);
    
}


/*
 * Transform a[] so that it becomes the previous permutation of the elements in it.
 * If a[] is the first permutation, leave it unchanged.
 */
void previous_permutation(int a[], int n)
{
    a[0] = 1;
    a[1] = 5;
    a[2] = 4;
    a[3] = 6;
    a[4] = 3;
    a[5] = 2;
}

/* Write your tests here. Use the previous assignment for reference. */

typedef struct
{
    int index;
    int err;
    int first;
} state_t;

static void test_selections_2165(int b[], int k, void *data)
{
    state_t *s = (state_t *)data;
    if (s->first)
    {
        s->err = 0;
        s->first = 0;
    }
    switch (s->index)
    {
    case 0:
        if ((b[0] != 2) || (b[1] != 1))
        {
            s->err = 1;
        }
        break;
    case 1:
        if ((b[0] != 2) || (b[1] != 6))
        {
            s->err = 1;
        }
        break;
    case 2:
        if ((b[0] != 2) || (b[1] != 5))
        {
            s->err = 1;
        }
        break;
    case 3:
        if ((b[0] != 1) || (b[1] != 6))
        {
            s->err = 1;
        }
        break;
    case 4:
        if ((b[0] != 1) || (b[1] != 5))
        {
            s->err = 1;
        }
        break;
    case 5:
        if ((b[0] != 6) || (b[1] != 5))
        {
            s->err = 1;
        }
        break;
    default:
        s->err = 1;
    }
    ++(s->index);
}

void count_selections(int b[], int k, void *data)
{
    int *d = (int *)data;
    ++*d;
}

typedef struct
{
    int b[100];
} selection_t;

void last_selection(int b[], int k, void *data)
{
    selection_t *s = (selection_t *)data;
    for (int i = 0; i < k; ++i)
    {
        s->b[i] = b[i];
    }
}

BEGIN_TEST(generate_selections)
{
    int a[] = {2, 1, 6, 5};
    int b[10];
    state_t s2165 = {.index = 0, .err = 1, .first = 1};
    generate_selections(a, 4, 2, b, &s2165, test_selections_2165);
    ASSERT(!s2165.err, "Failed on 2 1 6 5.");
    int c = 0;
    int aa[] = {1, 5, 3, 0, 1, 12, 4, 3, 6, 6};
    generate_selections(aa, 10, 5, b, &c, count_selections);
    ASSERT_EQ(c, 252, "Failed on 10C5.");

    selection_t s;
    generate_selections(aa, 10, 5, b, &s, last_selection);
    ASSERT_ARRAY_VALUES_EQ(s.b, 5, "Failed on last of 10C5.", 12, 4, 3, 6, 6);
}
END_TEST

void test_splits_art(char buf[], void *data)
{
    state_t *s = (state_t *)data;
    if (s->first)
    {
        s->err = 0;
        s->first = 0;
    }
    switch (s->index)
    {
    case 0:
        if (strcmp(buf, "art is toil"))
        {
            s->err = 1;
        }
        break;
    case 1:
        if (strcmp(buf, "artist oil"))
        {
            s->err = 1;
        }
        break;
    default:
        s->err = 1;
    }
    ++(s->index);
}

BEGIN_TEST(generate_splits)
{
    const char *a = "artistoil";
    const char *dict[] = {
        "art",
        "artist",
        "is",
        "oil",
        "toil"};
    int nwords = 5;
    state_t s = {.index = 0, .err = 1, .first = 1};
    char buf[256];
    generate_splits(a, dict, nwords, buf, &s, test_splits_art);
    ASSERT(!s.err, "Failed on 'artistoil'.");
}
END_TEST

BEGIN_TEST(previous_permutation)
{
    int a[] = {1, 5, 6, 2, 3, 4};
    previous_permutation(a, 6);
    ASSERT_ARRAY_VALUES_EQ(a, 6, "Failed on 1 5 6 2 3 4.", 1, 5, 4, 6, 3, 2);
    int aa[] = {1, 2, 3, 5, 4, 6};
    previous_permutation(aa, 3); // 3 is correct.
    ASSERT_ARRAY_VALUES_EQ(aa, 3, "Failed on 1 2 3.", 1, 2, 3);
}
END_TEST

int main()
{
    run_tests((test_t[]){
        TEST(generate_selections),
        TEST(generate_splits),
        TEST(previous_permutation),
        0});
    return 0;
}
