/*************************************************************************
	> File Name: hash.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 15时36分10秒
 ************************************************************************/

#include<stdio.h>

typedef struct Data {
    int val, pos;
} Data;

typedef struct HashTable {
    Data *data;
    char *flag;
    int n;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (int *)malloc(sizeif(Data) * n);
    h->flag = (char *)
    h->n = n;
    return h;
}

int hash_func(HashTable *h, int val) {
    return val % h->n;
}

void insert(HashTable *h, int val) {
    int hash = hash_func(h, val);
    int time = 1;
    while (h->flag[hash]) {
        hash += (time++);
    }
    h->data[hash].val = val;
    h->data[hash].pos = ind;
    h->flag[hash] = 1;
    return ;
}

void query(HashTable *h, int val) {
    int hash = hash_func(h, val);
    int time = 1;
    while (h->flag[hash] && h->data[hash].val != val) {
        hash += (time++);
    }
    if (h->flag[hash]) return -1;
    return h->data[hash].pos;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}


#define MAX_N 500
int arr[MAX_N + 5] = {0};

int main() {
    int n, target;
    scanf("%d", &n);
    HashTable *h = init(3 * n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &target);
    for (int i = 1; i <= n; i++) {
        int pos;
        if ((pos = query(h, target - arr[i])) == -1) {
            insert(h, arr[i], i);
            continue;
        }
        printf("%d %d\n", pos, i);
        continue;
    }
}
