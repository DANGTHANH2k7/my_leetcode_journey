typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    const Interval *i1 = (const Interval *)a;
    const Interval *i2 = (const Interval *)b;
    if (i1->end < i2->end) return -1;
    if (i1->end > i2->end) return 1;
    return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 1) return 0;

    Interval *flat = (Interval *)malloc(intervalsSize * sizeof(Interval));
    for (int i = 0; i < intervalsSize; i++) {
        flat[i].start = intervals[i][0];
        flat[i].end = intervals[i][1];
    }

    qsort(flat, intervalsSize, sizeof(Interval), compare);

    int count = 1; 
    int last_end = flat[0].end;

    for (int i = 1; i < intervalsSize; i++) {
        if (flat[i].start >= last_end) {
            count++;
            last_end = flat[i].end;
        }
    }

    free(flat);
    return intervalsSize - count;
}