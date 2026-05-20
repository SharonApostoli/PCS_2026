#include <iostream>
#include "ese9.h"

int main(){
    //Creo grafo non diretto (lo stesso della scorsa es.)
    unidirected_graph<int> G;
    G.add_edge(1,2);
    G.add_edge(1,3);
    G.add_edge(2,3);
    G.add_edge(3,4);
    G.add_edge(3,5);
    G.add_edge(4,5);
    G.add_edge(5,6);

    //Coda
    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    export_dot(bfsG, "bfs.dot");

    //Stack
    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    export_dot(dfsG, "dfs.dot");

    //DFS ricorsiva
    lifo<int> s_i;
    auto dfs_iG = recursive_dfs(G, 1);
    export_dot(dfs_iG, "dfs_i.dot");

    //Dijkstra
    weighted_graph Gd;

    //Quando aggiungo un arco ho 3 parametri: il nodo di partenza, quello di arrivo e il peso
    Gd.add_edge_w(1, 2, 4);
    Gd.add_edge_w(1, 3, 1);
    Gd.add_edge_w(3, 2, 2);
    Gd.add_edge_w(3, 4, 5);
    Gd.add_edge_w(4, 5, 2);
    Gd.add_edge_w(5, 6, 1);

    auto dist = dijkstra(Gd, 1);

    for(const auto& [nodo, d] : dist){
        std::cout << "Nodo " << nodo << " distanza = " << d << std::endl;
    }

    return 0;
}