#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &M, int i, int j, int ROW,
         int COL)
{
    //Base condition
    //if i less than 0 or j less than 0 or i greater than ROW-1 or j greater than COL-  or if M[i][j] != 1 then we will simply return
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] < 1)
    {
        return;
    }

    if (M[i][j] >= 1)
    {
        M[i][j] = 0;
        // Checking Traversals
        DFS(M, i + 1, j, ROW, COL);
        DFS(M, i - 1, j, ROW, COL);
        DFS(M, i, j + 1, ROW, COL);
        DFS(M, i, j - 1, ROW, COL);
        DFS(M, i + 1, j + 1, ROW, COL);
        DFS(M, i - 1, j - 1, ROW, COL);
        DFS(M, i + 1, j - 1, ROW, COL);
        DFS(M, i - 1, j + 1, ROW, COL);
    }
}

int countIslands(vector<vector<int>> M)
{
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] >= 1)
            {
                M[i][j] = 0;
                count++;
                // checking on traversals
                DFS(M, i + 1, j, ROW, COL);
                DFS(M, i - 1, j, ROW, COL);
                DFS(M, i, j + 1, ROW, COL);
                DFS(M, i, j - 1, ROW, COL);
                DFS(M, i + 1, j + 1, ROW, COL);
                DFS(M, i - 1, j - 1, ROW, COL);
                DFS(M, i + 1, j - 1, ROW, COL);
                DFS(M, i - 1, j + 1, ROW, COL);
            }
        }
    }
    return count;
}

vector<vector<int>> read_data()
{
    ifstream data_file("data.txt");
    vector<vector<int>> dane;
    std::string eachrow;
    if(!data_file.is_open()){
        cout << "Error while opening data file";
        return {};
    }
    while (std::getline(data_file, eachrow))
    {
        std::vector<int> row;

        std::istringstream is( eachrow );
        int n;
        while( is >> n ) {
         row.push_back(n);   // do something with n
        }
        //after iterating row in text file, add vector into 2D vector
        dane.push_back(row);
    }
    return dane;
}


void print_map(vector<vector<int>> M)
{
    for (std::vector<int> &row : M)
    {
        for (int &x : row)
            //print each element
            std::cout << x << ' ';

        //change row
        std::cout << '\n';
    }
}
// Driver Code
int main()
{
    vector<vector<int>> N = read_data();
    // Creating 1D array to find maximum land level
    vector<int> tmp1D;
    for(auto & i : N){
        tmp1D.insert(tmp1D.end(),i.begin(),i.end());
    }
    auto max = *max_element(tmp1D.begin(), tmp1D.end());
    cout << "Max land level is: " << max << endl;
    int water_raised_by_x_levels = 0;
    int initial_island_count = countIslands(N);
    cout << "Number of islands is: " << initial_island_count << endl;
    for(auto i = 0; i < max; i++)
    {
        for(int row = 0; row < N.size(); row++)
        {
            for(int col = 0; col < N[0].size(); col++)
            {
                if(N[row][col] != 0)
                {
                    bool can_be_flooded = false;
                    if(N[row][col] == 1)
                    {
                        if(row + 1 >= 0 && col >= 0 && row + 1 < N.size() && col < N[0].size())
                        {
                            if(N[row + 1][col] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row - 1 >= 0 && col >= 0 && row - 1 < N.size() && col < N[0].size())
                        {
                            if(N[row - 1][col] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row >= 0 && col + 1 >= 0 && row < N.size() && col + 1 < N[0].size())
                        {
                            if(N[row][col + 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row >= 0 && col - 1 >= 0 && row < N.size() && col - 1 < N[0].size())
                        {
                            if(N[row][col - 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row + 1 >= 0 && col + 1 >= 0 && row + 1 < N.size() && col + 1 < N[0].size())
                        {
                            if(N[row + 1][col + 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row - 1 >= 0 && col - 1 >= 0 && row - 1 < N.size() && col - 1 < N[0].size())
                        {
                            if(N[row - 1][col - 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row + 1 >= 0 && col - 1 >= 0 && row + 1 < N.size() && col - 1 < N[0].size())
                        {
                            if(N[row + 1][col - 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                        if(row - 1 >= 0 && col + 1 >= 0 && row - 1 < N.size() && col + 1 < N[0].size())
                        {
                            if(N[row - 1][col + 1] == 0)
                            {
                                can_be_flooded = true;
                            }
                        }
                        else
                        {
                            can_be_flooded = true;
                        }
                    }
                    else
                    {
                        can_be_flooded = true;
                    }
                    if(can_be_flooded)
                    {
                        N[row][col]--;
                    }
                }
            }
        }
        water_raised_by_x_levels++;
        print_map(N);
        int island_count = countIslands(N);
        if(initial_island_count < island_count)
        {
            cout << "To split island into two pieces water needs to raise by " << water_raised_by_x_levels << " levels";
            return 0;
        }
        cout << "Number of islands is: " << island_count << endl;
    }
    return 0;
}