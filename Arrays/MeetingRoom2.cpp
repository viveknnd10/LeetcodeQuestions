class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        vector<int> start_time,end_time;
        for(int i=0;i<intervals.size();i++)
        {
            start_time.push_back(intervals[i][0]);
            end_time.push_back(intervals[i][1]);
        }
        sort(end_time.begin(),end_time.end());
        sort(start_time.begin(),start_time.end());
        int rooms=0,max_rooms=0,start=0,end=0;
      while(end<end_time.size())
      {
        if(start<start_time.size() && start_time[start]<end_time[end])
        {
          rooms++;
          start++;
        }
        else
        {
          rooms--;
          end++;
        }
        max_rooms=max(rooms,max_rooms);
      }
        return max_rooms;
    }
};