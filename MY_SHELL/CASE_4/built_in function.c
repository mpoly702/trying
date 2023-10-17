#include "shell.h"

void* findMatchingFunction(char *str) 
{
    int i;
    /*Define an array of struct pairs*/
    struct StringFunctionPair functionPairs[] = {
        {"A", functionA},
        {"B", functionB},
        {"C", functionC}
    };

    for (i = 0; i < sizeof(functionPairs) / sizeof(functionPairs[0]); i++) 
    {
        if (strcmp(functionPairs[i].str, str) == 0) 
        {
            return functionPairs[i].func;
        }
    }
    return NULL; /*Return NULL if no match is found*/
}

int main() {
    const char *inputStrings[] = {"B", "other", "data"}; // Change the input strings as needed

    void (*selectedFunction)() = findMatchingFunction(inputStrings[0]);

    if (selectedFunction != NULL) {
        selectedFunction();
    } else {
        printf("Function not found for input: %s\n", inputStrings[0]);
    }

    return 0;
}


