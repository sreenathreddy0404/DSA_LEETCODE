//Problem Link : https://leetcode.com/problems/rotate-list/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)return head;
        int nodes = 1;
        ListNode* temp = head;
        while(temp->next){
            nodes++;
            temp = temp->next;
        }

        k = k%nodes;
        if(k == 0)return head;

        ListNode* temp1 = head;
        while(k--)temp1 = temp1->next;

        ListNode* temp2 = head;
        while(temp1->next){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1->next = head;
        head = temp2->next;
        temp2->next = NULL;
        return head;
    }
};