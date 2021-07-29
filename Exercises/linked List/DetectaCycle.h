//httpswww.hackerrank.comchallengesctci-linked-list-cycleproblem
bool has_cycle(Node* root) {
    if(!root){
        return NULL;
    }
    Node *slow = root, *fast=root;
    while(fast && fast->next && slow){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast){
        return NULL;
    }

    if(!fast){
        return NULL;
    }
    fast = root;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast; 
}
