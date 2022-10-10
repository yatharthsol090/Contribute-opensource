class MyCalendar {
public:
    set<pair<int, int>> st;
    
    bool book(int start, int end) {
        pair<int, int> pp = {start, end};
        
        auto nexxt = st.lower_bound(pp);
        
        if(nexxt != st.end() and nexxt->first < end) {
            return false;
        }
        
        if(nexxt != st.begin()) {
            auto prevv = prev(nexxt);
            if(prevv->second > start) return false;
        }
        
        st.insert({start, end});
        return true;
    }
};
