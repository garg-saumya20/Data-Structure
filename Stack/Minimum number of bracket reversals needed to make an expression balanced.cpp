#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
    
}

//Efficient approach

int countRev (string s)
{
    // your code here
    int n=s.length();
    int lb=0;
    int rb=0;
    if(n%2==1)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
        {
            lb++;
        }
        else
        {
            if(lb==0)
            {
                rb++;
            }
            else
            {
                lb--;
            }
        }
    }
    int ans=ceil(lb/2.0)+ceil(rb/2.0);
    return ans;
}