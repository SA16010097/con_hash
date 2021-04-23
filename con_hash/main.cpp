#include <functional>
#include "con_hash.h"

uint64_t hash_fun_1(const std::string& str)
{
    return std::hash<std::string>{}(str);
}

int main()
{
    auto hasher = Con_Hash::GetInstance(); 
        
    hasher->AddNodeHashFun(hash_fun_1);
    hasher->SetKeyHashFun(hash_fun_1);

    hasher->AddNode("one", node(1, "one")); 
    hasher->AddNode("two", node(2, "two")); 
    hasher->AddNode("three", node(3, "three")); 
    hasher->AddNode("four", node(4, "four")); 
    hasher->AddNode("five", node(5, "five")); 
    hasher->AddNode("six", node(6, "six")); 
    hasher->AddNode("seven", node(7, "seven")); 
    hasher->AddNode("eight", node(8, "seven")); 
    hasher->AddNode("nine", node(9, "nine")); 
    
    cout << hasher->hash("22934aa9383").node_info << endl;
    cout << hasher->hash("83***").node_info << endl;
    cout << hasher->hash("1sdfj2").node_info << endl;
    cout << hasher->hash("123123").node_info << endl;
    cout << hasher->hash("23").node_info << endl;
    cout << hasher->hash("145").node_info << endl;
    cout << hasher->hash("28934829287387334").node_info << endl;
    cout << hasher->hash("1402386967195812459").node_info << endl;

    return true;
}
