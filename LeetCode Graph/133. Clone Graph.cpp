class Solution {
public:
    vector<bool> vis;
    vector<Node *> nei;
    Solution(){
        nei.resize(101 , NULL);
        vis.resize(101 , false);
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        vis[node->val]=true;
        Node *ans = new Node(node->val);
        nei[node->val]=ans;
        for(auto it : node->neighbors){
            if(vis[it->val]){
                ans->neighbors.push_back(nei[it->val]);
            }else{
                ans->neighbors.push_back(cloneGraph(it));
            }
            
        }
        return ans;
    }
};
