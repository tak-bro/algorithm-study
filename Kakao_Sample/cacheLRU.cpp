#include <cstdlib>
#include <cstdio>
#include <memory>
#include <list>
#include <unordered_map> 
#include <cstdint>
#include <iostream>

// Refer to below link 
// https://stackoverflow.com/questions/15463128/better-understanding-the-lru-algorithm

typedef uint32_t data_key_t;

class TileData
{
public:
    TileData(const data_key_t &key) : theKey(key) {}
    data_key_t theKey;
    ~TileData() { std::cerr << "delete " << theKey << std::endl; }
};

typedef std::shared_ptr<TileData> TileDataPtr;   // automatic memory management!

TileDataPtr loadDataFromDisk(const data_key_t &theKey)
{
    return std::shared_ptr<TileData>(new TileData(theKey));
}

class CacheLRU
{
public:
    // the linked list keeps track of the order in which the data was accessed
    std::list<TileDataPtr> linkedList;
    // the hash map (unordered_map is part of c++0x while hash_map isn't?) gives quick access to the data 
    std::unordered_map<data_key_t, TileDataPtr> hashMap; 
    CacheLRU() : cacheHit(0), cacheMiss(0) {}
    TileDataPtr getData(data_key_t theKey)
    {
        std::unordered_map<data_key_t, TileDataPtr>::const_iterator iter = hashMap.find(theKey);
        if (iter != hashMap.end()) {
            TileDataPtr ret = iter->second;
            linkedList.remove(ret);
            linkedList.push_front(ret);
            ++cacheHit;
            return ret;
        }
        else {
            ++cacheMiss;
            TileDataPtr ret = loadDataFromDisk(theKey);
            linkedList.push_front(ret);
            hashMap.insert(std::make_pair(theKey, ret));
            if (linkedList.size() > MAX_LRU_CACHE_SIZE) {
                const TileDataPtr dropMe = linkedList.back();
                hashMap.erase(dropMe->theKey);
                linkedList.remove(dropMe);
            }
            return ret;
        }
    }
    static const uint32_t MAX_LRU_CACHE_SIZE = 8;
    uint32_t cacheMiss, cacheHit;
};

int main()
{
    CacheLRU cache;
    for (uint32_t i = 0; i < 238; ++i) {
        int key = random() % 32;
        TileDataPtr tileDataPtr = cache.getData(key);
    }
    std::cerr << "Cache hit: " << cache.cacheHit << ", cache miss: " << cache.cacheMiss << std::endl;
    return 0;
}