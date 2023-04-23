#include <stdio.h>

int n; int c=0;
int a[100], pa=0;
int b[100], pb=0;
    
void inp()
{
    //accepts data to be sent
    printf("n : ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        printf("%dth term : ", (i+1));
        scanf("%d", (a+i));
    }    
}

void key()
{
    //ingrave the key at the start and end of each data stream
    b[pb++] = 0;
    for(int i=0; i<6; i++)
        b[pb++] = 1;
    b[pb++] = 0;
}

void stuff()
{
    int c;
    
    key();
    
    for(int i=0; i<n; i++)
    {
        int bit = a[i];
        if(bit == 0)
        {
            if(c == 0)
                ++c;
            else
                c = 0;
            
            b[pb++] = 0;
        }
        else
        {
            if(c == 6)// 0 and 5 1's adds another 0
            {
                c = 0;
                b[pb++] = 0;
            }
            else if(c != 0)
                c += 1;
            
            b[pb++] = 1;
        }
    }
    
    key();
}

int main()
{
    inp();
    stuff();
    for(int i=0; i<pb; i++)
        printf("%d ", *(b+i));
    
    return 0;
}
