#ifndef GRAPH_H_
#define GRAPH_H_

#include <queue.h>
#include <stack.h>
#include <vector>

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
            if (v1 < 1 || v2 < 1)
            {
                return;
            }

            adj_[v1 - 1][v2 - 1] = weight;
            if (!is_directed_)
            {
                adj_[v2 - 1][v1 - 1] = weight;
            }
        }

        bool is_edge(int v1, int v2)
        {
            if (v1 < 1 || v2 < 1)
            {
                return false;
            }
            return adj_[v1 - 1][v2 - 1] != 0;
        }

        bool has_node(int v)
        {
            return ((v < vertex_count_) && (v >= 1));
        }

        bool bfs_traversal(int start, std::vector<int> &traversal)
        {
            if (!has_node(start))
            {
                return false;
            }

            Queue<int> q;
            bool *discovered = new bool[vertex_count_]();

            q.push(start - 1);
            discovered[start - 1] = 1;
            traversal.push_back(start);

            while (!q.empty())
            {
                int v = q.pop();
                for (int w = 0; w < vertex_count_; w++)
                {
                    if (adj_[v][w] != 0)
                    {
                        if (!discovered[w])
                        {
                            traversal.push_back(w + 1);
                            discovered[w] = true;
                            q.push(w);
                        }
                    }
                }
            }

            delete[] discovered;
            return true;
        }

        bool dfs_traversal(int start, std::vector<int> &traversal)
        {
            if (!has_node(start))
            {
                return false;
            }

            Stack<int> st;
            bool *discovered = new bool[vertex_count_]();

            st.push(start - 1);

            while (!st.empty())
            {
                int v = st.pop();
                if (!discovered[v])
                {
                    discovered[v] = true;
                    traversal.push_back(v + 1);
                    for (int w = vertex_count_ - 1; w >= 0; w--)
                    {
                        if (adj_[v][w] != 0)
                        {
                            st.push(w);
                        }
                    }
                }
            }

            delete[] discovered;
            return true;
        }

        friend std::ostream& operator<< (std::ostream &out, const Graph &g)
        {
            out << "Graph(\n";
            for(int i = 0; i < g.vertex_count_; i++)
            {
                out << i + 1 <<": ";
                for (int j = 0; j < g.vertex_count_; j++)
                {
                    if (g.adj_[i][j] != 0)
                    {
                        out << j + 1 << " ";
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