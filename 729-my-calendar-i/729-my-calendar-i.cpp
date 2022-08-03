class MyCalendar {
private :
    set<pair<int, int>> vec;
    
    bool check(pair<int, int> x, int st, int end){
        if(end <= x.first) return true;
        if(st >= x.second) return true;
        
        return false;
    }
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        if(vec.size()==0) {
            vec.insert({start, end});
            return true;
        }
        for(pair<int, int> x : vec){
            if(!check(x, start, end)) return false;
        }
        
        vec.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */