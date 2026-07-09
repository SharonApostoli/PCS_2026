#include <iostream>
#include <fstream> //file I/O
#include <string>
#include <map>
#include <set>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "progetto.h"


void read_file(const std::string filename, unidirected_graph<int>& G){
    std::ifstream ifs(filename);

    //Controllo se il file è stato aperto correttamente
    if(!ifs.is_open()){
        std::cerr << "Il file dei dati non è stato aperto correttamente! \n";
        return;
    }

    //Se siamo qui, il file è stato aperto correttamente
    //La prima variabile che troviamo sarà il tipo (R oppure V) seguita dal numero
    std::string name;
    //Subito dopo avremo il valore della componente (resistenza o tensione)
    double valore;
    //Infine avremo gli estremi dell'arco 
    int nodo1, nodo2;

    //Estraiamo ora i dati dal file, andando avanti fino a che riesco a leggere il risultato
    while(ifs >> name >> valore >> nodo1 >> nodo2){
        //per i generatori il nodo_pos è nodo1, per i resistori è 0 
        int nodo_pos = (name[0] == 'V') ? nodo1 : 0;
        G.add_edge(nodo1, nodo2, name, valore, nodo_pos);
    }

    ifs.close();
}

//Algoritmo DFS
//Funzione aiuto
void recursive_dfs_aiuto(const unidirected_graph<int>& G, int v, unidirected_graph<int>& tree, std::set<int>& visited){
    visited.insert(v);
    for(auto [vicino, peso] : G.neighbours(v)){
        if(!visited.count(vicino)){
            tree.add_edge(v, vicino, G.get_componente);
            recursive_dfs_aiuto(G, vicino, tree, visited);
        }
    }
}
//Funzione ricorsiva
unidirected_graph<int> recursive_dfs(const unidirected_graph<int>& G, int v){
    unidirected_graph<int> tree;
    std::set<int> visited;

    recursive_dfs_aiuto(G, v, tree, visited);

    return tree;
}



template<typename T>
Eigen::MatrixXd Rmatrix(const unidirected_graph<T>& G){
    std::vector<T> resistori = G.valori_res();
    
    
    return resist.asDiagonal();
}