/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.left = (left === undefined ? null : left);
 *     this.right = (right === undefined ? null : right);
 * }
 */

/**
 * Converts an array to a binary tree
 * @param {number[]} arr
 * @return {TreeNode}
 */
function arrayToBST(arr) {
    if (arr.length === 0) return null;

    let root = new TreeNode(arr[0]);
    let queue = [root];
    let i = 1;

    while (i < arr.length) {
        let currentNode = queue.shift();

        if (arr[i] !== null) {
            currentNode.left = new TreeNode(arr[i]);
            queue.push(currentNode.left);
        }
        i++;

        if (i < arr.length && arr[i] !== null) {
            currentNode.right = new TreeNode(arr[i]);
            queue.push(currentNode.right);
        }
        i++;
    }

    return root;
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    // Helper function to validate the BST in a range
    function helper(node, low, high) {
        if (!node) return true; // base case: empty subtree is valid
        if (node.val <= low || node.val >= high) return false; // check bounds
        
        // recursively check left and right subtrees
        return helper(node.left, low, node.val) && helper(node.right, node.val, high);
    }
    
    return helper(root, -Infinity, Infinity); // start with the full range
};

// Example usage:

// Array input
let arr = [2, 1, 3];

// Convert the array to a binary tree
let root = arrayToBST(arr);

// Check if it's a valid BST
console.log(isValidBST(root));  // Output: true
