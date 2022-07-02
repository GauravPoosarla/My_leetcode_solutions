class Solution {
public:
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
int x=jug1Capacity,y=jug2Capacity,z=targetCapacity;
if(x+y<z)
return false;

    int m[]={x,-x,y,-y}; //array
    map<int,int>vis;// to mark visited
    queue<int>q;
    q.push(0);// pushing the first node
    vis[0]=1;// marking the first node as visited
    
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        
        if(a==z)
            return true;
        for(int i=0;i<4;i++)// loop for 4 types of operations
        {
            int node=a+m[i];
            if(node==z)
                return true;
            if(node<0 || node>x+y)// boundary conditions
                continue;
            if(vis[node]==0)// if not visited
            {
                q.push(node);
                vis[node]=1;
            }
        }
    }
    
    return false;// it is not possible to measure exactly targetCapacity liters using these two jugs
    
}
};