#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to count occurrences of an element in a formula
int countElement(char *formula, char element) {
    int count = 0;
    for (int i = 0; formula[i] != '\0'; i++) {
        if (formula[i] == element) {
            if (isdigit(formula[i + 1])) {
                count += (formula[i + 1] - '0');
            } else {
                count += 1;
            }
        }
    }
    return count;
}

// Function to check if the reaction is balanced
int isBalanced(char reactants[][MAX], int numReactants, char products[][MAX], int numProducts, char element) {
    int reactantCount = 0, productCount = 0;

    // Count occurrences in reactants
    for (int i = 0; i < numReactants; i++) {
        reactantCount += countElement(reactants[i], element);
    }

    // Count occurrences in products
    for (int i = 0; i < numProducts; i++) {
        productCount += countElement(products[i], element);
    }

    return (reactantCount == productCount);
}

// Main function
int main() {
    char reactants[5][MAX], products[5][MAX];
    int numReactants, numProducts;

    printf("=== Compiler for Chemistry Reaction Simulation ===\n");

    // Input reactants
    printf("Enter number of reactants: ");
    scanf("%d", &numReactants);
    printf("Enter reactant formulas:\n");
    for (int i = 0; i < numReactants; i++) {
        scanf("%s", reactants[i]);
    }

    // Input products
    printf("Enter number of products: ");
    scanf("%d", &numProducts);
    printf("Enter product formulas:\n");
    for (int i = 0; i < numProducts; i++) {
        scanf("%s", products[i]);
    }

    // Check balance for key elements (H, O, C)
    char elements[] = {'H', 'O', 'C'};
    int balanced = 1;

    for (int i = 0; i < 3; i++) {
        if (!isBalanced(reactants, numReactants, products, numProducts, elements[i])) {
            balanced = 0;
            printf("Unbalanced for element: %c\n", elements[i]);
        }
    }

    if (balanced) {
        printf("The chemical equation is balanced!\n");
    } else {
        printf("The chemical equation is NOT balanced. Adjust coefficients.\n");
    }

    return 0;
}

