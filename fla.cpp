//Bartosz Salwiczek
#include <iostream>

using namespace std;

int main()
{
    int n,X;

    cin>>n;
    cin>>X;

    int barrierx[n+1];
    int barriera[n+1];
    int barrierb[n+1];
    
    

    for(int i=0;i<n;i++)
    {
        cin>>barrierx[i];
        cin>>barriera[i];
        cin>>barrierb[i];
    }

    //algorytm obliczania ilości stuknięć palcem
    int hits = 0;
    int positionx = 0;
    int positiony = 0;
    for(int i=0;i<X;i++)
    {
        bool ifHit = false;
        for(int j=0;j<n;j++)
        {
            int distToBarrier = barrierx[j]-positionx;
            if(distToBarrier==0)
            {
                if(positiony <= barriera[j] || positiony >= barrierb[j])
                {
                    cout<<"NIE"<<endl;
                    return 0;
                }
            }
            if(distToBarrier>0)
            {
                if(positiony-2 < barriera[j])
                {
                    ifHit = true;
                }
                if(positiony+2 > barrierb[j])
                {
                    ifHit = false;
                }
                if(positiony+1 < barrierb[j] && positiony-1 > barriera[j]) //gdy jest pomiędzy półprostymi zabronionymi to trzymaj się góry lub dołu(w zależności od pozycji kolejnej przeszkody)
                {
                    if(j+1<n)
                    {
                        if(barrierb[j] - barriera[j] > 4)
                        {
                            if(positiony-2 < barriera[j+1])
                            {
                                ifHit = true;
                            }
                            if(positiony+2 > barrierb[j+1])
                            {
                                ifHit = false;
                            }
                        }
                    }
                    if(j+2<n)
                    {
                        if(barrierb[j] - barriera[j] > 4)
                        {
                            if(positiony-2 < barriera[j+2])
                            {
                                ifHit = true;
                            }
                            if(positiony+2 > barrierb[j+2])
                            {
                                ifHit = false;
                            }
                        }
                    }
                }
                break;
            }
        }

        positionx+=1;
        if(ifHit == false)
        {
            positiony -= 1;
        }
        else{
            hits++;
            positiony += 1;
        }
    }
    cout<<hits<<endl;

    return 0;
}
