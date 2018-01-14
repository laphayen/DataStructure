
#include <stdio.h>

#include <stdlib.h>

#define MAX_VERTEX 30

typedef struct graphType
{
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;


// 그래프 생성 - 0 초기화
void createGraph(graphType* g)
{
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++)
	{
		for (j = 0; j < MAX_VERTEX; j++)
		{
			g->adjMatrix[i][j] = 0;
		}
	}
}


void insertVertex(graphType* g, int v)
{
	if (((g->n)+1)>MAX_VERTEX)
	{
		printf("그래프 정점 개수 초과\n");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v)
{
	if (u >= g->n || v >= g->n)
	{
		printf("그래프에 없는 정점\n");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType* g)
{
	int i, j;
	for (i = 0; i < (g->n); i++)
	{
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++)
		{
			printf("%2d", g->adjMatrix[i][j]);
		}
	}
}

void main()
{
	int i;
	graphType *G1, *G2, *G3, *G4;
	G1 = (graphType *)malloc(sizeof(graphType));
	G2 = (graphType *)malloc(sizeof(graphType));
	G3 = (graphType *)malloc(sizeof(graphType));
	G4 = (graphType *)malloc(sizeof(graphType));
	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);
	for (i = 0; i<4; i++)          // 그래프 G1 
		insertVertex(G1, i);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 3, 0);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 2);
	printf("\n G1의 인접행렬");
	print_adjMatrix(G1);

	for (i = 0; i<3; i++)        // 그래프 G2
		insertVertex(G2, i);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 0, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 2, 0);
	insertEdge(G2, 2, 1);
	printf("\n\n G2의 인접행렬");
	print_adjMatrix(G2);

	for (i = 0; i<4; i++)    // 그래프 G3
		insertVertex(G3, i);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 0, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 2, 3);
	printf("\n\n G3의 인접행렬");
	print_adjMatrix(G3);

	for (i = 0; i<3; i++)      // 그래프 G4
		insertVertex(G4, i);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 1, 0);
	insertEdge(G4, 1, 2);
	printf("\n\n G4의 인접행렬");
	print_adjMatrix(G4);

	getchar();
}
