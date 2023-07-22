class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        vector<int> hash(1e4+1 ,0);
        Node * ans = head;
        hash[head->data]=1;
        while(head!=NULL && head->next!=NULL){
            hash[head->next->data]++;
            if(hash[head->next->data]>1){
                head->next = head->next->next;
            }else{
                 head=head->next;
                
            }
            
        }

        return ans;
    }
};
