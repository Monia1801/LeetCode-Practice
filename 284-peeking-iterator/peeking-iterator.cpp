class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasNextElement;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        if (Iterator::hasNext()) {
            nextElement = Iterator::next();
            hasNextElement = true;
        } else {
            hasNextElement = false;
        }
    }

    int peek() {
        return nextElement;
    }

    int next() {
        int ans = nextElement;

        if (Iterator::hasNext()) {
            nextElement = Iterator::next();
        } else {
            hasNextElement = false;
        }

        return ans;
    }

    bool hasNext() const {
        return hasNextElement;
    }
};