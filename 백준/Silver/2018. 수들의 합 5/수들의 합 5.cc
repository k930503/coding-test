#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,pos1=1,pos2=1,sum=1,cnt=1;
	cin >> n;

	while (pos2 != n)
	{
		if (sum == n)
		{
			cnt++, pos2++;
			sum += pos2;
            sum -= pos1;
            pos1++;
		}
		else if (sum > n)
		{
			sum -= pos1;
			pos1++;

		}
		else
		{
			
			pos2++;
			sum += pos2;
		}
	}

	printf("%d", cnt);
	return 0;
}