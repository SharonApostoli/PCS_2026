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
            Componente Gcomp = G.get_componente(v, vicino);
            tree.add_edge(v, vicino, Gcomp.nome, Gcomp.valore, Gcomp.nodo_pos);
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

//Cerchiamo un cammino
//Funzione aiuto
bool find_path_aiuto(const unidirected_graph<int>& T, int u, int v, std::vector<int>& path, std::set<int>& visited){
    //Qui segno u come visitato
    visited.insert(u);
    //Qui segno u come inizio del mio ipotetico cammino
    path.push_back(u);

    //Se sono arrivata a v: finito, esiste cammino tra u e v e restituisco vero
    if(u == v){
        return true;
    }

    //Se no sono arrivata a v: esploro i nodi che non ho ancora visitato
    for(auto [vicino, w] : T.neighbours(u)){
        if(!visited.count(vicino)){
            if(find_path_aiuto(T, vicino, v, path, visited)){
                return true;
            }
        }
    }

    //Se invece arrivo qui, ho esplorato tutti i nodi e v non c'è.
    path.pop_back();
    return false;
}
//Funzione principale
std::vector<int> find_path(const unidirected_graph<int>& T, int u, int v, ){
    std::vector<int> path;
    std::set<int> visited;

    find_path_aiuto(T, u, v, path, visited);
    //Qui restituisco path: l'eventuale cammino tra u e v, se eiste.
    return path;
}

cicli_fondamentali_dfs(const unidirected_graph<int>& G){
    //Cominciamo con la creazione dell'abero di supporto (da definire come trovare v)
    unidirected_graph<int> T = recursive_dfs(G, v);

    //Coalbero
    unidirected_graph<int> C = G - T; 

    /*Per ogni arco del coalbero C trovo il perorso in T tale che 
    quel percorso + l'arco = ciclo (= maglia del circuito)*/
    for(const auto& edge : C.all_edges()){

    }

}





template<typename T>
Eigen::MatrixXd Rmatrix(const unidirected_graph<T>& G){
    std::vector<T> resistori = G.valori_res();
    
    
    return resist.asDiagonal();
}