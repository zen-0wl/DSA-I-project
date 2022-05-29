#include <bits/stdc++.h> //all standard library in c++
using namespace std;

int main ()
{
    // user input for inserting elements 
    int a, b, c, d, e, f, g, h, i , j;
    cout << "Insert 10 numeric elements: " << endl;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j; 
    // Create a min heap
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    pq.push(f);
    pq.push(g);
    pq.push(h);
    pq.push(i);
    pq.push(j);
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}