#pragma once

#include <string>
#include <map>
#include <set>

#include <string>

//Funzione per lettura e immagazzinazione dati dal file netlist
void read_file(std::string filename);

template<typename T>
class unidirected_edge{
    T node_f;
    T node_t;
public:
    unidirected_edge(const T& partenza, const T& arrivo);
    T from() const;
    T to() const;
    bool operator< (const unidirected_edge& other) const;
    bool operator== (const unidirected_edge& other) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& edge)

template<typename T>
class unidirected_graph{
    std::map<T, std::vector<std::pair<T, int>>> adiacenza;
    std::set<unidirected_edge<T>> edge;
    std::string name;
public:
    unidirected_graph();
    unidirected_graph(const unidirected_graph& other);
    std::vector<std::pair<T,int>> neighbours(const T& nodo) const
    void add_edge(T a, T b, int w = 1);
    std::set<unidirected_edge<T>> all_edges() const;
    std::set<T> all_nodes() const;
    int edge_number(const unidirected_edge<T> & arco) const;
    std::optional<unidirected_edge<T>> edge_at(int num) const;
    unidirected_graph operator-(const unidirected_graph& other) const;
}

