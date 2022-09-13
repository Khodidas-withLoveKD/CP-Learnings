#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int> > rotateImage(std::vector<std::vector<int> > a) {

    int temp1,vectSize,temp2,row=0,iteration=0,allowed;

    vectSize=(a.size()+1)/2; cout<<"Vectsize="<<vectSize<<endl;
     allowed=a.size()-2;
    for(int i=0;i<vectSize;i++)
       {    iteration=0;
           for(int j=i,k=a.size()-i-1;j<a.size()-1 && iteration<=allowed;j++)
            {
                cout<<endl<<"Iteration="<<iteration+1<<endl;
                if(a.size()%2!=0 && row==vectSize-1)
                    break;

                cout<<"i="<<i<<endl<<"j="<<j<<endl<<"k="<<k<<endl;
                temp2=a[i][j];

                //top row
                temp1=a[j][k];
                a[j][k]=temp2;
                cout<<"After TOP ROW"<<endl;
                for(int x=0;x < a.size();x++)
                {
                    for(int y=0;y < a.size();y++)
                        cout<<a[x][y]<<",";

                    cout<<endl;
                 }


                //right row
                temp2=a[k][k-j+row];
                a[k][k-j+row]=temp1;
                cout<<"After RIGHT ROW"<<endl;
                for(int x=0;x < a.size();x++)
                {
                    for(int y=0;y < a.size();y++)
                        cout<<a[x][y]<<",";

                    cout<<endl;
                 }


                //bottom row
                temp1=a[k-j+row][i];
                a[k-j+row][i]=temp2;
                cout<<"After BOTTOM ROW"<<endl;
                for(int x=0;x < a.size();x++)
                {
                    for(int y=0;y < a.size();y++)
                        cout<<a[x][y]<<",";

                    cout<<endl;
                 }


                //left row
                a[i][j]=temp1;
                cout<<"After LEFT ROW"<<endl;
                for(int x=0;x < a.size();x++)
                {
                    for(int y=0;y < a.size();y++)
                        cout<<a[x][y]<<",";

                    cout<<endl;
                 }

            iteration++;
            cout<<"--------------------------"<<endl;
            }

            row++;
            allowed-=2;
    }

    return a;
}


int main()
{
    int temp,N;
    vector< vector<int> > vect;
    vector< vector<int> > vect2;

    cin>>N;
    for(int i=0;i<N;i++)
    {
        vector<int> row;
        for(int j=0;j<N;j++)
        {
            cout<<"a["<<i<<"]"<<"["<<j<<"]=";
            cin>>temp;
            row.push_back(temp);
        }
        vect.push_back(row);
    }

    vect2=rotateImage(vect);

    cout<<"--------------------------"<<endl;
    for(int i=0;i < vect2.size();i++)
            {
                for(int j=0;j < vect2.size();j++)
                    cout<<vect2[i][j]<<",";

                cout<<endl;
            }
}


