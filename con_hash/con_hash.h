#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

struct node
{
    uint64_t node_id;
    std::string node_info;

    node():node_id(0){}
    node(const uint64_t nid, const std::string& nip)
    {
        node_id = nid;
        node_info = nip;
    }
};

class Con_Hash
{
    public:

        static Con_Hash* GetInstance()
        {
            static Con_Hash* ptr = new Con_Hash;
            return ptr; 
        }

        ~Con_Hash(){}

        void AddNodeHashFun(const std::function<uint64_t(const std::string&)>& fun){
            node_hash_funs.push_back(fun);
        };

        void SetKeyHashFun(const std::function<uint64_t(const std::string&)>& fun){
            key_hash_fun = fun;  
        };
        
        void AddNode(const std::string& node_hash_key, const node& node){
            for(size_t i = 0; i < node_hash_funs.size(); ++i)
            {
                circle.insert(std::make_pair(node_hash_funs[i](node_hash_key), node)); 
            }
        }
        
        node hash(const std::string& hash_str)
        {
            uint64_t hash_key = key_hash_fun(hash_str);
            auto it = std::lower_bound(circle.begin(), circle.end(), hash_key, [](const std::pair<uint64_t, node>& a, const uint64_t b){
                return a.first < b;
            });
            
            if(it != circle.end())
            {
                return it->second;
            }
            return node();
        }

     private:
        Con_Hash(){}
        std::vector<std::function<uint64_t(const std::string&)> > node_hash_funs;
        std::function<uint64_t(const std::string&) > key_hash_fun;
        std::map<uint64_t, node> circle; 
};


