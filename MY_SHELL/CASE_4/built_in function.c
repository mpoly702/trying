void* findMatchingFunction(const char *str) {
    // Define an array of struct pairs
    struct StringFunctionPair functionPairs[] = {
        {"A", functionA},
        {"B", functionB},
        {"C", functionC}
    };

    for (int i = 0; i < sizeof(functionPairs) / sizeof(functionPairs[0]); i++) {
        if (strcmp(functionPairs[i].str, str) == 0) {
            return functionPairs[i].func;
        }
    }
    return NULL; // Return NULL if no match is found
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
In this code, inputStrings[0] is directly passed to findMatchingFunction as the argument, and the rest of the code remains the same. It will work with the first string from the array for matching.





