class AuctionSystem {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        }
    };

    unordered_map<int, set<pair<int,int>, cmp>> itemBids;
    unordered_map<int, unordered_map<int, int>> userBid;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if(userBid[itemId].count(userId)) {
            int oldAmount = userBid[itemId][userId];
            itemBids[itemId].erase({oldAmount, userId});
        }
        userBid[itemId][userId] = bidAmount;
        itemBids[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = userBid[itemId][userId];
        itemBids[itemId].erase({oldAmount, userId});
        userBid[itemId][userId] = newAmount;
        itemBids[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int oldAmount = userBid[itemId][userId];
        itemBids[itemId].erase({oldAmount, userId});
        userBid[itemId].erase(userId);
        if(itemBids[itemId].empty()) {
            itemBids.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        if(!itemBids.count(itemId) || itemBids[itemId].empty()) return -1;
        return itemBids[itemId].begin()->second;
    }
};
