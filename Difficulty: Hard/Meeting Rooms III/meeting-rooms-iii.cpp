//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int N, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long int, long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>> pendingMeetings; //room, end time of meeting
        priority_queue<long long int, vector<long long int>, greater<long long int>> availableRooms;

        long long int currTime=0;
        long long int rooms=-1;
        long long int n=meetings.size();
        unordered_map<long long int,long long int> roomToMeetingCount;
        pair<long long int,long long int> res{-1,0};  //roomNo, no of meets
       
        for(long long int i=0;i<n;i++)
        {
            if(currTime<meetings[i][0]) currTime=meetings[i][0];
            if(rooms==N-1 && availableRooms.empty() && currTime<=pendingMeetings.top().first){
                currTime = pendingMeetings.top().first;
                long long int r = pendingMeetings.top().second;
                pendingMeetings.pop();
                // cout<<"r="<<r<<endl;
                // cout<<"currTime="<<currTime<<endl;
                availableRooms.push(r);
            }

            while(!pendingMeetings.empty() && currTime>=pendingMeetings.top().first)
            {
                long long int t = pendingMeetings.top().first;
                long long int ro = pendingMeetings.top().second;
                pendingMeetings.pop();
                availableRooms.push(ro);
            }
            long long int r;
            if(availableRooms.empty()){
                // cout<<"i="<<i<<endl;
                rooms++;
                roomToMeetingCount[rooms]++;
                r=rooms;
            }
            else{
                r=availableRooms.top();
                availableRooms.pop();
                roomToMeetingCount[r]++;
            }
            
            pendingMeetings.push({currTime+(meetings[i][1]-meetings[i][0]), r});
            if(roomToMeetingCount[r]>res.second){
                res={r, roomToMeetingCount[r]};
            }
            else if(roomToMeetingCount[r]==res.second){
                res={min(int(r),int(res.first)), roomToMeetingCount[r]};
            }
            // cout<<"room="<<r<<" size="<<roomToMeetingCount.size()<<endl;
            // cout<<"res="<<res.first<<" "<<res.second<<endl;
        }
        return res.first;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends