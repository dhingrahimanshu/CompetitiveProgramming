et* constructTree(char postfix[]){
    
    stack <et *> st;
    
    for (int i = 0; postfix[i]!='\0'; i++) {
        char it = postfix[i];
        if (isOperator(it)) {
            et *temp = new et(it);
            temp->right = st.top(); st.pop();
            temp->left = st.top(); st.pop();
            st.push(temp);
        } else {
            st.push(new et(it));
        }
    }
    
    
    
    return st.top();
}
