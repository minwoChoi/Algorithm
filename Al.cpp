#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <limits.h>
#define UP  72
#define DOWN  80
#define ENTER 13


void Swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void DrawStart();
void gotoxy(int x, int y);
void DrawPage1();
void P0_MenuDraw();
void P1_MenuDraw();
int KeyControl();
int MenuCursor(int* x, int* y, int c, int move);
void RadixSort();
void ShellSort();
void SS(int arr[], int size,int x,int y);
void DrawDefinition();
void DrawCondition();

void DrawExpression();
//Experession 
void DrawPseudoCode();
void DrawFlowchart();
void DrawProgrammingLanguage();

void DrawEvaluation();
void DrawAlgorithmType();

void Sort();
void SortMenu();
void SortFrame();

void BubbleSort();
void BubbleExe();
void BubbleFrame();
void SelectSort();
void SelectFrame();
void SelectExe();

void InsertSort();
void InsertFrame();
void InsertExe();

void MergeSort();
void MergeExe();
void MergePrintR(int arr[], int start, int end);
void MergePrintL(int arr[], int start, int end);
void MergeFrame();
void MS();
void MergePrint(int* arr, int left, int mid, int right, int x, int y);

void Quick();
void QuickSort(int arr[], int left, int right, int size);
void QuickFrame();
void QuickExe();
void QPrintArr(int arr[], int left, int right);

void HeapSort(int arr[], int size);
void HFrame();
void HExe();
void printTree(int tree[], int heightOfTree, int size);
void RadixSortEXE();
void PrintArr(int arr[], int size);
void RS(int* a, int n,int x,int y);
void ShellEXE();
void GraphFrame();
void GraphMenu();
void IsGraph();
void GraphTraversalAlgorithm();
void GraphTerm();
void GraphRealize();
void AdjacencyList();
void GraphType();
void GraphSearchFrame();
void GraphSearch();
void DFS();
void DFSEXE();
void BFS();
void BFSEXE();
void Kruskal();
void KruskalEXE();
void AStar();
void MST();
void Prim();
void PrimEXE();
void Backtracking();
void BranchandBound();
void TopologicalSorting();
void ConditionMenuDraw();
void DefinitionMenuDraw();
void ExpressionMenuDraw();
void PseudoCodeMenuDraw();
void FlowchartMenuDraw();
void ProgrammingLanguageMenuDraw();
void AlgorithmTypeMenu();
void End();

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}


void kruskal(struct Edge edges[], int V, int E, int x_, int y_) {

    qsort(edges, E, sizeof(edges[0]), compare);

    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    gotoxy(x_, y_);
    printf("최소 신장 트리의 간선:");

    for (int i = 0; i < E; ++i) {

        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            gotoxy(x_, y_ += 1);
            printf("%d - %d 가중치: %d", edges[i].src, edges[i].dest, edges[i].weight);
            Union(parent, x, y);

        }
    }

    free(parent);
}

struct Edge_ {
    int src, dest, weight, selected;
};

void prim(struct Edge_ edges[], int V, int E, int x, int y) {
    int* selected = (int*)malloc(V * sizeof(int));

    struct Edge_* minEdge = (struct Edge_*)malloc(V * sizeof(struct Edge_));


    for (int i = 0; i < V; ++i) {
        selected[i] = 0;
        minEdge[i].weight = INT_MAX;
        minEdge[i].src = -1;
    }

    int startVertex = 0;


    minEdge[startVertex].weight = 0;

    for (int i = 0; i < V - 1; ++i) {

        int minVertex = -1;
        for (int j = 0; j < V; ++j) {
            if (!selected[j] && (minVertex == -1 || minEdge[j].weight < minEdge[minVertex].weight)) {

                minVertex = j;
            }
        }


        selected[minVertex] = 1;

        if (minEdge[minVertex].src != -1) {
            gotoxy(x, y += 1);
            printf("%d - %d 가중치: %d\n", minVertex, minEdge[minVertex].src, minEdge[minVertex].weight);
        }

        for (int j = 0; j < E; ++j) {
            if (edges[j].src == minVertex && edges[j].weight < minEdge[edges[j].dest].weight) {
                minEdge[edges[j].dest] = edges[j];
            }
            if (edges[j].dest == minVertex && edges[j].weight < minEdge[edges[j].src].weight) {
                minEdge[edges[j].src] = edges[j];
            }
        }
    }
    free(selected);
    free(minEdge);
}
typedef struct node {
    int vertex;
    struct node* next = NULL;
}node;

typedef struct graph {
    int vertexCount;
    node* head;
}graph;

void graphinit(graph* g, int size) {
    g->head = (node*)malloc(sizeof(node) * size);
    for (int i = 0; i < size; i++) {
        g->head[i].vertex = i;
        g->head[i].next = NULL;
    }
}

void AddEdge(graph* g, int src, int vertex) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    if (g->head[src].next == NULL) {
        g->head[src].next = newNode;
        return;
    }

    newNode->next = g->head[src].next;
    g->head[src].next = newNode;
}

void PrintGraph(graph* g, int size, int x, int y, int start) {
    node* tmp;
    for (int i = start; i < size; i++) {
        tmp = g->head[i].next;
        gotoxy(x, y);
        printf("NODE[%d] :", i);
        while (tmp)
        {
            printf("%2d", tmp->vertex);
            tmp = tmp->next;
            if (tmp) {
                printf("  →");
            }
        }
        y += 1;
    }
}

typedef struct node_ {
    int num;
    struct node_* next;
}node_;

typedef struct stack {
    node_* head = NULL;

};

void push(stack* s, int vertex) {
    node_* newNode = (node_*)malloc(sizeof(node_));
    newNode->next = NULL;
    newNode->num = vertex;
    if (s->head == NULL) {
        s->head = newNode;
        return;
    }
    newNode->next = s->head;
    s->head = newNode;

}
void printStack(stack* s, int x, int y) {
    node_* tmp = s->head;
    gotoxy(x, y);
    printf("                           ");
    gotoxy(x, y);
    printf("Stack : ");
    while (tmp) {
        printf("%2d", tmp->num);
        tmp = tmp->next;

    }
}
\
int isEmpty(stack* s) {
    if (s->head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int pop(stack* s) {
    if (s->head == NULL) {
        return 1;
    }
    else {
        int num;
        node_* tmp = s->head;
        s->head = tmp->next;
        num = tmp->num;
        free(tmp);
        return num;

    }
}
void DFS_stack(graph* g, int src, int x, int y) {
    int* visitedStack = (int*)malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; i++) {
        visitedStack[i] = 0;
    }
    stack s;
    push(&s, src);
    visitedStack[src] = 1;
    while (!isEmpty(&s))
    {
        while (1) {
            if (KeyControl() == ENTER) {
                break;
            }
            else {
                continue;
            }
        }
        gotoxy(x, y + 3);
        printf("visitedStack :");
        for (int i = 0; i < 7; i++) {
            printf("%3d", visitedStack[i]);
        }
        printStack(&s, x, y);
        int popData = pop(&s);
        gotoxy(x, y + 2);
        printf("제거한 데이터 %4d\n", popData);
        node* tmp = g->head[popData].next;
        while (tmp) {
            if (visitedStack[tmp->vertex] == 0) {
                push(&s, tmp->vertex);
                visitedStack[tmp->vertex] = 1;
            }

            tmp = tmp->next;
        }

    }
    //printStack(&s,x,y);
    free(visitedStack);
}

typedef struct queue {
    node_* front;
    node_* rear;
} queue;

void enqueue(queue* q, int vertex) {
    node_* newNode = (node_*)malloc(sizeof(node_));
    newNode->next = NULL;
    newNode->num = vertex;
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        return -1; // Assuming -1 as an invalid vertex
    }
    node_* tmp = q->front;
    q->front = tmp->next;
    int num = tmp->num;
    free(tmp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return num;
}

int isQueueEmpty(queue* q) {
    return (q->front == NULL);
}

void printQueue(queue* q, int x, int y) {
    node_* tmp = q->front;
    gotoxy(x, y);
    printf("                           ");
    gotoxy(x, y);
    printf("Queue : ");
    while (tmp) {
        printf("%2d", tmp->num);
        tmp = tmp->next;
    }
}

void BFS_queue(graph* g, int src, int x, int y) {
    int* visitedQueue = (int*)malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; i++) {
        visitedQueue[i] = 0;
    }
    queue q;
    q.front = q.rear = NULL;

    enqueue(&q, src);
    visitedQueue[src] = 1;

    while (!isQueueEmpty(&q)) {
        while (1) {
            if (KeyControl() == ENTER) {
                break;
            }
            else {
                continue;
            }
        }
        gotoxy(x, y + 3);
        printf("visitedQueue :");
        for (int i = 0; i < 7; i++) {
            printf("%3d", visitedQueue[i]);
        }
        printQueue(&q, x, y);
        int dequeueData = dequeue(&q);
        gotoxy(x, y + 2);
        printf("Removed data: %4d\n", dequeueData);

        node* tmp = g->head[dequeueData].next;
        while (tmp) {
            if (visitedQueue[tmp->vertex] == 0) {
                enqueue(&q, tmp->vertex);
                visitedQueue[tmp->vertex] = 1;
            }

            tmp = tmp->next;
        }
    }

    free(visitedQueue);
}

int main() {

    //HFrame();
    DrawStart();

    return 0;
}

int MenuCursor(int* x, int* y, int c, int move) {
    int originalX = *x;
    int originalY = *y;

    while (1) {

        int key = KeyControl();

        if (key == UP && *y > originalY) {
            gotoxy(*x, *y);
            printf("  ");
            gotoxy(*x, (*y) -= move);
            printf("▶");
        }
        else if (key == DOWN && *y < (originalY + c - 1)) {
            gotoxy(*x, *y);
            printf("  ");
            gotoxy(*x, (*y) += move);
            printf("▶");
        }
        else if (key == ENTER) {
            return 1;
        }

    }
}
void gotoxy(int x, int y) {
    HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandel, pos);
}
int KeyControl() {
    int key = _getch();
    if (key == 224) {
        key = _getch(); // 두 번째 입력을 받아 방향키를 식별한다.

        if (key == 72) {
            return key;
        }

        else if (key == 80) {
            return key;
        }
    }
    else if (key == ENTER) return ENTER;

    return 0;
}


void DrawStart() {

    system("mode con: cols=150 lines=50");
    //printf("\n\n\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■             ■           ■                                                                              ■\n");
    printf("■            ■ ■         ■                                     ■            ■                         ■\n");
    printf("■           ■   ■        ■                                            ■     ■                         ■\n");
    printf("■          ■      ■      ■    ■■■■    ■■■    ■  ■■   ■   ■■■   ■                         ■\n");
    printf("■         ■■■■■■     ■   ■     ■   ■     ■  ■■       ■     ■     ■■■    ■■ ■■        ■\n");
    printf("■        ■          ■    ■   ■     ■   ■     ■  ■         ■     ■     ■  ■   ■   ■   ■      ■\n");
    printf("■       ■            ■   ■    ■■■■   ■     ■  ■         ■     ■     ■  ■   ■   ■   ■      ■\n");
    printf("■       ■            ■   ■          ■   ■     ■  ■         ■     ■     ■  ■   ■        ■      ■\n");
    printf("■       ■            ■   ■          ■    ■■■    ■         ■     ■     ■  ■   ■        ■      ■\n");
    printf("■                                      ■                                                                  ■\n");
    printf("■                                ■■■                                                                    ■\n");
    printf("■       ───────────────────────────────────────────────────────────────────────────────────────            ■\n");
    printf("■                                                                                                          ■\n");
    printf("■                                                                                                          ■\n");
    printf("■                                        ┌───────────────┐                                                 ■\n");
    printf("■                                        │               │                                                 ■\n");
    printf("■                                        │               │                                                 ■\n");
    printf("■                                        │               │                                                 ■\n");
    printf("■                                        │               │                                                 ■\n");
    printf("■                                        └───────────────┘                                                 ■\n");
    printf("■                                                                                                          ■\n");
    printf("■                                                                                                          ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");


    P0_MenuDraw();
}
void DrawPage1() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 15; i++) {
        printf("■                                                              ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    P1_MenuDraw();

    gotoxy(1, 20);
}

void DrawDefinition() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 25; i++) {
        printf("■                                                                                                                                      ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    DefinitionMenuDraw();

}
void DrawCondition() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");
    printf("■                                                                                                        ■\n");;
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    ConditionMenuDraw();
}
void DrawExpression() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 12; i++) {
        printf("■                            ■\n");
    }
    printf("■■■■■■■■■■■■■■■■\n");
    ExpressionMenuDraw();
    getchar();
}

void DrawPseudoCode() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 20; i++) {
        printf("■                                                                                                        ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    PseudoCodeMenuDraw();
}
void DrawFlowchart() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 25; i++) {
        printf("■                                                                                                              ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    FlowchartMenuDraw();
}
void DrawProgrammingLanguage() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 25; i++) {
        printf("■                                                                                                                      ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    ProgrammingLanguageMenuDraw();
}

void DrawEvaluation() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 30; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("알고리즘 평가");

    gotoxy(x, y += 2);
    printf("1. 시간 복잡도(Time Complexity)");
    gotoxy(x, y += 2);
    printf(": 알고리즘의 소요 시간을 정확히 평가할 수는 없으므로, ");
    gotoxy(x, y += 2);
    printf("  자료의 수 n이 증가할 때 시간이 증가하는 대략적인 패턴을 시간 복잡도라는 이름으로 나타내게 된다.");
    gotoxy(x, y += 2);
    printf("  이를 Big-O 표기법(Big O notation)으로 주로 나타낸다.(O(n))");
    gotoxy(x, y += 2);
    printf("2. 공간 복잡도(Space Complexity)");
    gotoxy(x, y += 2);
    printf(": 공간 복잡도 역시 앞서 언급한 시간 복잡도처럼 Big-O 표기법(Big O notation)을 주로 사용한다.");
    gotoxy(x, y += 2);
    printf("  현실에서는 시간 복잡도보다 중요도는 떨어지는데, 시간이 적으면서 메모리까지 지수적으로 증가하는 경우는 없기 때문이고, ");
    gotoxy(x, y += 2);
    printf("  다항 시간 내에서 나타나는 메모리 문제들은 보통 알고리즘 자체보다는 알고리즘의 구현에서 발생하는 문제이기 때문이다.");

    gotoxy(x, y += 3);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            DrawPage1();
        }
        else {
            continue;
        }
    }
}
void DrawAlgorithmType() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 15; i++) {
        printf("■");
        for (int j = 0; j < 44; j++) {
            printf(" ");
        }
        printf("■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    AlgorithmTypeMenu();
    getchar();
}
void Sort() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 25; i++) {
        printf("■");
        for (int j = 0; j < 48; j++) {
            printf(" ");
        }
        printf("■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    SortMenu();
}
void BubbleSort() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("버블 정렬");
    gotoxy(x, y += 2);
    printf(": 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘");
    gotoxy(x, y += 1);
    printf("인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환한다.");
    gotoxy(x, y += 2);
    printf("이름의 유래로는 정렬 과정에서 원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어졌다고 한다.");

    gotoxy(x, y += 3);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 11;
    MenuCursor(&x, &y, 2, 2);
    if (y == 11) {
        BubbleFrame();
    }
    else if (y == 13) {
        Sort();
    }
}
void BubbleFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    BubbleExe();
}
void BubbleExe() {

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("버블 정렬");
    gotoxy(x, y += 3);
    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    gotoxy(x + 2, y + 7);
    printf("if( Arr[j] > Arr[j+1])");
    gotoxy(x + 2, y + 8);
    printf("{ Swap( Arr[j], Arr[j+1]); }");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < (size + 1) * 4; j++) {
                    gotoxy(x + j, y + i + 3);
                    printf(" ");
                }
            }

            gotoxy(x + ((i + 1) * 4) - 1, y + 3);
            printf("i");
            gotoxy(x + ((j + 1) * 4) - 1, y + 4);
            printf("j   j+1");

            gotoxy(x, y + 5);
            for (int k = 0; k < size; k++) {
                printf("%4d", arr[k]);
            }

            if (arr[j] > arr[j + 1]) {


                gotoxy(x + 2, y + 11);
                printf("Arr[j]\t Arr[j+1]");
                gotoxy(x + 1, y + 12);
                printf(" [ %4d \t> %4d ]  SWAP!      ", arr[j], arr[j + 1]);
                Swap(&arr[j], &arr[j + 1]);

            }
            else {
                gotoxy(x + 1, y + 12);
                printf(" [ %4d \t> %4d ]  DON'T SWAP!", arr[j], arr[j + 1]);
            }

            while (1) {
                if (KeyControl() == ENTER) {
                    break;
                }
                else {
                    continue;
                }
            }

        }
    }

    gotoxy(x + 2, y += 15);
    printf("뒤로가기(ENRER)");
    int key = KeyControl();
    while (1) {
        if (key == ENTER) {
            free(arr);
            Sort();
        }
        else {
            continue;
        }
    }

}
void SelectSort() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("선택 정렬");
    gotoxy(x, y += 2);
    printf(": 선택 정렬(Selection Sort)이란, 현재 선택된 데이터 이후의 정렬 되지 않은 데이터 중에서 ");
    gotoxy(x, y += 1);
    printf("가장 작은(혹은 가장 큰) 데이터를 선택해 현재의 데이터와 위치를 교환하는 방식으로 정렬되는 방식이다. ");
    gotoxy(x, y += 2);
    printf("순서 ");
    gotoxy(x, y += 2);
    printf("1. 주어진 리스트 중에 최소값을 찾는다.");
    gotoxy(x, y += 2);
    printf("2. 그 값을 맨 앞에 위치한 값과 교체한다(패스(pass)).");
    gotoxy(x, y += 2);
    printf("3. 맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.");
    gotoxy(x, y += 3);

    gotoxy(x, y += 3);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 20;
    MenuCursor(&x, &y, 2, 2);
    if (y == 20) {
        SelectFrame();
    }
    else if (y == 22) {
        Sort();
    }

}
void SelectFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    SelectExe();
}
void SelectExe() {

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("선택 정렬");
    gotoxy(x, y += 1);
    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }
    int min;
    gotoxy(x + 2, y + 7);
    printf("if(arr[min] > arr[j])");
    gotoxy(x + 2, y + 8);
    printf("{ min = j; }");
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            gotoxy(x, y + 3);
            printf("                         ");
            gotoxy(x + ((i + 1) * 4) - 1, y + 3);
            printf("i");
            gotoxy(x, y + 4);
            printf("                         ");
            gotoxy(x + ((j + 1) * 4) - 1, y + 4);
            printf("j");
            if (arr[min] > arr[j]) {
                min = j;
            }
            gotoxy(x, y + 5);
            for (int k = 0; k < size; k++) {
                printf("%4d", arr[k]);
            }
            gotoxy(x + 2, y + 10);
            printf("i = %d, min = %d", i, min);
            gotoxy(x + 2, y + 12);
            printf("ARR[i] = %d , ARR[Min] = %d", arr[i], arr[min]);
            gotoxy(x + 2, y + 14);
            printf("                                              ");
            int key = KeyControl();
            while (1) {
                if (key == ENTER) {
                    break;
                }
                else {
                    continue;
                }
            }
        }
        gotoxy(x + 2, y + 14);
        printf("SWAP (ARR[MIN], ARR[I])  ");
        Swap(&arr[min], &arr[i]);
        gotoxy(x, y + 5);
        for (int k = 0; k < size; k++) {
            printf("%4d", arr[k]);
        }
        int key = KeyControl();
        while (1) {
            if (key == ENTER) {
                break;
            }
            else {
                continue;
            }
        }

    }
    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }
}

void InsertSort() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("삽입 정렬");
    gotoxy(x, y += 2);
    printf(": 삽입 정렬(Insert Sort)은 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여,");
    gotoxy(x, y += 1);
    printf("자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다. ");
    gotoxy(x, y += 2);
    printf("순서 ");
    gotoxy(x, y += 2);
    printf("삽입 정렬은 두 번째 자료부터 시작하여 그 앞(왼쪽)의 자료들과 비교하여 삽입할 위치를 지정한 후");
    gotoxy(x, y += 1);
    printf("자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘이다.");
    gotoxy(x, y += 2);
    printf("두 번째 자료는 첫 번째 자료, 세 번째 자료는 두 번째와 첫 번째 자료, ");
    gotoxy(x, y += 1);
    printf("네 번째 자료는 세 번째, 두 번째, 첫 번째 자료와 비교한 후");
    gotoxy(x, y += 1);
    printf("자료가 삽입될 위치를 찾는다.");
    gotoxy(x, y += 1);
    printf("자료가 삽입될 위치를 찾았다면 그 위치에 자료를 삽입하기 위해 자료를 한 칸씩 뒤로 이동시킨다.");

    gotoxy(x, y += 2);
    printf("처음 Key 값은 두 번째 자료부터 시작한다.");

    gotoxy(x, y += 3);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 21;
    MenuCursor(&x, &y, 2, 2);
    if (y == 21) {
        InsertFrame();
    }
    else if (y == 23) {
        Sort();
    }
}
void InsertFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    InsertExe();
}
void InsertExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("삽입 정렬");
    gotoxy(x, y += 3);
    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    gotoxy(x + 2, y + 10);
    printf(" while (j>=0 && arr[j]>key)");
    gotoxy(x + 2, y + 11);
    printf("{ arr[j+1] = arr[j]; \tj--; } ");

    for (int i = 1; i < size; i++) {
        int j, key;
        j = i - 1;
        key = arr[i];
        gotoxy(x + 8, y + 14);
        printf("                            ");
        gotoxy(x + 8, y + 15);
        printf("                             ");
        gotoxy(x + 8, y + 16);
        printf("                             ");
        gotoxy(x + 8, y + 17);
        printf("                             ");
        gotoxy(x + 8, y + 18);
        printf("                             ");
        gotoxy(x + 8, y + 19);
        printf("                             ");
        gotoxy(x + 8, y + 20);
        printf("                             ");
        while (j >= 0 && arr[j] > key) {
            gotoxy(x, y + 3);
            printf("                         ");
            gotoxy(x + ((i + 1) * 4) - 1, y + 3);
            printf("key");
            gotoxy(x, y + 4);
            printf("                         ");
            gotoxy(x + ((i + 1) * 4) - 1, y + 4);
            printf("i");
            gotoxy(x - 3, y + 5);
            printf("                         ");
            gotoxy(x + ((j + 1) * 4) - 1, y + 5);
            printf("j");
            gotoxy(x, y + 7);
            PrintArr(arr, size);
            gotoxy(x + 8, y + 14);
            printf("조건 충족");
            gotoxy(x + 5, y + 16);
            printf(" arr[%d] = arr[%d]", j + 1, j);

            arr[j + 1] = arr[j];
            j--;
            gotoxy(x + 11, y + 17);
            printf(" j--");


            int Key = KeyControl();
            while (1) {

                if (Key == ENTER) {
                    break;
                }
                else {
                    continue;
                }
            }
            gotoxy(x, y + 3);
            printf("                         ");
            gotoxy(x + ((i + 1) * 4) - 1, y + 3);
            printf("key");
            gotoxy(x, y + 4);
            printf("                         ");
            gotoxy(x + ((i + 1) * 4) - 1, y + 4);
            printf("i");
            gotoxy(x, y + 5);
            printf("                         ");
            gotoxy(x + ((j + 1) * 4) - 1, y + 5);
            printf("j");
        }
        gotoxy(x + 8, y + 14);
        printf("                            ");
        gotoxy(x + 8, y + 15);
        printf("                             ");
        gotoxy(x + 8, y + 16);
        printf("                             ");
        gotoxy(x + 8, y + 17);
        printf("                             ");
        gotoxy(x + 8, y + 14);
        printf("조건문 탈출");
        gotoxy(x + 8, y + 16);
        printf("arr[j+1] = key;");
        gotoxy(x, y + 7);
        PrintArr(arr, size);
        arr[j + 1] = key;
        int Key = KeyControl();
        while (1) {

            if (Key == ENTER) {
                break;
            }
            else {
                continue;
            }
        }
        gotoxy(x, y + 7);
        PrintArr(arr, size);
    }

    gotoxy(x, y += 21);
    printf("\t\t\t\t뒤로가기(ENRER)");
    int key = KeyControl();
    while (1) {
        if (key == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }
}

int Pivot(int arr[], int left, int right, int size) {
    int x = 5;
    int y = 10;
    gotoxy(x, y + 7);
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            for (int j = -3; j < (size + 2) * 4; j++) {
                gotoxy(x + j, y + 4 + i);
                printf(" ");
            }
        }
        else {
            gotoxy(x, y + 6 + i);
            for (int j = 0; j < (size + 2) * 4; j++) {
                gotoxy(x + j, y + 6 + i);
                printf(" ");
            }
        }
    }
    int j = left - 1;
    gotoxy(x, y + 9);
    printf("if (arr[right] > arr[i])");
    for (int i = left; i < right; i++) {
        gotoxy(x, y + 14);
        printf("                                  ");
        gotoxy(x, y + 11);
        printf("                             ");
        gotoxy(x, y + 12);
        printf("                             ");
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                for (int j = -3; j < (size + 2) * 4; j++) {
                    gotoxy(x + j, y + 4 + i);
                    printf(" ");
                }
            }
            else {
                gotoxy(x, y + 4 + i);
                for (int j = 0; j < (size + 2) * 4; j++) {
                    gotoxy(x + j, y + 4 + i);
                    printf(" ");
                }
            }
        }
        gotoxy((x + 3) + ((j - left) * 4), y + 4);
        printf("j");
        gotoxy((x - 1) + ((i - left + 1) * 4), y + 5);
        printf("i");
        gotoxy((x - 1) + (right - left + 1) * 4, y + 6);
        printf("pivot");
        gotoxy(x, y + 7);
        if (arr[right] > arr[i]) {
            for (int i = 0; i < 4; i++) {
                if (i == 0) {
                    for (int j = -3; j < (size + 2) * 4; j++) {
                        gotoxy(x + j, y + 4 + i);
                        printf(" ");
                    }
                }
                else {
                    gotoxy(x, y + 4 + i);
                    for (int j = 0; j < (size + 2) * 4; j++) {
                        gotoxy(x + j, y + 4 + i);
                        printf(" ");
                    }
                }
            }
            gotoxy((x - 1) + ((i - left + 1) * 4), y + 5);
            printf("i");
            gotoxy((x + 3) + ((j - left) * 4), y + 4);
            printf("j");
            gotoxy((x - 1) + (right - left + 1) * 4, y + 6);
            printf("pivot");
            gotoxy(x, y + 7);
            QPrintArr(arr, left, right);

            gotoxy(x, y + 11);
            printf("Swap(&arr[j], &arr[i])!");
            gotoxy(x, y + 12);
            printf("j++!");
            int key2 = KeyControl();
            while (1) {
                if (key2 == ENTER) {
                    j++;
                    Swap(&arr[j], &arr[i]);

                    break;
                }
                else {
                    continue;
                }
            }

        }

        gotoxy(x, y + 11);
        printf("                             ");
        gotoxy(x, y + 12);
        printf("                             ");
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                for (int j = -3; j < (size + 2) * 4; j++) {
                    gotoxy(x + j, y + 4 + i);
                    printf(" ");
                }
            }
            else {
                gotoxy(x, y + 4 + i);
                for (int j = 0; j < (size + 2) * 4; j++) {
                    gotoxy(x + j, y + 4 + i);
                    printf(" ");
                }
            }
        }
        gotoxy((x + 3) + ((j - left) * 4), y + 4);
        printf("j");
        gotoxy((x - 1) + ((i - left + 1) * 4), y + 5);
        printf("i");
        gotoxy((x - 1) + (right - left + 1) * 4, y + 6);
        printf("pivot");
        gotoxy(x, y + 7);


        QPrintArr(arr, left, right);

        while (1) {

            gotoxy(x, y + 14);
            printf("Swap(&arr[right], &arr[j + 1])!!");
            if (KeyControl() == ENTER) {
                break;
            }
            else {
                continue;
            }
        }

    }
    Swap(&arr[right], &arr[j + 1]);
    return j + 1;
}
void Quick() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("퀵 정렬");
    gotoxy(x, y += 2);
    printf(":퀵 정렬(Quick Sort)은 컴퓨터 과학에서 사용되는 정렬 알고리즘 중 하나로,");
    gotoxy(x, y += 1);
    printf("분할 정복(divide and conquer) 방법을 기반으로 데이터를 효율적으로 정렬하는 알고리즘 중 하나입니다.  ");
    gotoxy(x, y += 2);
    printf("순서 ");
    gotoxy(x, y += 2);
    printf("1. 리스트 안의 임의의 요소 하나를 선택한다. 이를 피봇(pivot) 이라고 하자.");
    gotoxy(x, y += 2);
    printf("2. pivot을 기준으로 pivot의 왼쪽에는 pivot보다 작은 원소를, pivot의 오른쪽에는 pivot보다 큰 원소를 배치한다..");
    gotoxy(x, y += 2);
    printf("3. pivot을 기준으로 분할된 왼쪽 리스트와 오른쪽 리스트에 대해 다시 1,2의 과정을 반복한다. ");
    gotoxy(x, y += 2);
    printf("4. 이렇게 순환 과정을 통해 분할된 각 리스트의 크기가 0이나 1이 되면 수행을 종료한다.");
    gotoxy(x, y += 2);
    printf("평균적으로 매우 빠른 수행속도를 자랑한다. o(NlogN).");
    gotoxy(x, y += 1);
    printf("주어진 배열 안에서 인덱스끼리 Swap을 통해 정렬이 수행되므로 공간 효율적이다. (= 제자리 정렬)");

    gotoxy(x, y += 2);
    printf("불안정 정렬이다.(=중복 값이 입력순서와 동일하게 정렬됨을 보장하지 않는다.)");
    gotoxy(x, y += 1);
    printf("정렬된 리스트에 대해서는 O(N^2)의 수행시간을 요구한다.");

    gotoxy(x, y += 3);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 25;
    MenuCursor(&x, &y, 2, 2);
    if (y == 25) {
        QuickFrame();
    }
    else if (y == 27) {
        Sort();
    }
}
void QuickSort(int arr[], int left, int right, int size, int x, int y, int c) {


    if (left < right) {
        int pivot = Pivot(arr, left, right, size);


        if (c == 0) {
            gotoxy(x + 4 + (right - left) / 2 * 4, y += 1);
            printf("↓");

        }
        else if (c == 1) {
            gotoxy(x + 4 + (right - left) / 2 * 4, y += 2);
            printf("↙");
        }
        else {
            gotoxy(x + (right - left) / 2 * 4, y += 2);
            printf("↘");
        }


        gotoxy(x + 3 + ((pivot - left) * 4), y += 2);
        printf("P");
        gotoxy(x, y += 2);
        QPrintArr(arr, left, right);
        while (1) {
            if (KeyControl() == ENTER) {
                break;
            }
            else {
                continue;
            }
        }
        if (c == '↓') {
            QuickSort(arr, left, pivot - 1, size, x - (right - left) * 1, y, 1);
            QuickSort(arr, pivot + 1, right, size, x + (right - left) * 4, y, 2);
        }
        else {
            QuickSort(arr, left, pivot - 1, size, x - (right - left) * 1, y, 1);
            QuickSort(arr, pivot + 1, right, size, x + (right - left) * 4, y, 2);
        }

    }
    else {
        return;
    }
}
void QPrintArr(int arr[], int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("%4d", arr[i]);
    }
}
void QuickFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    QuickExe();
}
void QuickExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("퀵 정렬");
    gotoxy(x, y += 2);

    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    QuickSort(arr, 0, size - 1, size, 70, 3, 0);

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }
}

void Merge(int arr[], int left, int mid, int right, int x, int y) {
    int i = left;
    int j = mid + 1;
    int count = 0;
    int arr_c[50] = { 0 };

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            arr_c[count] = arr[i];
            count++;
            i++;
        }
        else {
            arr_c[count] = arr[j];
            count++;
            j++;
        }
    }

    while (i <= mid) {
        arr_c[count] = arr[i];
        count++;
        i++;
    }

    while (j <= right) {
        arr_c[count] = arr[j];
        count++;
        j++;
    }

    gotoxy(x, y);
    for (int i = 0; i < count; i++) {
        arr[left + i] = arr_c[i];
        printf("%4d", arr_c[i]);
    }
}
void MergeSort(int arr[], int left, int right, int size, int x, int y) {
    if (left < right) {

        int mid = (left + right) / 2;
        if (mid % 2 == 1) {
            MergeSort(arr, left, mid, size, x - (mid - left) * 4, y -= 2);
            MergeSort(arr, mid + 1, right, size, x + (right) * 4, y);
        }
        else {
            MergeSort(arr, left, mid, size, x - (mid - left) * 4, y -= 2);
            MergeSort(arr, mid + 1, right, size, x + (right) * 4, y);
        }
        Merge(arr, left, mid, right, x, (y + size));
    }

}
void MS() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("병합 정렬");
    gotoxy(x, y += 2);
    printf(":병합 정렬은 분할 정복 (Devide and Conquer) 기법과 재귀 알고리즘을 이용해서 정렬 알고리즘입니다.");
    gotoxy(x, y += 1);
    printf("주어진 배열을 원소가 하나 밖에 남지 않을 때까지 계속 둘로 쪼갠 후에");
    gotoxy(x, y += 1);
    printf(" 다시 크기 순으로 재배열 하면서 원래 크기의 배열로 합칩니다.");

    gotoxy(x, y += 2);
    printf("순서 ");
    gotoxy(x, y += 2);
    printf("1. 리스트의 길이가 1 이하이면 이미 정렬된 것으로 본다. 그렇지 않은 경우에는");
    gotoxy(x, y += 2);
    printf("2. 분할(divide): 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.");
    gotoxy(x, y += 2);
    printf("3. 정복(conquer): 각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.");
    gotoxy(x, y += 2);
    printf("4. 결합(combine): 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다. 이때 정렬 결과가 임시배열에 저장된다.");
    gotoxy(x, y += 2);
    printf("5. 복사(copy): 임시 배열에 저장된 결과를 원래 배열에 복사한다.");


    gotoxy(x, y += 2);
    printf("일반적인 방법으로 구현했을 때 이 정렬은 안정 정렬 에 속하며, 분할 정복 알고리즘의 하나 이다.");

    gotoxy(x, y += 3);

    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");

    y = 24;
    MenuCursor(&x, &y, 2, 2);
    if (y == 24) {
        MergeFrame();
    }
    else if (y == 26) {
        Sort();
    }
}
void MergeFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    MergeExe();
}
void MergeExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("병합 정렬");
    gotoxy(x, y += 2);

    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    MergeSort(arr, 0, size - 1, size, 50, 20);

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }
}

void printTree(int tree[], int heightOfTree, int size) {
    int x = 50, y = 15;

    gotoxy(x + 30, y);
    y += 3;
    printf("%2d", tree[0]);

    int count = 1;
    for (int i = 1; i <= heightOfTree; i++) {
        gotoxy(x, y);
        int spaces = (8 / i) - 1;
        for (int j = 0; j < (1 << (i - 1)); j++) {
            for (int k = spaces; k >= 0; k--) {
                printf("  ");
            }
            printf("%2d", tree[count]);
            count++;
            if (count == size) break;

            // 오른쪽 자식 출력
            for (int k = spaces * 2; k >= 0; k--) {
                printf("  ");
            }
            printf("%2d", tree[count]);
            for (int k = spaces; k > 0; k--) {
                printf("  ");
            }
            count++;
            if (count == size) break;
        }
        y += 2;
        if (size == count) break;
    }
}

void ShiftDown(int arr[], int parentIdx, int size) {
    int leftIdx = 2 * parentIdx + 1;
    int rightIdx = leftIdx + 1;
    int largeIdx = parentIdx;

    if (leftIdx < size && arr[leftIdx] > arr[largeIdx]) {
        largeIdx = leftIdx;
    }

    if (rightIdx < size && arr[rightIdx] > arr[largeIdx]) {
        largeIdx = rightIdx;
    }

    if (largeIdx != parentIdx) {
        Swap(&arr[parentIdx], &arr[largeIdx]);
        ShiftDown(arr, largeIdx, size);
    }
}

void HeapSort(int arr[], int size, int x, int y) {
    // Build heap (rearrange array)
    printTree(arr, size / 2, size);
    for (int i = size / 2 - 1; i >= 0; i--) {
        ShiftDown(arr, i, size);
        while (KeyControl() != ENTER) {}
        printTree(arr, size / 2, size);

    }

    // One by one extract an element from the heap
    for (int i = size - 1; i > 0; i--) {
        while (KeyControl() != ENTER) {}
        printTree(arr, size / 2, size);

        gotoxy(x, y);
        printf("SWAP [%d   %d]", arr[0], arr[i]);
        Swap(&arr[i], &arr[0]);
        ShiftDown(arr, 0, i);
    }

    // Print the final tree
    printTree(arr, size / 2, size);
}


void HS() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("힙 정렬");
    gotoxy(x, y += 2);
    printf(":힙 정렬(Heap sort)이란 최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법으로서,");
    gotoxy(x, y += 1);
    printf("내림차순 정렬을 위해서는 최소 힙을 구성하고 오름차순 정렬을 위해서는 최대 힙을 구성하면 된다.");


    gotoxy(x, y += 2);
    printf("순서 ");
    gotoxy(x, y += 2);
    printf("1. n개의 노드에 대한 완전 이진 트리를 구성한다. ");
    gotoxy(x, y += 1);
    printf("  이때 루트 노드부터 부모노드, 왼쪽 자식노드, 오른쪽 자식노드 순으로 구성한다.");
    gotoxy(x, y += 2);
    printf("2. 최대 힙을 구성한다. 최대 힙이란 부모노드가 자식노드보다 큰 트리를 말하는데,");
    gotoxy(x, y += 1);
    printf("   단말 노드를 자식노드로 가진 부모노드부터 구성하며 아래부터 루트까지 올라오며 순차적으로 만들어 갈 수 있다.");
    gotoxy(x, y += 2);
    printf("3. 가장 큰 수(루트에 위치)를 가장 작은 수와 교환한다.");
    gotoxy(x, y += 2);
    printf("4. 2와 3을 반복한다.");

    gotoxy(x, y += 4);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 22;
    MenuCursor(&x, &y, 2, 2);
    if (y == 22) {
        HFrame();
    }
    else if (y == 24) {
        Sort();
    }

}
void HFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    HExe();
}
void HExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("힙 정렬");
    gotoxy(x, y += 2);

    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    gotoxy(x, y += 2);
    HeapSort(arr, size, x, y);
    gotoxy(x, y + 5);
    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            free(arr);
            Sort();
        }
        else {
            continue;
        }
    }
}
void PrintArr(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%4d", arr[i]);
    }
}
void SortFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                      ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void P0_MenuDraw() {
    int x = 10;
    int y = 13;
    gotoxy(x, y);
    printf(" : 알고리즘(algorithm)은 문제 해결을 위한 단계들을 체계적으로 명시한 것을 의미한다.");
    x = 45;
    y = 17;
    gotoxy(x, y);
    printf("▶ 탐구하기");
    gotoxy(x + 3, y + 1);
    printf("  종료");


    MenuCursor(&x, &y, 2, 1);

    if (x == 45 && y == 17) {
        DrawPage1();
    }
    else if (x == 45 && y == 18) {
        system("cls");
        printf("\n\n\n\t\t프로그램이 종료되었습니다!!\n\n\n");
    }

}
void P1_MenuDraw() {
    int x = 20;
    int y = 3;
    gotoxy(x, y);
    printf("▶  1. 알고리즘이란");
    gotoxy(x, y = y + 2);

    printf("    2. 알고리즘의 조건 ");
    gotoxy(x, y = y + 2);

    printf("    3. 알고리즘의 표현 방법 ");

    gotoxy(x, y = y + 2);
    printf("    4. 알고리즘의 평가 ");

    gotoxy(x - 2, y = y + 2);
    printf("      5. 알고리즘의 종류");

    gotoxy(x, y = y + 2);
    printf("    6. 종료");

    y = 3;
    MenuCursor(&x, &y, 10, 2);

    if (y == 3) {
        DrawDefinition();
    }
    else if (y == 5) {
        DrawCondition();
    }

    else if (y == 7) {
        DrawExpression();
    }

    else if (y == 9) {
        DrawEvaluation();
    }

    else if (y == 11) {
        DrawAlgorithmType();
    }

    else if (y == 13) {
        End();
    }

}
void DefinitionMenuDraw() {
    int x = 12;
    int y = 3;
    gotoxy(x, y);
    printf("알고리즘이란");
    gotoxy(x - 1, y += 2);
    printf(":알고리즘이라는 용어는 문제를 해결하기 위한 절차나 방법을 의미하는 단어로 넓은 범위에서 사용된다.");
    gotoxy(x, y += 1);
    printf("조금 더 정확한 의미를 따져보자면 알고리즘은 어떠한 행동을 하기 위해서 만들어진 명령어들의 유한 집합(finite set)이다.");

    gotoxy(x, y += 3);
    printf("컴퓨터 프로그램은 정교한 알고리즘들의 집합이라고 간주할 수 있다.");
    gotoxy(x, y += 1);
    printf(" 수학이나 컴퓨터과학에서 말하는 알고리즘은, 보통 반복되는 문제를 풀기 위한 작은 프로시저(진행절차)를 의미한다");

    gotoxy(x, y += 3);
    printf("컴퓨터 시대 이후로는 알고리즘이라고 하면 컴퓨터를 통해 실행되는 것이라고 여겨지는 경향이 있으나,");
    gotoxy(x, y += 1);
    printf("사실 알고리즘 자체는 컴퓨터가 등장하기 이전부터도 존재했다.");
    gotoxy(x, y += 1);
    printf("즉, 사람이 수동으로 종이를 사용해 일정한 절차로 문제를 풀더라도 알고리즘에 해당한다. ");

    gotoxy(x, y += 3);
    printf("다만, 컴퓨터의 등장과 함께 알고리즘 역시 급속도로 발전하게 된 것은 사실이다.");

    gotoxy(x, y += 4);
    printf("\t\t\t\t\t▶ 뒤로가기(Enter 입력)");

    while (1) {
        int key = KeyControl();
        if (key == ENTER) {
            DrawPage1();
        }
        else {
            continue;
        }
    }
}
void ConditionMenuDraw() {
    int x = 15;
    int y = 3;
    gotoxy(x, y);
    printf("\t\t\t\t알고리즘의 조건");
    gotoxy(x, y += 2);
    printf("입력 - 알고리즘은 0 또는 그 이상의 외부에서 제공된 자료가 존재해야한다.");
    gotoxy(x, y += 2);
    printf("출력 - 알고리즘은 최소 1개 이상의 결과를 가져야한다.");
    gotoxy(x, y += 2);
    printf("명확성 - 알고리즘의 각 단계는 명확하여 애매함이 없어야 한다.");
    gotoxy(x, y += 2);
    printf("유한성 - 알고리즘은 단계들을 유한한 횟수로 거친 후 문제를 해결하고 종료해야 한다.");
    gotoxy(x, y += 2);
    printf("효과성 - 알고리즘의 모든 연산들은 사람이 종이와 연필을 이용하여 ");
    gotoxy(x, y += 2);
    printf("\t\t유한한 시간 안에 정확하게 수행할 수 있을 정도로 충분히 단순해야 한다.");
    gotoxy(x, y = y + 3);
    printf("\t\t\t\t▶ 뒤로가기(Enter 입력)");

    while (1) {
        int key = KeyControl();
        if (key == ENTER) {
            DrawPage1();
        }
        else {
            continue;
        }
    }
}
void ExpressionMenuDraw() {
    int x = 5;
    int y = 3;

    gotoxy(x, y);
    printf("▶  1. 유사 코드");
    gotoxy(x, y += 2);
    printf("    2. 순서도");
    gotoxy(x, y += 2);
    printf("    3. 프로그래밍 코드");
    gotoxy(x, y += 2);
    printf("    -  이전 페이지");

    y = 3;
    MenuCursor(&x, &y, 6, 2);

    if (y == 3) {
        DrawPseudoCode();
    }
    else if (y == 5) {
        DrawFlowchart();
    }
    else if (y == 7) {
        DrawProgrammingLanguage();
    }
    else if (y == 9) {
        DrawPage1();
    }
}
void PseudoCodeMenuDraw() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("유사 코드");
    gotoxy(x, y += 2);
    printf(": 알고리즘을 표현하는 방법 중 하나로, ");
    gotoxy(x, y += 1);
    printf("  일반적으로는 자연어를 이용해 만든 문장을 프로그래밍 언어와 유사한 형식으로 배치한 코드를 뜻한다. ");

    gotoxy(x, y += 3);
    printf("ex)\"a * b = 값\" 의 형식으로 구구단을 2단부터 9단까지 출력한다. ");
    gotoxy(x, y += 2);
    printf("  \t반복문 시작 (a를 2에서 9까지)");
    gotoxy(x, y += 1);
    printf("  \t\t반복문 시작 (b를 1에서 9까지)");
    gotoxy(x, y += 1);
    printf("  \t\t\t출력 : a * b  = 값 (개행)");
    gotoxy(x, y += 1);
    printf("  \t\t반복문 종료");
    gotoxy(x, y += 1);
    printf("  \t반복문 종료");

    gotoxy(x, y += 4);
    printf("\t\t\t\t\t뒤로가기(ENTER)");

    while (1) {
        int key = KeyControl();
        if (key == ENTER) {
            DrawExpression();
        }
        else {
            continue;
        }
    }
}
void FlowchartMenuDraw() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("순서도 (Flow Chart)");
    gotoxy(x, y += 2);
    printf(": 어떤 일을 처리하는 과정을 간단한 기호와 화살표로 도식화한 그림.");
    gotoxy(x, y += 1);
    printf("  주로 컴퓨터 프로그래밍에서 프로그램이 돌아가는 과정을 그림으로 나타낼 때 사용되는 일종의 블록선도이다.");

    gotoxy(x, y += 3);
    printf("ex) for 문 순서도 간략 표현");

    gotoxy(x, y += 2);
    printf("Start");
    gotoxy(x + 2, y += 1);
    printf("↓");
    gotoxy(x, y += 1);
    printf("for 명령문 <───────┐");
    gotoxy(x + 2, y += 1);
    printf("↓\t\t│");
    gotoxy(x, y += 1);
    printf("반복 처리문\t│");
    gotoxy(x + 2, y += 1);
    printf("↓\t\t│");
    gotoxy(x, y += 1);
    printf("카운터 증감\t│");
    gotoxy(x + 2, y += 1);
    printf("↓\t\t│");
    gotoxy(x, y += 1);
    printf("끝 값 도달  (거짓)─┘");
    gotoxy(x + 2, y += 1);
    printf("↓");
    gotoxy(x + 2, y += 1);
    printf("끝\n\n\n\t\t\t\t\t 뒤로가기(ENTER)");
    while (1) {
        int key = KeyControl();
        if (key == ENTER) {
            DrawExpression();
        }
        else {
            continue;
        }
    }
}
void ProgrammingLanguageMenuDraw() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("프로그래밍 언어 (programming language)");
    gotoxy(x, y += 2);
    printf(": 기계(컴퓨터)에게 명령이나 연산을 시킬 목적으로 설계되어 기계와 의사소통을 할 수 있게 해주는 언어를 뜻한다.");
    gotoxy(x, y += 1);
    printf("  그 결과, 사람이 원하는 작업을 컴퓨터가 수행할 수 있도록 프로그래밍 언어로 일련의 과정을 작성하여 일을 시킨다.");
    gotoxy(x, y += 1);
    printf("  쉽게 말하면 컴퓨터를 이용하기 위한 언어이다.");
    gotoxy(x, y += 1);
    printf("  이 언어들은 사람이 이해하기 쉽게 만든 언어로 실행전 컴파일러를 통해 기계어로 컴파일된 후 실행된다.");
    gotoxy(x, y += 3);
    printf("ex)\"a * b = 값\" 의 형식으로 구구단을 2단부터 9단까지 출력한다. ");
    gotoxy(x, y += 2);
    printf("#include <stdio.h>//c언어");
    gotoxy(x, y += 3);
    printf("for(int i=1; i<10; i++) {");
    gotoxy(x, y += 1);
    printf("\tfor(int j=1; j<10; j++) {");
    gotoxy(x, y += 1);
    printf("\t\tprint(\"\\%_d * \\%_d = \\%_d\",i,j \\n);");
    gotoxy(x, y += 1);
    printf("\t}");
    gotoxy(x, y += 1);
    printf("}");
    gotoxy(x, y += 2);
    printf("\t\t\t\t\t\t뒤로가기(ENTER)");
    while (1) {
        int key = KeyControl();
        if (key == ENTER) {
            DrawExpression();
        }
        else {
            continue;
        }
    }

}
void AlgorithmTypeMenu() {
    int x = 10;
    int y = 3;
    gotoxy(x + 5, y);
    printf("\t   알고리즘 종류");
    gotoxy(x, y += 3);
    printf("▶  1. 정렬(Sort)");
    gotoxy(x, y += 2);
    printf("    2. 그래프(Graph)");
    gotoxy(x, y += 2);
    printf("    - 뒤로가기(ENTER)");
    y = 6;
    MenuCursor(&x, &y, 4, 2);

    if (y == 6) {
        Sort();
    }
    else if (y == 8) {
        GraphMenu();
    }
    else if (y == 10) {
        DrawPage1();
    }

}
void SortMenu() {
    int x = 10;
    int y = 3;
    gotoxy(x + 5, y);
    printf("\t   정렬 종류");
    gotoxy(x, y += 3);
    printf("▶  1. 버블 정렬(Bubble Sort)");
    gotoxy(x, y += 2);
    printf("    2. 선택 정렬(Select Sort)");
    gotoxy(x, y += 2);
    printf("    3. 삽입 정렬(Insert Sort)");
    gotoxy(x, y += 2);
    printf("    4. 퀵 정렬(Quick Sort)");
    gotoxy(x, y += 2);
    printf("    5. 병합 정렬(Merge Sort)");
    gotoxy(x, y += 2);
    printf("    6. 힙 정렬(Heap Sort)");
    gotoxy(x, y += 2);
    printf("    7. 기수 정렬(Radix Sort)");
    gotoxy(x, y += 2);
    printf("    8. 쉘 정렬(Shell Sort)");
    gotoxy(x, y += 2);
    printf("    - 뒤로가기(ENTER)");
    y = 6;
    MenuCursor(&x, &y, 16, 2);

    if (y == 6) {
        BubbleSort();

    }
    else if (y == 8) {
        SelectSort();
    }
    else if (y == 10) {
        InsertSort();
    }
    else if (y == 12) {
        Quick();
    }
    else if (y == 14) {
        MS();
    }
    else if (y == 16) {
        HS();
    }
    else if (y == 18) {
        RadixSort();
    }
    else if (y == 20) {
        ShellSort();
    }

    else if (y == 22) {
        DrawAlgorithmType();
    }
}
void RadixSort() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("기수 정렬(RadixSort)");
    gotoxy(x, y += 2);
    printf(": 기수 정렬(radix sort)은 기수 별로 비교 없이 수행하는 정렬 알고리즘이다. ");
    gotoxy(x, y += 2);
    printf("  기수로는 정수, 낱말, 천공카드 등 다양한 자료를 사용할 수 있으나 크기가 유한하고 사전순으로 정렬할 수 있어야 한다. ");
    gotoxy(x, y += 2);
    printf("  버킷 정렬의 일종으로 취급되기도 한다. ");
    gotoxy(x, y += 3);
    printf("기수 정렬의 시간복잡도는 O(nw)이다.여기서 n은 키의 수이고 w는 키의 길이이다.");
    gotoxy(x, y += 2);
    printf("LSD는 위에서 설명한대로 가변 길이 키를 여러 무리로 분할하면 w에 대한 하한인 평균 키 길이를 달성할 수 있다. ");
    gotoxy(x, y += 3);
    printf("정렬 방식");
    gotoxy(x, y += 2);
    printf("1. 0~9 까지의 Bucket(Queue 자료구조의)을 준비한다.");
    gotoxy(x, y += 2);
    printf("2. 모든 데이터에 대하여 가장 낮은 자리수에 해당하는 Bucket에 차례대로 데이터를 둔다.");
    gotoxy(x, y += 2);
    printf("3. 0부터 차례대로 버킷에서 데이터를 다시 가져온다.");
    gotoxy(x, y += 2);
    printf("4. 가장 높은 자리수를 기준으로 하여 자리수를 높여가며 2번 3번 과정을 반복한다.");

    gotoxy(x, y += 3);
    printf("특징");
    gotoxy(x, y += 2);
    printf("1. 시간 복잡도는 O(dn)");
    gotoxy(x, y += 2);
    printf("2. 자리수가 고정되어 있어서 안정성이 있는 정렬 방식");

    gotoxy(x, y += 4);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 36;
    MenuCursor(&x, &y, 2, 2);
    if (y == 36) {
        RadixSortEXE();
    }
    else if (y == 38) {
        Sort();
    }
}
void RadixSortEXE() {
     system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y += 2);
    printf("기수 정렬 ");
    gotoxy(x, y += 2);
    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    RS(arr, size, x, y);

    gotoxy(x, y += 10);
    printf("정렬된 배열 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    gotoxy(x + 28, y+=2);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }



}
void RS(int* a, int n,int x,int y) {
    int result[100] = {}; 
    int maxValue = 0;
    int exp = 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxValue) maxValue = a[i];
    }
    while (maxValue / exp > 0) { // 1의 자릿수 계산
        
        int bucket[10] = { 0 };
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // 자릿수 배열 처리
        for (int i = 1; i < 10; i++)bucket[i] += bucket[i - 1]; // 누적 계산 : 결과 배열을 만들기 위해서!	
        for (int i = n - 1; i >= 0; i--) { //같은 자릿수 끼리는 순서를 유지
            result[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (int i = 0; i < n; i++) a[i] = result[i]; // 기본 배열 갱신
        exp *= 10;
        gotoxy(x, y += 2);
        printf("%d 번째 정렬 : ",c);
        for (int i = 0; i < n; i++) {
            printf("%4d", a[i]);
        }
        while (1) {
            if (KeyControl() == ENTER) {
                break;
            }

        }
        c++;
    }
}
void ShellSort() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("셸 정렬(shell sort)");
    gotoxy(x, y += 2);
    printf(": Donald L. Shell’이라는 사람이 제안한 방법으로, 삽입정렬을 보완한 알고리즘이다. ");
    gotoxy(x, y += 2);
    printf("  기수로는 정수, 낱말, 천공카드 등 다양한 자료를 사용할 수 있으나 크기가 유한하고 사전순으로 정렬할 수 있어야 한다.");
    gotoxy(x, y += 2);
    printf("  버킷 정렬의 일종으로 취급되기도 한다");
    gotoxy(x, y += 3);
    printf("기수 정렬의 시간복잡도는 O(nw)이다.여기서 n은 키의 수이고 w는 키의 길이이다");
    gotoxy(x, y += 2);
    printf(".LSD는 위에서 설명한대로 가변 길이 키를 여러 무리로 분할하면 w에 대한 하한인 평균 키 길이를 달성할 수 있다. ");
    gotoxy(x, y += 3);
    printf("정렬 방식");
    gotoxy(x, y += 2);
    printf("1.정렬할 배열의 요소를 그룹으로 나눠 각 그룹별로 삽입 정렬 수행");
    gotoxy(x, y += 2);
    printf("2. 그 그룹을 합치면서 정렬을 반복하여 요소의 이동 횟수를 줄인다.");
    gotoxy(x, y += 2);
    printf("3. 위의 과정을 그룹의 개수가 1이 될 때까지 반복한다.");

    gotoxy(x, y += 3);
    printf("특징");
    gotoxy(x, y += 2);
    printf("1. 정렬을 마쳤거나 정렬을 마친 상태에 가까우면 정렬 속도가 매우 빨라진다.(장점)");
    gotoxy(x, y += 2);
    printf("2. 삽입할 위치가 멀리 떨어져 있으면 이동해야 하는 횟수가 많아진다. (단점)");


    gotoxy(x, y += 4);
    printf("▶  실습하기");
    gotoxy(x, y += 2);
    printf("    돌아가기");
    gotoxy(x, y += 2);
    printf("    (방향키 · ENTER) 조작");
    y = 34;
    MenuCursor(&x, &y, 2, 2);
    if (y == 34) {
        ShellEXE();
    }
    else if (y == 36) {
        Sort();
    }
}
void ShellEXE() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y += 2);
    printf("쉘 정렬 ");
    gotoxy(x, y += 2);
    int size;
    printf("실습) 원하는 배열의 크기를 입력하시오 : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("배열의 원소를 입력하시오 :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    SS(arr, size, x, y);

    gotoxy(x, y += 10);
    printf("정렬된 배열 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    gotoxy(x + 28, y += 2);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            Sort();
        }
        else {
            continue;
        }
    }
}
void SS(int arr[], int size,int x,int y) {
    int i, j, key, t;
    int c = 0;
    for (t = size / 2; t >= 1; t /= 2) {
        for (i = t; i < size; i++) {
            key = arr[i];
            for (j = i - t; j >= 0; j -= t) {
                if (key >= arr[j]) break;
                arr[j + t] = arr[j];
            }
            arr[j + t] = key;
        }
        gotoxy(x, y += 2);
        printf("%d 번째 정렬 된 배열 : ",c);
        for (int k = 0; k < size; k++) {
            printf("%3d", arr[k]);
        }
        c++;
    }
}
void GraphFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 40; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void GraphMenu() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 15; i++) {
        printf("■                                                              ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 20;
    int y = 3;
    gotoxy(x, y);
    printf("▶  1. 그래프의 정의");
    gotoxy(x, y = y + 2);

    printf("    2. 그래프 용어 ");
    gotoxy(x, y = y + 2);

    printf("    3. 그래프 구현 방법 ");

    gotoxy(x, y = y + 2);
    printf("    4. 그래프의 종류 ");

    gotoxy(x, y = y + 2);
    printf("    5. 그래프의 탐색 기법");

    gotoxy(x, y = y + 2);
    printf("    -  뒤로가기");

    y = 3;
    MenuCursor(&x, &y, 10, 2);

    if (y == 3) {
        IsGraph();
    }
    else if (y == 5) {
        GraphTerm();
    }

    else if (y == 7) {
        GraphRealize();
    }

    else if (y == 9) {
        GraphType();
    }

    else if (y == 11) {
        GraphSearchFrame();
    }

    else if (y == 13) {
        DrawAlgorithmType();
    }
}
void IsGraph() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 15; i++) {
        printf("■                                                                              ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph)");
    gotoxy(x, y += 2);
    printf(": 그래프는 정점(Vertex)과 정점들을 연결하는 변(Edge)으로 구성이 된다.");
    gotoxy(x, y += 1);
    printf("  일반적으로 정점은 원으로 표현하고 변은 화살표나 선분으로 표현한다. ");

    gotoxy(x, y += 2);

    printf("그래프(graph)G는 꼭짓점의 집합 V와 변의 집합 E의 순서쌍으로 정의된다.");
    gotoxy(x, y += 1);
    printf("G≡(V, E)");
    gotoxy(x + 20, y += 3);
    printf("뒤로가기(ENTER)");
    while (true)
    {
        if (KeyControl() == ENTER) {
            GraphMenu();
        }
    }
}
void GraphTerm() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 35; i++) {
        printf("■                                                                                                                      ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph) 용어");
    gotoxy(x, y += 3);
    printf("1. 정점(vertice) : 노드(node)라고도 하며 정점에는 데이터가 저장됩니다.");
    gotoxy(x, y += 3);
    printf("2. 간선(edge): 링크(arcs)라고도 하며 노드간의 관계를 나타냅니다.");
    gotoxy(x, y += 3);
    printf("3. 인접 정점(adjacent vertex) : 간선에 의해 연결된 정점으로 위에서 (정점0과 정점1은 인접 정점)");
    gotoxy(x, y += 3);
    printf("4. 단순 경로(simple-path): 경로 중 반복되는 정점이 없는것, 같은 간선을 자나가지 않는 경로");
    gotoxy(x, y += 3);
    printf("5. 차수(degree): 무방향 그래프에서 하나의 정점에 인접한 정점의 수");
    gotoxy(x, y += 3);
    printf("6. 진출 차수(out-degree) : 방향그래프에서 사용되는 용어로 한 노드에서 외부로 향하는 간선의 수를 뜻합니다.");
    gotoxy(x, y += 3);
    printf("7. 진입차수(in-degree) : 방향그래프에서 사용되는 용어로 외부 노드에서 들어오는 간선의 수를 뜻합니다.");

    gotoxy(x + 30, y += 5);
    printf("\t뒤로가기(ENTER)");
    while (true)
    {
        if (KeyControl() == ENTER) {
            GraphMenu();
        }
    }
}
void AdjacencyMaterix() {
    GraphFrame();
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph) 구현 방법");
    gotoxy(x, y += 2);
    printf("그래프를 구현하는 방법에는 인접행렬(Adjacency Materix)와 인접리스트(Adjacency List)방식이 있습니다.");

    gotoxy(x, y += 2);
    printf("1. 인접행렬 방식(Adjacency Materix)");
    gotoxy(x, y += 1);
    printf(" : 인접 행렬은 그래프의 연결 관계를 이차원 배열로 나타내는 방식입니다.");

    gotoxy(x, y += 2);
    printf("1-------3");
    gotoxy(x, y += 1);
    printf("|       |");
    gotoxy(x, y += 1);
    printf("|       |");
    gotoxy(x, y += 1);
    printf("|       |");
    gotoxy(x, y += 1);
    printf("2-------4");

    int arr[4][4] = {};
    arr[0][2] = 1;
    arr[2][0] = 1;

    arr[1][3] = 1;
    arr[3][1] = 1;

    arr[2][3] = 1;
    arr[3][2] = 1;

    arr[0][1] = 1;
    arr[1][0] = 1;

    gotoxy(x, y -= 4);
    for (int i = 0; i < 4; i++) {
        gotoxy(x + 20 + i * 4, y);
        printf("%4d", i + 1);
    }
    y += 2;
    for (int i = 0; i < 4; i++) {
        gotoxy(x + 16, y);
        printf("%4d", i + 1);
        for (int j = 0; j < 4; j++) {
            gotoxy(x + 20 + j * 4, y);
            printf("%4d", arr[i][j]);
        }
        y += 2;
    }

    gotoxy(x, y += 2);
    printf("장점 1. 2차원 배열 안에 모든 정점들의 간선 정보를 담기 때문에 ");
    gotoxy(x, y += 1);
    printf("       배열의 위치를 확인하면 두 점에 대한 연결 정보를 조회할 때 O(1) 의 시간 복잡도면 가능합니다.");
    gotoxy(x, y += 2);
    printf("     2. 구현이 비교적 간단하다");


    gotoxy(x, y += 2);
    printf("단점 1. 모든 정점에 대해 간선 정보를 대입해야 하므로  ");
    gotoxy(x, y += 1);
    printf("       O(n²) 의 시간복잡도가 소요됩니다");
    gotoxy(x, y += 2);
    printf("     2.  무조건 2차원 배열이 필요하기에 필요 이상의 공간이 낭비됩니다.");
    gotoxy(x + 25, y += 3);
    printf("     \t 돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphRealize();
        }
    }
}
void AdjacencyList() {
    GraphFrame();
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph) 구현 방법");
    gotoxy(x, y += 2);
    printf("그래프를 구현하는 방법에는 인접행렬(Adjacency Materix)와 인접리스트(Adjacency List)방식이 있습니다.");

    gotoxy(x, y += 2);
    printf("2.인접리스트 방식(Adjacency List)");
    gotoxy(x, y += 1);
    printf(" : 그래프의 각 노드에 인접한 노드들을 연결리스트(Linked List)로 표현하는 방법이다.");
    gotoxy(x, y += 1);
    printf("   노드의 개수만큼 인접리스트가 존재하며, 각각의 인접리스트에는 인접한 노드 정보가 저장된다.");
    gotoxy(x, y += 1);
    printf("   그래프는 각 인접리스트에 대한 헤드포인터를 배열로 갖는다.");


    graph g;
    graphinit(&g, 5);
    AddEdge(&g, 2, 1);
    AddEdge(&g, 2, 4);
    AddEdge(&g, 4, 1);
    AddEdge(&g, 4, 3);
    AddEdge(&g, 3, 1);


    gotoxy(x, y += 2);
    printf("1<-------3");
    gotoxy(x, y += 1);
    printf("↑↖    ↑");
    gotoxy(x, y += 1);
    printf("┃   ＼  ┃");
    gotoxy(x, y += 1);
    printf("┃     ＼┃");
    gotoxy(x, y += 1);
    printf("2------->4");

    gotoxy(x, y += 2);
    PrintGraph(&g, 5, x, y, 1);


    gotoxy(x, y += 6);
    printf("장점 1.존재하는 간선만 관리하면 되므로 메모리 사용 측면에서 보다 효율적이다. ");
    gotoxy(x, y += 2);
    printf("     2. 그래프의 모든 간선의 수를 알아내려면 각 정점의 헤더 노드부터 모든 인접리스트를 탐색해야 하므로 O(n+e)의 시간이 소요된다.");


    gotoxy(x, y += 2);
    printf("단점 1. 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서는 정점의 인접 리스트를 탐색해야 하므로 ");
    gotoxy(x, y += 1);
    printf("      정점의 차수만큼의 시간이 필요하다. O(degree(v))");
    gotoxy(x, y += 2);
    printf("     2. 구현이 비교적 어렵다..");
    gotoxy(x + 25, y += 3);
    printf("     \t 돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphRealize();
        }
    }

}
void GraphRealize() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 15; i++) {
        printf("■                                                                                                              ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph) 구현 방법");
    gotoxy(x, y += 2);
    printf("그래프를 구현하는 방법에는 인접행렬(Adjacency Materix)와 인접리스트(Adjacency List)방식이 있습니다.");

    gotoxy(x, y += 2);
    printf("▶ 1. 인접행렬 방식(Adjacency Materix)");
    gotoxy(x, y += 2);
    printf("   2. 인접리스트(Adjacency List)");
    gotoxy(x, y += 2);
    printf("      -돌아가기");
    y = 7;
    MenuCursor(&x, &y, 4, 2);

    if (y == 7) {
        AdjacencyMaterix();
    }
    else if (y == 9) {
        AdjacencyList();
    }
    else {

        GraphMenu();
    }
}
void GraphType() {
    system("mode con: cols=150 lines=90");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 65; i++) {
        printf("■                                                                                                                            ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프(Graph) 종류");
    gotoxy(x, y += 2);
    printf("1. 무방향 그래프 (Non-Directed Graph)");
    gotoxy(x, y += 2);
    printf(": 무방향 그래프의 간선은 간선을 통해서 양 방향으로 이동할 수 있다.");

    gotoxy(x, y += 3);
    printf("2. 방향 그래프 (Directed Graph)");
    gotoxy(x, y += 2);
    printf(": 간선의 방향성이 존재하는 그래프이다. 방향 그래프의 간선은 주어진 방향으로만 이동할 수 있다.");
    gotoxy(x, y += 3);
    printf("3. 가중치 그래프 (Weighed Graph)");
    gotoxy(x, y += 2);
    printf(": 두 정점을 연결하는 간선에 비용이나 가중치가 할당된 그래프, 네트워크라고도 한다");
    gotoxy(x, y += 3);
    printf("4. 완전 그래프 (Complete Graph)");
    gotoxy(x, y += 2);
    printf(": 그래프에 속해 있는 모든 정점이 서로 연결되어 있는 그래프, 정점의 수를 n이라고 할 때, 간선의 수는 n * (n-1) / 2이다.");
    gotoxy(x, y += 3);
    printf("5. 다중 그래프 (Multi Graph)");
    gotoxy(x, y += 2);
    printf(": 두 정점 사이에 두 개 이상의 간선이 연결되어 있는 그래프");
    gotoxy(x, y += 3);
    printf("6. 부분 그래프 (Sub Graph)");
    gotoxy(x, y += 2);
    printf(": 기존 그래프에서 특정 간선을 제외하여 만든 그래프 ");
    gotoxy(x, y += 3);
    printf("7. 연결 그래프 (Connected Graph)");
    gotoxy(x, y += 2);
    printf(": 무방향 그래프에 있는 모든 정점 쌍에 대해서 항상 경로가 존재하는 그래프");
    gotoxy(x, y += 2);
    printf("  컴포넌트가 단 하나인 경우이다.예를 들어 트리(Tree)는 사이클이 없는 연결 그래프이다. ");
    gotoxy(x, y += 3);
    printf("8. 비연결 그래프 (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": 무방향 그래프에서 특정 정점쌍 사이에 경로가 존재하지 않는 그래프");
    gotoxy(x, y += 3);
    printf("9. 순환 VS 비순환 그래프 (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": 사이클을 가지고 있으면 순환 그래프이고, 그렇지 않으면 비순환 그래프이다.");
    gotoxy(x, y += 3);
    printf("10. 희소 VS 밀집 그래프 (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": 희소 그래프는 노드수보다 간선의 수가 적은 그래프이다");
    gotoxy(x, y += 2);
    printf("  밀집 그래프는 노드 수보다 간선의 수가 더 많은 그래프이다.");

    gotoxy(x + 20, y += 3);
    printf("뒤로가기(ENTER)");
    while (true)
    {
        if (KeyControl() == ENTER) {
            GraphMenu();
        }
    }
}
void GraphSearchFrame() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 30; i++) {
        printf("■");
        for (int j = 0; j < 62; j++) {
            printf(" ");
        }
        printf("■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    GraphSearch();
    getchar();
}
void GraphSearch() {
    int x = 10;
    int y = 3;
    gotoxy(x + 5, y);
    printf("\t   알고리즘 종류");
    gotoxy(x, y += 3);
    printf("▶  1. 깊이 우선 탐색(DFS, Depth-First Search)");
    gotoxy(x, y += 2);
    printf("    2. 너비 우선 탐색(BFS, Breadth-First Search)");
    gotoxy(x, y += 2);
    printf("    3. 크루스칼 알고리즘(Kruskal Algorithm)");
    gotoxy(x, y += 2);
    printf("    4. 프림(Prim)");
    gotoxy(x, y += 2);
    printf("    5. A* 알고리즘(A* Algorithm)");
    gotoxy(x, y += 2);
    printf("    6. 위상 정렬(Topological Sorting)");
    gotoxy(x, y += 2);
    printf("    7. 백트래킹(Back-tracking)");
    gotoxy(x, y += 2);
    printf("    8. 분기한정(Branch and Bound)");
    gotoxy(x, y += 2);
    printf("    - 뒤로가기(ENTER)");
    y = 6;
    MenuCursor(&x, &y, 16, 2);
    ;
    if (y == 6) {
        DFS();
    }
    else if (y == 8) {
        BFS();
    }
    else if (y == 10) {
        Kruskal();
    }
    else if (y == 12) {
        Prim();
    }
    else if (y == 14) {
        AStar();
    }
    else if (y == 16) {
        TopologicalSorting();
    }
    else if (y == 18) {
        Backtracking();
    }
    else if (y == 20) {
        BranchandBound();
    }
    else {
        GraphMenu();
    }

}
void BranchandBound() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 35; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf(" 분기한정(Branch and Bound)");
    gotoxy(x, y += 2);
    printf(": 분기를 한정시켜 쓸데없는 시간 낭비를 줄이는 방법");
    gotoxy(x, y += 2);
    printf("  백트래킹에서 부가적으로 발생한 알고리즘 설계 기법 백트래킹이 허용되는 탐색에서 더 이상 탐색할 필요가 없는 지점을 판단하는 것.");

    gotoxy(x, y += 3);
    printf("Branch & Bound 원리");
    gotoxy(x, y += 2);
    printf(" 각 노드를 방문할 때 마다, 그 노드가 유망한지의 여부를 결정하기 위해서 한계치(bound)를 계산한다.");
    gotoxy(x, y += 2);
    printf("   -한계치는 그 노드로부터 가지를 뻗어나가서(branch) 얻을 수 있는 해답치의 한계를 나타낸다.");
    gotoxy(x, y += 2);
    printf("   -한계치가 이전까지 찾은 최고 해답값보다 더 좋으면 그 마디는 유망하다(Promising).");

    gotoxy(x, y += 3);
    printf("Backtracking과의 공통점 및 차이점");
    gotoxy(x, y += 2);
    printf("공통점 : 경우들을 차례로 나열하는 방법 필요");
    gotoxy(x, y += 2);
    printf("차이점 : Backtracking: 가보고 더 이상 진행이 되지 않으면 돌아온다.");
    gotoxy(x, y += 2);
    printf("         Branch&Bound: 최적해를 찾을 가능성이 없으면 분기를 하지 않는다. ");

    gotoxy(x + 28, y += 2);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }

}
void DFS() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("깊이 우선 탐색(DFS, Depth-First Search)");
    gotoxy(x, y += 2);
    printf(": DFS는 깊이 우선 탐색이라는 그 이름답게 그래프의 깊은 부분을 우선적으로 탐색하는 알고리즘");
    gotoxy(x, y += 2);
    printf("  스택 자료구조를 사용하여 그래프의 가장 깊은 곳까지 방문한 뒤 다시 돌아가 다른 경로를 탐색");

    gotoxy(x, y += 3);
    printf("구체적인 동작 과정");
    gotoxy(x, y += 2);
    printf("1. 탐색 시작 노드를 스택에 삽입하고 방문 처리, 이미 방문했던 노드를 재방문하지 않기 위해");
    gotoxy(x, y += 2);
    printf("2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있다면 그 노드를 스택에 넣고 방문 처리");
    gotoxy(x, y += 2);
    printf("   만약 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼냄");
    gotoxy(x, y += 2);
    printf("3. 두번째 과정을 더 이상 수행할 수 없을 때까지 반복");

    gotoxy(x, y += 3);
    printf("DFS의 시간 복잡도는 O(N)");

    gotoxy(x, y += 3);
    printf("장점");
    gotoxy(x, y += 2);
    printf("1. 단지 현 경로상의 노드들만을 기억하면 되므로 저장 공간의 수요가 비교적 적다.");
    gotoxy(x, y += 2);
    printf("2. 목표 노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있다.");

    gotoxy(x, y += 3);
    printf("단점");
    gotoxy(x, y += 2);
    printf("1. 해가 없는 경로에 깊이 빠질 가능성이 있다. ");
    gotoxy(x, y += 2);
    printf("  따라서 실제로는 미리 지정한 임의 깊이까지만 탐색하고 목표 노드를 발견하지 못하면 다음 경로를 따라 탐색하는 방법이 유용할 수 있다.");
    gotoxy(x, y += 2);
    printf("2. 얻어진 해가 최단 경로가 된다는 보장이 없다.이는 목표에 이르는 경로가 다수인 문제에 대해 깊이우선탐색은 해에 다다르면 탐색을 끝내버리므로,");
    gotoxy(x, y += 2);
    printf("   이때 얻어진 해는 최적이 아닐 수 있다는 의미이다");
    gotoxy(x + 25, y += 3);

    gotoxy(x, y += 2);
    printf("▶ 1. 과정보기");
    gotoxy(x, y += 2);
    printf("   2. 돌아가기");
    y = 44;
    MenuCursor(&x, &y, 2, 2);

    if (y == 44) {
        DFSEXE();
    }
    else if (y == 46) {
        GraphSearchFrame();
    }
}
void DFSEXE() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("깊이 우선 탐색(DFS, Depth - First Search) 과정");
    graph g;
    graphinit(&g, 7);
    AddEdge(&g, 0, 1);
    AddEdge(&g, 0, 2);
    AddEdge(&g, 0, 3);
    AddEdge(&g, 1, 4);
    AddEdge(&g, 4, 7);
    AddEdge(&g, 2, 5);
    AddEdge(&g, 3, 6);
    AddEdge(&g, 5, 7);
    AddEdge(&g, 6, 7);

    gotoxy(x, y += 2);
    printf("    0    ");
    gotoxy(x, y += 2);
    printf("↙  ↓  ↘");
    gotoxy(x, y += 2);
    printf("1   2   3");
    gotoxy(x, y += 2);
    printf("↓  ↓  ↓");
    gotoxy(x, y += 2);
    printf("4   5   6");
    gotoxy(x, y += 2);
    printf("↘ ↓ ↙");
    gotoxy(x, y += 2);
    printf("    7    ");


    gotoxy(x, y += 5);
    PrintGraph(&g, 7, x, y, 0);
    y += 10;
    DFS_stack(&g, 0, x, y);;

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}
void BFS() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("깊이 우선 탐색(BFS, Breadth First Search)");
    gotoxy(x, y += 2);
    printf(": 맹목적 탐색방법의 하나로 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다.");
    gotoxy(x, y += 2);
    printf("  더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은 모든 정점들에 대해서도 너비 우선 검색을 적용한다.");
    gotoxy(x, y += 2);
    printf("  OPEN List는 큐를 사용해야만 레벨 순서대로 접근이 가능하다.");

    gotoxy(x, y += 3);
    printf("구체적인 동작 과정");
    gotoxy(x, y += 2);
    printf("1. 탐색 시작 노드 정보를 큐에 삽입하고 방문 처리합니다.");
    gotoxy(x, y += 2);
    printf("2. 큐에서 노드를 꺼내 방문하지 않은 인접 노드 정보를 모두 큐에 삽입하고 방문 처리합니다.");
    gotoxy(x, y += 2);
    printf("3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복합니다.");

    gotoxy(x, y += 3);
    printf("BFS의 시간 복잡도는  O(n^2)");

    gotoxy(x, y += 3);
    printf("장점");
    gotoxy(x, y += 2);
    printf("1. 출발노드에서 목표노드까지의 최단 길이 경로를 보장한다.");

    gotoxy(x, y += 3);
    printf("단점");
    gotoxy(x, y += 2);
    printf("1. 경로가 매우 길 경우에는 탐색 가지가 급격히 증가함에 따라 보다 많은 기억 공간을 필요로 하게 된다. ");
    gotoxy(x, y += 2);
    printf("2. 해가 존재하지 않는다면 유한 그래프(finite graph)의 경우에는 모든 그래프를 탐색한 후에 실패로 끝난다.");
    gotoxy(x, y += 2);
    printf("3. 무한 그래프(infinite graph)의 경우에는 결코 해를 찾지도 못하고, 끝내지도 못한다.");


    gotoxy(x, y += 2);
    printf("▶ 1. 과정보기");
    gotoxy(x, y += 2);
    printf("   2. 돌아가기");
    y = 37;
    MenuCursor(&x, &y, 2, 2);

    if (y == 37) {
        BFSEXE();
    }
    else if (y == 39) {
        GraphSearchFrame();
    }

}
void BFSEXE() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("깊이 우선 탐색(DFS, Depth - First Search) 과정");
    graph g;
    graphinit(&g, 7);
    AddEdge(&g, 0, 1);
    AddEdge(&g, 0, 2);
    AddEdge(&g, 0, 3);
    AddEdge(&g, 1, 4);
    AddEdge(&g, 4, 7);
    AddEdge(&g, 2, 5);
    AddEdge(&g, 3, 6);
    AddEdge(&g, 5, 7);
    AddEdge(&g, 6, 7);

    gotoxy(x, y += 2);
    printf("    0    ");
    gotoxy(x, y += 2);
    printf("↙  ↓  ↘");
    gotoxy(x, y += 2);
    printf("1   2   3");
    gotoxy(x, y += 2);
    printf("↓  ↓  ↓");
    gotoxy(x, y += 2);
    printf("4   5   6");
    gotoxy(x, y += 2);
    printf("↘ ↓ ↙");
    gotoxy(x, y += 2);
    printf("    7    ");
    gotoxy(x, y += 5);
    PrintGraph(&g, 7, x, y, 0);
    y += 10;
    BFS_queue(&g, 0, x, y);;

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}
void Kruskal() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("크루스칼 알고리즘(Kruskal Algorithm)");
    gotoxy(x, y += 2);
    printf(": 크러스컬 알고리즘(Kruskal’s algorithm)은 최소 비용 신장 부분 트리를 찾는 알고리즘이다. ");
    gotoxy(x, y += 2);
    printf("  변의 개수를 E 꼭짓점의 개수를 V 라고 하면 알고리즘은 O(ElogV)의 시간 복잡도를 가진다.");
    gotoxy(x, y += 2);
    printf("  크루스칼의 핵심은 모든 간선을 가중치 기준으로 오름차순으로 정렬하고,");
    gotoxy(x, y += 2);
    printf("  이 간선들을 순서대로 모든 정점이 연결될 때까지 연결하는 것이다.");
    gotoxy(x, y += 2);
    printf(" Union-Find 알고리즘을 이용해서 구현할 수 있고, 이를 통해 사이클이 형성되지 않으면서 모든 정점을 연결할 수 있다.");

    gotoxy(x, y += 3);
    printf("구체적인 동작 과정");
    gotoxy(x, y += 2);
    printf("1. 주어진 모든 간선을 오름차순 정렬 수행한다.");
    gotoxy(x, y += 2);
    printf("2. 정렬된 간선을 하나씩 확인하며 현재 간선이 노드 간 사이클을 발생시키는지 확인한다.");
    gotoxy(x, y += 2);
    printf("3. 사이클 발생시키지 않을 경우 최소신장트리에 포함, 사이클 발생할 경우 포함하지 않는다.");

    gotoxy(x, y += 2);
    printf("▶ 1. 과정보기");
    gotoxy(x, y += 2);
    printf("   2. 돌아가기");
    y = 24;
    MenuCursor(&x, &y, 2, 2);

    if (y == 24) {
        KruskalEXE();
    }
    else if (y == 26) {
        GraphSearchFrame();
    }
}
void KruskalEXE() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("크루스칼 알고리즘(Kruskal Algorithm) 과정");
    int E = 9;
    int V = 8;
    gotoxy(x, y += 2);
    printf("V = %d   E = %d", V, E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    gotoxy(x, y += 2);
    printf("    0     방향표시는 있지만 사실은 무방향 그래프   0       ");
    gotoxy(x, y += 2);
    printf("↙  ↓  ↘                                    ↙  ↓  ↘");
    gotoxy(x, y += 2);
    printf("1   2   3                                     1   2   3");
    gotoxy(x, y += 2);
    printf("↓  ↓  ↓                    →              ↓  ↓  ↓");
    gotoxy(x, y += 2);
    printf("4   5   6                                     4   5   6");
    gotoxy(x, y += 2);
    printf("↘  ↓  ↙                                            ↙");
    gotoxy(x, y += 2);
    printf("    7                                             7    ");


    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 11;

    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 200;

    edges[2].src = 0;
    edges[2].dest = 3;
    edges[2].weight = 1;

    edges[3].src = 1;
    edges[3].dest = 4;
    edges[3].weight = 8;

    edges[4].src = 2;
    edges[4].dest = 5;
    edges[4].weight = 12;

    edges[5].src = 3;
    edges[5].dest = 6;
    edges[5].weight = 5;

    edges[6].src = 6;
    edges[6].dest = 7;
    edges[6].weight = 4;

    edges[7].src = 4;
    edges[7].dest = 7;
    edges[7].weight = 2;

    edges[8].src = 5;
    edges[8].dest = 7;
    edges[8].weight = 7;


    kruskal(edges, V, E, x, y += 2);

    free(edges);

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}
void MST() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("신장 트리(ST, Spanning Tree)");
    gotoxy(x, y += 2);
    printf(": ST는 무방향 그래프 G(V,E)에서 E에 속한 간선들로 사이클을 포함하지 않으면서");
    gotoxy(x, y += 2);
    printf("  모든 정점 V를 연결한 부분 그래프를 신장 트리(Spanning Tree)라 한다.");
    gotoxy(x, y += 2);
    printf("  그래프에서 신장 트리는 여러 형태로 존재할 수 있으며,");
    gotoxy(x, y += 2);
    printf("  신장 트리의 특징은 n개의 정점을 갖는 그래프에서 신장 트리에 속하는 간선의 수는 n-1개이며 사이클을 이루지 않는다는 특징이 있다.");

    gotoxy(x, y += 3);
    printf("최소 신장 트리(MST,Minimum Spanning Tree)");
    gotoxy(x, y += 2);
    printf(": MST란 최소 비용 신장 트리(이하 최소 신장 트리)를 뜻하며, 무방향 그래프의 간선들에 가중치가 주어진 경우, ");
    gotoxy(x, y += 2);
    printf("  여러 신장 트리 중에 간선들의 가중치 합이 최소인 신장 트리를 말한다.");

    gotoxy(x, y += 2);
    printf("효율적인 통신 망 설계 등에 이용될 수 있다.");

    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}
void MSTEXE() {


}
void AStar() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("A* 알고리즘 ");
    gotoxy(x, y += 2);
    printf(": 다익스트라 알고리즘을 확장하여 만들어진 경로 탐색 알고리즘이다.");
    gotoxy(x, y += 2);
    printf("  드론이나 로봇 차량의 인공지능 주행을 구현하기 위해 개발되었다.");

    gotoxy(x, y += 3);
    printf("알고리즘 순서");

    gotoxy(x, y += 2);
    printf("1. 출발 지점을 Closed List에 집어 넣는다.");

    gotoxy(x, y += 2);
    printf("2. 출발 지점에 연결되어 있는 node들을 Open List에 추가한다. 이때 f, g, h, parent node 값을 포함해야한다.");

    gotoxy(x, y += 2);
    printf("3. Open List 중 가장 적은 F 값을 가진 Node를 Closed List에 추가한다. ");
    gotoxy(x, y += 2);
    printf("  이후, 해당 Node와 연결된 Node 중 Closed List에 존재하지 않는 Node들은 다시 f,g,h,parent Node를 갱신하거나 추가한다.");

    gotoxy(x, y += 2);
    printf("  이 때 새롭게 계산한 g값이 기존보다 클 때 f,g,h,parent node를 갱신한다");

    gotoxy(x, y += 2);
    printf("4. 이를 반복한다.");
    gotoxy(x, y += 2);
    printf("5, Closed List에 목적지 node가 추가되면 알고리즘이 종료된다.");
    gotoxy(x, y += 2);
    printf("6.  목적지 node부터 parent node를 따라 올라가게 되면 최단 경로를 파악할 수 있다.");
    gotoxy(x, y += 2);
    printf("7. 만약 목적지를 찾는 와중에 Open List가 비게된다면, 경로를 찾을 수 없는 경우가 된다.");

    gotoxy(x, y += 3);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }


}
void Prim() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("프림(Prim)");
    gotoxy(x, y += 2);
    printf(": 프림은 위에서 말한 최소 신장 트리를 구하는 알고리즘이다.");
    gotoxy(x, y += 2);
    printf("  프림은 임의의 시작점에서 현재까지 연결된 정점들에서 연결되지 않은 정점들에 대해, ");
    gotoxy(x, y += 2);
    printf("  가장 가중치가 작은 정점을 연결하는 정점 선택 기반으로 동작한다. ");
    gotoxy(x, y += 2);
    printf(" 프림의 핵심은 트리 집합을 단계적으로 확장하는 것이고, ");
    gotoxy(x, y += 2);
    printf("  새로운 정점을 연결할 때마다 새로운 정점에서 갈 수 있는 아직 연결되지 않은 정점들에 대한 간선을 추가해줘야 한다. ");
    gotoxy(x, y += 2);
    printf("  Priority Queue를 이용한 최소 힙으로 구현할 수 있고, 다익스트라 알고리즘과 구현 방식이 유사하다. ");

    gotoxy(x, y += 3);
    printf("O(ElogV)가 프림 알고리즘의 시간 복잡도가 된다.");
    gotoxy(x, y += 2);
    printf("최소 힙을 사용하지 않는 경우 O(V ^ 2)의 시간 복잡도를 가질 수 있지만, 최소 힙으로 구현하는 것이 어렵지 않다.");


    gotoxy(x, y += 3);
    printf("프림 알고리즘의 동작 방식");
    gotoxy(x, y += 2);
    printf("1. 임의의 정점을 시작점으로 선택한다.");
    gotoxy(x, y += 2);
    printf("2. 시작점에서 갈 수 있는 정점 중 가장 가중치가 작은 정점을 연결한다.");
    gotoxy(x, y += 2);
    printf("3-1. 2번 과정에서 시작점과 어떠한 정점들이 연결되었다.");
    gotoxy(x, y += 2);
    printf("3-2. 시작점과 연결된 정점들을 a집합이라 할 때, a집합에서 갈 수 있는 a집합에 속하지 않은 정점들에 대해 가중치가 가장 작은 정점을 연결한다.");
    gotoxy(x, y += 2);
    printf("a집합의 크기가 늘어났다.(시작점을 포함한 a집합에 새로운 정점을 연결했다.) 위의 과정을 모든 정점이 연결될 때까지 반복한다.");
    gotoxy(x, y += 3);
    printf("돌아가기(ENTER)");

    gotoxy(x, y += 2);
    printf("▶ 1. 과정보기");
    gotoxy(x, y += 2);
    printf("   2. 돌아가기");
    y = 38;
    MenuCursor(&x, &y, 2, 2);

    if (y == 38) {
        PrimEXE();
    }
    else if (y == 40) {
        GraphSearchFrame();
    }
}
void PrimEXE() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("프림(Prim) 과정");
    int E = 9;
    int V = 8;
    gotoxy(x, y += 2);
    printf("V = %d   E = %d", V, E);

    gotoxy(x, y += 2);
    printf("    0     방향표시는 있지만 사실은 무방향 그래프   0       ");
    gotoxy(x, y += 2);
    printf("↙  ↓  ↘                                    ↙  ↓  ↘");
    gotoxy(x, y += 2);
    printf("1   2   3                                     1   2   3");
    gotoxy(x, y += 2);
    printf("↓  ↓  ↓                  →                ↓  ↓  ↓");
    gotoxy(x, y += 2);
    printf("4   5   6                                     4   5   6");
    gotoxy(x, y += 2);
    printf("↘  ↓  ↙                                            ↙");
    gotoxy(x, y += 2);
    printf("    7                                             7    ");

    struct Edge_ edges[] = {
       {0, 1, 11}, {0, 2, 9}, {0, 3, 1},
       {1, 4, 8}, {2, 5, 12}, {3, 6, 5},
       {6, 7, 4}, {4, 7, 2}, {5, 7, 7}
    };
    gotoxy(x, y += 2);
    printf("프림 알고리즘 결과:\n");
    prim(edges, V, E, x, y += 2);



    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}
void TopologicalSorting() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 50; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("위상 정렬 (Topological Sorting)");
    gotoxy(x, y += 2);
    printf(": 정렬 알고리즘의 일종으로, 순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용할 수 있는 알고리즘이다.");
    gotoxy(x, y += 2);
    printf("  사이클이 없는 방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열하는 것'을 의미");
    gotoxy(x, y += 2);
    printf("  사이클이 없는 방향 그래프 (DAG) 이여야 한다!");

    gotoxy(x, y += 3);
    printf("위상 정렬 알고리즘 동작 과정");
    gotoxy(x, y += 2);
    printf("1. 진입차수가 0인 노드를 큐에 넣는다.");
    gotoxy(x, y += 2);
    printf("2. 큐가 빌 때까지 다음의 과정을 반복한다.");
    gotoxy(x, y += 2);
    printf("    ① 큐에서 원소를 꺼내 해당 노드에서 나가는 간선을 그래프에서 제거");
    gotoxy(x, y += 2);
    printf("    ② 새롭게 진입차수가 0이 된 노드를 큐에 삽입");


    gotoxy(x, y += 3);
    printf("위상 정렬의 특징");
    gotoxy(x, y += 2);
    printf("1. 위상 정렬은 사이클이 없는 방향 그래프 (DAG)에 대해서만 수행할 수 있다");
    gotoxy(x, y += 2);
    printf("2. 위상 정렬에서는 여러 가지 답이 존재할 수 있다.");
    gotoxy(x, y += 2);
    printf("   한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상인 경우가 있다면 여러 가지 답이 존재할 수 있다는 의미이다.");
    gotoxy(x, y += 2);
    printf("3. 모든 원소를 방문하기 전에 큐가 비게 된다면 사이클이 존재한다고 판단할 수 있다.");
    gotoxy(x, y += 2);
    printf("4. 보통 큐로 구현하나, 스택을 이용한 DFS를 이용해 위상 정렬을 구현할 수도 있다.");
    gotoxy(x + 28, 38);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}

void Backtracking() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 25; i++) {
        printf("■                                                                                                                                                  ■\n");
    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("백트래킹 (Back-tracking)");
    gotoxy(x, y += 2);
    printf(": 해를 찾는 도중에 막히면 더 이상 깊이 들어가지 않고, 이전 단계로 되돌아가서 해를 찾아나가는 기법을 말한다. ");




    gotoxy(x, y += 3);
    printf("백트래킹 알고리즘 특징");
    gotoxy(x, y += 2);
    printf(": 해를 찾아가는 도중에 지금의 경로가 해가 될 거 같지 않으면, 더 이상 깊이 들어가지 않고 이전 단계로 다시 돌아간다.");
    gotoxy(x, y += 2);
    printf("   불필요한 부분을 쳐내고 최대한 올바른 방향으로 나아가는 방식이기 때문에 DFS보다 효율적이다.");
    gotoxy(x, y += 2);

    gotoxy(x + 28, y += 2);
    printf("돌아가기(ENTER)");
    while (1) {
        if (KeyControl() == ENTER) {
            GraphSearchFrame();
        }
        else {
            continue;
        }
    }
}

void End() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("■■■■■■■■■■■■■■■■\n");
    for (int i = 0; i < 5; i++) {
        printf("■                            ■\n");
    }
    printf("■■■■■■■■■■■■■■■■\n");
    gotoxy(4, 3);
    printf("★★종료되었습니다★★");
    getchar();
}