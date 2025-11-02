
#include "pasta\headers.cpp"
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minHeap.size() > 0 && num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        } else {
            if (maxHeap.size() > minHeap.size()) {
                return maxHeap.top();
            } else {
                return minHeap.top();
            }
        }
    }
};
