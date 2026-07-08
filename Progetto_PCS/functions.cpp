#include <iostream>
#include <fstream> //file I/O
#include <string>
#include <map>
#include <set>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "progetto.h"


template<typename T>
void read_file(const std::string filename, unidirected_graph<T>& G){
    std::ifstream ifs(filename);

    //Controllo se il file è stato aperto correttamente
    if(!ifs.is_open()){
        std::cerr << "Il file dei dati non è stato aperto correttamente! \n";
        return;
    }

    //Se siamo qui, il file è stato aperto correttamente
    //La prima variabile che troviamo sarà il tipo (R oppure V) 
    std::string name;
    //seguita dal numero 
    doule valore;
    //Subito dopo avremo il valore della componente (resistenza o tensione) 
    
    //Infine avremo gli estremi dell'arco 
    int nodo1, nodo2;

    
    //Estraiamo ora i dati dal file, andando avanti fino a che riesco a leggere il risultato
    //Da mettere apposto
    while(ifs >> name >> valore >> nodo1 >> nodo2){
        G.add_edge(nodo1, nodo2, valore);
    }

    ifs.close();
}



template<typename T>
Eigen::MatrixXd Rmatrix(const unidirected_graph<T>& G){
    std::vector<T> resistori = G.valori_res();
    
    
    return resist.asDiagonal();
}