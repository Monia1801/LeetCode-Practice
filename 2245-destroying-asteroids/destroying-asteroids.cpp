class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i=0;
        while(i<asteroids.size() && mass>=asteroids[i]){
            mass+=asteroids[i];
            i++;
        }
        return i==asteroids.size();
    }
};