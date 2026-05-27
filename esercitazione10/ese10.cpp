#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "ese10.h"

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(int argc, char **argv){
    //indico la tolleranza
    const double tol = 1.0e-10;

    for(int n = 3; n < 30; n++){
        //costruisco la matrice B in maniera random
        Eigen::MatrixXd B = Eigen::MatrixXd::Random(n,n);

        //qui controllo che la matrice B sia invertibile
        if(abs(B.determinant()) < tol)
            return -1;

        //definisco la matrice A in questo modo cosi che sicuramente sara simmetrica semidef. pos.
        Eigen::MatrixXd A = B.transpose() * B;
        //definidco ora la soluzione esatta x = 1
        Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
        //posso ora costruire b cosi da far riportare x
        Eigen::VectorXd b = A * x_ex;

        //tolleranza residuo e iterazioni massime
        const double res_tol = 1.0e-10;
        const unsigned int it_max = 10000;    

        std::cout.precision(2);
        std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

        //algoritmo
        Eigen::VectorXd x = grad_cong(A, b, res_tol, it_max, n);

        //errore relativo
        const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() : (x - x_ex).norm() / x_ex.norm();

        std::cout << std::scientific << "err_rel" << std::endl;
        std::cout << std::scientific << err_rel << std::endl;

        std::cout << std::scientific << "soluzione" << std::endl;
        std::cout << std::scientific << x << std::endl << std::endl;
    };
    
    return 0;
}