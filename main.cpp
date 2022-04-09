#include <iostream>

using namespace std;

struct adjNode{
    int val, cost;
    adjNode* next;
};

struct graphEdge{
    int start_ver, end_ver, weight;
};

class DiaGraph{
    adjNode* getAdjListNode(int value, int weight, adjNode* head){
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;
        return newNode;
    }
    int N;
public:
    adjNode **head;
    DiaGraph(graphEdge edges[], int n, int N){
        head = new adjNode*[N]();
        this->N = N;
        for(int i = 0; i < N; i++){
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

        }
    }
};


int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
