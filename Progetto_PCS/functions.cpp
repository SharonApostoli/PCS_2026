#include <iostream>
#include <fstream> //file I/O
#include <string>
#include <map>
#include <set>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "progetto.h"


void read_file(const std::string filename, unidirected_graph<T>& G){
    std::ifstream ifs(filename);

    //Controllo se il file è stato aperto correttamente
    if(!ifs.is_open()){
        std::cerr << "Il file dei dati non è stato aperto correttamente! \n";
        return -1;
    }


    //Se siamo qui, il file è stato aperto correttamente
    //La prima variabile che troviamo sarà il tipo (R oppure V) seguita dal numero 
    //Devo ancora creare gli oggetti da inserire qui
    //Subito dopo avremo il valore della componente (resistenza o tensione) 
    
    //Infine avremo gli estremi dell'arco 

    
    //Estraiamo ora i dati dal file, andando avanti fino a che riesco a leggere il risultato
    while(ifs >> name >> peso >> nodo1 >> nodo2){
        G.add_edge(nodo1, nodo2, peso);
    }

    file.close();
}

class unidirected_edge{
    T node_f;
    T node_t;

public:
    unidirected_edge(const T& partenza, const T& arrivo){
        if(partenza < arrivo){
            node_f = partenza;
            node_t = arrivo;
        }else{
            node_f = arrivo;
            node_t = partenza;
        }
    }

    T from() const {
        return node_f;
    }

    T to() const {
        return node_t;
    }

    bool operator< (const unidirected_edge& other) const {
        unidirected_edge ret = *this;
        if(ret.node_f != other.node_f){
            return ret.node_f < other.node_f;
        }
        return ret.node_t < other.node_t;
    }

    bool operator== (const unidirected_edge& other) const {
        unidirected_edge ret = *this;
        return (ret.node_f == other.node_f && ret.node_t == other.node_t);
    }
};

//operator<<
template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& edge){
    os << "(" << edge.from() << ", " << edge.to() << ")";
    return os;
}

template<typename T>
class unidirected_graph{
    std::map<T, std::vector<std::pair<T, int>>> adiacenza;
    std::set<unidirected_edge<T>> edge;
    std::string name;
public:
    unidirected_graph(){
    };

    unidirected_graph(const unidirected_graph& other){
        adiacenza = other.adiacenza;
        edge = other.edge;
    }

    std::string get_name() const{
        return name;
    }

    std::vector<std::pair<T,int>> neighbours(const T& nodo) const{
        auto key = adiacenza.find(nodo);
        if(key == adiacenza.end()){
            return {};
        }
        return key -> second;
    }

    void add_edge(T a, T b, int w = 1){
        unidirected_edge<T> arco(a, b);
        if(edge.find(arco) != edge.end()){
            return;
        }
        edge.insert(arco);
        adiacenza[a].push_back({b, w});
        adiacenza[b].push_back({a, w});
    }

    std::set<unidirected_edge<T>> all_edges() const{
        return edge;
    }

    std::set<T> all_nodes() const{
        std::set<T> nodi;
        for(const auto& pair : adiacenza){
            nodi.insert(pair.first);
        }
        return nodi;
    }

    int edge_number(const unidirected_edge<T> & arco) const{
        int pos = 0;
        for(const unidirected_edge<T>& i : edge){
            if(i == arco){
                return pos;
            }
            pos++;
        }
        return -1;
    }

    std::optional<unidirected_edge<T>> edge_at(int num) const{
        if(num < 0 || num >= edge.size()){
            return std::nullopt;
        }
        auto it = edge.begin();
        std::advance(it, num);
        return *it;
    }

    unidirected_graph operator-(const unidirected_graph& other) const{
        unidirected_graph archi;
        for(const unidirected_edge<T>& el : edge){
            if(other.edge.find(el) == other.edge.end()){
                archi.add_edge(el.from(), el.to(), 1);
            }
        }
        return archi;  
    }
};

//presa da es_9 e modificata per cercare gli archi con i nomi
Eigen::VectorXd graph_visit_dfs_search(const unidirected_graph<double>& G, int v, char ){
    
    std::set<int> visited;
    std::vector<int> stack;
    std::vector<int> selected;

    visited.insert(v);
    stack.push_back(v);

    while(!stack.empty()){
        int node = stack.back();
        stack.pop_back();

        std::string nome = G.get_name();

        if(nome[0] == type){
            selected.push_back()
        }

        for(auto [vicino, peso] : G.neighbours(node)){
            if(!visited.count(vicino)){
                visited.insert(vicino);
                stack.push_back(vicino);
            }
        }
    }
    
}

Eigen::MatrixXd Rmatrix(const unidirected_graph& G){

    std::vector resistenze 
    
    return resist.asDiagonal();
}