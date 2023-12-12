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
    printf("�ּ� ���� Ʈ���� ����:");

    for (int i = 0; i < E; ++i) {

        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            gotoxy(x_, y_ += 1);
            printf("%d - %d ����ġ: %d", edges[i].src, edges[i].dest, edges[i].weight);
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
            printf("%d - %d ����ġ: %d\n", minVertex, minEdge[minVertex].src, minEdge[minVertex].weight);
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
                printf("  ��");
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
        printf("������ ������ %4d\n", popData);
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
            printf("��");
        }
        else if (key == DOWN && *y < (originalY + c - 1)) {
            gotoxy(*x, *y);
            printf("  ");
            gotoxy(*x, (*y) += move);
            printf("��");
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
        key = _getch(); // �� ��° �Է��� �޾� ����Ű�� �ĺ��Ѵ�.

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
    printf("��������������������������������������������������������\n");
    printf("��             ��           ��                                                                              ��\n");
    printf("��            �� ��         ��                                     ��            ��                         ��\n");
    printf("��           ��   ��        ��                                            ��     ��                         ��\n");
    printf("��          ��      ��      ��    �����    ����    ��  ���   ��   ����   ��                         ��\n");
    printf("��         �������     ��   ��     ��   ��     ��  ���       ��     ��     ����    ��� ���        ��\n");
    printf("��        ��          ��    ��   ��     ��   ��     ��  ��         ��     ��     ��  ��   ��   ��   ��      ��\n");
    printf("��       ��            ��   ��    �����   ��     ��  ��         ��     ��     ��  ��   ��   ��   ��      ��\n");
    printf("��       ��            ��   ��          ��   ��     ��  ��         ��     ��     ��  ��   ��        ��      ��\n");
    printf("��       ��            ��   ��          ��    ����    ��         ��     ��     ��  ��   ��        ��      ��\n");
    printf("��                                      ��                                                                  ��\n");
    printf("��                                ����                                                                    ��\n");
    printf("��       ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������            ��\n");
    printf("��                                                                                                          ��\n");
    printf("��                                                                                                          ��\n");
    printf("��                                        ����������������������������������                                                 ��\n");
    printf("��                                        ��               ��                                                 ��\n");
    printf("��                                        ��               ��                                                 ��\n");
    printf("��                                        ��               ��                                                 ��\n");
    printf("��                                        ��               ��                                                 ��\n");
    printf("��                                        ����������������������������������                                                 ��\n");
    printf("��                                                                                                          ��\n");
    printf("��                                                                                                          ��\n");
    printf("��������������������������������������������������������\n");


    P0_MenuDraw();
}
void DrawPage1() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("����������������������������������\n");
    for (int i = 0; i < 15; i++) {
        printf("��                                                              ��\n");
    }
    printf("����������������������������������\n");

    P1_MenuDraw();

    gotoxy(1, 20);
}

void DrawDefinition() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("����������������������������������������������������������������������\n");
    for (int i = 0; i < 25; i++) {
        printf("��                                                                                                                                      ��\n");
    }
    printf("����������������������������������������������������������������������\n");
    DefinitionMenuDraw();

}
void DrawCondition() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("�������������������������������������������������������\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");
    printf("��                                                                                                        ��\n");;
    printf("�������������������������������������������������������\n");

    ConditionMenuDraw();
}
void DrawExpression() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("�����������������\n");
    for (int i = 0; i < 12; i++) {
        printf("��                            ��\n");
    }
    printf("�����������������\n");
    ExpressionMenuDraw();
    getchar();
}

void DrawPseudoCode() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("�������������������������������������������������������\n");
    for (int i = 0; i < 20; i++) {
        printf("��                                                                                                        ��\n");
    }
    printf("�������������������������������������������������������\n");
    PseudoCodeMenuDraw();
}
void DrawFlowchart() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("����������������������������������������������������������\n");
    for (int i = 0; i < 25; i++) {
        printf("��                                                                                                              ��\n");
    }
    printf("����������������������������������������������������������\n");
    FlowchartMenuDraw();
}
void DrawProgrammingLanguage() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);


    printf("��������������������������������������������������������������\n");
    for (int i = 0; i < 25; i++) {
        printf("��                                                                                                                      ��\n");
    }
    printf("��������������������������������������������������������������\n");
    ProgrammingLanguageMenuDraw();
}

void DrawEvaluation() {
    system("mode con: cols=150 lines=60");
    system("cls");
    gotoxy(0, 0);
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 30; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("�˰��� ��");

    gotoxy(x, y += 2);
    printf("1. �ð� ���⵵(Time Complexity)");
    gotoxy(x, y += 2);
    printf(": �˰����� �ҿ� �ð��� ��Ȯ�� ���� ���� �����Ƿ�, ");
    gotoxy(x, y += 2);
    printf("  �ڷ��� �� n�� ������ �� �ð��� �����ϴ� �뷫���� ������ �ð� ���⵵��� �̸����� ��Ÿ���� �ȴ�.");
    gotoxy(x, y += 2);
    printf("  �̸� Big-O ǥ���(Big O notation)���� �ַ� ��Ÿ����.(O(n))");
    gotoxy(x, y += 2);
    printf("2. ���� ���⵵(Space Complexity)");
    gotoxy(x, y += 2);
    printf(": ���� ���⵵ ���� �ռ� ����� �ð� ���⵵ó�� Big-O ǥ���(Big O notation)�� �ַ� ����Ѵ�.");
    gotoxy(x, y += 2);
    printf("  ���ǿ����� �ð� ���⵵���� �߿䵵�� �������µ�, �ð��� �����鼭 �޸𸮱��� ���������� �����ϴ� ���� ���� �����̰�, ");
    gotoxy(x, y += 2);
    printf("  ���� �ð� ������ ��Ÿ���� �޸� �������� ���� �˰��� ��ü���ٴ� �˰����� �������� �߻��ϴ� �����̱� �����̴�.");

    gotoxy(x, y += 3);
    printf("���ư���(ENTER)");
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
    printf("�������������������������\n");
    for (int i = 0; i < 15; i++) {
        printf("��");
        for (int j = 0; j < 44; j++) {
            printf(" ");
        }
        printf("��\n");
    }
    printf("�������������������������\n");
    AlgorithmTypeMenu();
    getchar();
}
void Sort() {
    system("mode con: cols=150 lines=50");
    system("cls");
    printf("���������������������������\n");
    for (int i = 0; i < 25; i++) {
        printf("��");
        for (int j = 0; j < 48; j++) {
            printf(" ");
        }
        printf("��\n");
    }
    printf("���������������������������\n");
    SortMenu();
}
void BubbleSort() {
    SortFrame();

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ����");
    gotoxy(x, y += 2);
    printf(": ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���");
    gotoxy(x, y += 1);
    printf("������ 2���� ���ڵ带 ���Ͽ� ũ�Ⱑ ������� �Ǿ� ���� ������ ���� ��ȯ�Ѵ�.");
    gotoxy(x, y += 2);
    printf("�̸��� �����δ� ���� �������� ������ �̵��� ��ǰ�� �������� �ö���� ���� ����� ���̱� ������ �������ٰ� �Ѵ�.");

    gotoxy(x, y += 3);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    BubbleExe();
}
void BubbleExe() {

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ����");
    gotoxy(x, y += 3);
    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
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
    printf("�ڷΰ���(ENRER)");
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
    printf("���� ����");
    gotoxy(x, y += 2);
    printf(": ���� ����(Selection Sort)�̶�, ���� ���õ� ������ ������ ���� ���� ���� ������ �߿��� ");
    gotoxy(x, y += 1);
    printf("���� ����(Ȥ�� ���� ū) �����͸� ������ ������ �����Ϳ� ��ġ�� ��ȯ�ϴ� ������� ���ĵǴ� ����̴�. ");
    gotoxy(x, y += 2);
    printf("���� ");
    gotoxy(x, y += 2);
    printf("1. �־��� ����Ʈ �߿� �ּҰ��� ã�´�.");
    gotoxy(x, y += 2);
    printf("2. �� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�(�н�(pass)).");
    gotoxy(x, y += 2);
    printf("3. �� ó�� ��ġ�� �� ������ ����Ʈ�� ���� ������� ��ü�Ѵ�.");
    gotoxy(x, y += 3);

    gotoxy(x, y += 3);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    SelectExe();
}
void SelectExe() {

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ����");
    gotoxy(x, y += 1);
    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
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
    printf("���ư���(ENTER)");
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
    printf("���� ����");
    gotoxy(x, y += 2);
    printf(": ���� ����(Insert Sort)�� �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�,");
    gotoxy(x, y += 1);
    printf("�ڽ��� ��ġ�� ã�� ���������ν� ������ �ϼ��ϴ� �˰����̴�. ");
    gotoxy(x, y += 2);
    printf("���� ");
    gotoxy(x, y += 2);
    printf("���� ������ �� ��° �ڷ���� �����Ͽ� �� ��(����)�� �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��");
    gotoxy(x, y += 1);
    printf("�ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰����̴�.");
    gotoxy(x, y += 2);
    printf("�� ��° �ڷ�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°�� ù ��° �ڷ�, ");
    gotoxy(x, y += 1);
    printf("�� ��° �ڷ�� �� ��°, �� ��°, ù ��° �ڷ�� ���� ��");
    gotoxy(x, y += 1);
    printf("�ڷᰡ ���Ե� ��ġ�� ã�´�.");
    gotoxy(x, y += 1);
    printf("�ڷᰡ ���Ե� ��ġ�� ã�Ҵٸ� �� ��ġ�� �ڷḦ �����ϱ� ���� �ڷḦ �� ĭ�� �ڷ� �̵���Ų��.");

    gotoxy(x, y += 2);
    printf("ó�� Key ���� �� ��° �ڷ���� �����Ѵ�.");

    gotoxy(x, y += 3);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    InsertExe();
}
void InsertExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ����");
    gotoxy(x, y += 3);
    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
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
            printf("���� ����");
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
        printf("���ǹ� Ż��");
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
    printf("\t\t\t\t�ڷΰ���(ENRER)");
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
    printf("�� ����");
    gotoxy(x, y += 2);
    printf(":�� ����(Quick Sort)�� ��ǻ�� ���п��� ���Ǵ� ���� �˰��� �� �ϳ���,");
    gotoxy(x, y += 1);
    printf("���� ����(divide and conquer) ����� ������� �����͸� ȿ�������� �����ϴ� �˰��� �� �ϳ��Դϴ�.  ");
    gotoxy(x, y += 2);
    printf("���� ");
    gotoxy(x, y += 2);
    printf("1. ����Ʈ ���� ������ ��� �ϳ��� �����Ѵ�. �̸� �Ǻ�(pivot) �̶�� ����.");
    gotoxy(x, y += 2);
    printf("2. pivot�� �������� pivot�� ���ʿ��� pivot���� ���� ���Ҹ�, pivot�� �����ʿ��� pivot���� ū ���Ҹ� ��ġ�Ѵ�..");
    gotoxy(x, y += 2);
    printf("3. pivot�� �������� ���ҵ� ���� ����Ʈ�� ������ ����Ʈ�� ���� �ٽ� 1,2�� ������ �ݺ��Ѵ�. ");
    gotoxy(x, y += 2);
    printf("4. �̷��� ��ȯ ������ ���� ���ҵ� �� ����Ʈ�� ũ�Ⱑ 0�̳� 1�� �Ǹ� ������ �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("��������� �ſ� ���� ����ӵ��� �ڶ��Ѵ�. o(NlogN).");
    gotoxy(x, y += 1);
    printf("�־��� �迭 �ȿ��� �ε������� Swap�� ���� ������ ����ǹǷ� ���� ȿ�����̴�. (= ���ڸ� ����)");

    gotoxy(x, y += 2);
    printf("�Ҿ��� �����̴�.(=�ߺ� ���� �Է¼����� �����ϰ� ���ĵ��� �������� �ʴ´�.)");
    gotoxy(x, y += 1);
    printf("���ĵ� ����Ʈ�� ���ؼ��� O(N^2)�� ����ð��� �䱸�Ѵ�.");

    gotoxy(x, y += 3);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
            printf("��");

        }
        else if (c == 1) {
            gotoxy(x + 4 + (right - left) / 2 * 4, y += 2);
            printf("��");
        }
        else {
            gotoxy(x + (right - left) / 2 * 4, y += 2);
            printf("��");
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
        if (c == '��') {
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    QuickExe();
}
void QuickExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�� ����");
    gotoxy(x, y += 2);

    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    QuickSort(arr, 0, size - 1, size, 70, 3, 0);

    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("���� ����");
    gotoxy(x, y += 2);
    printf(":���� ������ ���� ���� (Devide and Conquer) ����� ��� �˰����� �̿��ؼ� ���� �˰����Դϴ�.");
    gotoxy(x, y += 1);
    printf("�־��� �迭�� ���Ұ� �ϳ� �ۿ� ���� ���� ������ ��� �ѷ� �ɰ� �Ŀ�");
    gotoxy(x, y += 1);
    printf(" �ٽ� ũ�� ������ ��迭 �ϸ鼭 ���� ũ���� �迭�� ��Ĩ�ϴ�.");

    gotoxy(x, y += 2);
    printf("���� ");
    gotoxy(x, y += 2);
    printf("1. ����Ʈ�� ���̰� 1 �����̸� �̹� ���ĵ� ������ ����. �׷��� ���� ��쿡��");
    gotoxy(x, y += 2);
    printf("2. ����(divide): ���ĵ��� ���� ����Ʈ�� �������� �߶� ����� ũ���� �� �κ� ����Ʈ�� ������.");
    gotoxy(x, y += 2);
    printf("3. ����(conquer): �� �κ� ����Ʈ�� ��������� �պ� ������ �̿��� �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("4. ����(combine): �� �κ� ����Ʈ�� �ٽ� �ϳ��� ���ĵ� ����Ʈ�� �պ��Ѵ�. �̶� ���� ����� �ӽù迭�� ����ȴ�.");
    gotoxy(x, y += 2);
    printf("5. ����(copy): �ӽ� �迭�� ����� ����� ���� �迭�� �����Ѵ�.");


    gotoxy(x, y += 2);
    printf("�Ϲ����� ������� �������� �� �� ������ ���� ���� �� ���ϸ�, ���� ���� �˰����� �ϳ� �̴�.");

    gotoxy(x, y += 3);

    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");

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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    MergeExe();
}
void MergeExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ����");
    gotoxy(x, y += 2);

    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    MergeSort(arr, 0, size - 1, size, 50, 20);

    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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

            // ������ �ڽ� ���
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
    printf("�� ����");
    gotoxy(x, y += 2);
    printf(":�� ����(Heap sort)�̶� �ִ� �� Ʈ���� �ּ� �� Ʈ���� ������ ������ �ϴ� ������μ�,");
    gotoxy(x, y += 1);
    printf("�������� ������ ���ؼ��� �ּ� ���� �����ϰ� �������� ������ ���ؼ��� �ִ� ���� �����ϸ� �ȴ�.");


    gotoxy(x, y += 2);
    printf("���� ");
    gotoxy(x, y += 2);
    printf("1. n���� ��忡 ���� ���� ���� Ʈ���� �����Ѵ�. ");
    gotoxy(x, y += 1);
    printf("  �̶� ��Ʈ ������ �θ���, ���� �ڽĳ��, ������ �ڽĳ�� ������ �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("2. �ִ� ���� �����Ѵ�. �ִ� ���̶� �θ��尡 �ڽĳ�庸�� ū Ʈ���� ���ϴµ�,");
    gotoxy(x, y += 1);
    printf("   �ܸ� ��带 �ڽĳ��� ���� �θ������ �����ϸ� �Ʒ����� ��Ʈ���� �ö���� ���������� ����� �� �� �ִ�.");
    gotoxy(x, y += 2);
    printf("3. ���� ū ��(��Ʈ�� ��ġ)�� ���� ���� ���� ��ȯ�Ѵ�.");
    gotoxy(x, y += 2);
    printf("4. 2�� 3�� �ݺ��Ѵ�.");

    gotoxy(x, y += 4);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    HExe();
}
void HExe() {
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�� ����");
    gotoxy(x, y += 2);

    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    gotoxy(x, y += 2);
    HeapSort(arr, size, x, y);
    gotoxy(x, y + 5);
    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("��������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                      ��\n");
    }
    printf("��������������������������������������������������������������\n");
}
void P0_MenuDraw() {
    int x = 10;
    int y = 13;
    gotoxy(x, y);
    printf(" : �˰���(algorithm)�� ���� �ذ��� ���� �ܰ���� ü�������� ����� ���� �ǹ��Ѵ�.");
    x = 45;
    y = 17;
    gotoxy(x, y);
    printf("�� Ž���ϱ�");
    gotoxy(x + 3, y + 1);
    printf("  ����");


    MenuCursor(&x, &y, 2, 1);

    if (x == 45 && y == 17) {
        DrawPage1();
    }
    else if (x == 45 && y == 18) {
        system("cls");
        printf("\n\n\n\t\t���α׷��� ����Ǿ����ϴ�!!\n\n\n");
    }

}
void P1_MenuDraw() {
    int x = 20;
    int y = 3;
    gotoxy(x, y);
    printf("��  1. �˰����̶�");
    gotoxy(x, y = y + 2);

    printf("    2. �˰����� ���� ");
    gotoxy(x, y = y + 2);

    printf("    3. �˰����� ǥ�� ��� ");

    gotoxy(x, y = y + 2);
    printf("    4. �˰����� �� ");

    gotoxy(x - 2, y = y + 2);
    printf("      5. �˰����� ����");

    gotoxy(x, y = y + 2);
    printf("    6. ����");

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
    printf("�˰����̶�");
    gotoxy(x - 1, y += 2);
    printf(":�˰����̶�� ���� ������ �ذ��ϱ� ���� ������ ����� �ǹ��ϴ� �ܾ�� ���� �������� ���ȴ�.");
    gotoxy(x, y += 1);
    printf("���� �� ��Ȯ�� �ǹ̸� �������ڸ� �˰����� ��� �ൿ�� �ϱ� ���ؼ� ������� ��ɾ���� ���� ����(finite set)�̴�.");

    gotoxy(x, y += 3);
    printf("��ǻ�� ���α׷��� ������ �˰������ �����̶�� ������ �� �ִ�.");
    gotoxy(x, y += 1);
    printf(" �����̳� ��ǻ�Ͱ��п��� ���ϴ� �˰�����, ���� �ݺ��Ǵ� ������ Ǯ�� ���� ���� ���ν���(��������)�� �ǹ��Ѵ�");

    gotoxy(x, y += 3);
    printf("��ǻ�� �ô� ���ķδ� �˰����̶�� �ϸ� ��ǻ�͸� ���� ����Ǵ� ���̶�� �������� ������ ������,");
    gotoxy(x, y += 1);
    printf("��� �˰��� ��ü�� ��ǻ�Ͱ� �����ϱ� �������͵� �����ߴ�.");
    gotoxy(x, y += 1);
    printf("��, ����� �������� ���̸� ����� ������ ������ ������ Ǯ���� �˰��� �ش��Ѵ�. ");

    gotoxy(x, y += 3);
    printf("�ٸ�, ��ǻ���� ����� �Բ� �˰��� ���� �޼ӵ��� �����ϰ� �� ���� ����̴�.");

    gotoxy(x, y += 4);
    printf("\t\t\t\t\t�� �ڷΰ���(Enter �Է�)");

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
    printf("\t\t\t\t�˰����� ����");
    gotoxy(x, y += 2);
    printf("�Է� - �˰����� 0 �Ǵ� �� �̻��� �ܺο��� ������ �ڷᰡ �����ؾ��Ѵ�.");
    gotoxy(x, y += 2);
    printf("��� - �˰����� �ּ� 1�� �̻��� ����� �������Ѵ�.");
    gotoxy(x, y += 2);
    printf("��Ȯ�� - �˰����� �� �ܰ�� ��Ȯ�Ͽ� �ָ����� ����� �Ѵ�.");
    gotoxy(x, y += 2);
    printf("���Ѽ� - �˰����� �ܰ���� ������ Ƚ���� ��ģ �� ������ �ذ��ϰ� �����ؾ� �Ѵ�.");
    gotoxy(x, y += 2);
    printf("ȿ���� - �˰����� ��� ������� ����� ���̿� ������ �̿��Ͽ� ");
    gotoxy(x, y += 2);
    printf("\t\t������ �ð� �ȿ� ��Ȯ�ϰ� ������ �� ���� ������ ����� �ܼ��ؾ� �Ѵ�.");
    gotoxy(x, y = y + 3);
    printf("\t\t\t\t�� �ڷΰ���(Enter �Է�)");

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
    printf("��  1. ���� �ڵ�");
    gotoxy(x, y += 2);
    printf("    2. ������");
    gotoxy(x, y += 2);
    printf("    3. ���α׷��� �ڵ�");
    gotoxy(x, y += 2);
    printf("    -  ���� ������");

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
    printf("���� �ڵ�");
    gotoxy(x, y += 2);
    printf(": �˰����� ǥ���ϴ� ��� �� �ϳ���, ");
    gotoxy(x, y += 1);
    printf("  �Ϲ������δ� �ڿ�� �̿��� ���� ������ ���α׷��� ���� ������ �������� ��ġ�� �ڵ带 ���Ѵ�. ");

    gotoxy(x, y += 3);
    printf("ex)\"a * b = ��\" �� �������� �������� 2�ܺ��� 9�ܱ��� ����Ѵ�. ");
    gotoxy(x, y += 2);
    printf("  \t�ݺ��� ���� (a�� 2���� 9����)");
    gotoxy(x, y += 1);
    printf("  \t\t�ݺ��� ���� (b�� 1���� 9����)");
    gotoxy(x, y += 1);
    printf("  \t\t\t��� : a * b  = �� (����)");
    gotoxy(x, y += 1);
    printf("  \t\t�ݺ��� ����");
    gotoxy(x, y += 1);
    printf("  \t�ݺ��� ����");

    gotoxy(x, y += 4);
    printf("\t\t\t\t\t�ڷΰ���(ENTER)");

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
    printf("������ (Flow Chart)");
    gotoxy(x, y += 2);
    printf(": � ���� ó���ϴ� ������ ������ ��ȣ�� ȭ��ǥ�� ����ȭ�� �׸�.");
    gotoxy(x, y += 1);
    printf("  �ַ� ��ǻ�� ���α׷��ֿ��� ���α׷��� ���ư��� ������ �׸����� ��Ÿ�� �� ���Ǵ� ������ ��ϼ����̴�.");

    gotoxy(x, y += 3);
    printf("ex) for �� ������ ���� ǥ��");

    gotoxy(x, y += 2);
    printf("Start");
    gotoxy(x + 2, y += 1);
    printf("��");
    gotoxy(x, y += 1);
    printf("for ��ɹ� <����������������");
    gotoxy(x + 2, y += 1);
    printf("��\t\t��");
    gotoxy(x, y += 1);
    printf("�ݺ� ó����\t��");
    gotoxy(x + 2, y += 1);
    printf("��\t\t��");
    gotoxy(x, y += 1);
    printf("ī���� ����\t��");
    gotoxy(x + 2, y += 1);
    printf("��\t\t��");
    gotoxy(x, y += 1);
    printf("�� �� ����  (����)����");
    gotoxy(x + 2, y += 1);
    printf("��");
    gotoxy(x + 2, y += 1);
    printf("��\n\n\n\t\t\t\t\t �ڷΰ���(ENTER)");
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
    printf("���α׷��� ��� (programming language)");
    gotoxy(x, y += 2);
    printf(": ���(��ǻ��)���� ����̳� ������ ��ų �������� ����Ǿ� ���� �ǻ������ �� �� �ְ� ���ִ� �� ���Ѵ�.");
    gotoxy(x, y += 1);
    printf("  �� ���, ����� ���ϴ� �۾��� ��ǻ�Ͱ� ������ �� �ֵ��� ���α׷��� ���� �Ϸ��� ������ �ۼ��Ͽ� ���� ��Ų��.");
    gotoxy(x, y += 1);
    printf("  ���� ���ϸ� ��ǻ�͸� �̿��ϱ� ���� ����̴�.");
    gotoxy(x, y += 1);
    printf("  �� ������ ����� �����ϱ� ���� ���� ���� ������ �����Ϸ��� ���� ����� �����ϵ� �� ����ȴ�.");
    gotoxy(x, y += 3);
    printf("ex)\"a * b = ��\" �� �������� �������� 2�ܺ��� 9�ܱ��� ����Ѵ�. ");
    gotoxy(x, y += 2);
    printf("#include <stdio.h>//c���");
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
    printf("\t\t\t\t\t\t�ڷΰ���(ENTER)");
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
    printf("\t   �˰��� ����");
    gotoxy(x, y += 3);
    printf("��  1. ����(Sort)");
    gotoxy(x, y += 2);
    printf("    2. �׷���(Graph)");
    gotoxy(x, y += 2);
    printf("    - �ڷΰ���(ENTER)");
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
    printf("\t   ���� ����");
    gotoxy(x, y += 3);
    printf("��  1. ���� ����(Bubble Sort)");
    gotoxy(x, y += 2);
    printf("    2. ���� ����(Select Sort)");
    gotoxy(x, y += 2);
    printf("    3. ���� ����(Insert Sort)");
    gotoxy(x, y += 2);
    printf("    4. �� ����(Quick Sort)");
    gotoxy(x, y += 2);
    printf("    5. ���� ����(Merge Sort)");
    gotoxy(x, y += 2);
    printf("    6. �� ����(Heap Sort)");
    gotoxy(x, y += 2);
    printf("    7. ��� ����(Radix Sort)");
    gotoxy(x, y += 2);
    printf("    8. �� ����(Shell Sort)");
    gotoxy(x, y += 2);
    printf("    - �ڷΰ���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("��� ����(RadixSort)");
    gotoxy(x, y += 2);
    printf(": ��� ����(radix sort)�� ��� ���� �� ���� �����ϴ� ���� �˰����̴�. ");
    gotoxy(x, y += 2);
    printf("  ����δ� ����, ����, õ��ī�� �� �پ��� �ڷḦ ����� �� ������ ũ�Ⱑ �����ϰ� ���������� ������ �� �־�� �Ѵ�. ");
    gotoxy(x, y += 2);
    printf("  ��Ŷ ������ �������� ��޵Ǳ⵵ �Ѵ�. ");
    gotoxy(x, y += 3);
    printf("��� ������ �ð����⵵�� O(nw)�̴�.���⼭ n�� Ű�� ���̰� w�� Ű�� �����̴�.");
    gotoxy(x, y += 2);
    printf("LSD�� ������ �����Ѵ�� ���� ���� Ű�� ���� ������ �����ϸ� w�� ���� ������ ��� Ű ���̸� �޼��� �� �ִ�. ");
    gotoxy(x, y += 3);
    printf("���� ���");
    gotoxy(x, y += 2);
    printf("1. 0~9 ������ Bucket(Queue �ڷᱸ����)�� �غ��Ѵ�.");
    gotoxy(x, y += 2);
    printf("2. ��� �����Ϳ� ���Ͽ� ���� ���� �ڸ����� �ش��ϴ� Bucket�� ���ʴ�� �����͸� �д�.");
    gotoxy(x, y += 2);
    printf("3. 0���� ���ʴ�� ��Ŷ���� �����͸� �ٽ� �����´�.");
    gotoxy(x, y += 2);
    printf("4. ���� ���� �ڸ����� �������� �Ͽ� �ڸ����� �������� 2�� 3�� ������ �ݺ��Ѵ�.");

    gotoxy(x, y += 3);
    printf("Ư¡");
    gotoxy(x, y += 2);
    printf("1. �ð� ���⵵�� O(dn)");
    gotoxy(x, y += 2);
    printf("2. �ڸ����� �����Ǿ� �־ �������� �ִ� ���� ���");

    gotoxy(x, y += 4);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y += 2);
    printf("��� ���� ");
    gotoxy(x, y += 2);
    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    RS(arr, size, x, y);

    gotoxy(x, y += 10);
    printf("���ĵ� �迭 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    gotoxy(x + 28, y+=2);
    printf("���ư���(ENTER)");
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
    while (maxValue / exp > 0) { // 1�� �ڸ��� ���
        
        int bucket[10] = { 0 };
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // �ڸ��� �迭 ó��
        for (int i = 1; i < 10; i++)bucket[i] += bucket[i - 1]; // ���� ��� : ��� �迭�� ����� ���ؼ�!	
        for (int i = n - 1; i >= 0; i--) { //���� �ڸ��� ������ ������ ����
            result[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (int i = 0; i < n; i++) a[i] = result[i]; // �⺻ �迭 ����
        exp *= 10;
        gotoxy(x, y += 2);
        printf("%d ��° ���� : ",c);
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�� ����(shell sort)");
    gotoxy(x, y += 2);
    printf(": Donald L. Shell���̶�� ����� ������ �������, ���������� ������ �˰����̴�. ");
    gotoxy(x, y += 2);
    printf("  ����δ� ����, ����, õ��ī�� �� �پ��� �ڷḦ ����� �� ������ ũ�Ⱑ �����ϰ� ���������� ������ �� �־�� �Ѵ�.");
    gotoxy(x, y += 2);
    printf("  ��Ŷ ������ �������� ��޵Ǳ⵵ �Ѵ�");
    gotoxy(x, y += 3);
    printf("��� ������ �ð����⵵�� O(nw)�̴�.���⼭ n�� Ű�� ���̰� w�� Ű�� �����̴�");
    gotoxy(x, y += 2);
    printf(".LSD�� ������ �����Ѵ�� ���� ���� Ű�� ���� ������ �����ϸ� w�� ���� ������ ��� Ű ���̸� �޼��� �� �ִ�. ");
    gotoxy(x, y += 3);
    printf("���� ���");
    gotoxy(x, y += 2);
    printf("1.������ �迭�� ��Ҹ� �׷����� ���� �� �׷캰�� ���� ���� ����");
    gotoxy(x, y += 2);
    printf("2. �� �׷��� ��ġ�鼭 ������ �ݺ��Ͽ� ����� �̵� Ƚ���� ���δ�.");
    gotoxy(x, y += 2);
    printf("3. ���� ������ �׷��� ������ 1�� �� ������ �ݺ��Ѵ�.");

    gotoxy(x, y += 3);
    printf("Ư¡");
    gotoxy(x, y += 2);
    printf("1. ������ ���ưų� ������ ��ģ ���¿� ������ ���� �ӵ��� �ſ� ��������.(����)");
    gotoxy(x, y += 2);
    printf("2. ������ ��ġ�� �ָ� ������ ������ �̵��ؾ� �ϴ� Ƚ���� ��������. (����)");


    gotoxy(x, y += 4);
    printf("��  �ǽ��ϱ�");
    gotoxy(x, y += 2);
    printf("    ���ư���");
    gotoxy(x, y += 2);
    printf("    (����Ű �� ENTER) ����");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y += 2);
    printf("�� ���� ");
    gotoxy(x, y += 2);
    int size;
    printf("�ǽ�) ���ϴ� �迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    gotoxy(x, y += 2);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� :");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    SS(arr, size, x, y);

    gotoxy(x, y += 10);
    printf("���ĵ� �迭 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    gotoxy(x + 28, y += 2);
    printf("���ư���(ENTER)");
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
        printf("%d ��° ���� �� �迭 : ",c);
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 40; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
}
void GraphMenu() {
    system("mode con: cols=150 lines=50");
    system("cls");
    gotoxy(0, 0);
    printf("����������������������������������\n");
    for (int i = 0; i < 15; i++) {
        printf("��                                                              ��\n");
    }
    printf("����������������������������������\n");
    int x = 20;
    int y = 3;
    gotoxy(x, y);
    printf("��  1. �׷����� ����");
    gotoxy(x, y = y + 2);

    printf("    2. �׷��� ��� ");
    gotoxy(x, y = y + 2);

    printf("    3. �׷��� ���� ��� ");

    gotoxy(x, y = y + 2);
    printf("    4. �׷����� ���� ");

    gotoxy(x, y = y + 2);
    printf("    5. �׷����� Ž�� ���");

    gotoxy(x, y = y + 2);
    printf("    -  �ڷΰ���");

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
    printf("������������������������������������������\n");
    for (int i = 0; i < 15; i++) {
        printf("��                                                                              ��\n");
    }
    printf("������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�׷���(Graph)");
    gotoxy(x, y += 2);
    printf(": �׷����� ����(Vertex)�� �������� �����ϴ� ��(Edge)���� ������ �ȴ�.");
    gotoxy(x, y += 1);
    printf("  �Ϲ������� ������ ������ ǥ���ϰ� ���� ȭ��ǥ�� �������� ǥ���Ѵ�. ");

    gotoxy(x, y += 2);

    printf("�׷���(graph)G�� �������� ���� V�� ���� ���� E�� ���������� ���ǵȴ�.");
    gotoxy(x, y += 1);
    printf("G��(V, E)");
    gotoxy(x + 20, y += 3);
    printf("�ڷΰ���(ENTER)");
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
    printf("��������������������������������������������������������������\n");
    for (int i = 0; i < 35; i++) {
        printf("��                                                                                                                      ��\n");
    }
    printf("��������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�׷���(Graph) ���");
    gotoxy(x, y += 3);
    printf("1. ����(vertice) : ���(node)��� �ϸ� �������� �����Ͱ� ����˴ϴ�.");
    gotoxy(x, y += 3);
    printf("2. ����(edge): ��ũ(arcs)��� �ϸ� ��尣�� ���踦 ��Ÿ���ϴ�.");
    gotoxy(x, y += 3);
    printf("3. ���� ����(adjacent vertex) : ������ ���� ����� �������� ������ (����0�� ����1�� ���� ����)");
    gotoxy(x, y += 3);
    printf("4. �ܼ� ���(simple-path): ��� �� �ݺ��Ǵ� ������ ���°�, ���� ������ �ڳ����� �ʴ� ���");
    gotoxy(x, y += 3);
    printf("5. ����(degree): ������ �׷������� �ϳ��� ������ ������ ������ ��");
    gotoxy(x, y += 3);
    printf("6. ���� ����(out-degree) : ����׷������� ���Ǵ� ���� �� ��忡�� �ܺη� ���ϴ� ������ ���� ���մϴ�.");
    gotoxy(x, y += 3);
    printf("7. ��������(in-degree) : ����׷������� ���Ǵ� ���� �ܺ� ��忡�� ������ ������ ���� ���մϴ�.");

    gotoxy(x + 30, y += 5);
    printf("\t�ڷΰ���(ENTER)");
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
    printf("�׷���(Graph) ���� ���");
    gotoxy(x, y += 2);
    printf("�׷����� �����ϴ� ������� �������(Adjacency Materix)�� ��������Ʈ(Adjacency List)����� �ֽ��ϴ�.");

    gotoxy(x, y += 2);
    printf("1. ������� ���(Adjacency Materix)");
    gotoxy(x, y += 1);
    printf(" : ���� ����� �׷����� ���� ���踦 ������ �迭�� ��Ÿ���� ����Դϴ�.");

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
    printf("���� 1. 2���� �迭 �ȿ� ��� �������� ���� ������ ��� ������ ");
    gotoxy(x, y += 1);
    printf("       �迭�� ��ġ�� Ȯ���ϸ� �� ���� ���� ���� ������ ��ȸ�� �� O(1) �� �ð� ���⵵�� �����մϴ�.");
    gotoxy(x, y += 2);
    printf("     2. ������ ���� �����ϴ�");


    gotoxy(x, y += 2);
    printf("���� 1. ��� ������ ���� ���� ������ �����ؾ� �ϹǷ�  ");
    gotoxy(x, y += 1);
    printf("       O(n��) �� �ð����⵵�� �ҿ�˴ϴ�");
    gotoxy(x, y += 2);
    printf("     2.  ������ 2���� �迭�� �ʿ��ϱ⿡ �ʿ� �̻��� ������ ����˴ϴ�.");
    gotoxy(x + 25, y += 3);
    printf("     \t ���ư���(ENTER)");
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
    printf("�׷���(Graph) ���� ���");
    gotoxy(x, y += 2);
    printf("�׷����� �����ϴ� ������� �������(Adjacency Materix)�� ��������Ʈ(Adjacency List)����� �ֽ��ϴ�.");

    gotoxy(x, y += 2);
    printf("2.��������Ʈ ���(Adjacency List)");
    gotoxy(x, y += 1);
    printf(" : �׷����� �� ��忡 ������ ������ ���Ḯ��Ʈ(Linked List)�� ǥ���ϴ� ����̴�.");
    gotoxy(x, y += 1);
    printf("   ����� ������ŭ ��������Ʈ�� �����ϸ�, ������ ��������Ʈ���� ������ ��� ������ ����ȴ�.");
    gotoxy(x, y += 1);
    printf("   �׷����� �� ��������Ʈ�� ���� ��������͸� �迭�� ���´�.");


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
    printf("���    ��");
    gotoxy(x, y += 1);
    printf("��   ��  ��");
    gotoxy(x, y += 1);
    printf("��     ����");
    gotoxy(x, y += 1);
    printf("2------->4");

    gotoxy(x, y += 2);
    PrintGraph(&g, 5, x, y, 1);


    gotoxy(x, y += 6);
    printf("���� 1.�����ϴ� ������ �����ϸ� �ǹǷ� �޸� ��� ���鿡�� ���� ȿ�����̴�. ");
    gotoxy(x, y += 2);
    printf("     2. �׷����� ��� ������ ���� �˾Ƴ����� �� ������ ��� ������ ��� ��������Ʈ�� Ž���ؾ� �ϹǷ� O(n+e)�� �ð��� �ҿ�ȴ�.");


    gotoxy(x, y += 2);
    printf("���� 1. �� ������ �����ϴ� ������ ��ȸ�ϰų� ������ ������ �˱� ���ؼ��� ������ ���� ����Ʈ�� Ž���ؾ� �ϹǷ� ");
    gotoxy(x, y += 1);
    printf("      ������ ������ŭ�� �ð��� �ʿ��ϴ�. O(degree(v))");
    gotoxy(x, y += 2);
    printf("     2. ������ ���� ��ƴ�..");
    gotoxy(x + 25, y += 3);
    printf("     \t ���ư���(ENTER)");
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
    printf("����������������������������������������������������������\n");
    for (int i = 0; i < 15; i++) {
        printf("��                                                                                                              ��\n");
    }
    printf("����������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�׷���(Graph) ���� ���");
    gotoxy(x, y += 2);
    printf("�׷����� �����ϴ� ������� �������(Adjacency Materix)�� ��������Ʈ(Adjacency List)����� �ֽ��ϴ�.");

    gotoxy(x, y += 2);
    printf("�� 1. ������� ���(Adjacency Materix)");
    gotoxy(x, y += 2);
    printf("   2. ��������Ʈ(Adjacency List)");
    gotoxy(x, y += 2);
    printf("      -���ư���");
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
    printf("�����������������������������������������������������������������\n");
    for (int i = 0; i < 65; i++) {
        printf("��                                                                                                                            ��\n");
    }
    printf("�����������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("�׷���(Graph) ����");
    gotoxy(x, y += 2);
    printf("1. ������ �׷��� (Non-Directed Graph)");
    gotoxy(x, y += 2);
    printf(": ������ �׷����� ������ ������ ���ؼ� �� �������� �̵��� �� �ִ�.");

    gotoxy(x, y += 3);
    printf("2. ���� �׷��� (Directed Graph)");
    gotoxy(x, y += 2);
    printf(": ������ ���⼺�� �����ϴ� �׷����̴�. ���� �׷����� ������ �־��� �������θ� �̵��� �� �ִ�.");
    gotoxy(x, y += 3);
    printf("3. ����ġ �׷��� (Weighed Graph)");
    gotoxy(x, y += 2);
    printf(": �� ������ �����ϴ� ������ ����̳� ����ġ�� �Ҵ�� �׷���, ��Ʈ��ũ��� �Ѵ�");
    gotoxy(x, y += 3);
    printf("4. ���� �׷��� (Complete Graph)");
    gotoxy(x, y += 2);
    printf(": �׷����� ���� �ִ� ��� ������ ���� ����Ǿ� �ִ� �׷���, ������ ���� n�̶�� �� ��, ������ ���� n * (n-1) / 2�̴�.");
    gotoxy(x, y += 3);
    printf("5. ���� �׷��� (Multi Graph)");
    gotoxy(x, y += 2);
    printf(": �� ���� ���̿� �� �� �̻��� ������ ����Ǿ� �ִ� �׷���");
    gotoxy(x, y += 3);
    printf("6. �κ� �׷��� (Sub Graph)");
    gotoxy(x, y += 2);
    printf(": ���� �׷������� Ư�� ������ �����Ͽ� ���� �׷��� ");
    gotoxy(x, y += 3);
    printf("7. ���� �׷��� (Connected Graph)");
    gotoxy(x, y += 2);
    printf(": ������ �׷����� �ִ� ��� ���� �ֿ� ���ؼ� �׻� ��ΰ� �����ϴ� �׷���");
    gotoxy(x, y += 2);
    printf("  ������Ʈ�� �� �ϳ��� ����̴�.���� ��� Ʈ��(Tree)�� ����Ŭ�� ���� ���� �׷����̴�. ");
    gotoxy(x, y += 3);
    printf("8. �񿬰� �׷��� (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": ������ �׷������� Ư�� ������ ���̿� ��ΰ� �������� �ʴ� �׷���");
    gotoxy(x, y += 3);
    printf("9. ��ȯ VS ���ȯ �׷��� (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": ����Ŭ�� ������ ������ ��ȯ �׷����̰�, �׷��� ������ ���ȯ �׷����̴�.");
    gotoxy(x, y += 3);
    printf("10. ��� VS ���� �׷��� (Disconnection Graph)");
    gotoxy(x, y += 2);
    printf(": ��� �׷����� �������� ������ ���� ���� �׷����̴�");
    gotoxy(x, y += 2);
    printf("  ���� �׷����� ��� ������ ������ ���� �� ���� �׷����̴�.");

    gotoxy(x + 20, y += 3);
    printf("�ڷΰ���(ENTER)");
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
    printf("����������������������������������\n");
    for (int i = 0; i < 30; i++) {
        printf("��");
        for (int j = 0; j < 62; j++) {
            printf(" ");
        }
        printf("��\n");
    }
    printf("����������������������������������\n");
    GraphSearch();
    getchar();
}
void GraphSearch() {
    int x = 10;
    int y = 3;
    gotoxy(x + 5, y);
    printf("\t   �˰��� ����");
    gotoxy(x, y += 3);
    printf("��  1. ���� �켱 Ž��(DFS, Depth-First Search)");
    gotoxy(x, y += 2);
    printf("    2. �ʺ� �켱 Ž��(BFS, Breadth-First Search)");
    gotoxy(x, y += 2);
    printf("    3. ũ�罺Į �˰���(Kruskal Algorithm)");
    gotoxy(x, y += 2);
    printf("    4. ����(Prim)");
    gotoxy(x, y += 2);
    printf("    5. A* �˰���(A* Algorithm)");
    gotoxy(x, y += 2);
    printf("    6. ���� ����(Topological Sorting)");
    gotoxy(x, y += 2);
    printf("    7. ��Ʈ��ŷ(Back-tracking)");
    gotoxy(x, y += 2);
    printf("    8. �б�����(Branch and Bound)");
    gotoxy(x, y += 2);
    printf("    - �ڷΰ���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 35; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf(" �б�����(Branch and Bound)");
    gotoxy(x, y += 2);
    printf(": �б⸦ �������� �������� �ð� ���� ���̴� ���");
    gotoxy(x, y += 2);
    printf("  ��Ʈ��ŷ���� �ΰ������� �߻��� �˰��� ���� ��� ��Ʈ��ŷ�� ���Ǵ� Ž������ �� �̻� Ž���� �ʿ䰡 ���� ������ �Ǵ��ϴ� ��.");

    gotoxy(x, y += 3);
    printf("Branch & Bound ����");
    gotoxy(x, y += 2);
    printf(" �� ��带 �湮�� �� ����, �� ��尡 ���������� ���θ� �����ϱ� ���ؼ� �Ѱ�ġ(bound)�� ����Ѵ�.");
    gotoxy(x, y += 2);
    printf("   -�Ѱ�ġ�� �� ���κ��� ������ �������(branch) ���� �� �ִ� �ش�ġ�� �Ѱ踦 ��Ÿ����.");
    gotoxy(x, y += 2);
    printf("   -�Ѱ�ġ�� �������� ã�� �ְ� �ش䰪���� �� ������ �� ����� �����ϴ�(Promising).");

    gotoxy(x, y += 3);
    printf("Backtracking���� ������ �� ������");
    gotoxy(x, y += 2);
    printf("������ : ������ ���ʷ� �����ϴ� ��� �ʿ�");
    gotoxy(x, y += 2);
    printf("������ : Backtracking: ������ �� �̻� ������ ���� ������ ���ƿ´�.");
    gotoxy(x, y += 2);
    printf("         Branch&Bound: �����ظ� ã�� ���ɼ��� ������ �б⸦ ���� �ʴ´�. ");

    gotoxy(x + 28, y += 2);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� �켱 Ž��(DFS, Depth-First Search)");
    gotoxy(x, y += 2);
    printf(": DFS�� ���� �켱 Ž���̶�� �� �̸���� �׷����� ���� �κ��� �켱������ Ž���ϴ� �˰���");
    gotoxy(x, y += 2);
    printf("  ���� �ڷᱸ���� ����Ͽ� �׷����� ���� ���� ������ �湮�� �� �ٽ� ���ư� �ٸ� ��θ� Ž��");

    gotoxy(x, y += 3);
    printf("��ü���� ���� ����");
    gotoxy(x, y += 2);
    printf("1. Ž�� ���� ��带 ���ÿ� �����ϰ� �湮 ó��, �̹� �湮�ߴ� ��带 ��湮���� �ʱ� ����");
    gotoxy(x, y += 2);
    printf("2. ������ �ֻ�� ��忡 �湮���� ���� ���� ��尡 �ִٸ� �� ��带 ���ÿ� �ְ� �湮 ó��");
    gotoxy(x, y += 2);
    printf("   ���� �湮���� ���� ���� ��尡 ������ ���ÿ��� �ֻ�� ��带 ����");
    gotoxy(x, y += 2);
    printf("3. �ι�° ������ �� �̻� ������ �� ���� ������ �ݺ�");

    gotoxy(x, y += 3);
    printf("DFS�� �ð� ���⵵�� O(N)");

    gotoxy(x, y += 3);
    printf("����");
    gotoxy(x, y += 2);
    printf("1. ���� �� ��λ��� ���鸸�� ����ϸ� �ǹǷ� ���� ������ ���䰡 ���� ����.");
    gotoxy(x, y += 2);
    printf("2. ��ǥ ��尡 ���� �ܰ迡 ���� ��� �ظ� ���� ���� �� �ִ�.");

    gotoxy(x, y += 3);
    printf("����");
    gotoxy(x, y += 2);
    printf("1. �ذ� ���� ��ο� ���� ���� ���ɼ��� �ִ�. ");
    gotoxy(x, y += 2);
    printf("  ���� �����δ� �̸� ������ ���� ���̱����� Ž���ϰ� ��ǥ ��带 �߰����� ���ϸ� ���� ��θ� ���� Ž���ϴ� ����� ������ �� �ִ�.");
    gotoxy(x, y += 2);
    printf("2. ����� �ذ� �ִ� ��ΰ� �ȴٴ� ������ ����.�̴� ��ǥ�� �̸��� ��ΰ� �ټ��� ������ ���� ���̿켱Ž���� �ؿ� �ٴٸ��� Ž���� ���������Ƿ�,");
    gotoxy(x, y += 2);
    printf("   �̶� ����� �ش� ������ �ƴ� �� �ִٴ� �ǹ��̴�");
    gotoxy(x + 25, y += 3);

    gotoxy(x, y += 2);
    printf("�� 1. ��������");
    gotoxy(x, y += 2);
    printf("   2. ���ư���");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� �켱 Ž��(DFS, Depth - First Search) ����");
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
    printf("��  ��  ��");
    gotoxy(x, y += 2);
    printf("1   2   3");
    gotoxy(x, y += 2);
    printf("��  ��  ��");
    gotoxy(x, y += 2);
    printf("4   5   6");
    gotoxy(x, y += 2);
    printf("�� �� ��");
    gotoxy(x, y += 2);
    printf("    7    ");


    gotoxy(x, y += 5);
    PrintGraph(&g, 7, x, y, 0);
    y += 10;
    DFS_stack(&g, 0, x, y);;

    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� �켱 Ž��(BFS, Breadth First Search)");
    gotoxy(x, y += 2);
    printf(": �͸��� Ž������� �ϳ��� ���� ������ �湮�� �� ���� ������ ������ ��� �������� �켱 �湮�ϴ� ����̴�.");
    gotoxy(x, y += 2);
    printf("  �� �̻� �湮���� ���� ������ ���� ������ �湮���� ���� ��� �����鿡 ���ؼ��� �ʺ� �켱 �˻��� �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("  OPEN List�� ť�� ����ؾ߸� ���� ������� ������ �����ϴ�.");

    gotoxy(x, y += 3);
    printf("��ü���� ���� ����");
    gotoxy(x, y += 2);
    printf("1. Ž�� ���� ��� ������ ť�� �����ϰ� �湮 ó���մϴ�.");
    gotoxy(x, y += 2);
    printf("2. ť���� ��带 ���� �湮���� ���� ���� ��� ������ ��� ť�� �����ϰ� �湮 ó���մϴ�.");
    gotoxy(x, y += 2);
    printf("3. 2���� ������ �� �̻� ������ �� ���� ������ �ݺ��մϴ�.");

    gotoxy(x, y += 3);
    printf("BFS�� �ð� ���⵵��  O(n^2)");

    gotoxy(x, y += 3);
    printf("����");
    gotoxy(x, y += 2);
    printf("1. ��߳�忡�� ��ǥ�������� �ִ� ���� ��θ� �����Ѵ�.");

    gotoxy(x, y += 3);
    printf("����");
    gotoxy(x, y += 2);
    printf("1. ��ΰ� �ſ� �� ��쿡�� Ž�� ������ �ް��� �����Կ� ���� ���� ���� ��� ������ �ʿ�� �ϰ� �ȴ�. ");
    gotoxy(x, y += 2);
    printf("2. �ذ� �������� �ʴ´ٸ� ���� �׷���(finite graph)�� ��쿡�� ��� �׷����� Ž���� �Ŀ� ���з� ������.");
    gotoxy(x, y += 2);
    printf("3. ���� �׷���(infinite graph)�� ��쿡�� ���� �ظ� ã���� ���ϰ�, �������� ���Ѵ�.");


    gotoxy(x, y += 2);
    printf("�� 1. ��������");
    gotoxy(x, y += 2);
    printf("   2. ���ư���");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("���� �켱 Ž��(DFS, Depth - First Search) ����");
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
    printf("��  ��  ��");
    gotoxy(x, y += 2);
    printf("1   2   3");
    gotoxy(x, y += 2);
    printf("��  ��  ��");
    gotoxy(x, y += 2);
    printf("4   5   6");
    gotoxy(x, y += 2);
    printf("�� �� ��");
    gotoxy(x, y += 2);
    printf("    7    ");
    gotoxy(x, y += 5);
    PrintGraph(&g, 7, x, y, 0);
    y += 10;
    BFS_queue(&g, 0, x, y);;

    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("ũ�罺Į �˰���(Kruskal Algorithm)");
    gotoxy(x, y += 2);
    printf(": ũ������ �˰���(Kruskal��s algorithm)�� �ּ� ��� ���� �κ� Ʈ���� ã�� �˰����̴�. ");
    gotoxy(x, y += 2);
    printf("  ���� ������ E �������� ������ V ��� �ϸ� �˰����� O(ElogV)�� �ð� ���⵵�� ������.");
    gotoxy(x, y += 2);
    printf("  ũ�罺Į�� �ٽ��� ��� ������ ����ġ �������� ������������ �����ϰ�,");
    gotoxy(x, y += 2);
    printf("  �� �������� ������� ��� ������ ����� ������ �����ϴ� ���̴�.");
    gotoxy(x, y += 2);
    printf(" Union-Find �˰����� �̿��ؼ� ������ �� �ְ�, �̸� ���� ����Ŭ�� �������� �����鼭 ��� ������ ������ �� �ִ�.");

    gotoxy(x, y += 3);
    printf("��ü���� ���� ����");
    gotoxy(x, y += 2);
    printf("1. �־��� ��� ������ �������� ���� �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("2. ���ĵ� ������ �ϳ��� Ȯ���ϸ� ���� ������ ��� �� ����Ŭ�� �߻���Ű���� Ȯ���Ѵ�.");
    gotoxy(x, y += 2);
    printf("3. ����Ŭ �߻���Ű�� ���� ��� �ּҽ���Ʈ���� ����, ����Ŭ �߻��� ��� �������� �ʴ´�.");

    gotoxy(x, y += 2);
    printf("�� 1. ��������");
    gotoxy(x, y += 2);
    printf("   2. ���ư���");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("ũ�罺Į �˰���(Kruskal Algorithm) ����");
    int E = 9;
    int V = 8;
    gotoxy(x, y += 2);
    printf("V = %d   E = %d", V, E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    gotoxy(x, y += 2);
    printf("    0     ����ǥ�ô� ������ ����� ������ �׷���   0       ");
    gotoxy(x, y += 2);
    printf("��  ��  ��                                    ��  ��  ��");
    gotoxy(x, y += 2);
    printf("1   2   3                                     1   2   3");
    gotoxy(x, y += 2);
    printf("��  ��  ��                    ��              ��  ��  ��");
    gotoxy(x, y += 2);
    printf("4   5   6                                     4   5   6");
    gotoxy(x, y += 2);
    printf("��  ��  ��                                            ��");
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
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� Ʈ��(ST, Spanning Tree)");
    gotoxy(x, y += 2);
    printf(": ST�� ������ �׷��� G(V,E)���� E�� ���� ������� ����Ŭ�� �������� �����鼭");
    gotoxy(x, y += 2);
    printf("  ��� ���� V�� ������ �κ� �׷����� ���� Ʈ��(Spanning Tree)�� �Ѵ�.");
    gotoxy(x, y += 2);
    printf("  �׷������� ���� Ʈ���� ���� ���·� ������ �� ������,");
    gotoxy(x, y += 2);
    printf("  ���� Ʈ���� Ư¡�� n���� ������ ���� �׷������� ���� Ʈ���� ���ϴ� ������ ���� n-1���̸� ����Ŭ�� �̷��� �ʴ´ٴ� Ư¡�� �ִ�.");

    gotoxy(x, y += 3);
    printf("�ּ� ���� Ʈ��(MST,Minimum Spanning Tree)");
    gotoxy(x, y += 2);
    printf(": MST�� �ּ� ��� ���� Ʈ��(���� �ּ� ���� Ʈ��)�� ���ϸ�, ������ �׷����� �����鿡 ����ġ�� �־��� ���, ");
    gotoxy(x, y += 2);
    printf("  ���� ���� Ʈ�� �߿� �������� ����ġ ���� �ּ��� ���� Ʈ���� ���Ѵ�.");

    gotoxy(x, y += 2);
    printf("ȿ������ ��� �� ���� � �̿�� �� �ִ�.");

    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("A* �˰��� ");
    gotoxy(x, y += 2);
    printf(": ���ͽ�Ʈ�� �˰����� Ȯ���Ͽ� ������� ��� Ž�� �˰����̴�.");
    gotoxy(x, y += 2);
    printf("  ����̳� �κ� ������ �ΰ����� ������ �����ϱ� ���� ���ߵǾ���.");

    gotoxy(x, y += 3);
    printf("�˰��� ����");

    gotoxy(x, y += 2);
    printf("1. ��� ������ Closed List�� ���� �ִ´�.");

    gotoxy(x, y += 2);
    printf("2. ��� ������ ����Ǿ� �ִ� node���� Open List�� �߰��Ѵ�. �̶� f, g, h, parent node ���� �����ؾ��Ѵ�.");

    gotoxy(x, y += 2);
    printf("3. Open List �� ���� ���� F ���� ���� Node�� Closed List�� �߰��Ѵ�. ");
    gotoxy(x, y += 2);
    printf("  ����, �ش� Node�� ����� Node �� Closed List�� �������� �ʴ� Node���� �ٽ� f,g,h,parent Node�� �����ϰų� �߰��Ѵ�.");

    gotoxy(x, y += 2);
    printf("  �� �� ���Ӱ� ����� g���� �������� Ŭ �� f,g,h,parent node�� �����Ѵ�");

    gotoxy(x, y += 2);
    printf("4. �̸� �ݺ��Ѵ�.");
    gotoxy(x, y += 2);
    printf("5, Closed List�� ������ node�� �߰��Ǹ� �˰����� ����ȴ�.");
    gotoxy(x, y += 2);
    printf("6.  ������ node���� parent node�� ���� �ö󰡰� �Ǹ� �ִ� ��θ� �ľ��� �� �ִ�.");
    gotoxy(x, y += 2);
    printf("7. ���� �������� ã�� ���߿� Open List�� ��Եȴٸ�, ��θ� ã�� �� ���� ��찡 �ȴ�.");

    gotoxy(x, y += 3);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("����(Prim)");
    gotoxy(x, y += 2);
    printf(": ������ ������ ���� �ּ� ���� Ʈ���� ���ϴ� �˰����̴�.");
    gotoxy(x, y += 2);
    printf("  ������ ������ ���������� ������� ����� �����鿡�� ������� ���� �����鿡 ����, ");
    gotoxy(x, y += 2);
    printf("  ���� ����ġ�� ���� ������ �����ϴ� ���� ���� ������� �����Ѵ�. ");
    gotoxy(x, y += 2);
    printf(" ������ �ٽ��� Ʈ�� ������ �ܰ������� Ȯ���ϴ� ���̰�, ");
    gotoxy(x, y += 2);
    printf("  ���ο� ������ ������ ������ ���ο� �������� �� �� �ִ� ���� ������� ���� �����鿡 ���� ������ �߰������ �Ѵ�. ");
    gotoxy(x, y += 2);
    printf("  Priority Queue�� �̿��� �ּ� ������ ������ �� �ְ�, ���ͽ�Ʈ�� �˰���� ���� ����� �����ϴ�. ");

    gotoxy(x, y += 3);
    printf("O(ElogV)�� ���� �˰����� �ð� ���⵵�� �ȴ�.");
    gotoxy(x, y += 2);
    printf("�ּ� ���� ������� �ʴ� ��� O(V ^ 2)�� �ð� ���⵵�� ���� �� ������, �ּ� ������ �����ϴ� ���� ����� �ʴ�.");


    gotoxy(x, y += 3);
    printf("���� �˰����� ���� ���");
    gotoxy(x, y += 2);
    printf("1. ������ ������ ���������� �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("2. ���������� �� �� �ִ� ���� �� ���� ����ġ�� ���� ������ �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("3-1. 2�� �������� �������� ��� �������� ����Ǿ���.");
    gotoxy(x, y += 2);
    printf("3-2. �������� ����� �������� a�����̶� �� ��, a���տ��� �� �� �ִ� a���տ� ������ ���� �����鿡 ���� ����ġ�� ���� ���� ������ �����Ѵ�.");
    gotoxy(x, y += 2);
    printf("a������ ũ�Ⱑ �þ��.(�������� ������ a���տ� ���ο� ������ �����ߴ�.) ���� ������ ��� ������ ����� ������ �ݺ��Ѵ�.");
    gotoxy(x, y += 3);
    printf("���ư���(ENTER)");

    gotoxy(x, y += 2);
    printf("�� 1. ��������");
    gotoxy(x, y += 2);
    printf("   2. ���ư���");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");

    int x = 5;
    int y = 3;
    gotoxy(x, y);

    printf("����(Prim) ����");
    int E = 9;
    int V = 8;
    gotoxy(x, y += 2);
    printf("V = %d   E = %d", V, E);

    gotoxy(x, y += 2);
    printf("    0     ����ǥ�ô� ������ ����� ������ �׷���   0       ");
    gotoxy(x, y += 2);
    printf("��  ��  ��                                    ��  ��  ��");
    gotoxy(x, y += 2);
    printf("1   2   3                                     1   2   3");
    gotoxy(x, y += 2);
    printf("��  ��  ��                  ��                ��  ��  ��");
    gotoxy(x, y += 2);
    printf("4   5   6                                     4   5   6");
    gotoxy(x, y += 2);
    printf("��  ��  ��                                            ��");
    gotoxy(x, y += 2);
    printf("    7                                             7    ");

    struct Edge_ edges[] = {
       {0, 1, 11}, {0, 2, 9}, {0, 3, 1},
       {1, 4, 8}, {2, 5, 12}, {3, 6, 5},
       {6, 7, 4}, {4, 7, 2}, {5, 7, 7}
    };
    gotoxy(x, y += 2);
    printf("���� �˰��� ���:\n");
    prim(edges, V, E, x, y += 2);



    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("���� ���� (Topological Sorting)");
    gotoxy(x, y += 2);
    printf(": ���� �˰����� ��������, ������ ������ �ִ� �Ϸ��� �۾��� ���ʴ�� �����ؾ� �� �� ����� �� �ִ� �˰����̴�.");
    gotoxy(x, y += 2);
    printf("  ����Ŭ�� ���� ���� �׷����� ��� ��带 '���⼺�� �Ž����� �ʵ��� ������� �����ϴ� ��'�� �ǹ�");
    gotoxy(x, y += 2);
    printf("  ����Ŭ�� ���� ���� �׷��� (DAG) �̿��� �Ѵ�!");

    gotoxy(x, y += 3);
    printf("���� ���� �˰��� ���� ����");
    gotoxy(x, y += 2);
    printf("1. ���������� 0�� ��带 ť�� �ִ´�.");
    gotoxy(x, y += 2);
    printf("2. ť�� �� ������ ������ ������ �ݺ��Ѵ�.");
    gotoxy(x, y += 2);
    printf("    �� ť���� ���Ҹ� ���� �ش� ��忡�� ������ ������ �׷������� ����");
    gotoxy(x, y += 2);
    printf("    �� ���Ӱ� ���������� 0�� �� ��带 ť�� ����");


    gotoxy(x, y += 3);
    printf("���� ������ Ư¡");
    gotoxy(x, y += 2);
    printf("1. ���� ������ ����Ŭ�� ���� ���� �׷��� (DAG)�� ���ؼ��� ������ �� �ִ�");
    gotoxy(x, y += 2);
    printf("2. ���� ���Ŀ����� ���� ���� ���� ������ �� �ִ�.");
    gotoxy(x, y += 2);
    printf("   �� �ܰ迡�� ť�� ���Ӱ� ���� ���Ұ� 2�� �̻��� ��찡 �ִٸ� ���� ���� ���� ������ �� �ִٴ� �ǹ��̴�.");
    gotoxy(x, y += 2);
    printf("3. ��� ���Ҹ� �湮�ϱ� ���� ť�� ��� �ȴٸ� ����Ŭ�� �����Ѵٰ� �Ǵ��� �� �ִ�.");
    gotoxy(x, y += 2);
    printf("4. ���� ť�� �����ϳ�, ������ �̿��� DFS�� �̿��� ���� ������ ������ ���� �ִ�.");
    gotoxy(x + 28, 38);
    printf("���ư���(ENTER)");
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
    printf("����������������������������������������������������������������������������\n");
    for (int i = 0; i < 25; i++) {
        printf("��                                                                                                                                                  ��\n");
    }
    printf("����������������������������������������������������������������������������\n");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("��Ʈ��ŷ (Back-tracking)");
    gotoxy(x, y += 2);
    printf(": �ظ� ã�� ���߿� ������ �� �̻� ���� ���� �ʰ�, ���� �ܰ�� �ǵ��ư��� �ظ� ã�Ƴ����� ����� ���Ѵ�. ");




    gotoxy(x, y += 3);
    printf("��Ʈ��ŷ �˰��� Ư¡");
    gotoxy(x, y += 2);
    printf(": �ظ� ã�ư��� ���߿� ������ ��ΰ� �ذ� �� �� ���� ������, �� �̻� ���� ���� �ʰ� ���� �ܰ�� �ٽ� ���ư���.");
    gotoxy(x, y += 2);
    printf("   ���ʿ��� �κ��� �ĳ��� �ִ��� �ùٸ� �������� ���ư��� ����̱� ������ DFS���� ȿ�����̴�.");
    gotoxy(x, y += 2);

    gotoxy(x + 28, y += 2);
    printf("���ư���(ENTER)");
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
    printf("�����������������\n");
    for (int i = 0; i < 5; i++) {
        printf("��                            ��\n");
    }
    printf("�����������������\n");
    gotoxy(4, 3);
    printf("�ڡ�����Ǿ����ϴ١ڡ�");
    getchar();
}