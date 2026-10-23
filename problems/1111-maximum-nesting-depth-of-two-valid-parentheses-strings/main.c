#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* maxDepthAfterSplit(char* seq, int* returnSize);

static int depthOf(const char* seq, const int* answer, int n, int group) {
    int depth = 0, maxDepth = 0;

    for (int i = 0; i < n; i++) {
        if (group >= 0 && answer[i] != group) {
            continue;
        }
        depth += seq[i] == '(' ? 1 : -1;
        if (depth < 0) {
            return -1;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    return depth == 0 ? maxDepth : -1;
}

static int isValidSplit(const char* seq, const int* answer, int n) {
    if (answer == NULL || n != (int)strlen(seq)) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (answer[i] != 0 && answer[i] != 1) {
            return 0;
        }
    }

    int depthA = depthOf(seq, answer, n, 0);
    int depthB = depthOf(seq, answer, n, 1);
    int best = (depthOf(seq, answer, n, -1) + 1) / 2;

    return depthA >= 0 && depthB >= 0 && (depthA > depthB ? depthA : depthB) == best;
}

int main(void) {
    const char* cases[] = { "(()())", "()(())()", "()", "((((()))))", "()()()" };
    int count = (int)(sizeof(cases) / sizeof(cases[0]));
    int failures = 0;

    for (int c = 0; c < count; c++) {
        size_t length = strlen(cases[c]);
        char* seq = (char*)malloc(length + 1);
        memcpy(seq, cases[c], length + 1);

        int n = -1;
        int* answer = maxDepthAfterSplit(seq, &n);
        int passed = isValidSplit(seq, answer, n);

        printf("%-12s ", seq);
        if (answer != NULL && n == (int)length) {
            printf("[");
            for (int i = 0; i < n; i++) {
                printf(i ? ",%d" : "%d", answer[i]);
            }
            printf("]");
        } else {
            printf("(returned size %d)", n);
        }
        printf(" %s\n", passed ? "PASS" : "FAIL");

        failures += !passed;
        free(answer);
        free(seq);
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
