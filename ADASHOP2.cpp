#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int test;
    cin>>test;
    if (test>0 || test<33)
    {
    while(test--)
    {
        int x,y;
        cin>>x>>y;
        if(x<0 || x>9 || y<0 || y>9 || (x+y)%2!=0 )
        {
            continue;
        }
        vector<pair<int,int>> pts;
        pts.push_back(make_pair((x+y)/2,(x+y)/2));
        pts.push_back(make_pair(1,1));
        for(int i=1;i<4;i++)
        {
            pts.push_back(make_pair(i+1,i+1));
            pts.push_back(make_pair(1,(2*i)+1));
            pts.push_back(make_pair((2*i)+1,1));
            pts.push_back(make_pair(i+1,i+1));


        }
        for(int i=1;i<4;i++)
        {
            pts.push_back(make_pair(i+4,i+4));
            pts.push_back(make_pair(8,2*i));
            pts.push_back(make_pair(2*i,8));
            pts.push_back(make_pair(i+4,i+4));
        }
        pts.push_back(make_pair(8,8));
        if(x!=y)
        {
            printf("26\n");
            for(int i=0;i<pts.size()-1;i++)
            {
                printf("%d %d\n",pts[i+1].first,pts[i+1].second);
            }
        }
        else if(x==1 &&y==1)
        {
            printf("25\n");
            for(int i=1;i<pts.size()-1;i++)
            {
                printf("%d %d\n",pts[i+1].first,pts[i+1].second);
            }
        }
        else
        {
            printf("25\n");
            for(int i=0;i<pts.size()-1;i++)
            {
                printf("%d %d\n",pts[i+1].first,pts[i+1].second);
            }
    
        }
       
        
    }
    }
    else
    {
        return 0;
    }
    
    return 0;
}