class Solution {
public:
    //write a function to find the prime factors for a number(sieve of eratosthenes)
    //creating a disjoint set;
    //for each prime factor for a number, do unionFind(primefactor[num[i]],num[i])
    //using a map, store the total number of values for each connected component using nums[i] as a group id.
    //using this map find the component with maximum size and return it.
    class disjointSet
    {
        public:
        vector<int> root,rank;
        disjointSet(int n)
        {
            root.resize(n);
            rank.resize(n,1);
            for(int i=0;i<n;i++)
                root[i]=i;
        }
        int find(int x)
        {
            if(x==root[x])
                return x;
            else
                return root[x]=find(root[x]);
        }
        void unionFind(int x,int y)
        {
            int rootX=find(x),rootY=find(y);
            if(rootX!=rootY)
            {
                if(rank[root[x]]>rank[root[y]])
                    root[root[y]]=root[x];
                else if(rank[root[y]]>rank[root[x]])
                    root[root[x]]=root[y];
                else
                {
                    root[root[y]]=root[x];
                    rank[root[y]]+=1;
                }
            }
            return;
        }
    };
    vector<int> primeFactor(int num)
    {
        vector<int> primeNumbers;
        int factor=2;
        while(num>=factor*factor)
        {
            if(num%factor==0)
            {
                primeNumbers.push_back(factor);
                num=num/factor;
            }
            else
                factor++;
        }
        primeNumbers.push_back(num);
        return primeNumbers;
    }
    int largestComponentSize(vector<int>& nums) 
    {
        int maxValue = 0;
        for(int i=0;i<nums.size();i++)
            maxValue=max(maxValue,nums[i]);
        disjointSet d(maxValue+1);
        for(int i=0;i<nums.size();i++)
        {
            vector<int> primeNumbers=primeFactor(nums[i]);
            for(int j=0;j<primeNumbers.size();j++)
                d.unionFind(primeNumbers[j],nums[i]);
        }
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
            int groupId=d.find(nums[i]);
            um.find(groupId)==um.end()?um[groupId]=1:um[groupId]+=1;
        }
        int maxgroupSize=0;
        for(auto i=um.begin();i!=um.end();i++)
            maxgroupSize=max(maxgroupSize,i->second);
        return maxgroupSize;
    }
};