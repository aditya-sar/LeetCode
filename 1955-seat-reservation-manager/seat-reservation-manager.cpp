class SeatManager {
public:
    set<int> st;

    SeatManager(int n) {
        for(int i=1; i<=n; i++) {
            st.insert(i);
        }    
    }
    
    int reserve() {
        int seat = *st.begin();
        st.erase(st.begin());
        return seat;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};
