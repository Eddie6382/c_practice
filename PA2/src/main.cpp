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

   int GenOneNode(int x, int y, vector<vector<int> > &ans){
      
      cout << "call GenOneNode ( " << x << ", " << y << " , vector)\n";
      if ( matrix.find(x*_nodeNumber+y) != matrix.end() ){
         ans = matrix[x*_nodeNumber+y]._data;
         return ans.size();
      }

      GenNodeData(x, y);
      for (int i = 0; i < _nodeNumber; ++i){
         for (int j = i; j < _nodeNumber; ++j){
            if (matrix.find(i*_nodeNumber+j) != matrix.end()){
               for (int m = 0; m < matrix[i*_nodeNumber+j]._data.size(); m++)
               {
                  bool flag = true;
                  for (int k = 0; k < ans.size(); ++k)
                  {
                     if (ans[k][0] == matrix[i*_nodeNumber+j]._data[m][0] && ans[k][1] == matrix[i*_nodeNumber+j]._data[m][1] ){
                        flag = false;
                        break;
                     }
                  }
                  if (flag)
                     ans.push_back(matrix[i*_nodeNumber+j]._data[m]);
               }
            }
         }
      }
      matrix[x*_nodeNumber+y]._data = ans;
      return ans.size();
   }

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

   void GenNodeData(int i, int j)
   {
      ++count;
      if ( i >= j ) {}
      else {
         int k = _connectNode[j];
         //cout << "(i, j, k) = " << "( " << i << ", " << j << ", " << k << " )" << endl;  

         if (k > j || k < i)
         {
            if ( matrix.find(i*_nodeNumber+j-1) == matrix.end())
               GenNodeData(i, j - 1);
            else if ( matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + j-1) == matrix[i*_nodeNumber+j].flag.end() )
            {
               for (int m = 0; m < matrix[i*_nodeNumber+j-1]._data.size(); m++)
               {
                  matrix[i*_nodeNumber+j]._data.push_back(matrix[i*_nodeNumber+j-1]._data[m]);
               }
               cout << "node[" << i << "][" << j << "] push back ";
               matrix[i*_nodeNumber+j].print(); cout << endl;
               matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j-1] = true;
            }
         }
         else if (k == i)
         {
            if ( matrix.find((i+1)*_nodeNumber+j-1) == matrix.end() )
               GenNodeData(i + 1, j - 1);
            else if (matrix[i*_nodeNumber+j].flag.find((i+1)*_nodeNumber + j-1) == matrix[i*_nodeNumber+j].flag.end())
            {
               for (int m = 0; m < matrix[(i+1)*_nodeNumber+j-1]._data.size(); m++)
               {
                  matrix[i*_nodeNumber+j]._data.push_back(matrix[(i+1)*_nodeNumber+j-1]._data[m]);
               }
               cout << "node[" << i << "][" << j << "] push back ";
               //matrix[i*_nodeNumber+j].print(); cout << endl;
               matrix[i*_nodeNumber+j].flag[(i+1)*_nodeNumber + j-1] = true;
            }
            if ( matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + j) == matrix[i*_nodeNumber+j].flag.end() ){
               matrix[i*_nodeNumber+j] = datanode();
               vector<int> tmp;
               tmp.push_back(i);
               tmp.push_back(j);
               matrix[i*_nodeNumber+j]._data.push_back(tmp);
               cout << "node[" << i << "][" << j << "] push back <" << i << ", " << j << ">\n";
               matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j] = true;
            }
         }
         else
         {
            /*
            vector<vector<int> > ans_1;
            vector<vector<int> > ans_2;
            bool case_1 = false, case_2 = true;
            GenOneNode(i, k-1, ans_1);
            GenOneNode(k+1, j-1, ans_1);
            GenOneNode(i, j-1, ans_2);
            if ( ans_1.size() + 1 > ans_2.size() ){
               case_1 = true;
            }
            else
               case_2 = true; 
            
            matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j] = true;
            */
            
            bool case_1 = true;
            if (case_1)
            {
               if (matrix.find(i*_nodeNumber+k-1) == matrix.end())
                  GenNodeData(i, k - 1);
               else if ( matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + k-1) == matrix[i*_nodeNumber+j].flag.end() )
               {
                  for (int m = 0; m < matrix[i*_nodeNumber+k-1]._data.size(); m++)
                  {
                     matrix[i*_nodeNumber+j]._data.push_back(matrix[i*_nodeNumber+k-1]._data[m]);
                  }
                  cout << "node[" << i << "][" << j << "] push back ";
                  matrix[i*_nodeNumber+j].print(); cout << endl;
                  matrix[i*_nodeNumber+j].flag[(i)*_nodeNumber + k-1] = true;
               }
               if ( matrix.find((k+1)*_nodeNumber+j-1) == matrix.end() )
                  GenNodeData(k + 1, j - 1);
               else if ( matrix[i*_nodeNumber+j].flag.find((k+1)*_nodeNumber + j-1) == matrix[i*_nodeNumber+j].flag.end() )
               {
                  for (int m = 0; m < matrix[(k+1)*_nodeNumber+j-1]._data.size(); m++)
                  {
                     matrix[i*_nodeNumber+j]._data.push_back(matrix[(k+1)*_nodeNumber+j-1]._data[m]);
                  }
                  cout << "node[" << i << "][" << j << "] push back ";
                  matrix[i*_nodeNumber+j].print(); cout << endl;
                  matrix[i*_nodeNumber+j].flag[(k+1)*_nodeNumber + j-1] = true;
               }
               if ( matrix[i*_nodeNumber+j].flag.find(i*_nodeNumber + j) == matrix[i*_nodeNumber+j].flag.end() )
               {
                  matrix[i*_nodeNumber+j] = datanode();
                  vector<int> tmp;
                  tmp.push_back(k);
                  tmp.push_back(j);
                  matrix[i*_nodeNumber+j]._data.push_back(tmp);
                  cout << "node[" << i << "][" << j << "] push back <" << k << ", " << j << ">\n";
                  matrix[i*_nodeNumber+j].flag[i*_nodeNumber + j] = true;
               }
            }
            else
            {

            }
         }
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
   PlanarSubset a("../public_cases/12.in");
   vector<vector<int> > ans;
   a.GenOneNode(0, 11 , ans);
   cout << ans.size() << endl;
   for( vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it )
      cout << *(*it).begin() << " " << *((*it).begin() + 1) << endl;
   cout << "\n\nNumber of calls: " << a.count << endl;
   return 0;
}