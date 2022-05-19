/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        if(mp.find(node) != mp.end()) return mp[node];
        
        mp[node] = new Node(node->val);
        for(Node* neighbor : node->neighbors){
            Node* tmp = cloneGraph(neighbor);
            mp[node]->neighbors.push_back(tmp);
        }
        
        return mp[node];
    }
private:
    map<Node*, Node*> mp;
};