#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node
{
    size_t parentIndex; // Targets the higher sum path.
    int total; // Cumulative total of this entire path.
};

int FindLargestTotal(const vector<int>& triangle)
{
    if (triangle.size() < 1) return -1;

    size_t prfi = 0; // Previous Row First Index
    size_t prli = 0; // Previous Row Last Index
    size_t crfi = 1; // Current Row First Index
    size_t crli = 2; // Current Row Last Index
    
    vector<Node> nodes;
    nodes.resize(triangle.size());
    nodes[0] = { 0, triangle[0] };
    
    size_t currentRowSize = 2;
    
    while (crli < triangle.size())
    {
        size_t rowSize = crli - crfi + 1;
        
        nodes[crfi] = { prfi, triangle[crfi] + nodes[prfi].total };
        nodes[crli] = { prli, triangle[crli] + nodes[prli].total };
        
        for (size_t i = 1; i < rowSize - 1; ++i)
        {
            size_t lpi = prfi + i - 1; // Left Parent Index
            size_t rpi = prfi + i; // Right Parent Index
            size_t ci = crfi + i; // Current Index
            
            int lpt = nodes[lpi].total; // Left Parent Total
            int rpt = nodes[rpi].total; // Right Parent Total
            
            Node& node = nodes[ci];
            node.total = triangle[ci];
            
            if (lpt < rpt)
            {
                node.parentIndex = rpi;
                node.total += rpt;
            }
            else
            {
                node.parentIndex = lpi;
                node.total += lpt;
            }
        }
        
        prfi = crfi;
        prli = crli;
        
        crfi += rowSize;
        crli += rowSize + 1;
    }
    
    int result = -1;
    
    for (auto i = prfi; i <= prli; ++i)
    {
        auto total = nodes[i].total;
        
        if (total > result) result = total;
    }
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            ifstream stream(argv[i], ifstream::binary);
            
            if (stream)
            {
                vector<int> triangle;
                int value;
                while (stream >> value) triangle.push_back(value);
            
                stream.close();
                
                cout << "largest total: " << FindLargestTotal(triangle) << endl;
            }
            else
            {
                cerr << "failed to open file: " << argv[i] << '\n';
            }
        }
    }
    else
    {
        cerr << "requires file inputs\n";
    }

    return 0;
}
