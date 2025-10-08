// Clone Graph - LeetCode #133

/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if (!node) return null;
    
    const visited = new Map();
    
    function dfs(original) {
        if (visited.has(original)) return visited.get(original);
        
        const clone = new Node(original.val);
        visited.set(original, clone);
        
        for (let neighbor of original.neighbors) {
            clone.neighbors.push(dfs(neighbor));
        }
        
        return clone;
    }
    
    return dfs(node);
};
