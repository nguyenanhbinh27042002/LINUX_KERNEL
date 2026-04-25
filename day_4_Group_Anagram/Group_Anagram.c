#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10007   // large prime for better hashing

// ----- Dynamic array of strings -----
typedef struct {
    char **data;
    int size;
    int capacity;
} StringList;

void initStringList(StringList *list) {
    list->size = 0;
    list->capacity = 4;
    list->data = malloc(sizeof(char*) * list->capacity);
}

void pushStringList(StringList *list, char *str) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(char*) * list->capacity);
    }
    list->data[list->size++] = strdup(str);
}

// ----- Hash table node -----
typedef struct Node {
    char *key;                // signature key
    StringList list;          // list of anagrams
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

// ----- Simple string hash -----
unsigned long hash(char *str) {
    unsigned long h = 5381;
    int c;
    while ((c = *str++))
        h = ((h << 5) + h) + c;
    return h % TABLE_SIZE;
}

// ----- Create signature from letter count -----
void makeKey(const char *s, char *key) {
    int count[26] = {0};
    while (*s) {
        count[*s - 'a']++;
        s++;
    }

    key[0] = '\0';
    char temp[20];
    for (int i = 0; i < 26; i++) {
        sprintf(temp, "#%d", count[i]);
        strcat(key, temp);
    }
}

// ----- Insert into hash table -----
void insert(char *s) {
    char key[200];
    makeKey(s, key);

    unsigned long h = hash(key);
    Node *curr = hashTable[h];

    // Check if key exists
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            pushStringList(&curr->list, s);
            return;
        }
        curr = curr->next;
    }

    // Create new node
    Node *newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    initStringList(&newNode->list);
    pushStringList(&newNode->list, s);
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// ----- Print output -----
void printGroups() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = hashTable[i];
        while (curr) {
            printf("[ ");
            for (int j = 0; j < curr->list.size; j++) {
                printf("%s ", curr->list.data[j]);
            }
            printf("]\n");
            curr = curr->next;
        }
    }
}

// ----- Main example -----
int main() {
    char *input[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(input)/sizeof(input[0]);

    for (int i = 0; i < n; i++) {
        insert(input[i]);
    }

    printGroups();
    return 0;
}
