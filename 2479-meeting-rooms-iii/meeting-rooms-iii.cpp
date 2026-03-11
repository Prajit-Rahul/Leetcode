class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> roomsLeft;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        sort(meetings.begin(), meetings.end());
        for(int i=0; i<n; i++){
            roomsLeft.push(i);
        }
        for(auto &meet:meetings){
            int s = meet[0], e = meet[1];
            while(pq.size()>0 && s>=pq.top().first){
                auto room = pq.top();
                pq.pop();
                roomsLeft.push(room.second);
            }
            if(roomsLeft.size() > 0){
                int room = roomsLeft.top();
                roomsLeft.pop();
                rooms[room]++;
                pq.push({e, room});
            }
            else{
                auto room = pq.top();
                pq.pop();

                rooms[room.second]++;

                long long newEnd = room.first;
                newEnd += e - s;

                pq.push({newEnd, room.second});
            }
        }
        int maxi = 0;
        for(int i=1; i<n; i++){
            if(rooms[i] > rooms[maxi]){
                maxi = i;
            }
        }
        return maxi;
    }
};