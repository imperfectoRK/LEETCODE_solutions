class Solution {
public:
    Node* dfs(Node* head) 
    {
        Node* curr = head;
        Node* tail = head;

        while (curr) 
        {
            Node* next = curr->next;

            if (curr->child) 
            {
                Node* childTail = dfs(curr->child);

                // Connect curr -> child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                // Connect child tail -> next
                if (next) 
                {
                    childTail->next = next;
                    next->prev = childTail;
                }

                tail = childTail;
            }
             else  tail = curr;

            curr = next;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if (!head)
            return nullptr;

        dfs(head);
        return head;
    }
};