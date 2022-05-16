#include "matrix.h"
Matrix::Matrix(int matixSize) : m_size(matixSize)
{
    m_matrix.resize(m_size, std::vector<int>(m_size));
}
void Matrix::printMatrix()
{
    std::for_each(m_matrix.begin(), m_matrix.end(), [](std::vector<int> rows)
                  {   std::for_each(rows.begin(), rows.end(), [](const int &i){std::cout<<i<<" ";});
     std::cout << std::endl; });
}
void Matrix::fillMatrix()
{
    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            m_matrix[i][j] = (rand() % 10);
}
int Matrix::determinant()
{
    return getDeterminant(m_matrix, m_size);
}
int Matrix::getDeterminant(std::vector<std::vector<int> > matrix, int size)
{
    if (size == 1)
        return matrix[0][0];
    if (size == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    int determinant = 0;
    std::vector<std::vector<int> > minor;
    minor.resize(size - 1, std::vector<int>(size - 1));
    ;

    for (int k = 0; k < size; k++)
    {
        for (int i = 1; i < size; i++)
        {
            int c = 0;
            for (int j = 0; j < size; j++)
            {
                if (j == k)
                    continue;
                minor[i - 1][c] = matrix[i][j];
                c++;
            }
        }
        determinant += pow(-1, k + 2) * matrix[0][k] * getDeterminant(minor, size - 1);
    }
    return determinant;
}
