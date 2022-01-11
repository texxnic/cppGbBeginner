#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int data;
} Node;

typedef struct lList
{
    Node *head;
    unsigned int size;
} lList;

typedef struct Queue
{
    int *data;
    int pointer;
    int size;
} Queue;

void initList(lList *list)
{
    list->head = NULL;
    list->size = 0;
}

int push(lList *stack, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "Stack overflow!\n");
        return 0;
    }
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;

    return 1;
}

int pop(lList *list)
{
    int data;
    Node *tmp;

    if (list->size == 0)
        return -1;
    data = list->head->data;
    tmp = list->head;
    list->size--;
    if (list->size == 0)
    {
        list->head = NULL;
    }
    else
    {
        list->head = list->head->next;
    }
    free(tmp);

    return data;
}

void freeList(lList *list)
{
    Node *tmp;

    while (list->size > 0)
    {
        tmp = list->head;
        list->size--;
        if (list->size > 0)
            list->head = list->head->next;
        free(tmp);
    }
    free(list);
}

Queue *dataQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->pointer = -1;
    queue->size = size;
    queue->data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        queue->data[i] = 0;

    return queue;
}

void enqueue(Queue *queue, int data)
{
    if (queue->pointer < queue->size - 1)
    {
        queue->pointer++;
        queue->data[queue->pointer] = data;
    }
    else
    {
        fprintf(stderr, "Queue overflow!\n");
    }
}

int dequeue(Queue *queue)
{
    if (queue->pointer < 0)
    {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    int val = queue->data[0];
    queue->pointer--;
    for (int i = 0; i <= queue->pointer; i++)
        queue->data[i] = queue->data[i + 1];

    return val;
}

void freeQueue(Queue *queue)
{
    free(queue->data);
    free(queue);
}

typedef struct AdjMatrix
{
    int M;
    int **matrix;
} AdjMatrix;

typedef struct NodeLinks
{
    int node;
    int links;
} NodeLinks;

AdjMatrix *adjMatrix(const int M)
{
    AdjMatrix *adjMatrix = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    adjMatrix->M = M;
    adjMatrix->matrix = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++)
        adjMatrix->matrix[i] = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            adjMatrix->matrix[i][j] = 0;
        }
    }

    return adjMatrix;
}

void printAdjMatrix(AdjMatrix *matrix)
{
    for (int i = 0; i < matrix->M; i++)
    {
        for (int j = 0; j < matrix->M; j++)
        {
            printf("%3d", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int unvisitedNode(AdjMatrix *graph, int curNode, int *visitedNodes)
{
    for (int i = 0; i < graph->M; i++)
    {
        if (graph->matrix[curNode][i] == 1 && visitedNodes[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void graphDepthTraversal(AdjMatrix *graph)
{
    int nextNode;
    int *visitedNodes = (int *)malloc(graph->M * sizeof(int));
    lList *stack = (lList *)malloc(sizeof(lList));
    initList(stack);

    visitedNodes[0] = 1;
    printf("%3d", 0);
    push(stack, 0);

    while (stack->size > 0)
    {
        nextNode = unvisitedNode(graph, stack->head->data, visitedNodes);
        if (nextNode == -1)
        {
            pop(stack);
        }
        else
        {
            visitedNodes[nextNode] = 1;
            printf("%3d", nextNode);
            push(stack, nextNode);
        }
    }
    printf("\n");
    freeList(stack);
    free(visitedNodes);
}

NodeLinks **linksCount(const int mat)
{
    NodeLinks **nodeLinks = (NodeLinks **)malloc(mat * sizeof(NodeLinks *));
    for (int i = 0; i < mat; i++)
        nodeLinks[i] = (NodeLinks *)malloc(sizeof(NodeLinks));
    for (int i = 0; i < mat; i++)
    {
        nodeLinks[i]->links = 0;
        nodeLinks[i]->node = i;
    }

    return nodeLinks;
}

void countLinksRecursive(AdjMatrix *graph, int node, NodeLinks **links)
{
    if (node >= graph->M)
        return;
    for (int i = 0; i < graph->M; i++)
    {
        if (node != i && graph->matrix[node][i] == 1)
        {
            links[node]->links++;
        }
    }
    countLinksRecursive(graph, node + 1, links);
}

void sortLinksCount(NodeLinks **links, const int size)
{
    NodeLinks *val;

    for (int i = 0; i < size; i++)
    {
        val = links[i];
        int j;
        for (j = i; j > 0 && links[j - 1]->links < val->links; j--)
            links[j] = links[j - 1];
        links[j] = val;
    }
}

void printLinksCount(NodeLinks **links, const int size)
{
    printf("node(links): ");
    for (int i = 0; i < size; i++)
        printf("%d(%d) ", links[i]->node, links[i]->links);
    printf("\n");
}

void empLinksCount(NodeLinks **links, const int size)
{
    for (int i = 0; i < size; i++)
        free(links[i]);
    free(links);
}

void countLinksQueue(AdjMatrix *graph, int node, NodeLinks **links)
{
    Queue *queue = dataQueue(graph->M);
    int *visitedNodes = (int *)malloc(graph->M * sizeof(int));

    enqueue(queue, node);
    while (queue->pointer >= 0)
    {
        int ind = dequeue(queue);
        if (visitedNodes[ind] == 1)
            continue;
        visitedNodes[ind] = 1;
        for (int i = 0; i < graph->M; ++i)
        {
            if (graph->matrix[ind][i] == 1)
            {
                if (i != ind)
                {
                    links[ind]->links++;
                }
                if (visitedNodes[i] == 0)
                {
                    enqueue(queue, i);
                }
            }
        }
    }
    free(visitedNodes);
    freeQueue(queue);
}

int main()
{

    const int mat = 9;

    
    printf("\n 1. Обход в глубину с использованием стека:\n");
    AdjMatrix *graph = adjMatrix(mat);
    if (graph == NULL)
        return 1;

    graph->matrix[0][1] = 1;
    graph->matrix[0][2] = 1;
    graph->matrix[1][0] = 1;
    graph->matrix[1][3] = 1;
    graph->matrix[1][6] = 1;
    graph->matrix[2][0] = 1;
    graph->matrix[2][2] = 1;
    graph->matrix[2][7] = 1;
    graph->matrix[3][1] = 1;
    graph->matrix[3][4] = 1;
    graph->matrix[3][5] = 1;
    graph->matrix[4][3] = 1;
    graph->matrix[5][3] = 1;
    graph->matrix[6][1] = 1;
    graph->matrix[6][6] = 1;
    graph->matrix[7][2] = 1;
    graph->matrix[7][8] = 1;
    graph->matrix[8][7] = 1;
    graph->matrix[8][8] = 1;

    printAdjMatrix(graph);

    graphDepthTraversal(graph);

    printf("\n2.1.  Рекурсивный счёт ссылок на узлы графа:\n");
    NodeLinks **links = linksCount(mat);
    countLinksRecursive(graph, 0, links);
    sortLinksCount(links, mat);

    printLinksCount(links, mat);
    empLinksCount(links, mat);

    printf("\n2.2. Счёт ссылок на узлы графа по таблице смежности:\n");
    NodeLinks **linksQty = linksCount(mat);
    countLinksQueue(graph, 0, linksQty);
    sortLinksCount(linksQty, mat);
    printLinksCount(linksQty, mat);
    empLinksCount(linksQty, mat);

    return 0;
}