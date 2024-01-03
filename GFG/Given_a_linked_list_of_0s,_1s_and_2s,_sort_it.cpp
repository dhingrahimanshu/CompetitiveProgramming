class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *ans = head;
         while(head!=NULL && head->data==0){
            head=head->next;
        }
        Node *temp = head;
        
        while(head!=NULL &&temp!=NULL){
            if(temp->data==0){
                temp->data = head->data;
                head->data =0;
                head=head->next;
            }
            temp=temp->next;
        }
        while(head!=NULL && head->data<=1){
            head=head->next;
        }
        temp =head;
        while(head!=NULL && temp!=NULL){
            if(temp->data==1){
                temp->data = head->data;
                head->data =1;
                head=head->next;
            }
            temp=temp->next;
        }
        return ans;
    }
};
