class Solution {
private:
int dayOfYear(string &date){
    vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int>mmddtodate(13,0);
    for(int i=0;i<12;i++){
        mmddtodate[i+1]=mmddtodate[i]+days[i];
    } 
    int month=stoi(date.substr(0,2));
    int day=stoi(date.substr(3,2));
    return mmddtodate[month-1]+day;
}
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start=max(dayOfYear(arriveAlice),dayOfYear(arriveBob));
        int end=min(dayOfYear(leaveAlice),dayOfYear(leaveBob));
        return max(0,end-start+1);
    }
};