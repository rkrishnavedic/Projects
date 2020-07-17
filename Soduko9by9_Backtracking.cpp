#include <bits/stdc++.h>

using namespace std;

#define ll int
#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)

ll ans=0;

//noissue fuction checks if we can place the number (1-9) on the particular cell or not
bool noissue(vector<vector<ll>> &board, ll go, ll input){

//Let us extract row and colum from go integer (which is a loop integer going from 0 to 80 and returning the answer at go=81)
      ll row=go/9; ll col=go%9;
    fori(9){
        if(row!=i){
            if(input==board[i][col]){
                return false;
            }
        }
        if(col!=i){
            if(input==board[row][i]) return false;
        }
    }
    //There are 9 blocks of each size 3x3
    //let us find in which block it is inside
    ll block_x=row/3;
    //if block_x == 0 it is in first column of block matrix
    ll block_y=col/3;
    //starting position of the block of 3x3 matrix
    ll starting_x=block_x*3;
    ll starting_y=block_y*3;
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            if(row==starting_x+i && col==starting_y+j){
                continue;
            }
            if(board[starting_x+i][starting_y+j]==input){
                return false;
            }
        }
    }
    
    return true;
}

//Here is the backtracking step which is basically a recursion
void backtrackingrecursion(vector<vector<ll>> &board, ll go){
    if(ans>0) return;
    if(go==81){
        ans++;
        cout<<"\nSolution :\n";
        //cout<<"\nSolution "<<ans<<" :\n";
        fori(9){
            forj(9){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    ll row=go/9; ll col=go%9;
    
    if(board[row][col]==0){
        fori(9){
            if(noissue(board, go, i+1)){
                board[row][col]=i+1;
                backtrackingrecursion(board, go+1);
                board[row][col]=0;
            }
        }
    }
    else{
        backtrackingrecursion(board, go+1);
    }
}

int main(){

//let us denot ll as int 
    
    ll n=9;
    
    vector<vector<ll>> board(n,vector<ll>(n,-1));
    
    cout<<"Soduko Solver 9x9:\n";
    cout<<"Input the Incomplete Soduko as input: \n";
    cout<<"(Please, keep space between the numbers and input 0 for empty boxes)\n";
    //Let us take the input
    fori(n){
        forj(n){
            cin>>board[i][j];
        }
    }
    //Let us now backtrack for the solution
    backtrackingrecursion(board, 0);
    
    return 0;
}
