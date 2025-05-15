#ifndef CACHESIMULATOR_H
#define CACHESIMULATOR_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

struct CacheBlock {
    bool valid;
    int tag;
    int lastUsed;   // For LRU

    CacheBlock() : valid(false), tag(-1), lastUsed(0) {}
};

class ReplacementPolicy {
public:
    virtual int chooseBlockToReplace(const std::vector<CacheBlock>& set) = 0;
    virtual void update(std::vector<CacheBlock>& set, int blockIndex) = 0;
    virtual ~ReplacementPolicy() {}
};

class CacheSimulator {
private:
    int cacheSize;
    int blockSize;
    int associativity;
    int numSets;
    std::string policyName;
    int currentTime;

    std::vector<std::vector<CacheBlock>> cacheSets;
    std::unique_ptr<ReplacementPolicy> policy;

    int hits, misses, evictions;

public:
    CacheSimulator(int cacheSize, int blockSize, int associativity, const std::string& policyType);
    void access(int address);
    void loadFromFile(const std::string& filename);
    void printStats() const;
};

#endif
