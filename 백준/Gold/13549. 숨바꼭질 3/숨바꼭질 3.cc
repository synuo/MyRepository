#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

#define MAX 100000

int N, K, x;
int check[100001];
deque<pair<int, int>> dq; // <위치, 시간>

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	dq.push_back({ N,0 });

	while (!dq.empty())
	{
		int now = dq.front().first;
		int time = dq.front().second;
		dq.pop_front();

		check[now] = true;

		if (now == K)
		{
			cout << time;
			break;
		}

		if (now - 1 >= 0 && !check[now - 1])
			dq.push_back({ now - 1,time + 1});

		if (now + 1 <= MAX && !check[now + 1])
			dq.push_back({ now + 1,time + 1 });

		if (2 * now <= MAX && !check[2 * now])
			dq.push_front({ 2 * now,time});
	}

}