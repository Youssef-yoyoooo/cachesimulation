#ifndef REPLACEMENTPOLICY_H
#define REPLACEMENTPOLICY_H

#include "CacheSimulator.h"

class LRUReplacement : public ReplacementPolicy {
public:
    int chooseBlockToReplace(const std::vector<CacheBlock>& set) override;
    void update(std::vector<CacheBlock>& set, int blockIndex) override;
};

class FIFOReplacement : public ReplacementPolicy {
    std::unordered_map<int, int> insertionOrder;
    int counter = 0;

public:
    int chooseBlockToReplace(const std::vector<CacheBlock>& set) override;
    void update(std::vector<CacheBlock>& set, int blockIndex) override;
};

#endif
