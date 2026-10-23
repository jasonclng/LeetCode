#include <string.h>
#include <stdlib.h>

int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = (int) strlen(seq);
    int* ans = (int*) malloc(sizeof(int) * n);
    int depth = 0;

    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            depth++;
            ans[i] = depth & 1;
        } else {
            ans[i] = depth & 1;
            depth--;
        }
    }

    *returnSize = n;
    return ans;
}