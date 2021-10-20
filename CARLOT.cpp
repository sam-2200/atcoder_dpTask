#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool sortbysecdesc(const pair<ll,ll> &a, 
                   const pair<ll,ll> &b) 
{ 
       return a.first>b.first; 
} 
int main()
{
    ll t;
    cin>>t;
    if(t<1||t>100)
        exit(0);
    while(t--)
    {
        vector<pair<ll,ll>> ans;
        ll m,n;
        cin>>m>>n;
        if(m<1||n<1||n>300||m>300)
            exit(0);
        char a[m][n];
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='P')
                {
                    ans.push_back(make_pair(i+1,j+1));
                }
            }
            


        }
        ll len=ans.size();
        ans.push_back(make_pair(-1,-1));
        ans.push_back(make_pair(-1,-1));
        
        ll row=1;
        ll col=1;
        ll rowmax=0;
        ll rowmin;
        ll count=0;
        ll temp=max(m,n);
        ll i=0;
        

        while(temp--) 
        { 
            if(row==ans[i].first)
            {
                rowmin=ans[i].second;
                while(row==ans[i].first)
                {
                    
                    rowmax=ans[i].second;
                    i++;
                    //cout<<"i="<<i<<endl;
                }
                count=count+(rowmax-rowmin);
                //cout<<"count1="<<count<<endl;
            }  
            row=row+1;
        }

        ll te=m-1;
        ll rowmp;
        ll rowmc;
        ll j=0;
        ll rowp=1;
        ll rowc;
        ll k=0;
        //ll c=0;


        while(te--)//&&j<=len&&k<=len)
        {
            rowmp=ans[j].second;
            if(rowp==ans[j].first)
            {
                while(rowp==ans[j].first)
                {
                    j++;
                }
                
                rowc=rowp+1;
                rowmc=ans[j].second;
                k=j;
                while(rowc==ans[k].first)
                {
                    k++;
                }
                if(rowp%2!=0)
                {
                    count=count+abs(ans[j-1].second-ans[k-1].second)+1;
                    //cout<<"count2="<<count<<endl;
                }
                else
                {
                    count=count+abs(rowmc-rowmp)+1;
                    //cout<<"count3="<<count<<endl;
                }
                rowp++;
            }
           // cout<<"j="<<j<<"k="<<k<<endl;
        }
        ll temp1=0;
        ll temp2=0;
        for(ll q=0;q<len-1;q++)
        {
            temp1=ans[q+1].first;
            temp2=ans[q].first;

            if((temp1-temp2)>1)
            {
                count=count+temp1-temp2;   
                count=count+abs(ans[q].second-ans[q+1].second);
                
            }

        }

        cout<<count<<endl;
    }
    return 0;
}
