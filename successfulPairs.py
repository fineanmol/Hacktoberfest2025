class Solution {
public:
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001]={0}, pMax=0;
        for(int p: potions){
            freq[p]++;
            pMax=max(pMax, p);
        }
        // freq = prefix sum for freq 
        partial_sum( freq, freq+pMax+1, freq);

        const int n=spells.size(), m=potions.size();
        vector<int> result(n, 0);
        
        for (int i=0; i<n; i++) {
            const int spell=spells[i];
            const long long k = (success+spell-1)/spell;
            if (k<=pMax) {
                result[i]=m-(k>=1?freq[k-1]:0);
            }
        }       
        return result;
    }
};
