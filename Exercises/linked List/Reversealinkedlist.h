//https://vjudge.net/problem/HackerRank-reverse-a-linked-list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* cur = llist;
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur-> next = prev;
        
        prev = cur;
        cur = next;
    }
    llist = prev;
    return llist;
}

