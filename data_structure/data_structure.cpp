#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    //array
    int a[2] = {10,20};
    cout << "array\n";
    for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    //vector
    vector<int> v;
    vector<float>v1(10);
    //vector<float>v2(10,3,5.5);
    //vector<float>v3(v2);
    v.empty(); //boolean
    v.begin();
    v.end();
    v.push_back(10);
    v.pop_back(); //no return value
    v.insert(v.begin(), -1); //return iterator
    v.insert(v.end(), 49);
    v.erase(v.begin()); //no return value
    v.at(0); //check ก่อนว่า out of index มั้ย ถ้าใช่จะ throw
    v[0]; //ไม่ check
    v1.resize(12);
    //v.clear() ล้างหมด
    cout << "vector\n";
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\nvector1\n";
    for (auto &x: v1) { cout << x << " ";}
    cout << endl << endl;

    //algorithm
    sort(v.begin(), v.end());
    if (find(v.begin(), v.end(), 49) != v.end()) {
        cout << "find found";
    }
    else {
        cout << "\nfind not found";
    }
    min_element(v.begin(), v.end()); // return Iterator to the smallest element in the range [first, last)
    max_element(v.begin(), v.end()); // return Iterator to the greatest element in the range [first, last)
    lower_bound(v.begin(), v.end(), 10); // return Iterator to the first element of the range [first, last) not ordered before value คือตัวที่แรกที่ค่ามากกว่าหรือเท่ากับ value
    upper_bound(v.begin(), v.end(), 11); // return Iterator to the first element of the range [first, last) ordered after value คือตัวแรกที่ค่ามากกว่า value
    cout << endl << endl;

    //pair
    pair<int, bool> p;
    p.first = 10;
    p.second = true;
    pair<int, bool> p2;
    p2 = make_pair(40, true);
    pair<int, bool> p3(p2);
    pair<int, bool> p4 = p; //มี < กับ == operator
    cout << "pair\n";
    cout << "[" << p.first << ", " << p.second << "]";
    cout << endl << endl;

    //set
    set<int> s;
    s.insert(5); //insert log(N) ++ -- log(N) find log(N)
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.erase(10);
    //s.lower_bound(5);
    //s.upper_bound(5);
    //s.find(5);
    //s.count(5);
    cout << "set\n";
    for (auto &x: s) {
        cout << x << " ";
    }
    cout << endl;
    auto it = s.find(10);
    if (it != s.end()) { 
        cout << "has " << *it << endl; 
    }
    else {
        cout << "not have 10" << endl;
    }
    cout << "set size: " << s.size() << endl;
    cout << "set count 5: " << s.count(5);
    cout << endl << endl;

    //map
    map<string,int> m;
    m["a"] = 10;
    m["b"] = 20;
    m["c"] = 45;
    cout << "map\n";
    cout << "Size = " << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " is mapped to " << it->second << endl;
    }
    for (auto &x: m) {
        cout << x.first << " is mapped to " << x.second << endl;
    }
    map<string,int>::iterator map_it;
    if ((map_it = m.find("b")) != m.end()) {
        cout << "Key " << map_it->first << " is mapped to " << map_it->second;
    }
    else {
        cout << "Key b is not exists in m.";
    }
    cout << endl << endl;

    //stack
    stack<int> st;
    st.empty(); //boolean
    st.push(100); //no return value
    st.push(50);
    st.size();
    //st.pop();
    //st.top();
    cout << "stack top->bottom\n";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl << endl;

    //queue
    queue<int> q;
    q.empty(); //boolean
    q.push(100); //no return value
    q.push(50);
    q.size();
    //q.pop();
    //q.front();
    //q.back();
    cout << "queue front->back\n";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;

    //priority queue
    priority_queue<int> pq;
    pq.empty(); //boolean
    pq.push(500); //no return value
    pq.push(300);
    pq.push(400);
    pq.size();
    //pq.pop();
    //pq.top();
    cout << "priority queue top->back\n";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;

    //list
    list<string> l;
    //l.begin();
    //l.end();
    l.empty();
    l.size();
    l.front();
    l.back();
    l.push_back("Vicario");
    l.push_back("etc");
    l.push_front("Noname");
    l.pop_back();
    l.pop_front();
    l.insert(l.end(), "Udogie");
    //l.erase(l.end());
}
