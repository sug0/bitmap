#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bitmap.h"

typedef struct {
    Bitmap_t **edges;
    size_t n_edges;
} Graph_t;

static void Graph_init(Graph_t *g, size_t n_edges)
{
    g->n_edges = n_edges;
    g->edges = malloc(n_edges * sizeof(Bitmap_t **));

    for (size_t i = 0; i < n_edges; i++) {
        g->edges[i] = malloc(sizeof(Bitmap_t));
        Bitmap_init(g->edges[i], n_edges);
    }
}

static void Graph_free(Graph_t *g)
{
    for (size_t i = 0; i < g->n_edges; i++) {
        Bitmap_free(g->edges[i]);
        free(g->edges[i]);
    }

    free(g->edges);
}

static inline void Graph_insert_arc(Graph_t *g, int a, int b)
{
    Bitmap_set(g->edges[a], b, 1);
}

static inline void Graph_remove_arc(Graph_t *g, int a, int b)
{
    Bitmap_set(g->edges[a], b, 0);
}

static inline int Graph_is_arc(Graph_t *g, int a, int b)
{
    return Bitmap_at(g->edges[a], b) != 0;
}

static int Graph_is_threestep(Graph_t *g, int a, int b)
{
    for (size_t i = 0; i < g->n_edges; i++) {
        if (Graph_is_arc(g, a, i) && Graph_is_arc(g, i, b))
            return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    Graph_t g;
    enum {A, B, C, N_NODES};

    /* init graph 'g' with N_NODES nodes */
    Graph_init(&g, N_NODES);

    /* connect node 'A' to node 'B' */
    Graph_insert_arc(&g, A, B);

    /* connect node 'B' to node 'C' */
    Graph_insert_arc(&g, B, C);

    /* arc from 'A' to 'B' */
    if (Graph_is_arc(&g, A, B))
        puts("There is an arc from A to B in G");

    /* arc from 'B' to 'C' */
    if (Graph_is_arc(&g, B, C))
        puts("There is an arc from B to C in G");

    /* threestep from 'A' to 'C' */
    if (Graph_is_threestep(&g, A, C))
        puts("There is a threestep from A to C in G");

    /* free the graph 'g' */
    Graph_free(&g);

    return 0;
}
