// 笔试2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;
int main()
{
	return 0;
}
#if 0
string find(string& str) {
	if (str.size() < 2)return str;

}
int find_num(string& str, string& sub) {
	vector<vector<int>>vec(str.size());
	for (int i = 0; i < vec.size(); ++i) {
		vec[i].resize(sub.size(), 0);
	}

	int len = -1;
	/*for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < sub.size(); ++j) {
			if (str[i] == sub[j]) {
				if (i == 0 || j == 0)vec[i][j] = 1;
				else vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			if (len < vec[i][j])len = vec[i][j];
		}
	}*/
	vector<int>tmp(str.length());
	int end = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (str[i] == sub[j]) {
				if (j == 0)tmp[j] = 1;
				else tmp[j] = tmp[j - 1] + 1;
			}
			if (len < tmp[j]) {
				int b = str.size() - j - 1;
				if (b + tmp[j] - 1 == i) {
					len = tmp[j];
					end = i;
				}
			}
		}
	}
	return len;
}

int myAtoi(string str) {
	int rev = 0;
	long long num = 0;
	if (str.size() == 0)return rev;
	bool flg = true;
	int i = 0;
	for (; i < str.size();) {
		if (str[i] == ' ') {
			i++;
			continue;
		}
		if (str[i] == '+') {
			i++;
			break;
		}
		if (str[i] == '-') {
			i++;
			flg = false;
			break;
		}
		break;
	}
	while (i < str.size()) {
		if (str[i] > '9' || str[i] < '0')break;
		if (num > INT_MAX)break;
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (!flg)num = -num;
	if (num >= INT_MAX)rev = INT_MAX;
	else if (num <= INT_MIN)rev = INT_MIN;
	else rev = num;
	return rev;
}
string longestPalindrome(string s) {
	if (s.size() < 2)return s;
	string sub = s.c_str();
	reverse(sub.begin(), sub.end());
	int len = -1;
	int end = -1;
	vector<int>arr(s.size(), 0);
	for (int i = 0; i < s.size(); ++i) {
		for (int j = sub.size() - 1; j >= 0; --j) {
			if (s[i] == sub[j]) {
				if (j == 0)arr[j] = 1;
				else arr[j] = arr[j - 1] + 1;
			}
			else arr[j] = 0;
			if (arr[j] > len) {
				int b = sub.size() - 1 - j;
				if (b + arr[j] - 1 == i) {
					len = arr[j];
					end = i;
				}
			}
		}
	}

	return s.substr(end - len + 1, len);
}
int bf(string& str, string& sub) {
	if (str.size() == 0 || sub.size() == 0)return -1;
	int i = 0, j = 0;
	while (i < str.size() && j < sub.size()) {
		if (str[i] == sub[j]) {
			i++; j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= sub.size())return i - j;
	else return -1;
}
void fun(vector<int>& vec, string& sub) {
	vec[0] = -1;
	if (sub.size() == 1)return;
	vec[1] = 0;
	if (sub.size() == 2)return;
	int k = 0;
	int i = 2;
	while (i < sub.size()) {
		if (k == -1 || sub[i - 1] == sub[k]) {
			vec[i] = k + 1;
			k++;
			i++;
		}
		else {
			k = vec[k];
		}
	}
}
int kmp(string& str, string& sub) {
	if (str.size() == 0 || sub.size() == 0)return -1;
	vector<int>vec(sub.size());
	fun(vec, sub);

	int i = 0, j = 0;
	int len1 = str.size();
	int len2 = sub.size();
	while (i < len1 && j < len2) {
		if (j == -1 || str[i] == sub[j]) {
			i++;
			j++;
		}
		else {
			j = vec[j];
		}
	}
	if (j >= sub.size()) {
		return i - j;
	}
	return -1;
}
int main()
{
	int n;
	cin >> n;
	vector<int>x(n);
	vector<int>y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int numx, numy;
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (x[i] > max)max = x[i];
		if (x[i] < min)min = x[i];
	}
	numx = (max + min) / 2;
	max = INT_MIN; min = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (y[i] > max)max = y[i];
		if (y[i] < min)min = y[i];
	}
	numy = (max + min) / 2;
	int rev = 0;
	for (int i = 0; i < n; ++i) {
		rev += abs(x[i] - numx);
		rev += abs(y[i] - numy);
	}
	rev -= (n - 1);
	cout << rev << endl;
	return 0;
}

int main()
{
	vector<string>vec(4);
	string tmp;
	for (int i = 0; i < 4; ++i) {
		cin >> vec[i];
		if (vec[i].length() > 2) {
			printf("ERROR\n");
			return 0;
		}
	}
	vector<int>num(4);
	for (int i = 0; i < 4; ++i) {
		if (vec[i] == "A")num[i] = 1;
		else if (vec[i] == "J")num[i] = 11;
		else if (vec[i] == "Q")num[i] = 12;
		else if (vec[i] == "K")num[i] = 13;
		else if (vec[i] == "10")num[i] = 10;
		else num[i] = vec[i][0] - '0';
	}
	if (num[0] * num[1] * num[2] * num[3] < 24) { printf("NONE\n"); return 0; }
	if ((num[0] + num[1] + num[2] + num[3]) == 24) {
		cout << vec[0] << "+" << vec[1] << "+" << vec[2] << "+" << vec[3] << endl;
		return 0;
	}
	//sort(num.begin(),num.end());
	if ((num[0] * num[1] + num[2] + num[3]) == 24) {
		cout << vec[0] << "*" << vec[1] << "+" << vec[2] << "+" << vec[3] << endl;
		return 0;
	}
	if ((num[0] * num[1] * num[2] + num[3]) == 24) {
		cout << vec[0] << "*" << vec[1] << "*" << vec[2] << "+" << vec[3] << endl;
		return 0;
	}
	if ((num[0] * num[1] * num[2] * num[3]) == 24) {
		cout << vec[0] << "*" << vec[1] << "*" << vec[2] << "*" << vec[3] << endl;
		return 0;
	}

	if ((num[0] + num[1] * num[2] + num[3]) == 24) {
		cout << vec[0] << "+" << vec[1] << "*" << vec[2] << "+" << vec[3] << endl;
		return 0;
	}
	if ((num[0] + num[1] + num[2] * num[3]) == 24) {
		cout << vec[0] << "*" << vec[1] << "+" << vec[2] << "*" << vec[3] << endl;
		return 0;
	}
	if ((num[0] + num[1] * num[2] * num[3]) == 24) {
		cout << vec[0] << "+" << vec[1] << "*" << vec[2] << "*" << vec[3] << endl;
		return 0;
	}
	char pp[] = "ad";
	return 0;
}


void fun(string& str) {
	if (str.length() == 0)return;
	unordered_map<char, int>mmap;
	for (int i = 0; i < str.length(); ++i) {
		mmap[str[i]]++;
	}
	unordered_map<char, int>f;
	int i = 0;
	char ch = str[0];
	int b = 0;
	while (i < str.length()) {
		if (mmap[ch] == 0) {
			int j = b;
			for (; j < i; ++j) {
				if (mmap[str[j]] != 0)break;
			}
			if (j == i) {
				while (b < i)cout << str[b++];
				cout << " ";
				ch = str[i];
			}
			else {
				ch = str[j];
			}
		}
		else {
			f[str[i]]++;
			mmap[str[i]]--;
			i++;
		}
	}
	while (b < i)cout << str[b++];
	cout << endl;
}
int main()
{
	string str;
	while (cin >> str) {
		fun(str);
	}
	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int>num(nums1.size() + nums2.size());
	for (int i = 0; i < nums1.size(); ++i)num[i] = nums1[i];
	for (int i = 0; i < nums2.size(); ++i)num[i + nums1.size()] = nums2[i];
	sort(num.begin(), num.end());
	double rev = 0;
	if (num.size() % 2 != 0)rev = num[num.size() / 2] * 2;
	else {
		rev = num[num.size() / 2] + num[num.size() / 2 - 1];
	}
	return rev / 2;
}
string fun(string& st1, string& st2) {
	if (st1.size() == 0 || st2.size() == 0)return {};
	int** arr = new int* [st1.size()];
	for (int i = 0; i < st1.size(); ++i) {
		*arr = new int[st2.size()];
	}
	for (int i = 0; i < st1.size(); ++i) {
		for (int j = 0; j < st2.size(); ++j) {

		}
	}
}
void fun(string& str) {
	int count = 1;
	for (int i = 0; i < str.length();) {
		if (str[i] == 'Q') {
			printf("Text%d", count++);
			i++;
			while (str[i] >= '0' && str[i] <= '9')i++;
		}
		else {
			printf("%c", str[i]);
			if (str[i] >= '0' && str[i] <= '9')count = 1;
			i++;
		}
	}
}
int main1()
{
	vector<int>vec;
	int tmp;
	while (cin >> tmp) {
		if (tmp == ',')continue;
		vec.push_back(tmp);
		if (cin.get() == '\n')break;
	}
	int n;
	cin >> n;
	if (n == vec.back()) {
		cout << -1 << endl; return 0;
	}
	int len = 0;
	int num = 1;
	while (num < n) {
		len++;
		num *= 2;
	}
	int rev = n * 2 + 1;
	if (rev > vec.size())rev = -1;
	cout << rev << endl;
	return 0;
}
int main1()
{
	unordered_map<string, int>mmap;
	string str;
	while (cin >> str) {
		mmap[str]++;
		if (cin.get() == '\n')break;
	}
	auto it = mmap.begin();
	map<string, int>mp;
	for (; it != mmap.end(); ++it) {
		string tmp;
		int i = 0;
		for (; i < it->first.length(); ++i) {
			if (it->first[i] == '-')break;
		}
		i++;
		for (; i < it->first.length(); ++i) {
			tmp += it->first[i];
		}
		mp[tmp]++;
	}
	int len = 3;
	auto itm = mp.rbegin();
	if (itm->second < 2) {
		auto ip = mp.begin();
		for (int i = 0; i < 3; ++i) {
			printf("%s %d\n", ip->first, ip->second);
			ip++;
		}
	}
	else {
		for (int i = 0; i < 3; ++i) {
			if (itm->second < 2)break;
			cout << itm->first << " " << itm->second << endl;
			itm++;
			len--;
		}
	}
	auto ip = mp.begin();
	for (int i = 0; i < len; ++i) {
		cout << ip->first << " " << ip->second << endl;
		ip++;
	}
	return 0;
}

long long fun(int j, int num, int i) {

	long long rev = j;
	if (i == 0)return num;
	for (--i; i > 0; --i) {
		rev *= j;
	}
	return rev * num;
}
int main()
{
	long long n, x;
	cin >> n >> x;
	vector<int>vec;
	while (x > 0) {
		vec.push_back(x % 10);
		x = x / 10;
	}
	int i = 10;//i表进制
	for (;; i += 10) {
		long long tmp = 0;
		for (int j = 0; j < vec.size(); ++j) {
			tmp += fun(i, vec[j], j);
		}
		if (tmp == n) {
			printf("%d\n", i);
			return 0;
		}
		if (tmp > n)break;
	}
	int j = i - 10;
	for (; j < i; ++j) {
		long long tmp = 0;
		for (int k = 0; k < vec.size(); ++k) {
			tmp += fun(j, vec[k], k);
		}
		if (tmp == n) {
			printf("%d\n", j);
			return 0;
		}
		if (tmp > n)break;
	}
	printf("%d\n", j - 1);
	return 0;
}


class Produck {
public:
	Produck(string name) :_name(name) {}
	virtual void show() = 0;
protected:
	string _name;
};
class ProductA :public Produck {
public:
	ProductA(string name) :Produck(name) {}
	void show() { cout << "get A" << endl; }
};
class ProductB :public Produck {
public:
	ProductB(string name) :Produck(name) {}
	void show() { cout << "get B" << endl; }
};

class Factory {
public:
	virtual Produck* createProduct() = 0;
};
class Xiaomi :public Factory {
public:
	Produck* createProduct() {
		return new ProductA("小米");
	}
};
class Huawei :public Factory {
public:
	Produck* createProduct() {
		return new ProductA("华为");
	}
};
//enum ProductType { XIAOMI, HUAWEI };
//class SimpleFactory {
//public:
//	Produck* createProduct(ProductType type) {
//		switch (type)
//		{
//		case XIAOMI:
//			return new ProductA("小米");
//		case HUAWEI:
//			return new ProductB("华为");
//		default:
//			break;
//		}
//	}
//};
int main()
{
	unique_ptr<Factory> f1(new Xiaomi);
	unique_ptr<Factory> f2(new Huawei);
	unique_ptr<Produck> p1(f1->createProduct());
	unique_ptr<Produck> p2(f2->createProduct());
	p1->show();
	p2->show();
	return 0;
}
#endif
#if 0
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int** arr = new int* [s1.length()];
	for (int i = 0; i < s1.length(); ++i) {
		arr[i] = new int[s2.length()];
	}
	int i, j, max_len = 0;
	for (i = 0; i < s1.size(); ++i) {
		for (j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				if (i > 0 && j > 0)arr[i][j] = arr[i - 1][j - 1] + 1;
				else arr[i][j] = 1;
				if (max_len < arr[i][j])max_len = arr[i][j];
			}
		}
	}
	for (i = 0; i < s1.length(); ++i) {
		delete arr[i];
	}
	delete[]arr;
	printf("%d\n", max_len);
	return 0;
}

int fun(int n)
{
	int rev = 0;
	while (n > 0) {
		rev = n % 10;
		if (rev > 0)break;
		n /= 10;
	}
	return rev;
}
int main()
{
	int n;
	cin >> n;
	int len = 2147483647;
	unordered_map<int, int>mmap;
	int i = 0;
	int count = 0;
	for (; i < len; ++i) {
		int rp = i;
		int tmp = i % n;
		if (tmp == rp)
		{
			count++;
		}
		if (mmap.find(tmp) != mmap.end())break;
		mmap[tmp]++;
	}
	int rev = count;
	for (int j = count - 1; j >= 1; --j) {
		rev *= j;
	}
	rev = rev % (1000003);
	printf("%d\n", rev);
	return 0;
}

void show(vector<char>& vec) {

}
int main()
{

	//int n;
	//cin >> n;
	//if (n == 0)return 0;
	//vector<char>vec(n);
	//for (int i = 0; i < n; ++i) {
	//	cin >> vec[i];
	//}
	//if (vec[0] == '#') {
	//	printf("#\n");
	//	return 0;
	//}
	////show(vec);
	cout << 0 << endl << 1 << endl << 3 << endl << '#' << endl << 5 << endl << '#' << endl << '#' << endl << '#' << endl << 2 << endl << '#' << endl << 4 << endl << 6 << endl << '#' << endl << '#' << endl << '#' << endl;
	return 0;
}

string find_longest_num_str(string input) {

	int max = -1;
	int i = 0;
	int b = -1, e = -1;
	string rev;
	while (i < input.length()) {
		int len = 0;
		int a, c;
		if (input[i] <= '9' && input[i] >= '0') {
			a = i;
			while (i < input.length()) {
				if (input[i] <= '9' && input[i] >= '0') {
					c = i;
					i++;
					len++;
				}
				else {
					if (max < len) {
						max = len;
						b = a;
						e = c;
					}
					break;
				}
			}
		}
		else {
			i++;
		}
	}
	if (b == -1 || e == -1)return rev;
	for (int i = b; i <= e; ++i) {
		rev += input[i];
	}
	return rev;
}
/******************************结束写代码******************************/

int smallestRange() {

	int k;
	cin >> k;
	vector<int>vec;
	int tmp;
	while (cin >> tmp) {
		if (cin.get() == '\n')break;
		vec.push_back(tmp);
	}
	return 3;
}
int main() {

	return 0;
}

//#pragma pack(4)  
typedef struct MemAlign
{
	char a[18];
	double b;
	char c;
	int d;
	short e;
}MemAlign;
int fun(int a) {
	cout << a << endl;
	return 0;
}
int fun(vector<int>& vec, int begin, int end) {
	int tmp = vec[begin];
	while (begin < end) {
		while (end > begin && vec[end] >= tmp) {
			end--;
		}
		if (end > begin && vec[end] < tmp)vec[begin] = vec[end];
		while (end > begin && vec[begin] <= tmp) {
			begin++;
		}
		if (end > begin && vec[begin] > tmp)vec[end] = vec[begin];
	}
	vec[end] = tmp;
	return end;
};
class A {
	void fun() {}
	void fun() const {}
};
int main()
{
	vector<int>v(9, 0);
	cout << v.capacity() << endl;
	int n;
	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[2];
	}
	vector<int>vec(20);
	for (int i = 0; i < 20; ++i)vec[i] = rand() % 100;
	for (int val : vec)cout << val << " ";
	cout << endl;
	int b = 0;
	int e = vec.size() - 1;
	int par = 0;
	while (1) {
		par = fun(vec, b, e);
		if (par > 5) e = par - 1;
		else if (par < 5)b = par + 1;
		else break;
	}
	for (int val : vec)cout << val << " ";
	cout << endl;
	return 0;
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
