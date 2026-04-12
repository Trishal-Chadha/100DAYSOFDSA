#include <stdio.h>

#define EMPTY -1

int table[100];

// Initialize hash table
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
    printf("Hash Table Overflow\n");
}

// Search using quadratic probing
void search(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

// Main function
int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key, m);
        } else if (op[0] == 'S') {
            search(key, m);
        }
    }

    return 0;
}