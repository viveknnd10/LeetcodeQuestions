class Solution{
public:	
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) 
	{
	    // code here
	    int greatest=0;
	    for(int i=n-1;i>=0;i--)
	    {
	        if(i==n-1)
	        {
	            greatest=arr[i];
	            arr[i]=-1;
	            continue;
	        }
	        int temp=arr[i];
	        arr[i]=greatest;
	        if(temp>greatest)
	        {
	            greatest=temp;
	        }
	        
	    }
	    return;
	}


};