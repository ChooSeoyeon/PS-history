#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
[문제 설명]
- N*N짜리 체스판에 퀸 N개를 서로 공격할 수 없게 놓기(NQueen 문제)
- 즉, 같은 행, 열, 대각선에는 다른 퀸을 놓을 수 없음
- 퀸을 놓을 수 있는 경우의 수 구하기
[문제 접근]
- 백트래킹
- 과정
1. 같은 행에는 퀸을 놓지 않는다고 가정
	일차원 배열로 퀸들의 위치 표현함. 
	예를 들어 N이 4라면, arr[5]에 퀸들의 위치 표현 가능 (하나의 행에는 하나의 퀸만 존재한다고 가정해서 1차원으로 표현 가능)
	arr[0]은 사용 안함
	체스판의 각 칸을 (1,1)~(4,4)로 명명
	예를 들어 arr={0,3,1,0,0}이라면 두 개의 퀸이 (1,3), (2,1)에 위치함을 의미
	배열의 i번째 원소는 퀸이 체스판의i번째 행에 위치함을 의미함 (1~4번째 행) (체스판의 행을 0번째부터 세지 않은 이유는 열과 통일하기 위함)
	배열의 각 원소의 값은 퀸이 체스판의 어느 열에 위치하는지를 의미함 (1~4번째 열) (체스판의 열을 0번쨰부터 세지 않은 이유는 arr 값이 0일 땐 퀸이 없는 걸로 표현하기 위함)
2. 같은 열이나 같은 대각선에 놓이는지 확인
	1) 같은 열 체크는 단순히 arr[i] 값과 arr[j] 값이 같은지 확인하면 됨
		예를 들어 {0,2,2,0,0}이라면 퀸이 (1,2), (2,2)에 위치한 것으로 두 퀸이 같은 열에 놓인 것임
	2) 같은 대각선 체크는 열의 차이와 행의 차이가 같은지 확인
		|i번째 원소값-k번째 원소값|==i-k라면 대각선에 위치하 것임
		예를 들어 {0,2,1,0,0}에서 퀸의 위치인 (2,1)과 (1,2)의 행의 차이는 2-1=1이고, 열의 차이는 |1-2|=1이므로 두 값이 같아 대각선에 위치한 것임을 알 수 있음
*/
int n; // 퀸의 개수
int v[100]; // 퀸의 위치 표현한 일차원 벡터
int cnt = 0; // 경우의 수

// 같은 열이나 같은 대각선에 놓이면 false, 안놓이면 true 반환
bool check(int x) {
	for (int i = 1; i < x; i++) {
		if ((v[x] == v[i]) || (abs(v[x] - v[i]) == (x - i))) {
			return false;
		}
	}
	return true;
}

void nqueen(int x) {
	if (check(x)) { // 4 -> 
		if (x == n) { // 모든 퀸을 배열한 것임
			cnt++;
		}
		else {
			for (int i = 1; i <= n; i++) { // 
				v[x + 1] = i;
				nqueen(x + 1);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	fill_n(v, n, 0);

	nqueen(0);

	cout << cnt;
}