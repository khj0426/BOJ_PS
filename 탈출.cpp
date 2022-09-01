#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

/* 큐에 S가 이동할 수 있는 위치를 넣어줬을 떄, (상,하,좌,우)-1초
2초뒤 S가 이동할 수 있는 위치는 (상,하,좌,우)에 대해서 (상,하,좌,우)를 한번 더 한 위치
큐를 한번 pop한 것으로는 (상,하,좌,우) 모든 경우를 판별하지 못했음->이걸 생각 못해서 틀림..

만약 S의 시작위치를 큐에 넣는다면 {i,j}이고,
1초 뒤 {i,j}에 대해서 Pop을 하고 상하좌우로 탐색하면 큐에 총 4개가 담기고,
큐에 존재하는 모든 값들에 대해서 탐색을 다시 시작해야함 -> 큐가 빌떄까지 POP을 해야했었고,
큐를 한번만 pop한 것으로는 {상,하,좌,우} 모든 경우를 확인할 수 없어서 틀림

*/
int dt[51][51];
int r, c;
char arr[51][51];
vector<pair<int, int>> water;
int start_x = 0;
int start_y = 0;
int end_x = 0;
int end_y = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void init()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			dt[i][j] = -1;
			if (arr[i][j] == '*')
			{
				water.push_back({i, j});
			}
			if (arr[i][j] == 'S')
			{
				start_x = i;
				start_y = j;
			}
			else if (arr[i][j] == 'D')
			{
				end_x = i;
				end_y = j;
			}
		}
	}
}
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	dt[x][y] = 0;
	while (!q.empty())
	{

		vector<pair<int, int>> next_water;
		for (int j = 0; j < water.size(); j++)
		{
			int water_x = water[j].first;
			int water_y = water[j].second;
			for (int k = 0; k < 4; k++)
			{
				int water_nx = water_x + dx[k];
				int water_ny = water_y + dy[k];
				if (water_nx < 0 || water_ny < 0 || water_nx >= r || water_ny >= c)
				{
					continue;
				}
				if (arr[water_nx][water_ny] == '.')
				{
					arr[water_nx][water_ny] = '*';
					next_water.push_back({water_nx, water_ny});
				}
			}
		}

		water.clear();
		water = next_water;

		int current_qsize = q.size();
		for (int j = 0; j < current_qsize; j++)
		{
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				{
					continue;
				}

				if (arr[nx][ny] != '*' && arr[nx][ny] != 'X' && dt[nx][ny] == -1)
				{
					dt[nx][ny] = dt[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
}
int main(void)
{
	init();
	bfs(start_x, start_y);

	if (dt[end_x][end_y] == -1)
	{
		cout << "KAKTUS";
	}
	else
	{
		cout << dt[end_x][end_y];
	}
}