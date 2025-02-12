#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class QNode {
public:
    string data;
    QNode* sled;
};

class SNode{
public:
    string data;
    SNode* sled;
};

class Queue {
public:
    QNode* head;
    QNode* tail;

    Queue ();

    void QPop();

    void QPrint();

    void QPush(string new_data);

    void QWrite(string& read, string filename, int ind_start, int end);

    void QRead(string& read, int& ind_start, int& ind);
};

class Stack{
public:
    SNode* head;

    Stack();

    void SPop();

    void SPrint();

    void SPush(string new_data);

    void SWrite(string& read, string filename, int ind_start, int end);

    void SRead(string& read, int& ind_start, int& ind);

};

class Massive{
public:
    int size=10;
    int realsize=0;

    string* elements = new string[size];

    Massive();

    string operator[](int ind);

    void MPrint();

    void MPush_ind(string element,int ind);

    void MPush_back(string element);

    void MPop_ind(int ind);

    void MChange (int ind, string element);

    void MSize(); 

    void MWrite(string& read, string filename, int ind_start, int end);

    void MRead(string& read, int& ind_start, int& ind);
};

class LNode1{
public:
    string data;
    LNode1* sled;
};

class List1{
public:
    LNode1* head;

    List1();

    void L1Push_back(string new_data);

    void L1Push_head(string new_data);

    void L1Pop_head();

    void L1Pop_back();

    void L1Pop_value(string value);

    bool L1Find_value(string value);

    void L1Print();

    void LsWrite(string& read, string filename, int ind_start, int end);

    void LsRead(string& read, int& ind_start, int& ind);
}; 

class LNode2{
public:
    string data;
    LNode2* sled;
    LNode2* pred;
};

class List2{
public:
    LNode2* head;
    LNode2* tail;

    List2();

    void L2Push_back(string new_data);

    void L2Push_head(string new_data);

    void L2Pop_head();

    void L2Pop_back();

    void L2Pop_value(string value);

    bool L2Find_value(string value);

    void L2Print();

    void LdWrite(string& read, string filename, int ind_start, int end);

    void LdRead(string& read, int& ind_start, int& ind);

};

class HNode{
public:
    string data;
    string key;
    HNode* sled;
};


class Hash{
public:
    int size=7;
    HNode** tabl= new HNode*[size];

    Hash();

    bool Empty();

    void HPrint();

    int Hashirovanie(string new_key);

    void HPush(string key_s, string value);

    void HPop(string key_s);

    void HGet(string key_s);
    
    void HWrite(string& read, string filename, int ind_start, int end);

    void HRead(string& read, int& ind_start, int& ind);
};

class TNode{
public:
    string data;
    TNode* left;
    TNode* right;
};

class Tree{
public:
    TNode* root;

    Tree();

    bool Empty();

    void TPush(TNode* current, string new_data);

    bool TFind(TNode* current, string find_data);

    bool is_full(TNode* current);

    void print(TNode* root, int level);

    void TWrite(string& read, string filename, int ind_start, int ind, string data);

    int TRead(string& read, int& ind_start, int& ind);

}; 
