class Solution {
public:
    map <Node *,Node *> check;
    Node *cloneIt(Node *node , Node *par){
        Node *n = new Node(node->val);
        check[node] = n;
        vector<Node *> a;
        for(auto & it : node->neighbors){
            if(check.find(it)!=check.end()){
                a.push_back(check[it]);
            }else{
                a.push_back(cloneIt(it, node));
            }
        }
        
        n->neighbors = a;
        return n;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        return cloneIt(node , NULL);
    }
};
