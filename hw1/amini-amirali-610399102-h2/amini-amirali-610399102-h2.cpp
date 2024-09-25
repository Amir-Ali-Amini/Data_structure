//P name
//Fig : 
//use ?:
//date
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<cstdlib>
#include <ctime>
#include <time.h>
using namespace std;


//----------------------------------------------------------------------------------
int main () 
{
    int m [100][100][100];
    for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                m[i][j][k] = rand() ;
            }
        }
    }

    const clock_t begin_time1 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                int temp =(~m[i][j][k]) ;
            }
        }
    }
cout<< float( clock () - begin_time1 ) / CLOCKS_PER_SEC;
cout <<endl;
    const clock_t begin_time2 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                int temp =(~m[i][k][j]) ;
            }
        }
    }
cout<< float( clock () - begin_time2 ) / CLOCKS_PER_SEC;
cout <<endl;
    const clock_t begin_time3 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
               int temp =(~m[j][k][i]) ;
            }
        }
    }
cout<< float( clock () - begin_time3 ) / CLOCKS_PER_SEC;
cout <<endl;
    const clock_t begin_time4 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                int temp =(~m[j][i][k]) ;
            }
        }
    }
cout<< float( clock () - begin_time4 ) / CLOCKS_PER_SEC;
cout <<endl;
    const clock_t begin_time5 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                int temp =(~m[k][j][i]) ;
            }
        }
    }
cout<< float( clock () - begin_time5 ) / CLOCKS_PER_SEC;
cout <<endl;
    const clock_t begin_time6 = clock();    
for (int i = 0 ; i < 100 ; i++)
    {
        for (int j = 0 ; j < 100 ; j++)
        {
            for (int k = 0 ; k<100 ; k++)
            {
                int temp =(~m[j][i][j]) ;
            }
        }
    }
cout<< float( clock () - begin_time6 ) / CLOCKS_PER_SEC;
}