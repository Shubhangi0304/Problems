#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


//Problem - Count egdes, return maximum product of nodes having maximum edges
/*
 * Complete the 'maxShared' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    //to find max product having maimum edges between them
    if(friends_nodes == 0){
        return 0;
    }
    map<int, set<int>> m;
    for(int i =0; i < friends_to.size(); i++){
        m[friends_weight[i]].insert(friends_from[i]);
        m[friends_weight[i]].insert(friends_to[i]);
    }

    map<pair<int,int>,int> p;
    int max = INT_MIN;
    int max_product = INT_MIN;
    for(auto it = m.begin(); it != m.end(); it++){
        set<int> s = it->second;
        vector<int> v(s.begin(),s.end());
        int vsize = v.size();
        for(int i =0; i < vsize - 1; i++){
            p[make_pair(v[i],v[i+1])]++;
            if(max<p[make_pair(v[i],v[i+1])]){
                max = p[make_pair(v[i],v[i+1])];
            }
        }
        if(vsize > 2){
            p[make_pair(v[0],v[vsize -1])]++;
            if(max<p[make_pair(v[0],v[vsize - 1])]){
                max = p[make_pair(v[0],v[vsize - 1])];
            }
        }
        
    }

    for(auto itr = p.begin(); itr != p.end(); itr++){
        pair<int, int> pr = itr->first;
        if(itr->second == max){
            if(max_product < pr.first*pr.second){
                max_product = pr.first*pr.second;
            }
        }
    }
    return max_product;
}

int main()
