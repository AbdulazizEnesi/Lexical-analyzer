#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_balanced(const char* code) {
    int paren = 0, brace = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(') paren++;
        if (code[i] == ')') paren--;
        if (code[i] == '{') brace++;
        if (code[i] == '}') brace--;
        if (paren < 0 || brace < 0) return false; // Early error
    }
    return paren == 0 && brace == 0;
}

int count_occurrences(const char* code, const char* word) {
    int count = 0;
    const char* temp = code;
    while ((temp = strstr(temp, word)) != NULL) {
        count++;
        temp += strlen(word);
    }
    return count;
}

int main() {
    char code[1000];
    printf("Enter code (end with $): ");
    fgets(code, sizeof(code), stdin);

    // Remove trailing $
    char* end = strchr(code, '$');
    if (end) *end = '\0';

    // Check balance
    if (!is_balanced(code)) {
        printf("❌ Error: Unbalanced parentheses or braces.\n");
        return 1;
    }

    // Detect nested if
    int if_count = count_occurrences(code, "if");
    int else_count = count_occurrences(code, "else");

    if (if_count >= 2) {
        printf("✅ Valid: Nested 'if' statements detected (%d levels).\n", if_count);
    } else if (if_count == 1 && else_count >= 1) {
        printf("✅ Valid: if-else structure detected.\n");
    } else if (if_count == 1) {
        printf("✅ Valid: Single 'if' statement detected.\n");
    } else if (strstr(code, "=")) {
        printf("✅ Valid: Assignment detected.\n");
    } else {
        printf("❌ Unknown or unsupported structure.\n");
    }

    return 0;
}
