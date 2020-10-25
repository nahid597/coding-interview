
#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007


int main()
 {
	int t ;
	cin >> t ;
	while(t--){
int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
scanf("%d%d%d%d%d%d%d%d",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2);
if(ax1 < bx2 || ax2 > bx1 || ay1 < by2 || ay2 > by1){
printf("0\n");
} else {
printf("1\n");
}
}

	return 0;

	}
