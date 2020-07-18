#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

#define N 100
using namespace std;

//function to get the cofactor
void getCofactor(double mat[N][N],double temp[N][N],int p,int q,int n)
{
    int i=0,j=0;
    for (int row=0;row<n;row++)
    {
        for(int columon=0;columon<n;columon++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if(row!=p && columon!=q)
            {
                temp[i][j++]=mat[row][columon];
                // Row is filled, so increase row index and
                // reset col index
                if(j==n-1)
                {
                    j=0;
                    i++;
                }
            }
        }
    }
}


/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
double determinantOfMatrix(double mat[N][N],int n)
{
    //initialize result
    double D=0;
    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];
    double temp[N][N]; //to store cofactors
    double sign=1; //to store sign multiplier
    for (int f=0;f<n;f++)
    {
        getCofactor(mat,temp,0,f,n);
        D += sign*mat[0][f]*determinantOfMatrix(temp,n-1);
        sign=-sign;
    }
    return D;
}
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double mat[N][N],double adj[N][N],int n)
{
    if (n==1)
    {
        adj[0][0]=1;
        return;
    }
    // temp is used to store cofactors of A[][]
    double sign = 1, temp[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(mat,temp,i,j,n);
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((j+i)%2==0)? 1: -1;
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i]=sign*(determinantOfMatrix(temp,n-1));
        }
    }
}
// Function to calculate and store inverse, returns false if
// matrix is singular
void inverse(double mat[N][N],double inverse[N][N],int n)
{
    // Find determinant of A[][]
    double det = determinantOfMatrix(mat,n);
    if (det == 0)
    {
        cout << "ERROR";
        exit(0);
    }
    // Find adjoint
    double adj[N][N];
    adjoint(mat,adj,n);
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            inverse[i][j] = adj[i][j]/det;
}

int main()
{
    //defining operation character and os and intilaiting it with "["
    char c;
    ostringstream os("");
    os << "[";
    //initalizing my inergers
    int x1=1,x2=1,y1=1,y2=1,z1,z2,p=0,q=0,n1;
    float n;
    string s1,s2,answer;
    //geting first string and operation
    getline(cin,s1);
    cin>>c;
    //checking if the operation is ^ as if so we don't need the second array
    if(c=='/')
    {
        cin.ignore();
        getline(cin,s2);
        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }

        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
        //getting the number of rows in matrices
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                x2++;
        }
        //getting the index of the last number before the first ;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                {
                    z2=i;
                    break;
                }
        }
        //getting the number of columns
        for(int i=0;i<z2;i++)
        {
            if(s2[i]==' ')
                y2++;
        }
        //removing ; from s2
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                s2[i]=' ';
        }
        //removing [ ] from s1 and s2
        s2.erase(0,1);
        s2.erase(s2.size()-1,1);
    }
    else if (c=='I')
    {
        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }
        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
    }
    else if (c=='D')
    {
        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }
        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
    }
    else if(c=='T')
    {
        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }

        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);

    }
    else if(c=='^')
    {
        //ignore is used as toma said to pervert the error from the flush
        cin.ignore();
        cin>>n1;

        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }

        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);


    }
    //if the operation is not ^ then we want the second array from the user
    else
    {
        cin.ignore();
        getline(cin,s2);
        //getting the number of rows in matrix
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                x1++;
        }

        //getting the index of the last number before the first ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                {
                    z1=i;
                    break;
                }
        }

        //getting the number of columns
        for(int i=0;i<z1;i++)
        {
            if(s1[i]==' ')
                y1++;
        }

        //removing ; from s1
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==';')
                s1[i]=' ';
        }

        //removing [ ] from s1 and s2
        s1.erase(0,1);
        s1.erase(s1.size()-1,1);
        //getting the number of rows in matrices
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                x2++;
        }
        //getting the index of the last number before the first ;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                {
                    z2=i;
                    break;
                }
        }
        //getting the number of columns
        for(int i=0;i<z2;i++)
        {
            if(s2[i]==' ')
                y2++;
        }
        //removing ; from s2
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==';')
                s2[i]=' ';
        }
        //removing [ ] from s1 and s2
        s2.erase(0,1);
        s2.erase(s2.size()-1,1);

    }

    //defining our arrays
    double matA[N][N],matB[N][N],inverse1[N][N];
        //trying to fill the array 1
        istringstream is1(s1);
        while(is1>>n)
        {
            matA[p][q]=n;
            q++;
            if(q==y1) { p++; q=0;}
            if(p==x1) break;
        }
        //initalizing p and q again with 0
        p=0;
        q=0;
        //trying to fill the array 2
        istringstream is2(s2);
        while(is2>>n)
        {
            matB[p][q]=n;
            q++;
            if(q==y2) { p++; q=0;}
            if(p==x2) break;
        }

    //if he asked for summition
    if(c=='+')
    {
        float matC[x1][y1];
        if( x1!=x2 || y1!=y2 )
        {cout<<"ERROR"; exit(0);}
        //summing at all
        for(int i=0;i<x1;i++)
           for(int j=0;j<y1;j++)
                matC[i][j]=matA[i][j]+matB[i][j];
        //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y1;j++)
            {
            os << matC[i][j];
            if((i+1)==x1 && (j+1)==y1) break;
            if((j+1)==y1) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;

    }
    //if he asked for substrction
    else if(c=='-')
    {
        float matC[x1][y1];
        if( x1!=x2 || y1!=y2 )
        {cout<<"ERROR"; exit(0);}
         //to substruct it all
         for(int i=0;i<x1;i++)
       for(int j=0;j<y1;j++)
            matC[i][j]=matA[i][j]-matB[i][j];
            //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y1;j++)
            {
            os << matC[i][j];
            if((i+1)==x1 && (j+1)==y1) break;
            if((j+1)==y1) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;

    }
    //if he asked for multiplication
    else if(c=='*')
    {
        //multiblication y1 must be equal x2 and the new size of the matrix is x1*y2
        if(y1!=x2)
        { cout<<"ERROR"; exit(0);}
        double matC[x1][y2];
        //summing it to zero and getting red of the garbage
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                matC[i][j]=0;
        //multiblication
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                for(int k=0;k<y1;k++)
                    matC[i][j]+=matA[i][k]*matB[k][j];
          //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y2;j++)
            {
            os << matC[i][j];
            if((i+1)==x1 && (j+1)==y2) break;
            if((j+1)==y2) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;

    }
    //if he asked for the power note that it has to be a sqaure matrices
    else if(c=='^')
    {
        if(x1!=y1) { cout<<"ERROR"; exit(0);}
        //defining two arrays one as temp and the other to be the unit matrix which will be the one that carries the multiplication
        float matMULTI[x1][y1],matTEMP[x1][y1];
        for(int i=0;i<x1;i++)
            for(int j=0;j<y1;j++)
                matMULTI[i][j]= (i==j);
        //performing the power operation
        for(int w=0;w<n1;w++)
        {
            for(int i=0;i<x1;i++)
               {for(int j=0;j<x1;j++)
                {
                    matTEMP[i][j]=0;
                    for(int k=0;k<x1;k++)
                        matTEMP[i][j]+=matMULTI[i][k]*matA[k][j];
                }
               }
            for(int i=0;i<x1;i++)
                for(int j=0;j<x1;j++)
                    matMULTI[i][j]=matTEMP[i][j];

        }
        //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<x1;j++)
            {
            os << matMULTI[i][j];
            if((i+1)==x1 && (j+1)==x1) break;
            if((j+1)==x1) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;

    }

    else if(c=='T')
    {
        float matTRANCE[y1][x1];
        for(int i=0;i<y1;i++)
            for(int j=0;j<x1;j++)
                matTRANCE[i][j]=matA[j][i];
        //converting the array to a string
        for(int i=0;i<y1;i++)
        {
            for(int j=0;j<x1;j++)
            {
            os << matTRANCE[i][j];
            if((i+1)==y1 && (j+1)==x1) break;
            if((j+1)==x1) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;
    }
    else if(c=='D')
    {
        if(x1!=y1) { cout<<"ERROR"; exit(0);}
        double ans = determinantOfMatrix(matA,x1);
        cout<<ans;

    }
    else if(c=='I')
    {
        if(x1!=y1) { cout<<"ERROR"; exit(0);}
        inverse(matA,inverse1,x1);
        //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y1;j++)
            {
            os << inverse1[i][j];
            if((i+1)==x1 && (j+1)==y1) break;
            if((j+1)==y1) os << ";";
            else os << " ";
            }

        }

        os << "]";
        answer=os.str();
        cout<<answer;

    }
    else if(c=='/')
    {
        if(y1!=x2) { cout<<"ERROR"; exit(0);}
        inverse(matB,inverse1,x2);
        float matC[N][N];
        //summing it to zero and getting red of the garbage
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                matC[i][j]=0;
        //multiblication
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                for(int k=0;k<y1;k++)
                    matC[i][j]+=matA[i][k]*inverse1[k][j];
        
          //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y2;j++)
            {
            os << matC[i][j];
            if((i+1)==x1 && (j+1)==y2) break;
            if((j+1)==y2) os << ";";
            else os << " ";
            }
        }
        os << "]";
        answer=os.str();
        cout<<answer;
    }

    return 0;
}
