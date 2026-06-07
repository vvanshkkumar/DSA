class Solution:
   
    def find(self, node, parent) :

        if parent[node] != node :
           parent[node] = self.find(parent[node], parent)

        return parent[node]


    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:


        length = len(edges) + 1

        parent = [i for i in range(length)]

        for i in range(len(edges)) :

            u = edges[i][0]
            v = edges[i][1]

            root_u = self.find(u, parent)
            root_v = self.find(v, parent)

            if root_u != root_v : parent[root_u] = root_v
            else : return [u,v]
            

                  

        return -1    

            

