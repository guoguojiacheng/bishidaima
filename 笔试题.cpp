// 笔试题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"std.h"
#include <iomanip>
using namespace std;
void fun(string& s1, string& s2)
{
	if (s1.length() == 0 || s2.length() == 0) {
		printf("NULL\n");
		return;
	}
	if (s1.length() > s2.length()) {
		swap(s1, s2);
	}
	int len1 = s1.length();
	int len2 = s2.length();
	int maxlen = 0, start = 0;
	vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maxlen) {
					maxlen = dp[i][j];
					start = i - maxlen;
				}
			}
		}
	}
	cout << s1.substr(start, maxlen) << endl;
}
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr)return pHead;
	map<int, int>mmap;
	ListNode* p = pHead;
	while (p != nullptr) {
		mmap[p->val]++;
		p = p->next;
	}
	ListNode* node = nullptr;
	p = pHead;
	while (p != nullptr) {
		if (mmap[p->val] == 1)
		{
			if (node == nullptr) {
				node = p;
				pHead = node;
			}
			else {
				node->next = p;
				node = node->next;
			}
		}
		p = p->next;
	}
	if (node == nullptr)pHead = node;
	node->next = nullptr;
	return pHead;
}
int main()
{
	ListNode* pHead = new ListNode(1);
	ListNode* p = pHead;
	p->next = new ListNode(1);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(5);
	deleteDuplication(pHead);
	return 0;
}
#if 0
vector<int> maxInWindows(const vector<int> & num, unsigned int size)
{
	vector<int>rev;
	int len = num.size();
	int max = -65536;
	int lenx = size < len ? size : len;
	for (int i = 0; i < lenx; ++i) {
		if (max < num[i])max = i;
	}
	if (size >= len)
	{
		rev.push_back(num[max]);
		return rev;
	}
	for (int i = size - 1; i < len; ++i) {
		if ((i - 2) <= max) {
			if (num[max] < num[i])max = i;
		}
		else {
			max = num[i - 2] > num[i - 1] ? i - 2 : i - 1;
			max = num[i] > max ? i : max;
		}
		rev.push_back(num[max]);
	}
	return rev;
}
int main1()
{//空间O(n)  时间O(n)+O(n/2)*O(log2^n)
	vector<int>vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(1);
	//maxInWindows(vec, 3);
	/*char str[] = "hello";
	char sub[] = "lloe";
	cout << strstr(str, sub) << endl;;
	int n;
	cin >> n;
	int i, j, k;
	vector<int>vec(n + 1, 0);
	for (i = 2; i <= n; ++i) {
		if (i & 1)vec[i] = 1;
	}
	if (n > 2)vec[2] = 1;
	for (i = 3; i <= n; i += 2) {
		if (vec[i]) {
			for (k = 2; k <= sqrt(i); ++k) {
				if (i % k == 0)vec[i] = 0;
				else break;
			}
			if (vec[i]) {
				for (j = 2 * i; j <= n; j += i) {
					vec[j] = 0;
				}
			}
		}
	}
	for (i = 1; i <= n; ++i) {
		if (vec[i])cout << i << " ";
	}
	cout << endl;*/
	return 0;
}
#endif
#if 0
const char str1[] = "abc";
const char str2[] = "abc";
const char* p1 = "abc";
const char* p2 = "abc";
enum a { ads };
class A {
	static void hwo() {}
};
class B :public A {
	void show() {}
};
struct Foo {
	Foo() {}
	Foo(int) {}
	void fun() {}
};
int main()
{
	Foo a(10);
	a.fun();
	Foo b();
	b.fun();
	int g, h;
	//int crr[][4];//错误
	g = h = 10;
	cout << g << h << endl;
	short* p, * q;
	short brr[12] = { 0 };
	p = q = brr;
	p++;
	printf("%d,", p - q);
	printf("%d,", (char*)p - (char*)q);
	printf("%d", sizeof(brr) / sizeof(*brr));
	int x = 0123;
	float xx = 1.2e2;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << *(arr + 2) << endl;
	int a = -32769;
	printf("%d\n", a);
	//printf("%d\n", (int*)a);

	cout << setw(6) << 1 << endl;

	cout << (void*)str1 << endl;
	cout << (void*)str2 << endl;
	cout << (void*)p1 << endl;
	cout << (void*)p2 << endl;
}

//int fun(vector<int>& vec) {
//	unordered_map<int, int>mmap;
//	mmap.find(1)->second / 2;
//	int count = 0;
//	for (int val : vec) {
//		mmap[val]++;
//
//	}
//
//	for (int val : vec) {
//		int num = 0 - val;
//		if (mmap.find(num) != mmap.end()) {
//			count += min(val, num);
//			mmap.erase(val);
//			mmap.erase(num);
//		}
//	}
//	return count;
//}
//static int c = 0;
//int f(int i = 10) {
//	c++;
//	if (i <= 2) return 1;
//	return f(i - 2) + f(i - 4) + 1;
//}
void fun(int(*p)[3]) {
	//fprintf(stdout, "%s\n", str.c_str());
}
class B {
public:
	B(int i = 10) :b(i) {}
	void show() { cout << "B:" << b << endl; }
	static void pp();
private:
	int b;
	friend class A;
};
void B::pp() {}
class C :public B {
private:
	const int val;
public:
	C() :val(10) {}
	void show() {}
};
class A {
public:
	static int i;
	A(int i = 20) :a(i) {}
	void show() { cout << "A:" << a << endl; }
	void fun() {
		B b;
		b.pp();
		cout << b.b << endl;
	}
	void get()const
	{
		//a++;
		i++;
		j++;
		k++;
		cout << i << j << k << endl;
	}
private:
	static int j;
	int a;
protected:
	static int k;
	friend void show(A& ptr);
};
int A::i = 0;
int A::j = 0;
int A::k = 0;
int op;
void show(A& ptr)
{
	op = ptr.a;
	op += ptr.a;
}

int GetUglyNumber_Solution(int index) {

	if (index < 7) {
		return index;
	}
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	vector<int>vec;
	int rev = 0;
	vec.push_back(1);
	while (vec.size() < index) {
		rev = min(vec[a1] * 2, min(vec[a2] * 3, vec[a3] * 5));
		if (rev == vec[a1] * 2) a1++;
		if (rev == vec[a2] * 3) a2++;
		if (rev == vec[a3] * 5) a3++;
		vec.push_back(rev);
	}
	return rev;
}
int main()
{
	int rev = GetUglyNumber_Solution(7);
	return 0;
}

class A {
public:
	A(int q = 0) { a = q; }
private:
	int a;
};
class B {
};
class C :public A, private B {
};
string ReverseSentence(string& str) {
	reverse(str.begin(), str.end());
	auto itb = str.begin();
	auto ite = str.begin();
	while (ite != str.end()) {
		while (*itb == ' ') {
			itb++;
		}
		if (ite < itb) {
			ite = itb;
		}
		while (ite != str.end() && *ite != ' ') {

			ite++;
		}
		if (*ite == ' ') {
			reverse(itb, ite);
			itb = ite + 1;
		}
	}

	//reverse(itb, ite);
	return str;
}
int main()
{
	string str("student. a am I");
	ReverseSentence(str);
	cout << str << endl;
	return 0;
}
#endif
//int main()
//{
//	int m, n;
//	cin >> n >> m;
//	vector<int>vec(m, 0);
//	int rev = 1;
//	for (int i = 0; i < m; ++i) {
//		cin >> vec[i];
//		rev *= 2;
//	}
//
//	cout << rev << endl;
//}
#if 0
unordered_map<int, int> mmap;
int len;
vector<int>arr;
int a = 0;
int sum = 0;
void fun(int i) {
	if (i == len) {
		mmap[sum - a]++;
	}
	else {
		a += arr[i];
		fun(i + 1);
		a -= arr[i];
		fun(i + 1);
	}
}
int main() {
	int m, n;
	cin >> n >> m;
	arr.resize(m, 0);
	int rev = 1;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	len = arr.size();
	fun(0);
	int count = 0;
	auto it = mmap.begin();
	for (; it != mmap.end(); ++it) {
		count++;
	}
	cout << count << endl;
	return 0;
}
class CSingleton {//饿汉
public:
	static CSingleton* get() {
		return single;
	}
private:
	CSingleton() { cout << "CSingleton" << endl; }
	~CSingleton() { cout << "~CSingleton" << endl; }
	static CSingleton* single;
};
CSingleton* CSingleton::single = nullptr;
int main1()
{
	vector<int>vec(100000);
	for (int i = 0; i < 100000; ++i) {
		vec.push_back(rand());
	}
	unsigned int max = 100000000;
	int size = max / 32 + 1;
	int* arr = new int[size];
	for (unsigned int i = 0; i < vec.size(); ++i) {
		int index = vec[i] / 32;
		int offset = vec[i] % 32;
		int v = arr[index] & (1 << offset);
		if (0 != v) { cout << vec[i]; break; }
		else { arr[index] = arr[index] | (1 << offset); }
	}
	return 0;
}
#endif
#if 0
void maopao(int* arr, int len) {
	//时间复杂度最坏：O(n^2)，最好O(n) 稳定排序
	for (int i = 0; i < len; ++i) {
		int flg = 1;
		for (int j = i + 1; j < len; ++j) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
				flg = 0;
			}
		}
		if (flg) {
			break;
		}
	}
}
void cha_ru(int* arr, int len) {
	//时间复杂度最坏：O(n^2)，最好O(n) 稳定排序
	for (int i = 1; i < len; ++i) {
		int tmp = arr[i];
		int j = i - 1;
		for (; j >= 0; --j) {
			if (tmp < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else { break; }
		}
		arr[j + 1] = tmp;
	}
}
void shell_sort(int* arr, int len, int tmp) {
	for (int i = tmp; i < len; ++i) {
		int num = arr[i];
		int j = i - tmp;
		for (; j >= 0; j -= tmp) {
			if (arr[j] > num) {
				arr[j + tmp] = arr[j];
			}
			else { break; }
		}
		arr[j + tmp] = num;
	}
}
void shell(int* arr, int len) {
	//时间复杂度最坏：O(n ^ 2)，最好O(n) 不稳定排序
	int brr[] = { len / 3,len / 4,1 };
	int lend = sizeof(brr) / sizeof(brr[0]);
	for (int i = 0; i < lend; ++i) {
		shell_sort(arr, len, brr[i]);
	}
}
void zhijie(int* arr, int len) {
	//时间复杂度最坏：O(n ^ 2)，最好O(n^2) 不稳定排序
	for (int i = 0; i < len - 1; ++i) {
		int m = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[m] > arr[j]) {
				m = j;
			}
		}
		if (m != i) {
			swap(arr[i], arr[m]);
		}
	}
}
void big_heap(int* arr, int start, int end) {
	for (int i = start * 2 + 1; i <= end; i = i * 2 + 1) {
		if (i < end && arr[i] < arr[i + 1]) {
			i++;
		}
		if (arr[start] > arr[i]) {
			break;
		}
		else {
			swap(arr[i], arr[start]);
			start = i;
		}
	}
}
void heap(int* arr, int len) {
	//时间复杂度最坏：O(nlog2^n)，最好O(nlog2^n) 不稳定排序
	for (int i = (len - 2) / 2; i >= 0; --i) {
		big_heap(arr, i, len - 1);
	}
	for (int i = 0; i < len - 1; i++) {
		swap(arr[0], arr[len - i - 1]);
		big_heap(arr, 0, len - i - 2);
	}
}
int quick_sort(int* arr, int low, int high) {
	int tmp = arr[low];
	while (low < high) {
		while (low < high && tmp < arr[high]) {
			high--;
		}
		if (low<high && tmp>arr[high]) {
			arr[low] = arr[high];
		}
		while (low<high && tmp>arr[low]) {
			low++;
		}
		if (low < high && tmp < arr[low]) {
			arr[high] = arr[low];
		}
	}
	arr[low] = tmp;
	return low;
}
void quick(int* arr, int low, int high) {
	//时间复杂度最坏：O(n^2)，最好O(nlog2^n) 不稳定排序   空间复杂度O(nlog2^n)
	/*if (low < high) {
		int par = quick_sort(arr, low, high);
		if (par - 1 > low) {
			quick(arr, low, par - 1);
		}
		if (par + 1 < high) {
			quick(arr, par + 1, high);
		}
	}*/
	stack<int>vec;
	int par = quick_sort(arr, low, high);
	if (par - 1 > low) { vec.push(low); vec.push(par - 1); }
	if (par + 1 < high) { vec.push(par + 1); vec.push(high); }
	while (!vec.empty()) {
		high = vec.top(); vec.pop();
		low = vec.top(); vec.pop();
		par = quick_sort(arr, low, high);
		if (par - 1 > low) { vec.push(low); vec.push(par - 1); }
		if (par + 1 < high) { vec.push(par + 1); vec.push(high); }
	}
}
void guibing_sort(int* arr, int len, int pow) {
	int s1 = 0, e1 = s1 + pow - 1, s2 = e1 + 1;
	int e2 = s2 + pow - 1 < len - 1 ? s2 + pow - 1 : len - 1;
	vector<int>brr;
	while (s2 < len) {
		while (s1 <= e1 && s2 <= e2) {
			if (arr[s1] <= arr[s2]) { brr.push_back(arr[s1++]); }
			else { brr.push_back(arr[s2++]); }
		}
		while (s1 <= e1) { brr.push_back(arr[s1++]); }
		while (s2 <= e2) { brr.push_back(arr[s2++]); }
		s1 = e2 + 1; e1 = s1 + pow - 1; s2 = e1 + 1;
		e2 = s2 + pow - 1 < len - 1 ? s2 + pow - 1 : len - 1;
	}
	int i = brr.size();
	while (s1 < len) { brr.push_back(arr[s1++]); }
	for (int j = 0; j < len; ++j) {
		arr[j] = brr[j];
	}
}
void guibing(int* arr, int len) {
	//时间复杂度最好、最好O(nlog2^n) 稳定排序 空间复杂度O(1)
	for (int i = 1; i < len; i *= 2) {
		guibing_sort(arr, len, i);
	}
}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 50;
	}
	for (int val : arr) {
		cout << val << " ";
	}
	cout << endl;
	guibing(arr, 10);
	for (int val : arr) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
#endif
#if 0
class A {
public:
	void show() { cout << "A" << endl; }
};
class B :public A {
public:
	void show() { cout << "B" << endl; }
};


class Parent {
public:
	Parent() {
		m_strPointerFrom = "Parent Pointer";
	};
public:
	void print() {
		printf("%s From Parent Func\n", m_strPointerFrom.c_str());
	};
	virtual void printv() {
		printf("%s From Parent Virutal Func\n", m_strPointerFrom.c_str());
	};
protected:
	std::string m_strPointerFrom;
};

//#define USEERROR

class Child : public Parent {

#ifndef USEERROR

public:
	Child() { m_strPointerFrom = "Child Pointer"; };
public:
	void print() {
		printf("%s From Child Func.\n", m_strPointerFrom.c_str());
	};
	virtual void printv() override {
		printf("%s From Child Virutal Func.\n", m_strPointerFrom.c_str());
	};
#else

public:
	Child() { m_strPointerFrom = "Child Pointer"; m_strOnlyChild = "OnlyInChild"; };
public:
	void print() { printf("%s From Child Func. %s\n", m_strPointerFrom.c_str(), m_strOnlyChild.c_str()); };
	virtual void printv() override { printf("%s From Child Virutal Func. %s\n", m_strPointerFrom.c_str(), m_strOnlyChild.c_str()); };
private:
	std::string m_strOnlyChild;

#endif

};

class Temp {};

int main()
{
	//auto_ptr<int>str(new int(10));
	//auto_ptr<int>ptr = str;
	//ptr.release();//把当前指针置为空，返回一个资源
	////_Ty* _Tmp = _Myptr;
	////_Myptr = nullptr;
	////return _Tmp; 
	//ptr.reset();//释放当前资源
	//cout << *ptr << endl;
	unique_ptr<int>up(new int(20));
	cout << *up << endl;
	unique_ptr<int>ap = std::move(up);
	ap = std::move(up);
	//cout << *up << *ap << endl;
	shared_ptr<int>sp(new int(30));
	weak_ptr<int>wp(sp);
	cout << sp.use_count() << endl;
	cout << wp.use_count() << endl;
	shared_ptr<int>xp = wp.lock();
	*xp = 100;
	shared_ptr<int>ppp(nullptr);
	xp.~shared_ptr();
	cout << sp.use_count() << endl;
	//Parent* pParent = new (std::nothrow) Parent();
	//if (!pParent) {
	//	return 0;
	//}
	//int a = (int)(pParent);			// 指针向整型转换
	//Parent* pParent1 = (Parent*)(a);// 整型向指针转换

	//new operator
	//int *a = new int(20);//普通new，申请内存及初始化
	////operator new
	//cout << *a << endl;
	//void *b = operator new(4);//只申请内存
	////placement new
	//cout << (int*)b << endl;
	//b = new(b)int(10);//在b的内存上初始化int内置类型对象，值为10；
	//int* c = new(b)int;
	//cout << *c << endl;
	//const int a = 10;
	//cout << *a << endl;
	//int b = static_cast<int>(a);

	/*B b;
	A* a = nullptr;
	a->show();
	a = &b;
	a->show();
	b.show();*/

	//printf("%%d", 10);

#if 0
	int x = 10, y = 5, z = 2;
	if (x > y) {
		cout << "1" << endl;
	}

	const int N = 10;
	const int M = 2;
	int* a = new int[N];
	for (int i = 0; i < N; ++i)
		a[i] = (0 == i % 2) ? (i + 2) : (i + 0);
	int(*b)[N / M] = (int(*)[N / M])a;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N / M; ++j)
			printf(" % d", b[i][j]);
#endif
	return 0;
}
#endif
#if 0
using namespace std;
void fun(int* arr, int len) {
	int x = 0;
	for (int i = 0; i < len; ++i) {
		x = arr[i] ^ x;
	}
	int index = 0;
	while (x) {
		if (x ^ 0) {
			break;
		}
		index++;
		x >> 1;
	}

	int p = 1;
	p = p << index;
	int a = 0;
	int b = 0;
	for (int i = 0; i < len; ++i) {
		if (arr[i] & p) {
			a = a ^ arr[i];
			continue;
		}
		b = b ^ arr[i];
	}
	cout << a << " " << b << endl;
}
//enum {a,b,n=10,c,m='A'};
static int a = 0;
int f(int n) {
	a++;
	if (n <= 3) return 1;
	else return f(n - 2) + f(n - 6) + 1;
}
struct st_t {
	int status;
	short* pdata;
	char errstr[32];
};


int main()
{
	st_t st[16];
	char* p = (char*)(st[2].errstr + 32);
	//cout << c << " " << n << " " << m << endl;
	//int arr[] = { 10,1,4,4,9,1,2,2 };
	//fun(arr, 8);
	return 0;
}

union X {
	int32_t a;
	struct {
		int16_t b;
		int16_t c;
	};
};
int i = 1;
class MyCls {
public:
	MyCls() :m_nFor(m_nThd), m_nSec(i++), m_nFir(i++), m_nThd(i++) {
		m_nThd = i;
	}
	void echo() {
		cout << "result:" << m_nFir + m_nSec + m_nThd + m_nFor << endl;
	}
private:
	int m_nFir;
	int m_nSec;
	int m_nThd;
	int& m_nFor;
};
int main()
{
	int* p = new int(12);
	MyCls oCls;
	oCls.echo();
	return 0;
}

int n;
string str;
vector<int>vec;
vector<char> ch;
bool jud(int i) {
	//- return 0
	if (str[i] + 1 == '-') {
		return true;
	}
	return false;
}
void fun(int st, int end)
{
	sort(vec.begin(), vec.end());
}
bool num() {

}
int main()
{
	cin >> n;
	cin >> str;
	int len = str.length();
	int i = 0;
	int st, end;
	st = 0;
	int x = 1;
	while (i < len) {
		if (str[i] == '*' || str[i] == '/') {
			end = i;
			int b = vec.back();
			vec.pop_back();
			fun(st, end);

		}
		if (str[i] == '+' || str[i] == '-') {
			if (i == 0 || jud(i + 1)) {//fuhao
				x = -1;
				i++;
				continue;
			}
			else {
				ch.push_back(str[i]);
			}
		}
		x *= (str[i] - '0');
		vec.push_back(x);
		x = 1;
	}
	return 0;
}
#endif
#if 0
class A {
protected:
	int a;
};
int main()
{
	double x = 3.0;
	int y = 5;

	x /= --y;
	cout << x << endl;
	return 0;
}

bool isup(string left, string right) {
	vector<int>lvec;
	vector<int>rvec;
	int tmp = 0;
	for (int i = 0; i < left.length(); i++) {
		if (left[i] == '.') {
			lvec.push_back(tmp);
			tmp = 0;
			continue;
		}
		tmp = 10 * tmp + left[i] - '0';
	}
	lvec.push_back(tmp);
	tmp = 0;
	for (int i = 0; i < right.length(); i++) {
		if (right[i] == '.') {
			rvec.push_back(tmp);
			tmp = 0;
			continue;
		}
		tmp = 10 * tmp + right[i] - '0';
	}
	rvec.push_back(tmp);
	int llen = lvec.size();
	int rlen = rvec.size();
	for (int i = 0; i < 3; i++) {
		if (llen > i && rlen > i) {
			if (lvec[i] < rvec[i]) {
				return true;
			}
			if (lvec[i] > rvec[i]) {
				return false;
			}
		}
		else if (rlen > i) {
			if (rvec[i] > 0) {
				return true;
			}
		}
		else if (llen > i) {
			if (lvec[i] > 0) {
				return false;
			}
		}
	}
	return false;
}


int main()
{
	int m;
	cin >> m;
	string left; string right;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		bool re = isup(left, right);
		if (re)
			cout << "true";
		else
			cout << "false";
	}
	return 0;
}

bool fun(int a)
{
	if (a == 1) {
		return true;
	}
	if (a == 0) {
		return false;
	}
	unordered_set<int>sset;
	sset.insert(a);
	while (a) {
		int x = 0;
		while (a > 0) {
			int p = a % 10;
			x += p * p;
			a /= 10;
		}
		a = x;
		if (a == 1) {
			return true;
		}
		if (sset.find(a) != sset.end()) {
			return false;
		}
		sset.insert(a);
	}
	return false;
}
int main()
{
	int m;

	cin >> m;
	vector<int>vec(m, 0);
	for (int i = 0; i < m; ++i) {
		cin >> vec[i];
	}
	vector<bool> rev;
	for (int val : vec) {
		rev.push_back(fun(val));
	}
	for (bool val : rev) {
		if (val) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}

bool fun(string& a, string& b)
{
	int lena = a.length();
	int lenb = b.length();
	int len = min(lena, lenb);
	int x = 0;
	int j = 0;
	vector<int>a1(3, 0);
	vector<int>b1(3, 0);
	for (int i = 0; i < lena; ++i) {
		if (a[i] == '.') {
			a1[j] = x;
			j++;
			x = 0;
			continue;
		}
		if (a[i] == '0') {
			continue;
		}
		x = x * 10 + a[i] - '0';
	}
	a1[j] = x;
	j = 0;
	x = 0;
	for (int i = 0; i < lena; ++i) {
		if (b[i] == '.') {
			b1[j] = x;
			j++;
			x = 0;
			continue;
		}
		if (b[i] == '0') {
			continue;
		}
		x = x * 10 + b[i] - '0';
	}
	b1[j] = x;
	int p = min(a1.size(), b1.size());
	for (int i = 0; i < p; ++i) {
		if (a1[i] < b1[i]) {
			return true;
		}
	}
	if (p < b1.size()) {
		for (int i = p; i < b1.size(); ++i) {
			if (b1[i] > '0') {
				return true;
			}
		}
	}

	return false;
}
int main()
{
	int m;
	string a, b;
	int tmp;
	cin >> m;
	vector<bool>rev(m);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		rev[i] = fun(a, b);
	}
	for (bool val : rev) {
		if (val) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>vec(m);
	int x;
	vector<int>tmp(2, 0);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> x;
			tmp[j] = x;
		}
		vec.push_back(tmp);
	}
	int count = 0;
	unordered_map<int, int> mmap;
	vector<int>rev;
	for (int i = 0; i < m; ++i) {

		if (mmap.find(vec[i][0]) == mmap.end()) {
			mmap[vec[i][0]]++;
			count++;
			rev.push_back(vec[i][0]);
		}
	}
	cout << count << endl;
	sort(rev.begin(), rev.end());
	for (int val : rev) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	int n;
	vector<int>dp;//dp[i]表示从0-i的最多次数
	//
	vector<long long> vec;
	cin >> n;
	dp.resize(n, 0);
	long long tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (vec[i] < vec[i - 1]) {
			dp[i] = dp[i - 1];
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}

int main()
{
	char ch = 040;
	int s = 200;
	//ch += 1;
	//s += ch;
	int a = 10;
	const int& b = a;
	printf("%o\n", ch << 1);
	return 0;
}

union text {//判断大下端
	int a;
	char b[4];
}t;
void swap(text& t)//大小端转换
{
	int tmp = t.a;

	int q;
	q = ((0xff & tmp) << 24) | ((0xff00 & tmp) << 8) | ((0xff0000 & tmp) >> 8) | ((0xff000000 & tmp) >> 24);
	t.a = q;
}
int main()
{
	t.a = 0x12345678;
	for (int i = 0; i < 4; ++i) {
		cout << "b" << i << ":";
		printf("%x", t.b[i]);
		cout << " ";
	}
	cout << endl;
	swap(t);
	for (int i = 0; i < 4; ++i) {
		cout << "b" << i << ":";
		printf("%x", t.b[i]);
		cout << " ";
	}
	cout << endl;
	std::cout << "Hello World!\n";
}
#endif
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
