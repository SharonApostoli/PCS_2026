#pragma once

#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <limits>
#include "ese8_w.h"

//FIFO = First in First Out
//il primo elemento messo sarà il primo elemnento ad uscire
//si pensi una coda di persone
template<typename T>
class fifo{
    std::queue<T> q;
public:
    // costruttore di default
    fifo(){
    };

    //metodo put() per inserire un el. nel  contenitore
    void put(const T& x){
        q.push(x);
    }

    //metodo get() per rimuovere un el. dal contenitore
    T get(){
        T x = q.front();
        q.pop();
        return x;
    }
    
    //metodo empty() per determinare de il contenitore è vuoto
    bool empty() const{
        return q.empty();
    }
};

//LIFO = Last in Last Out
//l'ultimo elemento messo sarà il primo elemento ad uscire
//si pensi ad una pila di vestiti ripiegati
template<typename T>
class lifo{
    std::stack<T> l;
public:
    // costruttore di default
    lifo(){
    };

    //metodo put() per inserire un el. nel  contenitore
    void put(const T& x){
        l.push(x);
    }

    //metodo get() per rimuovere un el. dal contenitore
    T get(){
        T x = l.top();
        l.pop();
        return x;
    }

    //metodo empty() per determinare de il contenitore è vuoto
    bool empty() const{
        return l.empty();
    }
};


template<typename contenitore>
unidirected_graph<int> graph_visit(const unidirected_graph<int>& G, int v,contenitore& tipo){
    unidirected_graph<int> tree;
    std::set<int> visited;
    visited.insert(v);
    tipo.put(v);

    while(!tipo.empty()){
        int node = tipo.get();
        for(auto [vicino, peso] : G.neighbours(node)){
            if(!visited.count(vicino)){
                visited.insert(vicino);
                tree.add_edge(node, vicino);
                tipo.put(vicino);
            }
        }
    }
    return tree;
}

void recursive_dfs_aiuto(const unidirected_graph<int>& G, int v, unidirected_graph<int>& tree, std::set<int>& visited){
    visited.insert(v);
    for(auto [vicino, peso] : G.neighbours(v)){
        if(!visited.count(vicino)){
            tree.add_edge(v, vicino);
            recursive_dfs_aiuto(G, vicino, tree, visited);
        }
    }
}

unidirected_graph<int> recursive_dfs(const unidirected_graph<int>& G, int v){
    unidirected_graph<int> tree;
    std::set<int> visited;

    recursive_dfs_aiuto(G, v, tree, visited);

    return tree;
}


/*Per usare l'algoritmo di Dijkstra sfruttiamo std::priority_queue
che è una coda che estrae l'elemento con priorità maggiore. Siccome
però di default std::priority_queue estrae l'elemento con priorità maggiore,
dobbiamo dirgli invece di estrarre l'elemento con priorità minore. 
Questo lo facciamo nella creaione di una nuova classe: weighted_graph.
Cosi facendo, si implementano i pesi degli archi e si può quindi sfruttare
l'lagoritmo di Dijkstra */

template<typename T>
std::map<T, int> dijkstra(const unidirected_graph<T>& G, T v){
    const int INF = std::numeric_limits<int>::max();

    //distanza minima dal nodo di partenza v
    std::map<T, int> dist;

    //inizializziamo tutti i nodi a dist. infinita
    for(T nodo : G.all_nodes()){
        dist[nodo] = INF;
    }

    dist[v] = 0;

    using NodeDistance = std::pair<int, T>;

    std::priority_queue<NodeDistance, std::vector<NodeDistance>, std::greater<NodeDistance>> pq;

    pq.push({0, v});

    while(!pq.empty()){
        auto [current_dist, u] = pq.top();
        pq.pop();

        //ignora entry obsolete
        if(current_dist > dist[u]){
            continue;
        }

        for(auto [vicino, weight] : G.neighbours(u)){
            int new_dist = dist[u] + weight;
            if(new_dist < dist[vicino]){
                dist[vicino] = new_dist;
                pq.push({new_dist, vicino});
            }
        }
    }
    return dist;
}

void export_dot(const unidirected_graph<int>& G, const std::string& filename){
    std::ofstream out(filename);
    out << "graph G { \n";
    out << "    node [shape=circle]; \n";

    for(const auto& e : G.all_edges()){
        out << "    " << e.from() << " -- " << e.to() << "; \n";
    }
    out << "} \n";
}