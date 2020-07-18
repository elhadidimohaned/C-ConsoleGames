#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int main()
{
    char c;
    ostringstream os("");
    os << "[";
    int x1=1,x2=1,y1=1,y2=1,z1,z2,p=0,q=0;
    float n;
    string s1,s2,answer;
    getline(cin,s1);
    cin>>c;
    cin.ignore();
    getline(cin,s2);

    //getting the number of rows in matrices
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==';')
            x1++;
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]==';')
            x2++;
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
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]==';')
            {
                z2=i;
                break;
            }
    }
    //getting the number of columns
    for(int i=0;i<z1;i++)
    {
        if(s1[i]==' ')
            y1++;
    }
    for(int i=0;i<z2;i++)
    {
        if(s2[i]==' ')
            y2++;
    }
    //outputting the number of xs and ys
    //cout<<"x and y: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    //defining the matrices
    float matA[100][100],matB[100][100],matA1[100][100],matB1[100][100];
    //removing ; from s1
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==';')
            s1[i]=' ';
    }
    //removing ; from s2
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]==';')
            s2[i]=' ';
    }
    //removing [ ] from s1 and s2
    s1.erase(0,1);
    s1.erase(s1.size()-1,1);
    s2.erase(0,1);
    s2.erase(s2.size()-1,1);
    /*trying to fill the array 1
    istringstream is1(s1);
    while(is1>>n)
    {
        matA[p][q]=n;
        q++;
        if(q==y1) { p++; q=0;}
        if(p==x1) break;
    }*/
    int sign,imag;
    string temp;
    bool flag;
    for(int i=0;i<x1*y1;i++)
    {
        matA[p][q]=atof(s1.c_str());
        for(int j=1;j<s1.size();j++)
        {
            if(s1[j]=='+' || s1[j]=='-')
            {
                sign=j;
                break;
            }
        }
        for(int k=1;k<s1.size();k++)
        {
            if(s1[k]=='i')
            {
                imag=k;
                break;
            }
        }
        if(s1[sign]=='-') flag=true;
        else flag=false;
        temp=s1.substr(sign+1,imag-sign-1);
        if(flag)
            matA1[p][q]=atof(temp.c_str())*-1;
        else
            matA1[p][q]=atof(temp.c_str());
        
        q++;
        if(q==y1) { p++; q=0;}
        if(p==x1) break;
        s1=s1.substr(imag+2);

    }


    //initalizing p and q again with 0
    p=0;
    q=0;
    /*trying to fill the array 2
    istringstream is2(s2);
    while(is2>>n)
    {
        matB[p][q]=n;
        q++;
        if(q==y2) { p++; q=0;}
        if(p==x2) break;
    }*/
    
    for(int i=0;i<x2*y2;i++)
    {
        matB[p][q]=atof(s2.c_str());
        for(int j=1;j<s2.size();j++)
        {
            if(s2[j]=='+' || s2[j]=='-')
            {
                sign=j;
                break;
            }
        }
        for(int k=1;k<s2.size();k++)
        {
            if(s2[k]=='i')
            {
                imag=k;
                break;
            }
        }
        if(s2[sign]=='-') flag=true;
        else flag=false;
        temp=s2.substr(sign+1,imag-sign-1);
        if(flag)
            matB1[p][q]=atof(temp.c_str())*-1;
        else
            matB1[p][q]=atof(temp.c_str());
        
        q++;
        if(q==y2) { p++; q=0;}
        if(p==x2) break;
        s2=s2.substr(imag+2);

    }


    //if he asked for summition
    if(c=='+')
    {
        float matC[100][100],matC1[100][100];
        if( x1!=x2 || y1!=y2 )
        {cout<<"ERROR"; exit(0);}
        //summing at all
        for(int i=0;i<x1;i++)
           for(int j=0;j<y1;j++)
               {
                   matC[i][j]=matA[i][j]+matB[i][j];
                   matC1[i][j]=matA1[i][j]+matB1[i][j];
               }

        //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y1;j++)
            {
            os << matC[i][j];
            if (matC1[i][j]>=0)
                os << "+" << matC1[i][j] <<"i";
            else os << matC1[i][j] <<"i";
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
        float matC[100][100],matC1[100][100];
        if( x1!=x2 || y1!=y2 )
        {cout<<"ERROR"; exit(0);}
         //to substruct it all
         for(int i=0;i<x1;i++)
       for(int j=0;j<y1;j++)
            {
                matC[i][j]=matA[i][j]-matB[i][j];
                matC1[i][j]=matA1[i][j]-matB1[i][j];
            }
            
            //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y1;j++)
            {
            os << matC[i][j];
            if (matC1[i][j]>=0)
                os << "+" << matC1[i][j] <<"i";
            else os << matC1[i][j] <<"i";
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
        float matC[100][100],matC1[100][100];
        //summing it to zero and getting red of the garbage
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                {
                    matC[i][j]=0;
                    matC1[i][j]=0;
                }
        //multiblication
        for(int i=0;i<x1;i++)
            for(int j=0;j<y2;j++)
                for(int k=0;k<y1;k++)
                    {
                        matC[i][j]=matC[i][j]+(matA[i][k]*matB[k][j]-matA1[i][k]*matB1[k][j]);
                        matC1[i][j]=matC1[i][j]+(matA[i][k]*matB1[k][j]+matA1[i][k]*matB[k][j]);
                    }
                    
          //converting the array to a string
        for(int i=0;i<x1;i++)
        {
            for(int j=0;j<y2;j++)
            {
            os << matC[i][j];
            if (matC1[i][j]>=0)
                os << "+" << matC1[i][j] <<"i";
            else os << matC1[i][j] <<"i";
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
