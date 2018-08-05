import java.util.*;
import java.io.*;

class DFSForGraph {
    // No. of vertices
    private int vNum;
 
    // Array of lists for Adjacency List Representation
    private LinkedList<Integer> adj[];

    // Constructor
    public DFSForGraph(int v) {
        this.vNum = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adj[i] = new LinkedList<>();
        }
    }
 
    //Function to add an edge into the graph
    public void addEdge(int v, int w) {
        // Add w to v's list.
        adj[v].add(w);
    }

    // A function used by DFS
    private void dfsUtil(int v, boolean visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");
 
        // Recur for all the vertices adjacent to this vertex
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n]) {
                dfsUtil(n, visited);
            }
        }
    }
 
    // The function to do DFS traversal. It uses recursive DFSUtil()
    public void dfs() {
        // Mark all the vertices as not visited(set as
        // false by default in java)
        boolean visited[] = new boolean[this.vNum];
 
        // Call the recursive helper function to print DFS traversal
        for (int i = 0; i < this.vNum; ++i) {
            if (visited[i] == false) {
                dfsUtil(i, visited);
            }
        }
    }

    public static void main(String[] args) {
        DFSForGraph g = new DFSForGraph(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        // 2 is start vertex
        g.dfs();
        System.out.println("\n");
    }
}
