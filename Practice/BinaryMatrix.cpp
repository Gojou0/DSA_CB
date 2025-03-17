#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin>>matrix[i][j];
            }
        }
        int cnt=0;
        for(int i =0;i<n;i++){
            int x=0;
            for(int j =0;j<m;j++){
                x = x^matrix[i][j];
            }
            if(x!=0){
                cnt++;
            }
        }
        int cnt1=0;
        for(int j =0;j<m;j++){
            int x=0;
            for(int i =0;i<n;i++){
                x = x^matrix[i][j];
            }
            if(x!=0){
                cnt1++;
            }
        }
        cout<<max(cnt,cnt1)<<endl;
    }    
}