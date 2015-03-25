#include <stdio.h>
#include <stdlib.h>

void Merge(int *array, int left, int mid, int right)
{
        int tempArray[right-left+1];
        int pos=0,lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right)
        {
                if(array[lpos] < array[rpos])
                {
                        tempArray[pos++] = array[lpos++];
                }
                else
                {
                        tempArray[pos++] = array[rpos++];
                }
        }
        while(lpos <= mid)  tempArray[pos++] = array[lpos++];
        while(rpos <= right)tempArray[pos++] = array[rpos++];
        int iter;
        for(iter = 0;iter < pos; iter++)
        {
                array[iter+left] = tempArray[iter];
        }
        return;
}

void MergeSort(int *array, int left, int right)
{
        int mid = (left+right)/2;
        if(left<right)
        {
                MergeSort(array,left,mid);
                MergeSort(array,mid+1,right);
                Merge(array,left,mid,right);
        }
}

int main()
{
	int c, n, t;

	while(scanf("%d %d %d", &c, &n, &t) != EOF)
	{
		int temp = 0, i=0, j=0, k=0;
		int bucket[c];
		int shoes[n];

		for (i = 0; i < n; ++i)
		{
			scanf("%d", &shoes[i]);
		}
		
		MergeSort(shoes, 0, n-1);

		for (j = 0; j < n%c; j++)
		{
			bucket[j] = shoes[j];
		}

		if(j != 0){
            temp = shoes[j-1] + t*2;
        }

		while(j<n)
		{
			for (k = 0; k < c; k++)
			{
				if(j+k<n){
                    bucket[k]=shoes[j+k];
                }else{
                    break;
                }
			}
			j=j+c;
			if(j<n){
                if(temp > bucket[k-1]){
                    temp = temp + t*2;
                }else{
                    temp = bucket[k-1] + t*2;
                }
            }else{
                if(temp > bucket[k-1]){
                    temp = temp + t;
                }else{
                    temp = bucket[k-1] + t;
                }
            }
		}
		printf("%d\n", temp);
	}
	return 0;
}