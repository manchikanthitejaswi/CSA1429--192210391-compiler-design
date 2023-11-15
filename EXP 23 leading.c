#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char nonTerminal;
    char leadingSet[MAX_SYMBOLS];
} SymbolSet;

SymbolSet leadingSets[MAX_SYMBOLS];

void addToSet(char set[], char symbols[]) {
    int i = 0;
    while (symbols[i] != '\0') {
        if (strchr(set, symbols[i]) == NULL) {
            strncat(set, &symbols[i], 1);
        }
        i++;
    }
}

void computeLeadingSets() {
    // Initialize leading sets
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        leadingSets[i].nonTerminal = '\0';
        leadingSets[i].leadingSet[0] = '\0';
    }

    // Productions
    char productions[][10] = {
        "E=E+T",
        "E=T",
        "T=T*F",
        "T=F",
        "F=(E)",
        "F=id"
    };

    int numProductions = sizeof(productions) / sizeof(productions[0]);

    // Compute leading sets
    for (int i = 0; i < numProductions; i++) {
        char lhs = productions[i][0];
        char rhs[10];
        strcpy(rhs, &productions[i][3]);

        int index = lhs - 'A';

        if (leadingSets[index].nonTerminal == '\0') {
            leadingSets[index].nonTerminal = lhs;
        }

        addToSet(leadingSets[index].leadingSet, rhs);
    }
}

void printLeadingSets() {
    printf("LEADING sets:\n");

    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (leadingSets[i].nonTerminal != '\0') {
            printf("LEADING(%c) = {%s}\n", leadingSets[i].nonTerminal, leadingSets[i].leadingSet);
        }
    }
}

int main() {
    computeLeadingSets();
    printLeadingSets();

    return 0;
}
