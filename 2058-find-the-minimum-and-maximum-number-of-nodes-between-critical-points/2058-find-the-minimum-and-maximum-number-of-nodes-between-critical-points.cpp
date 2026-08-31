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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        
        int minDist = INT_MAX;
        int index = 0;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {
            
            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (isCritical) {
                
                // First critical point
                if (first == -1) {
                    first = index + 1;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, (index + 1) - last);
                }

                // Current critical point becomes previous
                last = index + 1;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than 2 critical points
        if (first == last) {
            return {-1, -1};
        }

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};