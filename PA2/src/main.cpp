#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class datanode
{
   friend class PlanarSubset;
public:
   datanode(){};
private:
   vector<vector<int>> _data;
   void print(){
      for (vector<vector<int>>::iterator it = _data.begin(); it != _data.end(); ++it){
         for (vector<int>::iterator _it = (*it).begin(); _it != (*it).end(); ++_it)
            cout << *_it << " ";
         cout << endl;
      }
      
   }
   void addelem(vector<int> a){
      _data.push_back(a);
   }
};

class PlanarSubset
{
public:
   PlanarSubset(){}
   PlanarSubset(const string &filename){
      // todo, read file, so you can know number of node, which nodes are connected
      //int _nodeNumber = 12;
      //_coonectNode = ?;
   }
   ~PlanarSubset(){}
   void read(const string &filename){}  // read file
   int MIS(int i, int j){
      size_t a;
      a = matrix[i][j]._data.size();
      return a;
   }
   void printNodeChrods(int i, int j){ matrix[i][j].print(); }
   
private:
   int _nodeNumber;                    // number of the node
   vector<vector<int>> _connectNode;   // return all the connected node. ex: < <0,4>, <1,9>, .... >
   datanode** matrix;
   datanode init;
   init._data = < <-1,-1> >;
   void IniMatrix()
   {
      matrix = new datanode* [_nodeNumber];
      for(int i=0; i<_nodeNumber; ++i){
         matrix[i] = new datanode [_nodeNumber];
         for(int j=i; j<_nodeNumber; ++j){
            matrix[i][j] = init;
         }
      }
   }
   void IniMatrix()
   {
      matrix = new datanode* [_nodeNumber];
      for(int i=0; i<_nodeNumber; ++i){
         matrix[i] = new datanode [_nodeNumber];
         for(int j=i; j<_nodeNumber; ++j){
            matrix[i][j] = GenNodeData(i, j);
         }
      }
   }

   datanode GenNodeData(int i, int j)
   {
      datanode node;
      datanode subnode;
      int k;
      for (int p = 0; p < _nodeNumber; p++){
         for (int q = 0 ;q < 2 ; q++){
            if (j == _connectNode[i][j] && j == 1){
               k = _connectNode[i][j-1];
            }
            else if (j == _connectNode[i][j] && j == 0){
               k = _connectNode[i][j+1];
            }
         }
      }
      if (k > j || k < i){
         node = GenNodeData(i, j-1);
      }
      else if (k == i){
         node = GenNodeData(i+1, j-1); 
         node._data.push_back( <i,j> );
      }
      else {
         node = GenNodeData(i , k-1) ; 
         subnode = GenNodeData(k +1, j-1);
         for (int m = 0; m < subnode._data.size(); m++){
            node._data.push_back(subnode._data[m]);
         }
         node._data.push_back( <k ,j> );
      }
      // _data store the information of chrods
      // ex: (i,j)=(1,9) return node that node._data = <<1,9>, <2,6>>
      // todo
      return node;
   }
};

int main()
{  
   PlanarSubset m;
   cout << m.MIS(0 , _nodenumber - 1) << endl;
   m.printNodeChrods(0, _nodenumber - 1);
   return 0;

}

