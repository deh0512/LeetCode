/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) : list(nestedList) {}

    int next() {
        if (current < 0) ++current;
        while (current < list.size()) {
            if (list[current].isInteger()) return list[current++].getInteger();
            auto& iter = getOrCreateNestedIter(current);
            if (iter.hasNext()) return iter.next();
            ++current;
        }
        throw out_of_range{"out of range"};
    }

    bool hasNext() {
        auto n = current;
        if (n < 0) ++n;
        while (n < list.size()) {
            if (list[n].isInteger()) return true;
            else if (getOrCreateNestedIter(n).hasNext()) return true;
            ++n;
        }
        return false;
    }
    
private:
    int current{-1};
    vector<NestedInteger>& list;
    unordered_map<int, unique_ptr<NestedIterator>> iters{};
    
    NestedIterator& getOrCreateNestedIter(int i) {
        auto iter = iters.find(i);
        if (iter == iters.end()) {
            auto ptr = make_unique<NestedIterator>(list[i].getList());
            iters.emplace(pair<int, unique_ptr<NestedIterator>>{i, move(ptr)});
            iter = iters.find(i);
        }
        return *iter->second;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

