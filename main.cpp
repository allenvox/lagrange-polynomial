#include <iostream>
#include <fstream>

using namespace std;

struct Data
{
    double x, y;
};

double interpolate(Data f[], int X, int n_points)
{
    double result = 0;
    for (int i = 0; i < n_points; i++)
    {
        // Compute individual terms of above formula
        double term = f[i].y;
        for (int j = 0; j < n_points; j++)
        {
            if (j != i)
            {
                term = term * (X - f[j].x) / (f[i].x - f[j].x);
            }
        }
        // Add current term to result
        result += term;
    }
    return result;
}

int main()
{
    ifstream file("in.txt");
    Data f[5]; // {{0.847, 1.104}, {1.546, 1.042}, {1.834, 0.029}, {2.647, -0.344}, {2.91, -0.449}};
    for (int i = 0; i < 5; i++)
    {
        file >> f[i].x;
    }
    for (int i = 0; i < 5; i++)
    {
        file >> f[i].y;
    }
    int X = 1, N = 5;
    cout << "Lagrange polynomial: ";
    for (int i = 0; i < N; i++)
    {
        cout << "(" << f[i].x << ", " << f[i].y << ") ";
    }
    cout << endl
         << "f(" << X << ") = " << interpolate(f, X, N) << endl;
    return 0;
}