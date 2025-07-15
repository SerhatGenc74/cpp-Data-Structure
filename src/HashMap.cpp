#include "header.h"
#include <vector>

template<typename KeyType,typename ValueType>
class HashMap{

    private:
        struct pair
        {
        ValueType value;
        KeyType key;
        };

        std::vector<pair> hashTable;
        
    public:

    ValueType& operator[](const KeyType& key)
    {
        for(auto& p : this->hashTable)
        {
            if (p.key == key) {
                return p.value;
            }
        }
        // If key not found, create a new pair and add it to the hash table
        pair newPair;
        newPair.key = key;
        newPair.value = ValueType(); // Default value for ValueType
        hashTable.push_back(newPair);
        return hashTable.back().value;
    }
    
    void PrintAll()
    {
        for (const auto& p : hashTable) {
            std::cout << "Key: " << p.key << ", Value: " << p.value << std::endl;
        }
    }
    void Clear()
    {
        hashTable.clear();
    }
    void selectedkey(const KeyType& key)
    {
        for (const auto& p : hashTable) {
            if (p.key == key) {
                std::cout << "Key: " << p.key << ", Value: " << p.value << std::endl;
                return;
            }
        }
        std::cout << "Key not found." << std::endl;
    }

};

int main()
{
    HashMap<std::string,int> map;
    map["I"] = 1;
    map["V"] = 5;
    map["X"] = 10;
    map["L"] = 50;
    map["C"] = 100;
    map["D"] = 500;
    map["M"] = 1000;
    map.PrintAll();
    map.selectedkey("X");
    return 0;
}



