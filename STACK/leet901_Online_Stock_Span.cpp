#include <iostream>
#include<vector>
#include <stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int> > st; // {price, span}
public:
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner ss;
    cout << ss.next(100) << endl; // 1
    cout << ss.next(80) << endl;  // 1
    cout << ss.next(60) << endl;  // 1
    cout << ss.next(70) << endl;  // 2
    cout << ss.next(60) << endl;  // 1
    cout << ss.next(75) << endl;  // 4
    cout << ss.next(85) << endl;  // 6
    return 0;
}
