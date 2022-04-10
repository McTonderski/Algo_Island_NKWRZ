// C++Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>

using namespace std;

// A utility function to do DFS for a 2D
//  boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(vector<vector<int>*> *M, int i, int j, int ROW,
         int COL)
{
    //Base condition
    //if i less than 0 or j less than 0 or i greater than ROW-1 or j greater than COL-  or if M[i][j] != 1 then we will simply return
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M->at(i)->at(j) != 1)
    {
        return;
    }

    if (M->at(i)->at(j) == 1)
    {
        M->at(i)->at(j) = 0;
        DFS(M, i + 1, j, ROW, COL);     //right side traversal
        DFS(M, i - 1, j, ROW, COL);     //left side traversal
        DFS(M, i, j + 1, ROW, COL);     //upward side traversal
        DFS(M, i, j - 1, ROW, COL);     //downward side traversal
        DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
        DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
        DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
        DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
    }
}

int countIslands(vector<vector<int>*> *M)
{
    int ROW = M->size();
    int COL = M->at(0)->size();
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M->at(i)->at(j) == 1)
            {
                M->at(i)->at(j) = 0;
                count++;
                DFS(M, i + 1, j, ROW, COL);     //right side traversal
                DFS(M, i - 1, j, ROW, COL);     //left side traversal
                DFS(M, i, j + 1, ROW, COL);     //upward side traversal
                DFS(M, i, j - 1, ROW, COL);     //downward side traversal
                DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
                DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
                DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
                DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
            }
        }
    }
    return count;
}

int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;

    }
    return length;
}

void split (string str, char seperator, vector<int> *tmpLine)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    string subStr;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            std::cout<<"appending value " << stoi(subStr) << std::endl;
            tmpLine->push_back(stoi(subStr));
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

void printMap(vector<vector<int>*> *M){
    std::cout << "printing map " <<std::endl;
    for(auto & i : *M){
        for(int j : *i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void readDataFromFile(vector<vector<int>*> *M){
    ifstream dataFile("data.txt");
    if(!dataFile.is_open()){
        std::cout<<"Error while opening file";
        return;
    }
    std::cout<<"file is opend"<<std::endl;
    string line;
    char separator = ' ';
    vector<int> *v = new vector<int>(10);

    while(std::getline(dataFile, line)){
        v->clear();
        std::cout<<line<<std::endl;
        split(line, separator, v);
        M->push_back(v);
        std::cout<<"adding vector";
    }
    std::cout<<"file is done working on"<<std::endl;
    dataFile.close();
}

// Driver Code
int main()
{
    auto *M = new vector<vector<int>*>(10);
    readDataFromFile(M);
    printMap(M);

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}