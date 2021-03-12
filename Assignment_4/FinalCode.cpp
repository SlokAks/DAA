#include <iostream>
#include<cstdlib>
#include <algorithm>
#include<time.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k)
{
	int current = arr[0];
	int element_count = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - current >= mid) 
		{
			current = arr[i];
			element_count++;

			if (element_count == k)
			{return true;}
		}
	}
	return false;
}

void printElem(int arr[], int maxMinDiff, int k, int n) {
    
    int prevPlaced = arr[0];
    cout<<prevPlaced<<" ";
    
    int numPlaced = 1;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] - prevPlaced >= maxMinDiff) {
            
            prevPlaced = arr[i];
            cout<<prevPlaced<<" ";
            
            numPlaced++;
            
            if(numPlaced == k) {
                break;
            }
        }
    }
	return;
} 

int maximised_min_dist(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int result = -1;

	int lower = 1, upper = arr[n - 1] - arr[0];

	while (lower < upper) {
		int mid = (lower + upper) / 2;

		if (isFeasible(mid, arr, n, k)) {
			result = max(result, mid);
			lower = mid + 1;
		}
		else
			upper = mid;
	}

	return result;
}

int randint(int min, int max)
{
    int range = (max - min);
    int div = RAND_MAX / range;
    return min + (int)(rand() / div);
}


int main()
{
	int T;
	cout<<"Number of testcases: ";
	cin>>T;
	cout<<endl<<endl;

	while(T--){

	srand(time(0));
	clock_t start,end;
	start = clock();

	int N,K;
	cout<<"N: "; cin>>N;
	cout<<"K: "; cin>>K;

	int arr[N] ;

	for(int i=0;i<N;i++)
	arr[i] = randint(-99999,99999);

    cout<<"arr: ";
	for(int i = 0;i<N;i++)
    cout<<arr[i]<<' ';
	cout<<endl;
	

	int ans = maximised_min_dist(arr, N, K);
    
	end = clock();

	cout<<"The maximised minimum distance is : "<<ans<<endl;
	cout<<"The K(= "<<K<<") - elements in which minimum distance between any two consecutive points is maximised are : " <<endl;
	printElem(arr, ans, K, N);
	cout<<endl;
	cout<<"Time : "<<(double(end-start)/double(CLOCKS_PER_SEC))*1000000<<endl<<endl;


	}

	return 0;
}
