// Merge k Sorted Lists - LeetCode #23

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (!lists || lists.length === 0) return null;
    
    const heap = [];
    
    // Custom min-heap push
    function push(node) {
        heap.push(node);
        heap.sort((a, b) => a.val - b.val);
    }
    
    // Initial push
    for (let node of lists) {
        if (node) push(node);
    }
    
    const dummy = new ListNode(0);
    let current = dummy;
    
    while (heap.length > 0) {
        const node = heap.shift();
        current.next = node;
        current = current.next;
        
        if (node.next) push(node.next);
    }
    
    return dummy.next;
};
