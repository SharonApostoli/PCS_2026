#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

Eigen::VectorXd grad_cong(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const double res_tol, const unsigned int it_max, int n){
    //adesso partiamo con l'algoritmo. partiamo da x = 0
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    //adesso prendo il vettore residuo iniziale
    Eigen::VectorXd res = b - A * x;
    //e ne definisco la norma ottenuta con x = 0
    double res_norm_0 = res.norm();
    //seguendo lo pseudocodice, pongo p uguale al residuo iniziale
    Eigen::VectorXd p = res;

    //iterazioni massime
    unsigned int it = 0;
    
    while(it < it_max && res.norm() > res_tol * res_norm_0){
        /*versione matriciale
        double alpha_k = ((p.transpose() * r) / (p.transpose() * A * p)).value();
        */
        double alpha_k = p.dot(res) / p.dot(A * p);
        x = x + (alpha_k * p);
        res = b - (A * x);
        double beta_k = p.dot(A * res) / p.dot(A * p);
        p = res - (beta_k * p);
        it++;
    }

    std::cout <<  "Numero iterazioni: " << it << std::endl;

    std::cout.precision(4);
    std::cout << "Dimensione matrice: " << n <<std::endl;

    std::cout << std::scientific << "it" << "/" << "it_max" << std::endl;
    std::cout << std::scientific << it << "/" << it_max<< std::endl;

    std::cout << std::scientific << "res" << "/" << "res_tol" << std::endl;
    std::cout << std::scientific << res.norm() / res_norm_0<< "/" << res_tol << std::endl;

    return x;
}