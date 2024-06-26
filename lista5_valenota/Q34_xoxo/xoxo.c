#include <stdio.h>

#define MAX_SIZE 200005

int elements[MAX_SIZE];
long long segment_tree[4 * MAX_SIZE];

void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        segment_tree[node] = elements[start];
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(2 * node, start, mid);
    buildSegmentTree(2 * node + 1, mid + 1, end);

    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
}

void updateSegmentTree(int node, int start, int end, int index, int value) {
    if (start == end) {
        elements[index] = value;
        segment_tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid)
        updateSegmentTree(2 * node, start, mid, index, value);
    else
        updateSegmentTree(2 * node + 1, mid + 1, end, index, value);

    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
}

long long querySegmentTree(int node, int start, int end, int left, int right) {
    if (right < start || left > end)
        return 0;

    if (left <= start && right >= end)
        return segment_tree[node];

    int mid = (start + end) / 2;
    long long sum_left = querySegmentTree(2 * node, start, mid, left, right);
    long long sum_right = querySegmentTree(2 * node + 1, mid + 1, end, left, right);
    return sum_left + sum_right;
}

int main() {
    int numElements, numQueries;
    scanf("%d %d", &numElements, &numQueries);

    for (int i = 1; i <= numElements; i++) {
        scanf("%d", &elements[i]);
    }

    buildSegmentTree(1, 1, numElements);

    while (numQueries--) {
        int operationType, queryStart, queryEnd;
        scanf("%d %d %d", &operationType, &queryStart, &queryEnd);

        if (operationType == 1) {
            updateSegmentTree(1, 1, numElements, queryStart, queryEnd);
        } else {
            printf("%lld\n", querySegmentTree(1, 1, numElements, queryStart, queryEnd));
        }
    }

    return 0;
}