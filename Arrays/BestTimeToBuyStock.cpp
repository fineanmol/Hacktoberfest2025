/*
 * Problem: Best Time to Buy and Sell Stock
 * 
 * You are given an array prices where prices[i] is the price of a given stock 
 * on the ith day. You want to maximize your profit by choosing a single day to 
 * buy one stock and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you cannot 
 * achieve any profit, return 0.
 * 
 * Example:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        
        return maxProfit;
    }
    
    // Alternative approach that returns buy and sell days
    pair<int, pair<int, int>> maxProfitWithDays(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int buyDay = 0, sellDay = 0;
        int minPriceDay = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                minPriceDay = i;
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
                buyDay = minPriceDay;
                sellDay = i;
            }
        }
        
        return {maxProfit, {buyDay, sellDay}};
    }
    
    // Brute force approach for comparison (O(n^2))
    int maxProfitBruteForce(vector<int>& prices) {
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int result1 = solution.maxProfit(prices1);
    cout << "Test Case 1 - Maximum Profit: " << result1 << endl;
    
    auto detailed1 = solution.maxProfitWithDays(prices1);
    cout << "Buy on day " << detailed1.second.first + 1 << " (price = " 
         << prices1[detailed1.second.first] << "), ";
    cout << "Sell on day " << detailed1.second.second + 1 << " (price = " 
         << prices1[detailed1.second.second] << ")" << endl;
    cout << "Profit: " << detailed1.first << endl << endl;
    
    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int result2 = solution.maxProfit(prices2);
    cout << "Test Case 2 - Maximum Profit: " << result2 << endl;
    
    // Test case 3
    vector<int> prices3 = {1, 2, 3, 4, 5};
    int result3 = solution.maxProfit(prices3);
    cout << "Test Case 3 - Maximum Profit: " << result3 << endl;
    
    auto detailed3 = solution.maxProfitWithDays(prices3);
    cout << "Buy on day " << detailed3.second.first + 1 << " (price = " 
         << prices3[detailed3.second.first] << "), ";
    cout << "Sell on day " << detailed3.second.second + 1 << " (price = " 
         << prices3[detailed3.second.second] << ")" << endl;
    cout << "Profit: " << detailed3.first << endl;
    
    return 0;
}