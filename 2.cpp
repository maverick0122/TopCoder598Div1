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

class FoxAndFencing
{ 	 
	public:
		string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)
		{
			if(mov1+rng1>=d) return "Ciel";
			else if(mov2+rng2>=mov1+d) return "Liss";
			
			if(mov1>mov2)
			{
				if((mov1-mov2)+rng1 > mov2+rng2) return "Ciel";
				return "Draw";
			}
			if(mov1<mov2)
			{
				if((mov2-mov1)+rng2 > mov1+rng1) return "Liss";
				return "Draw";
			}
			return "Draw";
		}
};

int main()
{
	FoxAndFencing t;
	cout << t.WhoCanWin(2,1,1,100,50)<<endl;
}





