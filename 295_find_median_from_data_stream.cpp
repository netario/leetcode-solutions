class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.size() == 0 && minHeap.size() == 0){
            maxHeap.push(num);
            return;
        }
        if (num > maxHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);
        if ((int)minHeap.size() - (int)maxHeap.size() > 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if ((int)maxHeap.size() - (int)minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) return (minHeap.top() + maxHeap.top()) / 2.0;
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
    private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
};
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();