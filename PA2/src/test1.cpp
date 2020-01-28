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
public:
   datanode(){};

   void print()
   {
      if (!_data.empty())
         for (vector<vector<int> >::iterator it = _data.begin(); it != _data.end(); ++it)
         {
            vector<int>::iterator _it = (*it).begin();
            cout << "" << *_it << " " << *(_it+1) << "\n";
         }
   }
private:
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
      delete [] _connectNode;
   }

   void read( const string & ); // read file

   int GenOneNode(int x, int y, vector<vector<int> > &ans){ GenNodeData(x, y, ans); }

   void printNode(int i, int j)
   {
      cout << "node[" << i << "][" << j << "]:  ";
      matrix[i*_nodeNumber+j].print();
   }

   void printListNode()
   {
      for (int i = 0; i < _nodeNumber; ++i){
         for (int j = i; j < _nodeNumber; ++j){
            if ( !matrix[i*_nodeNumber+j]._data.empty() )
               printNode(i, j);
         }
      }
      cout << "number of calls: " << count << endl;
   }

   int MIS(int i, int j)
   {
      size_t a;
      a = matrix[i*_nodeNumber+j]._data.size();
      return a;
   }
   int count = 0;                        // count the number of calls of GenNodeData;

private:
   int _nodeNumber;                  // number of the node
   int* _connectNode;                // return all the connected node in a adjecent list
   map<int, datanode> matrix;

   
   void IniMatrix()
   {
      map<int, datanode> matrix;
   }

   int GenNodeData(int i, int j, vector<vector<int> > &ans)
   {
      ++count;
      //cout << "call GenNodeData ( " << i << ", " << j << " , vector)\n";
      if ( matrix.find(i*_nodeNumber+j) != matrix.end() ){
         ans = matrix[i*_nodeNumber+j]._data;
         return ans.size();
      }
      
      if ( i >= j ) {}
      else {
         int k = _connectNode[j];
         vector<vector<int> > ans_1;

         if (k > j || k < i)
         {
            if ( matrix.find(i*_nodeNumber+j-1) == matrix.end()){
               GenNodeData(i, j - 1, ans);
               matrix[i*_nodeNumber+j]._data = ans;
               matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j-1] = true;
            }
            else if (matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + j-1) == matrix[i*_nodeNumber+j].flag.end()) {}
            else{
               matrix[i*_nodeNumber+j]._data = matrix[i*_nodeNumber+j-1]._data;
               matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j-1] = true;
            }
         }
         else if (k == i)
         {
            if ( matrix.find((i+1)*_nodeNumber+j-1) == matrix.end() ){
               GenNodeData(i + 1, j - 1, ans);
               matrix[i*_nodeNumber+j]._data = ans;
               matrix[i*_nodeNumber+j].flag[(i+1)*_nodeNumber + j-1] = true;
            }
            else if (matrix[i*_nodeNumber+j].flag.find((i+1)*_nodeNumber + j-1) == matrix[i*_nodeNumber+j].flag.end()) {}
            else {
               ans = matrix[i*_nodeNumber+j]._data = matrix[(i+1)*_nodeNumber+j-1]._data;
               matrix[i*_nodeNumber+j].flag[(i+1)*_nodeNumber + j-1] = true;
            }
            if ( matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + j) == matrix[i*_nodeNumber+j].flag.end() ){
               matrix[i*_nodeNumber+j] = datanode();
               vector<int> tmp;
               tmp.push_back(i);
               tmp.push_back(j);
               matrix[i*_nodeNumber+j]._data.push_back(tmp);
               //cout << "node[" << i << "][" << j << "] push back <" << i << ", " << j << ">\n";
               matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j] = true;
               ans = matrix[i*_nodeNumber+j]._data;
            }
         }
         else
         {
            vector<vector<int> > ans_1;
            vector<vector<int> > ans_2;
            GenNodeData(i, k-1, ans_1);
            GenNodeData(k+1, j-1, ans_1);
            GenNodeData(i, j-1, ans_2);
            if ( ans_1.size() + 1 > ans_2.size() ){
               matrix[i*_nodeNumber+j]._data = ans_1;
               vector<int> tmp;
               tmp.push_back(k);
               tmp.push_back(j);
               matrix[i*_nodeNumber+j]._data.push_back(tmp);
               ans = matrix[i*_nodeNumber+j]._data;
            }
            else{
               ans = matrix[i*_nodeNumber+j]._data = ans_2;
            } 
            matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j] = true;
         }
         return ans.size();
         // _data store the information of chrods
         // ex: (i,j)=(1,9) return node that node._data = <<1,9>, <2,6>>
         // todo
      }
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
   PlanarSubset a("../public_cases/100.in");
   vector<vector<int> > ans;
   a.GenOneNode(0, 99 , ans);
   a.printListNode();
   cout << ans.size() << "\n\n";
   for( vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it )
      cout << *(*it).begin() << " " << *((*it).begin() + 1) << endl;
   cout << "\n\nNumber of calls: " << a.count << endl;
   return 0;
}