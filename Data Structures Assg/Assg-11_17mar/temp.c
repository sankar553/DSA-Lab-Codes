#include <stdio.h>
#include <stdlib.h>


struct Interval {
    int start, end;
};


int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

void mergeIntervals(int arr[][2], int n) {
    struct Interval intervals[n];
    for (int i = 0; i < n; i++) {
        intervals[i].start = arr[i][0];
        intervals[i].end = arr[i][1];
    }
    
    
    qsort(intervals, n, sizeof(struct Interval), compare);
    
    int index = 0; 
    for (int i = 1; i < n; i++) {
        if (intervals[index].end >= intervals[i].start) {
            
            intervals[index].end = intervals[i].end > intervals[index].end ? intervals[i].end : intervals[index].end;
        } else {
            
            index++;
            intervals[index] = intervals[i];
        }
    }
    
    
    printf("Merged Intervals: ");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    int arr[][2] = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeIntervals(arr, n);
    
    return 0;
}
