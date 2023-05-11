#include <stdio.h>
#include <stdlib.h>

const int maxN = 1001;
int m, n, sr, sc;

int Maze[maxN][maxN];
int step[maxN][maxN];   // Save minimum numb3er of step from r c to i j

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int visited[maxN][maxN];

// Define the structure for a node
typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int r, int c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->row = r;
    newNode->col = c;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to add an element to the queue
void push(Queue* queue, int r, int c) {
    Node* newNode = createNode(r, c);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the queue
void pop(Queue* queue) {
    if (isEmpty(queue)) {
        exit(1);
    }
    Node* temp = queue->front;
    int r = temp->row;
    int c = temp->col;
    queue->front = queue->front->next;
    free(temp);
}

// Function to display the elements of the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d %d", temp->row, temp->col);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated to the queue
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int BFS(int row, int col) {

    push(Q, row, col);
    visited[row][col] = 1;
    step[row][col] = 0; // previously 0

    while (!isEmpty()) {
        int x0 = Q->front->row;
        int y0 = Q->front->col;

        pop(Q);
        for(int i = 0; i < 4; i++) {
            int x1 = x0 + dx[i];
            int y1 = y0 + dy[i];

            if (x1 < 1 || x1 > m || y1 < 1 || y1 > n)
                return step[x0][y0] + 1;

            if (Maze[x1][y1] == 0 && visited[x1][y1] == false) {
                push(Q, x1, y1);
                visited[x1][y1] = 1;
                step[x1][y1] = step[x0][y0] + 1;
            }
        }
    }

    return -1;
}


int main() {
    Queue* Q = createQueue();
    scanf("%d %d %d %d", &n, &m, &sr, &sc);

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)scanf("%d", &Maze[i][j]);

    int result = BFS(sr,sc);
    printf("%d", result);

    return 0;
}
