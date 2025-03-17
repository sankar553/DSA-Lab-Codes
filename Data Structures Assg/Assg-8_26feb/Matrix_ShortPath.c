#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 10

int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

int isValid(int row, int col, int mat[ROW][COL], int visited[ROW][COL])
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL && mat[row][col] == 1 && !visited[row][col]);
}

int shortestPath(int mat[ROW][COL], int srcX, int srcY, int destX, int destY)

{

    if (mat[srcX][srcY] == 0 || mat[destX][destY] == 0)

        return -1;

    int visited[ROW][COL] = {0};
    int queue[ROW * COL][3]; // [x, y, distance]
    int front = 0, rear = 0;
    visited[srcX][srcY] = 1;
    queue[rear][0] = srcX;
    queue[rear][1] = srcY;
    queue[rear][2] = 0;
    rear++;

    while (front < rear)

    {

        int x = queue[front][0], y = queue[front][1], dist = queue[front][2];

        front++;

        if (x == destX && y == destY)

            return dist;

        for (int i = 0; i < 4; i++)

        {

            int newX = x + dRow[i];

            int newY = y + dCol[i];

            if (isValid(newX, newY, mat, visited))

            {
                visited[newX][newY] = 1;
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                queue[rear][2] = dist + 1;
                rear++;
            }
        }
    }

    return -1;
}

int main()
{
    int Matrix[ROW][COL] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}};

    int result = shortestPath(Matrix, 0, 0, 3, 4);
    if (result != -1)
        printf("The shortest path is %d\n", result);
    else
        printf("No path exists.\n");

    return 0;
}
