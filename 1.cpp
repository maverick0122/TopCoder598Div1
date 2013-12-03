#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

class BinPacking
{ 	 
	public:
		int minBins(vector <int> item)
		{
			sort(item.begin(),item.end());
			
			int ans = 0;
			
			vector<int>::iterator it;
			while(!item.empty() && item.back()>200)
			{
				ans++;
				item.pop_back();
			}
			while(!item.empty())
			{
				int i=item.size()-1,j=i-1; 
				if(item[i]==100)
				{
					ans += (item.size()+2)/3;
					return ans;
				}
				for(; j>=0; j--)
				{
					if(item[i]+item[j]<=300)
						break;
				} 
				item.pop_back();
				if(j>=0) item.erase(item.begin()+j,item.begin()+j+1);
				ans++;
			} 
				
			return ans;
		} 
};

int main()
{
	int a[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 193, 160, 124, 178, 105, 150, 140, 117, 219, 126, 153, 183, 212, 179, 140, 103, 195};
	vector<int> tmp;
	for(int i=0; a[i]>0; i++)
	{
		tmp.push_back(a[i]);
	}
	BinPacking t;
	cout<<t.minBins(tmp)<<endl;
}





