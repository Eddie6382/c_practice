#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Flag
{
   int a;
   int b;
};

class datanode
{
   friend class PlanarSubset;
private:
   datanode(){};

   void print()
   {
      if (!_data.empty())
         for (vector<vector<int> >::iterator it = _data.begin(); it != _data.end(); ++it)
         {
            vector<int>::iterator _it = (*it).begin();
            cout << "<" << *_it << ", " << *(_it+1) << ">  ";
         }
   }

   vector<vector<int> > _data;
   map<int, bool> flag;
};

class PlanarSubset
{
public:
   PlanarSubset() {}
   PlanarSubset(const string &filename)
   {
      // todo, read file, so you can know number of node, which nodes are connected
      //int _nodeNumber = 12;
      //_coonectNode = ?;
      read(filename);
      IniMatrix();
   }
   ~PlanarSubset() { 
      for (int i = 0; i < _nodeNumber; ++i)
         delete [] matrix[i];
      delete [] matrix;
      delete [] _connectNode;
   }

   void read( const string & ); // read file
   void GenMatrix() { 
      for (int i = 0; i < _nodeNumber; ++i){
         for (int j = i; j < _nodeNumber; ++j){
            GenNodeData(i, j);
         }
      }
   }

   void printNode(int i, int j)
   {
      cout << "node[" << i << "][" << j << "]:  ";
      matrix[i][j].print();
      cout << endl;
   }

   void printListNode()
   {
      for (int i = 0; i < _nodeNumber; ++i){
         for (int j = i; j < _nodeNumber; ++j){
            if ( !matrix[i][j]._data.empty() )
               printNode(i, j);
         }
      }
   }

   int MIS(int i, int j)
   {
      size_t a;
      a = matrix[i][j]._data.size();
      return a;
   }

private:
   int _nodeNumber;                  // number of the node
   int* _connectNode;                // return all the connected node in a adjecent list
   datanode **matrix;
   
   void IniMatrix()
   {
      matrix = new datanode *[_nodeNumber];
      for (int i = 0; i < _nodeNumber; ++i)
      {
         matrix[i] = new datanode [_nodeNumber];
         for (int j = i; j < _nodeNumber; ++j)
         {
            matrix[i][j] = datanode();
         }
      }
   }

   void GenNodeData(int i, int j)
   {
      //cout << "call GenNodeData(" << i << ", " << j << ")" << endl;
      if ( i >= j ) {}
      else {
         int k = _connectNode[j];
         //cout << "(i, j, k) = " << "( " << i << ", " << j << ", " << k << " )" << endl;  

         if (k > j || k < i)
         {
            if (matrix[i][j-1]._data.empty())
               GenNodeData(i, j - 1);
            else if ( matrix[i][j].flag.find(i*_nodeNumber + j-1) == matrix[i][j].flag.end() )
            {
               for (int m = 0; m < matrix[i][j-1]._data.size(); m++)
               {
                  matrix[i][j]._data.push_back(matrix[i][j-1]._data[m]);
               }
               //cout << "node[" << i << "][" << j << "] push back ";
               //matrix[i][j].print(); cout << endl;
               matrix[i][j].flag[i*_nodeNumber + j-1] = true;
            }
         }
         else if (k == i)
         {
            if ( matrix[i+1][j-1]._data.empty() )
               GenNodeData(i + 1, j - 1);
            else if (matrix[i][j].flag.find((i+1)*_nodeNumber + j-1) == matrix[i][j].flag.end())
            {
               for (int m = 0; m < matrix[i+1][j-1]._data.size(); m++)
               {
                  matrix[i][j]._data.push_back(matrix[i+1][j-1]._data[m]);
               }
               //cout << "node[" << i << "][" << j << "] push back ";
               //matrix[i][j].print(); cout << endl;
               matrix[i][j].flag[(i+1)*_nodeNumber + j-1] = true;
            }
            if ( matrix[i][j].flag.find(i*_nodeNumber + j) == matrix[i][j].flag.end() ){
               vector<int> tmp;
               tmp.push_back(i);
               tmp.push_back(j);
               matrix[i][j]._data.push_back(tmp);
               //cout << "node[" << i << "][" << j << "] push back <" << i << ", " << j << ">\n";
               matrix[i][j].flag[i*_nodeNumber + j] = true;
            }
         }
         else
         {
            if (matrix[i][k-1]._data.empty())
               GenNodeData(i, k - 1);
            else if ( matrix[i][j].flag.find(i*_nodeNumber + k-1) == matrix[i][j].flag.end() )
            {
               for (int m = 0; m < matrix[i][k-1]._data.size(); m++)
               {
                  matrix[i][j]._data.push_back(matrix[i][k-1]._data[m]);
               }
               //cout << "node[" << i << "][" << j << "] push back ";
               //matrix[i][j].print(); cout << endl;
               matrix[i][j].flag[(i)*_nodeNumber + k-1] = true;
            }
            if (matrix[k+1][j-1]._data.empty())
               GenNodeData(k + 1, j - 1);
            else if ( matrix[i][j].flag.find((k+1)*_nodeNumber + j-1) == matrix[i][j].flag.end() )
            {
               for (int m = 0; m < matrix[k+1][j-1]._data.size(); m++)
               {
                  matrix[i][j]._data.push_back(matrix[k+1][j-1]._data[m]);
               }
               //cout << "node[" << i << "][" << j << "] push back ";
               //matrix[i][j].print(); cout << endl;
               matrix[i][j].flag[(k+1)*_nodeNumber + j-1] = true;
            }
            if ( matrix[i][j].flag.find(i*_nodeNumber + j) == matrix[i][j].flag.end() )
            {
               vector<int> tmp;
               tmp.push_back(k);
               tmp.push_back(j);
               matrix[i][j]._data.push_back(tmp);
               //cout << "node[" << i << "][" << j << "] push back <" << k << ", " << j << ">\n";
               matrix[i][j].flag[i*_nodeNumber + j] = true;
            }
         }
      }
      // _data store the information of chrods
      // ex: (i,j)=(1,9) return node that node._data = <<1,9>, <2,6>>
      // todo
   }
};

void PlanarSubset::read(const string &filename)
{
   ifstream file;
   file.open(filename, ios::in);
   if (!file)
   {
      cerr << "file doesn't open" << endl;
   }
   file >> _nodeNumber;
   cout << "successfully read \"" << filename << "\"" << "  nodeNumber: " << _nodeNumber << "\n\n";
   _connectNode = new int [_nodeNumber];
   for (int i = 0; i < _nodeNumber; ++i)
      _connectNode[i] = -1; 
   int a, b, pre_b;
   while (!file.eof())
   {
      pre_b = b;
      file >> a;
      file >> b;
      if (a!=0 || b!=pre_b){
         _connectNode[b] = a;
         _connectNode[a] = b;
         cout << b << " -> " << a << "    " << a << " -> " << b << endl;
      }
      else
         break;
   }
   cout << "\n\n";
}

int main()
{
   PlanarSubset a("../public_cases/12.in");
   a.GenMatrix();
   a.printListNode();
   return 0;
}