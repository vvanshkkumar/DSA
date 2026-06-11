/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
}
*/
class Solution {
    
    private Node dfs(Node node, HashMap<Node, Node> map) {

         if (map.containsKey(node)) return map.get(node);

         ArrayList<Node> clonedNeigh = new ArrayList<Node>();

         Node clone = new Node(node.val, clonedNeigh);

         map.put(node, clone);

         for(Node neigh : node.neighbors){

            clonedNeigh.add(dfs(neigh, map));
         }

         return clone;
    }
    
    public Node cloneGraph(Node node) {

        if (node==null) {
            return null;
        }

        HashMap<Node, Node> map = new HashMap<>();

        return dfs(node, map);
    }
}