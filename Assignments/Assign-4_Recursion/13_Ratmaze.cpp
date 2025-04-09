#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool solve(vector<vector<char> > &maze, vector<vector<int> > &sol, int i = 0, int j = 0){
    if (i == maze.size()-1 && j == maze[0].size()-1){
        sol[i][j] = 1;
        for(int a = 0; a < maze.size(); a++){
            for (int b = 0; b < maze[0].size(); b++){
                cout << sol[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
        sol[i][j] = 0;
        return true;          
    }

    sol[i][j] = 1;

    if (i + 1 < maze.size() && maze[i+1][j] != 'X' && sol[i+1][j] == 0){
        bool kyarightsebani = solve(maze, sol, i+1, j);
        if (kyarightsebani) return true;
    }

    if (j + 1 < maze[0].size() && maze[i][j+1] != 'X' && sol[i][j+1] == 0){
        bool kyadownsebani = solve(maze, sol, i, j+1);
        if (kyadownsebani) return true;
    }

    if (i - 1 >= 0 && maze[i-1][j] != 'X' && sol[i-1][j] == 0){
        bool kyaupsebani = solve(maze, sol, i-1, j);
        if (kyaupsebani) return true;
    }

    if (j - 1 >= 0 && maze[i][j-1] != 'X' && sol[i][j-1] == 0){
        bool kyaleftsebani = solve(maze, sol, i, j-1);
        if (kyaleftsebani) return true;
    }

    sol[i][j] = 0;          // Backtracking
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > maze(n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    vector<vector<int> > sol(n, vector<int> (m,0));
    cout << endl;
    if (!solve(maze, sol)){
		cout << "NO PATH FOUND" << endl;
	};
}