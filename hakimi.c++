#include <bits/stdc++.h>
using namespace std;
void substractOne(std::vector<int> & sequence, int n) {
    for (int i = 0; i < n; ++i) {
      sequence.at(i) = --sequence.at(i);
    }
}
bool havel_hakimi(vector<int> degreeSeq) {
    //Sort the input into non-increasing order.
    sort(degreeSeq.begin(), degreeSeq.end(), greater<int>());

    
    //If there's negative degree present     return false
    if (degreeSeq.back() < 0)
        return false;
    
    
    //element greater than the number of elements    return false.
    if (degreeSeq.front() > degreeSeq.size())
        return false;

    if (!degreeSeq.front())
        return true;



    int n = degreeSeq.front();
    degreeSeq.erase(degreeSeq.begin());
    substractOne(degreeSeq, n);

    return havel_hakimi(degreeSeq);

}

int main() {
    int V,elem;
    cout << "Enter no of vertices : \n";
    cin >> V;
    vector<int> degreeSeq(V);
    cout << "Enter degree space-separated sequence \n";
    for(int i=0; i<V; i++) {
    cin >> elem;
    degreeSeq.push_back(elem);
    }
    cout << "There ";

    cout << (havel_hakimi(degreeSeq) ? "exists " : "does not exist "); 

    cout << "a simple graph with the given degree sequence" << endl;
    return 0;
}