#include "header.h"

Hash::Hash(){
        for(int i=0; i<size; i++){
           tabl[i]==nullptr; 
        }
    }

    bool Hash::Empty(){
        for(int i=0; i<size; i++){
           if (tabl[i]!=nullptr){
            return false;
           }
        }
        return true;
    }

    void Hash::HPrint(){
        int ind = 0;
        if (Empty()){
            return;
        }
    HNode* current=nullptr;
    while (ind<size){
        if (tabl[ind]!=nullptr){
            for (current=tabl[ind]; current!=nullptr; current=current->sled){
                cout<<current->key << " " << current->data <<endl;
            }
        }
        ind++;   
    }
    }
    
    int Hash::Hashirovanie(string new_key){
        int sum=0;
        for (int i=0; i<new_key.size(); i++){
            sum+=new_key[i];
        }
        return sum%size;//получаем индекс
    }

    void Hash::HPush(string key_s, string value){
        int new_key = Hashirovanie(key_s);
        if (tabl[new_key] != nullptr){
            HNode* current = tabl[new_key];
            for (current; current != nullptr; current = current->sled){
                if (current->key == key_s) {
                    current->data = value;
                    return;
                }
            }
        }
        HNode* new_node = new HNode{value, key_s, tabl[new_key]};
        tabl[new_key] = new_node;
    }

    void Hash::HPop(string key_s){
        if (Empty()){
            return;
        }
        int new_key = Hashirovanie(key_s);
        if (tabl[new_key]==nullptr){
            return;
        }
        HNode* current = tabl[new_key];
        if (tabl[new_key]->key==key_s){
            current = tabl[new_key];
            delete current;
            tabl[new_key]=tabl[new_key]->sled;
            return;
        }
        while (current->sled!=nullptr){
            if (current->sled->key==key_s){
                HNode* kill_node = current->sled;
                current->sled=kill_node->sled;
                delete kill_node;
                return;
            }
                current=current->sled;
            }
        if (current->sled==nullptr){
            return;
        }
    }

    void Hash::HGet(string key_s){
        if (Empty()){
            return;
        }
        int new_key = Hashirovanie(key_s);
        if (tabl[new_key]==nullptr){
            return;
        }
        HNode* current = tabl[new_key];
        while (current != nullptr){
            if (current->key == key_s){
                cout << current->data << endl;
            }
            current = current->sled;
        }
        if (current == nullptr){
            return;
        }
        return;
    }

     void Hash::HWrite(string& read, string filename, int ind_start, int end){
        ofstream in;
        in.open(filename);
        if (Empty()){
            cout << "Hash is empty" << endl;
            in << read;
            in.close();
            return;
        }
        int i = 0;
        while (i < size){
            if (tabl[i] != nullptr){
                HNode* current = tabl[i];
                while(current != nullptr){
                    read.insert(ind_start+1, '(' + current->key + ',' + current->data + ')');
                    ind_start += current->key.size() + current->data.size() + 3;
                    current = current->sled;
                }
            }
            i++;
        }
        in << read;
        in.close();
        return;
    }

    void Hash::HRead(string& read, int& ind_start, int& ind){
        for (ind; read[ind] != '{' && ind < read.size(); ind++);
        ind_start = ind;
        ind++;
        if (read[ind] == '}'){
            return;
        }
        string datas = "";
        string key = "";
        for (ind; read[ind] != '}' && read[ind] != '\n' && ind < read.size(); ind++){
            for (ind; read[ind] != '(' && read[ind] != '}' && ind < read.size(); ind++);
            ind++;
            for (ind; read[ind] != ',' && read[ind] != ')' && ind < read.size(); ind++){
                key += read[ind];
            }
            ind++;
            for (ind; read[ind] != ')' && read[ind] != '}' && ind < read.size(); ind++){
                datas += read[ind];
            }
            HPush(key, datas);
            datas = "";
            key = "";
        }
        read.erase(ind_start + 1, ind - ind_start - 1);
        return;
    }