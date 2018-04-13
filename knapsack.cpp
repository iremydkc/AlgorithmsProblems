/*
    This small program is about solving 0-1 knapsack problem. Your input variables 
    number of items, capacity of knapscak and index number of items, weight of item, value of item. 
    Your output maximum gain and index number of selected items

*/

#include <iostream>

using namespace std;

    // A utility function that returns maximum of two integers

    int max(int a, int b)

    {

        return (a > b) ? a : b;

    }

    void knapSack(int W, int weight[], int value[], int n)
    {
        int i, w;

        int K[n + 1][W + 1];

        // Build table K[][] in bottom up manner

        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                    K[i][w] = 0;

                else if (weight[i - 1] <= w)

                    K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);

                else

                    K[i][w] = K[i - 1][w];
            }
        }

        int items[n] = {0};
        for(int i = n, j = W; i > 0; i--){
          if(K[i][j] - K[i-1][j - weight[i - 1]] == value[i-1]){
            items[i-1] = 1;
            j = j - weight[i-1]; 
          } 
        } 
       
        cout << K[n][W] << endl; 
        for(int i =0 ; i < n; i++){
          if(items[i] == 0){

          } else {
            cout << 1+i << " ";
          }
        }
        cout << endl;
        

    }


//85
    int main()

    {

        int n, W;

        cin >> n;
        
        cin >> W;


        int number[n], value[n], weight[n];

        for (int i = 0; i < n; i++)

        {
            cin >> number[i];
            cin >> weight[i];
            cin >> value[i];
        }

        knapSack(W, weight, value, n); 


     

        return 0;

    }
