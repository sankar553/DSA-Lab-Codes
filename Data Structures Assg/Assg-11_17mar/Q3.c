#include <stdio.h>
#include <stdlib.h>

struct Meeting
{
    int start;
    int end;
    int index;
};

void maxMeetings(int start[], int end[], int n)
{
    struct Meeting meetings[n];

    for (int i = 0; i < n; i++)
    {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i + 1;
    }

    int lastEndTime = 0;
    printf("Meetings that can be attended: ");

    for (int i = 0; i < n; i++)
    {
        if (meetings[i].start > lastEndTime)
        {
            printf("%d ", meetings[i].index);
            lastEndTime = meetings[i].end;
        }
    }
    printf("\n");
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5, 12};
    int end[] = {2, 4, 6, 7, 9, 9, 29};
    int n = sizeof(start) / sizeof(start[0]);

    maxMeetings(start, end, n);

    return 0;
}
