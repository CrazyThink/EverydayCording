#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>
#include <algorithm>

struct w { int a; int b; } d[100001];
int n;
bool cmp(w x, w y) { return x.a<y.a; }
int max(int p, int q) { return p>q ? p : q; }

int solve(int k){
	int i, count = 1;
	for (i = k-1; i >= 1; i--)
		if (d[k].b > d[i].b) count = max(count, solve(i) + 1);
	return count;
}
void main() {
	freopen("sample.txt", "r", stdin);

	int i, t, m = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &d[i].a, &d[i].b);
	std::sort(d + 1, d + n + 1, cmp);
	for (i = 1; i <= n; i++)
	{
		t = solve(i);
		if (m < t) m = t;
	}
	printf("%d\n", n - m);
}