#include <iostream>
#include <Eigen/Core>
using namespace Eigen;

int main()
{
    MatrixXd::Index maxRow, maxCol;
    MatrixXd::Index minRow, minCol;
    MatrixXd x(4,4);
    x << 11, 10, 13, 15,
         3, 24, 56, 1,
         2, 12, 45, 0,
         8, 5,  6,  4;
    double min = x.minCoeff(&minRow,&minCol);
    double max = x.maxCoeff(&maxRow,&maxCol);
    std::cout << "Max = \n" << max << std::endl;
    std::cout << "Min = \n" << min << std::endl;
    std::cout << "minRow = " << minRow << "minCol = " <<minCol<<std::endl;
    std::cout << "maxRow = " << maxRow << "maxCol = " << maxCol << std::endl;
    return 0;
}
