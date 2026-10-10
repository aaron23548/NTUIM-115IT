#include <iostream>
using namespace std;

void function(int** array, int* k, int n, int p, int q, int r);
int main()
{
    int n = 0, m = 0, p = 0, q = 0, r = 0;
    cin >> n >> m >> p >> q >> r;
    int* k = new int[p];
    for(int i = 0; i < p; i++)
    {
        cin >> k[i];
    }
    
    int** array = new int* [n];
    for(int i = 0; i < n; i++)
    {
        array[i] = new int[m];
        for(int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }
    function(array, k, n, p, q, r);
    cout << array[q - 1][r - 1];
    delete [] k;
    for(int i = 0; i < n; i++)
    {
        delete [] array[i];
    }
    delete [] array;
    return 0;
}
void function(int** array, int* k, int n, int p, int q, int r)
{
    while(true)
    {
        bool swap = false;
        for(int i = 0; i < n - 1; i++)
        {
            int comp = 0;
            for(int j = 0; j < p; j++)
            {
                int dim = k[j] - 1;
                if(array[i][dim] < array[i + 1][dim])
                {
                    comp = -1;
                    break;
                }
                else if(array[i][dim] == array [i + 1][dim])
                {
                    comp = 1;
                    break;
                }
            }
            if(comp == 1)
            {
                int* temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
        if(!swap)
            break;
    }
}
