#include "header.h"
#include "queue.cpp"
#include "stack.cpp"
#include "massive.cpp"
#include "list1.cpp"
#include "list2.cpp"
#include "hash.cpp"
#include "tree.cpp"

string READ (string filename){
    ifstream out;
    out.open(filename);
    string read = "";
    getline(out, read, '\0');
    out.close();
    return read;
}

bool is_same_name (string name, int& ind, string filename){
        string name_chek = "";
        bool is_same = 0;
        string read = READ(filename);
        while(ind < read.size()){
            while (read[ind] != '[' && ind < read.size()){
                ind++;
            }
            ind++;
            while (read[ind] != ']' && ind < read.size()){
                name_chek += read[ind];
                ind++;
            }
            if (name_chek == name){
                is_same = 1;
                return is_same;
            }
            name_chek = "";
            ind++;
        }
        return is_same;
}

bool is_same_type (string struc_type, int& ind, string read){
    string type_chek = "";
    while (read[ind] != '<'){
        ind++;
    }
    ind++;
    while (read[ind] != '>'){
        type_chek += read[ind];
        ind++;
    }
    if (type_chek == struc_type){
        return true;
    } else {
        return false;
    }
}


int main(int size, char* inter[]) {

    string enter = inter[4];
    string filename = inter[2];
    string command = "";
    string name = "";
    string new_data = "";
    string key = "";
    int i = 0;
    while (enter[i] != ' '){
        if(i == enter.size()){
            cout << "Inccorect enter" << endl;
            return 0;
        }
        command += enter[i];
        i++;
    }
    i++;
    if(command == "TPUSH"){
        while (enter[i] != ' '){
           if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Tree derevo;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("t", ind, read)){
                derevo.TRead(read, ind_start, ind);
                derevo.TPush(derevo.root, new_data);
                derevo.TWrite(read, filename, ind_start, ind, new_data);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if(command == "TFIND"){
        while (enter[i] != ' '){
           if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Tree derevo;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("t", ind, read)){
                derevo.TRead(read, ind_start, ind);
                if (derevo.TFind(derevo.root, new_data)) cout << "Tree has it" << endl;
                else {
                    cout << "Don't have" << endl;
                }
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if(command == "TISFULL"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        i++;
        int ind = 0;
        int ind_start = 0;
        Tree derevo;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("t", ind, read)){
                derevo.TRead(read, ind_start, ind);
                if (derevo.is_full(derevo.root)) cout << "IS FULL" << endl;
                if (!derevo.is_full(derevo.root)) cout << "NOT FULL" << endl;
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if(command == "TFIND"){
        while (enter[i] != ' '){
           if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Tree derevo;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("t", ind, read)){
                derevo.TRead(read, ind_start, ind);
                if (derevo.TFind(derevo.root, new_data)) cout << "Tree has it" << endl;
                else {
                    cout << "Don't have" << endl;
                }
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if(command == "TPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        i++;
        int ind = 0;
        int ind_start = 0;
        Tree derevo;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("t", ind, read)){
                derevo.TRead(read, ind_start, ind);
                derevo.print(derevo.root, 0);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "SPUSH"){
        while (enter[i] != ' '){
           if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        } 
        int ind = 0;
        int ind_start = 0;
        Stack stack;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("s", ind, read)){
                stack.SRead(read, ind_start, ind);
                stack.SPush(new_data);
                stack.SWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "SPOP"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Stack stack;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("s", ind, read)){
                stack.SRead(read, ind_start, ind);
                if (stack.head==nullptr){
                    cout << "Stack is empty" << endl;
                    return 0;
                }
                stack.SPop();
                stack.SWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "SPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Stack stack;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("s", ind, read)){
                stack.SRead(read, ind_start, ind);
                if (stack.head==nullptr){
                    cout << "Stack is empty" << endl;
                    return 0;
                }
                stack.SPrint();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPUSH_h"){
        while (enter[i] != ' '){
           if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        } 
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Push_head(new_data);
                list.LsWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPUSH_b"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Push_back(new_data);
                list.LsWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPOP_h"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Pop_head();
                list.LsWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPOP_b"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Pop_back();
                list.LsWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPOP_data"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Pop_value(new_data);
                list.LsWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSISMEMBER"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Find_value(new_data);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LSPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List1 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LsRead(read, ind_start, ind);
                list.L1Print();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPUSH_h"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        cout << "proverka" << read << endl;
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Push_back(new_data);
                list.LdWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPUSH_b"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Push_back(new_data);
                list.LdWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPOP_h"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Pop_head();
                list.LdWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPOP_b"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Pop_back();
                list.LdWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPOP_data"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Pop_value(new_data);
                list.LdWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDISMEMBER"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Find_value(new_data);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
            
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "LDPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        List2 list;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("l", ind, read)){
                list.LdRead(read, ind_start, ind);
                list.L2Print();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MPUSH_b"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                mas.MPush_back(new_data);
                mas.MWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MPUSH_ind"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Incorrect enter" << endl;
                return 0;
            }
            key += enter[i];
            i++;
        }
        i++;
        for (int index_check = 0; index_check < key.size(); index_check++){
            if(!isdigit(key[index_check])){
                cout << "Not correct index" <<endl;
                return 0;
            }
        }
        istringstream is(key);
        int index = 0;
        is >> index;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                if (index > mas.realsize){
                    cout << "Index is too BIG" << endl;
                    return 0;
                }
                mas.MPush_ind(new_data, ind);
                mas.MWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MPOP"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            key += enter[i];
            i++;
        }
        i++;
        for (int index_check = 0; index_check < key.size(); index_check++){
            if(!isdigit(key[index_check])){
                cout << "Not correct index" <<endl;
                return 0;
            }
        }
        istringstream is(key);
        int index = 0;
        is >> index;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                if (index > mas.realsize){
                    cout << "Index is too BIG" << endl;
                    return 0;
                }
                mas.MPop_ind(index);
                mas.MWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }
    
    if (command == "MCHANGE"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Incorrect enter" << endl;
                return 0;
            }
            key += enter[i];
            i++;
        }
        i++;
        for (int index_check = 0; index_check < key.size(); index_check++){
            if(!isdigit(key[index_check])){
                cout << "Not correct index" <<endl;
                return 0;
            }
        }
        istringstream is(key);
        int index = 0;
        is >> index;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                if (index > mas.realsize){
                    cout << "Index is too BIG" << endl;
                    return 0;
                }
                mas.MChange(index, new_data);
                mas.MWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MGET"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            key += enter[i];
            i++;
        }
        i++;
        for (int index_check = 0; index_check < key.size(); index_check++){
            if(!isdigit(key[index_check])){
                cout << "Not correct index" <<endl;
                return 0;
            }
        }
        istringstream is(key);
        int index = 0;
        is >> index;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                if (index > mas.realsize){
                    cout << "Index is too BIG" << endl;
                    return 0;
                }
                cout << mas[index] << endl;
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MSIZE"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                mas.MSize();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "MPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Massive mas;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("m", ind, read)){
                mas.MRead(read, ind_start, ind);
                mas.MPrint();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "QPUSH"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Queue que;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("q", ind, read)){
                que.QRead(read, ind_start, ind);
                que.QPush(new_data);
                que.QWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "QPOP"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Queue que;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("q", ind, read)){
                que.QRead(read, ind_start, ind);
                que.QPop();
                que.QWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "QPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Queue que;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("q", ind, read)){
                que.QRead(read, ind_start, ind);
                que.QPrint();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "HPUSH"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            key += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            new_data += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Hash hash;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("h", ind, read)){
                hash.HRead(read, ind_start, ind);
                hash.HPush(key, new_data);
                hash.HWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "HPOP"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            key += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Hash hash;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("h", ind, read)){
                hash.HRead(read, ind_start, ind);
                hash.HPop(key);
                hash.HWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "HGET"){
        while (enter[i] != ' '){
            if(i == enter.size()){
                cout << "Inccorect enter" << endl;
                return 0;
            }
            name += enter[i];
            i++;
        }
        i++;
        while (i < enter.size()){
            key += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Hash hash;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("h", ind, read)){
                hash.HRead(read, ind_start, ind);
                cout << "element with key = " << key << " ";
                hash.HGet(key);
                hash.HWrite(read, filename, ind_start, ind);
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }

    if (command == "HPRINT"){
        while (i < enter.size()){
            name += enter[i];
            i++;
        }
        int ind = 0;
        int ind_start = 0;
        Hash hash;
        string read = READ(filename);
        if (is_same_name(name, ind, filename) == 1){
            if (is_same_type("h", ind, read)){
                hash.HRead(read, ind_start, ind);
                hash.HPrint();
                return 1;
            } else {
                cout << "Structure has a different type" << endl;
                return 0;
            }
        } else {
            cout << "file don't have struct with this name." << endl;
            return 0;
        }
        return 1;
    }
}
