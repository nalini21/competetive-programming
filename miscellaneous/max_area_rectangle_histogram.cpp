#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int flag =1;
	while(flag){
		int n;
		cin>>n;
		if(n!=0){
			//find area of the biggest rectangle here
			vector<long long> hts(n);
			for(int i=0;i<n;i++){
				cin>>hts[i];
			}	
			vector<long long> mx_arr(n);
			//approach - for each bar we check the area of rectangles that can be formed taking it as the starting bar
			//           and we return the rectangle with max area.
			//time comp: O(n^2)
			int s =0;
			while(s<n){
				if(hts[s]>0){
					int cnt=0;
					long long mx_area = 0;
					long long min_height = INT_MAX;
					for(int j=s;j<n;j++){
						cnt++;
						min_height = min(min_height, hts[j]);
						mx_area = max(mx_area, min_height*cnt);
					}
					mx_arr[s] = mx_area;
					s++;
				}
				else{
					mx_arr[s]=0;
					s++;
				}
			}
           cout<<*max_element(mx_arr.begin(),mx_arr.end())<<endl;		
		}
		else{
			flag = 0;
		}
	}

	return 0;
}