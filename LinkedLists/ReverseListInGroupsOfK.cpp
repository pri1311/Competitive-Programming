// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (k == 1 || !head || !head->next) return head;
        node *temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }
        temp = head;
        node *prev = head;
        node *n = temp->next;
        int t = 1;
        while (t < k){
            // 
            temp->next = n->next;
            n->next = prev;
            prev = n;
            n = temp->next;
            t++;
        }
        head = prev;
        count -= k;
        cout << prev->data << " " << temp->data << " " << n->data << "\n";
        while(count >= k){
            t = 1;
            prev = temp;
            temp = n;
            n = n->next;
            cout << prev->data << " " << temp->data << " " << n->data << "\n";
            while(t < k){
                t++;
                temp->next = n->next;
                n->next = prev->next;
                prev->next = n;
                n = temp->next;
            }
            count -= k;
        }
        return head;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends