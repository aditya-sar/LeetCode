class FoodRatings {
public:
    int n;
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodType;
    unordered_map<string, set<pair<int, string>>> mp;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for(int i=0; i<n; ++i) {
            foodRating[foods[i]] = ratings[i];
            foodType[foods[i]] = cuisines[i];
            mp[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    } 

    void changeRating(string food, int newRating) {
        string cuisine = foodType[food];
        auto it = mp[cuisine].find({-foodRating[food], food});
        mp[cuisine].erase(it);
        foodRating[food] = newRating;
        mp[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto s = *mp[cuisine].begin();
        return s.second;
    }
};
