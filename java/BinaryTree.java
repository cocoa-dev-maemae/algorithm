class TreeNode {
    int value;
    TreeNode right, left;

    TreeNode(int value) {
        this.value = value;
        right = null;
        left = null;
    }
}

public class BinaryTree {
    TreeNode node;
  
    private TreeNode addRecur(TreeNode curNode, int value) {
        if (curNode == null) {
            return new TreeNode(value);
        }
        if (value < curNode.value) {
            curNode.left = addRecur(curNode.left, value);
        } else if (value > curNode.value) {
            curNode.right = addRecur(curNode.right, value);
        } else {
            return curNode;
        }
        return curNode;
    }

    public void add(int value) {
        node = addRecur(node, value);
    }

    /**
     * print all the binary tree nodes in order
     */
    public void printInOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        printInOrder(node.left);
        System.out.print(node.value + " ");
        printInOrder(node.right);
    }

    public static void main(String args[]) {
        //create node
        BinaryTree tree = new BinaryTree();
        tree.add(3);
        tree.add(1);
        tree.add(9);
        tree.add(4);
        tree.add(2);
        tree.add(10);

        tree.printInOrder(tree.node);
        System.out.println("");
    }
}
