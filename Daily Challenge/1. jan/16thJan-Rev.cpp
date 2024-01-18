#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (valueToIndex.find(val) != valueToIndex.end()) {
            return false; // Element already present
        }

        values.push_back(val);
        valueToIndex[val] = values.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (valueToIndex.find(val) == valueToIndex.end()) {
            return false; // Element not present
        }

        int indexToRemove = valueToIndex[val];
        int lastValue = values.back();

        values[indexToRemove] = lastValue;
        valueToIndex[lastValue] = indexToRemove;

        values.pop_back();
        valueToIndex.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }

private:
    std::vector<int> values;
    std::unordered_map<int, int> valueToIndex;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
