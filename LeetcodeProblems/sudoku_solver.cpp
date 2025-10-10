class Solution {
public:
    vector<vector<char>> ans;
    void solveSudoku(vector<vector<char>>& b){
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    int a = b[i][j]-'0';
                    
                    mr[i][a]=1;
                    mc[j][a]=1;
                    mb[i/3][j/3][a]=1;
                }
            }
        }
        solveSudoku1(b);
        b = ans;
    }

    map<vector<vector<char>>, int> mp1;
    int mr[10][10],mc[10][10],mb[3][3][10];
    int solveSudoku1(vector<vector<char>> &b) {
        if(b[0][2]=='9'){cout<<"to";}
        if(mp1.find(b)!=mp1.end()){return 0;}
        mp1[b]=0;
        int t=0;
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.'){
                    t++;
                    break;
                }
            }
        }
        if(t==0){
            ans = b;
            return 1;
        }


        vector<pair<int,int>> vp;
        int maxx=INT_MAX, ii1, jj1;
        int fi=0;
        while(fi==0){
        fi=1;
        maxx=INT_MAX;
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    continue;
                }
                else{
                    int f=0, kk=0;
                    for(int k=1;k<10;k++){
                        if(mr[i][k]==0 && mc[j][k]==0 && mb[i/3][j/3][k]==0){
                            f++;
                            kk=k;
                            
                        }
                    }

                    if(f==1){
                        fi=0;
                        b[i][j]=('0'+kk);
                        vp.push_back({i,j});
                        // cout<<i<<" add "<<j<<" k "<<kk<<endl;
                        mr[i][kk]=1; mc[j][kk]=1; mb[i/3][j/3][kk]=1;
                    }


                    if(f==0){
                        for(int x=0;x<vp.size();x++){
                            int ii = vp[x].first, jj= vp[x].second;
                            int k1 = b[ii][jj]-'0';
                            // cout<<k1<<endl;
                            b[ii][jj]='.';
                            mr[ii][k1]=0; mc[jj][k1]=0; mb[ii/3][jj/3][k1]=0;
                        }
                        return 0;
                    }

                    if(f<maxx && f>1){
                        maxx = f;
                        ii1 = i;
                        jj1 = j;
                    }
                }
            }
        }
        }



        int p=1;

        int i = ii1, j=jj1;
        for(int k=1;k<10;k++){
            if(mr[i][k]==0 && mc[j][k]==0 && mb[i/3][j/3][k]==0){
                  b[i][j]='0'+k;
                  mr[i][k]=1; mc[j][k]=1; mb[i/3][j/3][k]=1;
                  int a1 = solveSudoku1(b);
                  if(a1==1){return 1;}
                  mr[i][k]=0; mc[j][k]=0; mb[i/3][j/3][k]=0;
                  b[i][j]='.';

            }
        }

        int k = 1;
        int fin=0;
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.'){fin=1; p=0;}
            
            }
        }
        if(fin==0){ans = b;}
        for(int x=0;x<vp.size();x++){
                            int ii = vp[x].first, jj= vp[x].second;
                            int kk = b[ii][jj]-'0';
                            b[ii][jj]='.';
                            mr[ii][kk]=0; mc[jj][kk]=0; mb[ii/3][jj/3][kk]=0;
        }

        return p;
    }
};
