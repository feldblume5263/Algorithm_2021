string이란?<br>
문자들의 나열이다.<br>
<br>
### C
8비트 정수<br>
7bit ascii를 지원한다.<br>
256개의 문자만 표현 가능하다.<br>
string은 문자들의 나열이다. null로 종료된다.<br>
<br>
<br>
### JAVA
16비트 정수<br>
21bit unicode 3.0을 지원한다.<br>
length로 처리한 string 자료형이다.<br>
<br>
<br>
### Radix = 기수 (root(base))




N개의 정수(0 ~ R - 1)를 가진 배열 a[]를 정렬해보자.
<br>
<br>

### Key 인덱스 카운트

```
int	N = a.length;
int	count[] = new int[R + 1];

for (int i = 0; i < N; i++)
	count[a[i] + 1]++;

for (int r = 0; r < R; R++)
	count[r + 1] += count[r];

for (int i = 0; i < N; i++)
	aux[count[a[i]]++] = a[i];

for (int i = 0; i < N; i++)
	a[i] = aux[i];
```
![1](https://user-images.githubusercontent.com/53016167/121769649-c5944800-cb9f-11eb-9af6-236a779f039f.png)
