// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void pushing(stack<int> &stk,int t){
    if(stk.empty() || stk.top()<=t){
        stk.push(t);
        return;
    }
    int val = stk.top();
    stk.pop();
    pushing(stk,t);
    stk.push(val);
}
void recSort(stack<int> &stk){
    if(stk.empty()) return;
    int t= stk.top();
    stk.pop();
    recSort(stk);
    pushing(stk,t);
}
void SortedStack :: sort()
{
   //Your code here
   recSort(s);
}