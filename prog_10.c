#include <stdio.h>
#define MAX 100

int hashTable[MAX];
int m;

void init() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % m;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
