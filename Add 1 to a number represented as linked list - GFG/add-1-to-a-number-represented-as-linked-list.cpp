//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        } 
        else 
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* add(Node* first, int number) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        Node* temp1 = first;
        while(first != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
            
            if(first != temp1){
                number = 0;
                // int sum = carry + val1 + number;
            }
            int sum = carry + val1 + number;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
        }
        return ansHead;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        // this question is similar to add 2 numbers to ll
        
        // step1: reverse the input linked list 
        head = reverse(head);
        
        // step 2: add 1 to the linked list
        Node* ans = add(head, 1);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends