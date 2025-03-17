#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 10

// Directions for moving in 4 directions (left, right, up, down)
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

// Structure to store a cell and its distance from the source
typedef struct
{
    int x, y, dist;
} Node;

// Queue structure for BFS
typedef struct
{
    Node *arr;
    int front, rear, size, capacity;
} Queue;

// Function to create a queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (Node *)malloc(queue->capacity * sizeof(Node));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// Function to enqueue an element
void enqueue(Queue *queue, Node item)
{
    if (queue->size == queue->capacity)
        return; // Queue overflow
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size += 1;
}

// Function to dequeue an element
Node dequeue(Queue *queue)
{
    Node item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

// Function to check if a cell is valid
int isValid(int row, int col, int mat[ROW][COL], int visited[ROW][COL])
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL && mat[row][col] == 1 && !visited[row][col]);
}

// BFS function to find the shortest path
int shortestPath(int mat[ROW][COL], int srcX, int srcY, int destX, int destY)
{
    // If source or destination is not 1, return -1
    if (mat[srcX][srcY] == 0 || mat[destX][destY] == 0)
        return -1;

    // Create visited matrix
    int visited[ROW][COL] = {0};

    // Create a queue for BFS
    Queue *queue = createQueue(ROW * COL);

    // Mark the source as visited and enqueue it
    visited[srcX][srcY] = 1;
    enqueue(queue, (Node){srcX, srcY, 0});

    // BFS loop
    while (!isEmpty(queue))
    {
        Node curr = dequeue(queue);
        int x = curr.x, y = curr.y, dist = curr.dist;

        // If we reach the destination, return the distance
        if (x == destX && y == destY)
            return dist;

        // Explore all 4 possible moves
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dRow[i];
            int newY = y + dCol[i];

            // Check if the move is valid
            if (isValid(newX, newY, mat, visited))
            {
                visited[newX][newY] = 1;
                enqueue(queue, (Node){newX, newY, dist + 1});
            }
        }
    }

    return -1; // If no path is found
}

// Main function
int main()
{
    int mat[ROW][COL] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}};

    int sourceX = 0, sourceY = 0;
    int destX = 3, destY = 4;

    int result = shortestPath(mat, sourceX, sourceY, destX, destY);

    if (result != -1)
        printf("Shortest path length: %d\n", result);
    else
        printf("No path exists.\n");

    return 0;
}
