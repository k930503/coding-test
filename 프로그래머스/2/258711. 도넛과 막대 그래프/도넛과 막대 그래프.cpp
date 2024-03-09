#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void fillCounts(vector<vector<int>> edges, int *gives, int *receives)
{
    for (int i = 0; i < edges.size(); i++)
    {
        gives[edges[i][0] - 1]++;
        receives[edges[i][1] - 1]++;
    }
}

void reduceCounts(vector<vector<int>> edges, int* receives, int genesis) {
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] == genesis) {
            receives[edges[i][1] - 1]--;
        }
    }
}

int searchBiggestNum(vector<vector<int>> edges)
{
    int biggestNum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] > biggestNum)
        {
            biggestNum = edges[i][0];
        }

        if (edges[i][1] > biggestNum)
        {
            biggestNum = edges[i][1];
        }
    }
    return biggestNum;
}

int searchGenesis(vector<vector<int>> edges, int* gives, int* receives, int pointCnt) {
    int genesis = 0;
    for (int i = 0; i < pointCnt; i++)
    {
        if (receives[i] == 0 && gives[i] > 1)
        {
            genesis = i + 1;
            break;
        }
    }
    return genesis;
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;
    int pointCnt = searchBiggestNum(edges);
    int *gives = new int[pointCnt];
    int *receives = new int[pointCnt];

    memset(gives, 0, sizeof(int) * pointCnt);
    memset(receives, 0, sizeof(int) * pointCnt);

    fillCounts(edges, gives, receives);

    int genesis = searchGenesis(edges, gives, receives, pointCnt);
    reduceCounts(edges, receives, genesis);

    int donutCnt = 0;
    int stickCnt = 0;
    int eightCnt = 0;

    for (int i = 0; i < pointCnt; i++)
    {
        if (gives[i] == 0)
        {
            stickCnt++;
        }
        else if (receives[i] == 2)
        {
            eightCnt++;
        }
    }

    int graphCnt = gives[genesis - 1];
    donutCnt = graphCnt - (stickCnt + eightCnt);
    answer = {genesis, donutCnt, stickCnt, eightCnt};

    return answer;
}