#include <stdio.h>
#include <stdlib.h>

int r, c;


int find_maximum(int a[], int n) {
    int c, max, index;
    
    max = a[0];
    index = 0;
    
    for (c = 1; c < n; c++) {
        if (a[c] > max) {
            index = c;
            max = a[c];
        }
    }
    
    return index;
}

int kadane(int arr[],int numRows){
    int max_So_far = 0, max_ending_here=0;
    int allNegativesF=1;
    int i;
    
    for(i=0;i<numRows;i++){
        max_ending_here=max_ending_here + arr[i];
        if(max_ending_here<0){
            max_ending_here = 0;
        }
        if(max_So_far < max_ending_here){
            max_So_far = max_ending_here;
        }
        
        if(arr[i]>0){
            allNegativesF = 0;
        }
        
    }
    if(allNegativesF == 1){
        return 0;
    }else{
        return max_So_far;
    }
}

int findMaxSum (int numRows, int numCols, int matrix[numRows][numCols])
{
    int maxSum=0;
    
    for (int left = 0; left < numCols; left++)
    {
        int temp[numRows];
        
        for (int right = left; right < numCols; right++)
        {
            // Find sum of every mini-row between left and right columns and save it into temp[]
            for (int i = 0; i < numRows; ++i)
                temp[i] += matrix[i][right];
            
            // Find the maximum sum subarray in temp[].
            int sum = kadane(temp, numRows);
            
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    
    return maxSum;
}



int main() {
    int i, j;
    scanf("%d %d", &r, &c);
    int tabela[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &tabela[i][j]);
        }
    }
    
    int resultado = findMaxSum(r,c,tabela);
    
    printf("%d\n", resultado);
    
    return 0;
}
