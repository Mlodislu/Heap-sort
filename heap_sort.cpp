#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int N = 20;
    int T[N + 1],i,j,k,y,x;

    srand(time(NULL));
    cout<<"Przed sortowaniem: "<<endl<<endl;

    for(i = 1; i <= N; i++)
    {
        T[i] = rand() % 100;
        cout << setw(4) << T[i];
    }
    cout << endl;

    for(i = 2; i <= N; i++)
    {
        j = i;
        k = j / 2;
        x = T[i];
        while((k > 0) && (T[k] < x))
        {
            T[j] = T[k];
            j = k;
            k = j / 2;
        }
        T[j] = x;
    }
    for(i = N; i > 1; i--)
    {
        swap(T[1], T[i]);
        j = 1;
        k = 2;
        while(k < i)
        {
            if((k + 1 < i) && (T[k + 1] > T[k]))
                y = k + 1;
            else
                y = k;
            if(T[y] <= T[j]) break;
            swap(T[j], T[y]);
            j = y;
            k = j + j;
        }
    }

    cout << "\nPo sortowaniu:\n\n";
    for(i = 1; i <= N; i++) cout << setw(4) << T[i];
    cout << endl<<endl;
    return 0;
}
