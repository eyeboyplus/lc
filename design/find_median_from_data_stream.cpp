#include "./../lc.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        smaller.push(num);
        larger.push(-smaller.top());
        smaller.pop();
        if(larger.size() > smaller.size()) {
            smaller.push(-larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if(larger.size() == smaller.size())
            return (double)(smaller.top() - larger.top()) / 2.0;
        
        return (double) smaller.top();
    }
    
private:
    priority_queue<long> smaller, larger;
};

int main(int argc, char **argv) {
    MedianFinder finder;
    finder.addNum(-1);
    double v = finder.findMedian(); // -> 1.5
    finder.addNum(-2);
    v = finder.findMedian();
    finder.addNum(-3); 
    v = finder.findMedian(); // -> 2
    finder.addNum(-4);
    v = finder.findMedian(); // -> 2
    finder.addNum(-5);
    v = finder.findMedian(); // -> 2 
    std::cout << "done.";
    return 0;
}