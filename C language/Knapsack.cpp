// Implementing the Knapsack Problem using the Branch and Bound Method
#include <stdio.h>
int n, m, maxProfit = 0;
int w[20], p[20];
int current_items[20], best_items[20];
float calculate_bound(int level, int current_weight, int current_profit) {
    if (current_weight >= m) return 0;
    float profit_bound = (float)current_profit;
    int j = level + 1;
    int totweight = current_weight;
    while (j < n && totweight + w[j] <= m) {
        totweight += w[j];
        profit_bound += p[j];
        j++;}
    if (j < n)
        profit_bound += (m - totweight) * (float)p[j] / w[j];
    return profit_bound;
}
void solve(int level, int current_weight, int current_profit) {
    if (current_weight <= m && current_profit > maxProfit) {
        maxProfit = current_profit;
        for (int i = 0; i < n; i++) best_items[i] = current_items[i];}
    if (level == n || calculate_bound(level - 1, current_weight, current_profit) <= maxProfit)
        return;
    current_items[level] = 1;
    if (current_weight + w[level] <= m)
        solve(level + 1, current_weight + w[level], current_profit + p[level]);
    current_items[level] = 0;
    solve(level + 1, current_weight, current_profit);}
int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &m);
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    solve(0, 0, 0);
    printf("Maximum profit = %d\n", maxProfit);
    printf("Selected items: {");
    for (int i = 0; i < n; i++) {
        printf("%d", best_items[i]);
        if (i < n - 1) printf(",");
    }
    printf("}\n");
    return 0;
}
