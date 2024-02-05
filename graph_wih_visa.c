#include <stdio.h>

struct Node
{
    int nodeid;
    int adjcount;
    int cost[10];
    int costs[10];
    
};

int addNode (struct Node * p, int nid, int count)
{
    int i =0, ncount = count;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid) { break; }
    }
    if (i == count)
    {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent (struct Node *p, int nid1, int nid2, int cost, int count)
{
    int i =0, index;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid1)
        {
            int c = p[i].adjcount;
            p[i].cost[c] = nid2;
            p[i].costs[c] = cost;
            p[i].adjcount = c+1;
           
            break;
        }
    }
}

int added (int * list, int lcount, int nid)
{
    int i =0;
    for (i=0;i<lcount;i++)
    {
        if (list[i] == nid) { return 1; }
    }
    return 0;
}
int find(int*visa,int lcount,int n)
{
    int i=0;int nid=n,tcount=lcount;
   for(i=0;i<tcount;i++)
   {
    if(visa[i]==nid)
    {return 1;}
   } 
    return 0;
    
}


void findpath (struct Node * p, int count, int start, int end, int * list, int *clist, int lcount,int*visa)
{
    int index = 0, i=0,j=0,m=0;
   
   
    //check if list contains the end node
    if (list[lcount-1] == end)
    {
        int tcost = 0;
        printf ("\n");
        
        for (i=0;i<lcount;i++)
        {
            printf (" %d ", list[i]);
              tcost += clist[i];    
        }
        printf (" cost = %d", tcost);
        
        return;
    }
   
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == start) { index = i; break; }
    }
   
    for (i=0;i<p[index].adjcount;i++)
    {
        int a = added (list, lcount, p[index].cost[i]);
        if (a == 0)
        {
            m=find(visa,count,p[index].cost[i]);
            if(m==1)
            {
                    list[lcount] = p[index].cost[i];
                    clist[lcount] = p[index].costs[i];
                    lcount++;        
                    findpath (p, count, p[index].cost[i], end, list, clist, lcount,visa);
                     lcount--;
            }
      
           
          
        }
    }
}


int main() {
    // Write C code here
    //printf("Hello world");
   
    struct Node nodes[50];
    int nodecount = 0;
    int n1=0, n2=0, c = 0;
   
    while (1)
    {
        printf ("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c== -9) {break;}
        nodecount = addNode (&nodes[0], n1, nodecount);
        nodecount = addNode (&nodes[0], n2, nodecount);
       
        addAdjacent (&nodes[0], n1, n2, c, nodecount);
        addAdjacent (&nodes[0], n2, n1, c, nodecount);
    }
   
    int start, end;
    printf ("start, end ? ");    
    scanf ("%d %d", &start, &end);
    int list[50], clist[50], lcount = 0;
    list[0] = start; clist[0] = 0; lcount = 1;
    int visa[nodecount];
    printf("visa are found :");
    for(int i=0;i<nodecount;i++)
    {
        scanf("%d",&visa[i]);
    }
   

    findpath (nodes, nodecount, start, end, list, clist, lcount,visa);
    
    return 0;
}
