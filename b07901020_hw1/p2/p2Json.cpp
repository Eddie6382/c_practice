/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "p2Json.h"

using namespace std;

// Implement member functions of class Row and Table here

bool Json::read(const string& jsonFile)
{
   ifstream File(jsonFile, ios::in);
   if (!File)
   {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(EXIT_FAILURE);
   }

   // read the whole file, stror in a big string
   char ch;
   while(!File.eof())
   {
      File.get(ch);
      
      allData.push_back(ch);
   }

   // get key_value pairs from the string
   string info, number;
   vector<string> key;
   vector<int> val;
   string::iterator it = allData.begin();
   while( it!=allData.end() ){
      if( *it=='\"' ){
         ++it;
         while( *it!='\"' ){
            info.push_back(*it);
            ++it;
         }
         key.push_back(info);
         info.clear();
         ++it;
      }
      else if( (*it>='0' && *it<='9') || (*it=='-') ){
         while( (*it>='0' && *it<='9') || (*it=='-') ){
            number.push_back(*it);
            ++it;
         }
         val.push_back(stoi(number));
         number.clear();
         ++it;
      }
      else{
         ++it;
      }
   }
   for( unsigned int i = 0; i < key.size(); i++ ){
      _obj.push_back( JsonElem( key[i], val[i] ) );
   }
    /*
   cout << "json._obj contains:  ";
   for( unsigned int i = 0; i < _obj.size(); i++ ){
      cout << _obj[i] << "  ";
   }
   cout << endl;
   */
   return true; // TODO
}

int Json::SUM(){
   int sum = 0;
   for(vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); ++it ){
      sum += it->get_value();
   }
   return sum;
}

double Json::AVE(){
   double ave = static_cast<double>(SUM())/static_cast<int>(_obj.size());
   return ave;
}

JsonElem Json::MAX(){
   vector<JsonElem>::iterator max = _obj.begin();
   for(vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); ++it){
      if( it->get_value() > max->get_value() ){
         max = it;
      }
   }
   return JsonElem(max->get_key(), max->get_value());
}

JsonElem Json::MIN(){
   vector<JsonElem>::iterator min = _obj.begin();
   for(vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); ++it){
      if( it->get_value() < min->get_value() ){
         min = it;
      }
   }
   return JsonElem(min->get_key(), min->get_value());
}

void Json::PRINT(){
    cout << "{\n";
    for(vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); ++it){
        cout << "  \"" << it->get_key() << "\" : " << it->get_value() ;
        if( it != _obj.end()-1 )
            cout << ",\n";
        else
            cout << "\n";
    }
    cout << "}" << endl;
}

void Json::ADD(const string &key, int value){
    _obj.push_back( JsonElem(key, value) );
}

void Json::print_allData(){
   cout << allData << endl;
}

unsigned int Json::elem_num(){
   return _obj.size();
}

string JsonElem::get_key(){
   return _key;
}
int JsonElem::get_value(){
   return _value;
}

ostream &operator << (ostream& os, const JsonElem& j)  // to print a single element in the json
{
   return (os << "\"" << j._key << "\" : " << j._value);
}




