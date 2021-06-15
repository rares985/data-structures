#ifndef GRAPH_H_
#define GRAPH_H_

#include "single_linked_list.h"

class Graph {
    private:
        bool is_directed_;
        int vertex_count_;

        int **adj_;

    public:
        Graph(int vertices, int directed=false)
        {
            adj_ = new int*[vertices]();
            for (int i = 0; i < vertices; i++)
            {
                adj_[i] = new int[vertices]();
            }
            is_directed_ = directed;
            vertex_count_ = vertices;
        }

        ~Graph()
        {
            for(int i = 0; i < vertex_count_; i++)
            {
                delete[] adj_[i];
            }
            delete[] adj_;
        }

        void add_edge(int v1, int v2, int weight=1)
        {
            adj_[v1][v2] = weight;
            if (!is_directed_)
            {
                adj_[v2][v1] = weight;
            }
        }

        int is_edge(int v1, int v2)
        {
            return adj_[v1][v2] != 0;
        }

        friend std::ostream& operator<< (std::ostream &out, const Graph &g)
        {
            out << "Graph(\n";
            for(int i = 0; i < g.vertex_count_; i++)
            {
                out << i <<": ";
                for (int j = 0; j < g.vertex_count_; j++)
                {
                    if (g.adj_[i][j] != 0)
                    {
                        out << j << " ";
                    }
                }
                if (i != g.vertex_count_ - 1)
                {
                    out <<"\n";
                }
            }
            out << "\n)";
            return out;
        }
};

#endif /* GRAPH_H_ */