#include <functional>
#include "con_hash.h"

uint64_t hash_fun_1(const std::string& str)
{
    //uint64_t hash_num = std::hash<std::string>{}(str); 
    //cout << "hash node num:" << hash_num << endl;
    return std::hash<std::string>{}(str);
}

int main()
{
    auto hasher = Con_Hash::GetInstance(); 
        
    hasher->AddHashFun(hash_fun_1);

    hasher->AddNode("shi", node(10, "shi")); 
    hasher->AddNode("zyy", node(10, "1yy")); 
    hasher->AddNode("ayy", node(10, "2yy")); 
    hasher->AddNode("byy", node(10, "3yy")); 
    hasher->AddNode("cyy", node(10, "4yy")); 
    hasher->AddNode("dyy", node(10, "5yy")); 
    hasher->AddNode("eyy", node(10, "6yy")); 
    hasher->AddNode("ershi", node(20, "ershi")); 
    hasher->AddNode("sanshi", node(30, "sanshi")); 
    
    cout << hasher->hash("229348298234379383").node_info << endl;
    cout << hasher->hash("83").node_info << endl;
    cout << hasher->hash("12").node_info << endl;
    cout << hasher->hash("137898234").node_info << endl;
    cout << hasher->hash("23").node_info << endl;
    cout << hasher->hash("145").node_info << endl;
    cout << hasher->hash("28934829287387334").node_info << endl;
    cout << hasher->hash("1402386967195812459").node_info << endl;


}
