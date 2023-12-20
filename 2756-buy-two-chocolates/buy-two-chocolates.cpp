class Solution {
public:
    int n;

    int buyChoco(vector<int>& prices, int money) {
        n = prices.size();

        int minPos = min_element(prices.begin(), prices.end()) - prices.begin();
        int cheapest = prices[minPos];
        prices[minPos] = INT_MAX;

        int secondCheapest = *min_element(prices.begin(), prices.end());
        int leftover = money - (cheapest + secondCheapest);
        
        return leftover >= 0 ? leftover : money;
    }
};