// Test_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <adj_list_undir_network.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <charconv>
#include <memory>

class ParkDragoman
{
public:
    ParkDragoman(std::ifstream& inFile);
    ~ParkDragoman();
    void Run();

private:
    AdjListUndirNetwork<std::string, double> *pNet;
    std::ifstream *pInFile;
    int maxNumOfShowPath;
    double **dist;
    int ** path;
    int LocateVex(const std::string &e);
    void Readln();
    void ShowTourismPath(int tourismPath[]);
    void CreateTourismPath(int to, int v, int tourismPath[], int pathVertexNum);
    void ShortestPathFloyd();
};

int main()
{
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

ParkDragoman::ParkDragoman(std::ifstream& inFile)
{
    auto RemoveSpace = [](std::string&str)
    {
        std::remove_if(str.begin(), str.end(), std::isspace);
    };
    auto GetNonSpaceChar = [](auto& buffer)
    {
        while (std::isspace(buffer.peek()))
        {
            buffer.get();
        }
        return buffer.peek();
    };
    inFile.clear();
    inFile.seekg(0, ios::beg);
    std::stringstream buffer;

    buffer << inFile.rdbuf();
    std::string line;
    std::vector<std::string> pathStrings;
    while (buffer)
    {
        switch (GetNonSpaceChar(buffer))
        {
        case 'n':
            buffer >> line;
            std::getline(buffer, line);
            RemoveSpace(line);
            line.find_first_of


        default:
            break;
        }
        

    }
    std::map<std::string, int> map;


}

void ParkDragoman::CreateTourismPath(int to, int v, int tourismPath[], int pathVertexNum)
{
    static int n = 0;
    for (int w = pNet->FirstAdjVex(v); w >= 0; w = pNet->NextAdjVex(v, w))
    {
        if (n == maxNumOfShowPath)
        {
            break;
        }
        else if (pNet->GetTag(w) == UNVISITED && pathVertexNum == pNet->GetVexNum() - 1 && to == w && n < maxNumOfShowPath)
        {
            ++n;
            tourismPath[pathVertexNum++] = w;
            ShowTourismPath(tourismPath);
        }
        else if (pNet->GetTag(w) == UNVISITED)
        {
            tourismPath[pathVertexNum++] = w;
            pNet->SetTag(w, UNVISITED);
            CreateTourismPath(to, w, tourismPath, pathVertexNum);
            --pathVertexNum;
            pNet->SetTag(w, UNVISITED);
        }

    }
}
