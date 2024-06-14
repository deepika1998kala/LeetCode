/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        //Step 1: iterate over the list of linklist and push the values into the arr
        for(int i=0;i<lists.size();i++){
            ListNode* node = lists[i];
            while(node!=NULL){
                arr.push_back(node->val);
                node=node=node->next;
            }
        }
        //Step 2: sort the array
        sort(arr.begin(), arr.end());
        ListNode dummy(0);
        //Step 3: add into the dummy linkList
        ListNode* newNode = &dummy;
        for(int i=0;i<arr.size();i++){
            newNode->next = new ListNode(arr[i]);
            newNode=newNode->next;
        }
        return dummy.next;
    }
};