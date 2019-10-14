#include <iostream>
#include <deque>
#include<string>
#include <vector>
#include <stack>
#include <atomic>
#include <map>
#include <unordered_set>
#include <set>
#include <time.h>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
using namespace std;
int a = 0;
#if 0
atomic_int total(0);
vector<vector<int>>threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>res;
	int size = nums.size();
	if (size < 3 || nums.front()>0 || nums.back() < 0)return res;
	int i, j, k;
	for (k = 0; k <= size - 3; ++k) {
		if (nums[k] > 0)break;
		if (k > 0 && nums[k] == nums[k - 1])continue;
		i = k + 1; j = size - 1;
		while (i < j) {
			if (nums[i] + nums[j] + nums[k] > 0)j--;
			else if (nums[i] + nums[j] + nums[k] < 0)i++;
			else {
				res.push_back({ nums[i],nums[j],nums[k] });
				while (i < j && nums[i] == nums[i + 1])i++;
				while (i < j && nums[j] == nums[j - 1])j--;
				i++;
				j--;
			}
		}
	}
}
int flg = 0;
mutex print_mutex;
condition_variable cond;
void print_thread(int num)
{
	cout << "A" << endl;
	/*for (int i = 0; i < 10; ++i) {
		unique_lock<mutex> lk(print_mutex);
		cond.wait(lk, [&]() { return num = flg; });
		cout << char('A' + num);
		flg = (flg + 1) % 3;
		cond.notify_all();
	}*/
}
int threeSumClosest(vector<int> nums, int target) {
	int size = nums.size();
	sort(nums.begin(), nums.end());
	int max = nums[0] + nums[1] + nums[2];
	if (size == 3)return max;
	int i, j, k;
	for (i = 0; i < size - 2; ++i) {
		if (i < size - 1 && nums[i] == nums[i + 1])continue;
		j = i + 1; k = size - 1;
		while (j < k) {
			int tmp = nums[i] + nums[j] + nums[k];
			if (abs(target - max) > abs(target - tmp)) {
				max = tmp;
			}
			if (tmp > target)k--;
			else if (tmp < target)j++;
			else return tmp;
		}
	}
	return max;
}
int divide(int divd, int divs)
{
	bool isbool = (divd ^ divs) >= 0;
	divd = divd < 0 ? divd : 0 - divd;
	divs = divs < 0 ? divs : 0 - divs;
	int _div = divs;
	int _ans = 0;
	int mul = 1;
	while (divd <= _div) {
		if (divd - divs <= 0) {
			_ans += mul;
			divd -= divs;
			divs += divs;
			mul += mul;
		}
		else {
			divs = _div;
			mul = 1;
		}
	}
	return _ans;
}
void nextPermutation(vector<int> nums) {
	int index = -1;
	int j = -1;
	for (int i = nums.size() - 1; i >= 0; --i) {
		if (i - 1 >= 0 && nums[i - 1] < nums[i]) { index = i - 1; break; }
	}
	if (index == -1) { reverse(nums.begin(), nums.end()); return; }
	for (int i = index + 1; i < nums.size(); ++i) {
		j = i;
		if (i + 1 < nums.size() && nums[i + 1] < nums[index])break;
	}
	int tmp = nums[index];
	nums[index] = nums[j];
	nums[j] = tmp;

	int i = index + 1; j = nums.size() - 1;
	while (i < j) {
		tmp = nums[i];
		nums[i++] = nums[j];
		nums[j--] = tmp;
	}
}
int longest(string str)
{
	int m = 0;
	int left = 0, right = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(')left++;
		else right++;

		if (left == right) {
			m = max(m, 2 * left);
		}
		else if (right >= left) {
			left = right = 0;
		}
	}
	left = right = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (str[i] == '(')left++;
		else right++;

		if (left == right) {
			m = max(m, 2 * left);
		}
		else if (right <= left) {
			left = right = 0;
		}
	}
	return m;
}
int search(vector<int> nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	while (start <= end) {
		int mid = (end - start) / 2 + start;
		if (nums[mid] == target)return mid;
		else if (nums[mid] < nums[end]) {
			if (nums[mid] < target && target <= nums[end])start = mid + 1;
			else end = mid - 1;
		}
		else {
			if (nums[start] <= target && target < nums[mid])end = mid - 1;
			else start = mid + 1;
		}
	}
	return -1;
}
string countAndSay(int n)
{
	string str = "1";
	for (int i = 2; i <= n; ++i) {
		string tmp;
		for (int j = 0; j < str.size(); ++j) {
			int count = 1;
			while (j + 1 < str.size() && str[j] == str[j + 1]) {
				count++;
				j++;
			}
			tmp += to_string(count) + str[j];
		}
		str = tmp;
	}
	return str;
}
int findnum(vector<int>nums)
{
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i] >= 1 && nums[i] < nums.size()) {
			int t = nums[i] - 1;
			if (nums[i] != nums[t]) {
				swap(nums[i], nums[t]);
				i -= (t > i);
			}
		}
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != i + 1)return i + 1;
	}
	return nums.size() + 1;
}
int trap(vector<int>height)
{
	int size = height.size();
	if (size == 0)return 0;
	int ans = 0;
	vector<int>left_max(size), right_max(size);
	left_max[0] = height[0];
	for (int i = 1; i < size; ++i) {
		left_max[i] = max(left_max[i - 1], height[i]);
	}
	right_max[size - 1] = height[size - 1];
	for (int i = size - 2; i >= 0; --i) {
		right_max[i] = max(height[i], right_max[i + 1]);
	}
	for (int i = 0; i < size; ++i) {
		ans += min(left_max[i], right_max[i]);
	}
	return ans;
}
int drap(vector<int>vec)
{
	int size = vec.size();
	int left = 0, right = size - 1;
	int ans = 0;
	int left_max = 0, right_max = 0;
	while (left < right)
	{
		if (vec[left] < vec[right])
		{
			vec[left] >= left_max ? left_max = vec[left] : ans += (left_max - vec[left]);
			left++;
		}
		else
		{
			vec[right] >= right_max ? right_max = vec[right] : ans += (right - vec[right]);
			right--;
		}
	}
	return ans;
}

vector<vector<int>>ans;
void print(vector<int>& vec, int i)
{
	if (i == vec.size()) {
		ans.push_back(vec);
	}
	else {
		for (int j = i; j < vec.size(); ++j) {
			swap(vec[i], vec[j]);
			print(vec, i + 1);
			swap(vec[i], vec[j]);
		}
	}
}
void rotate(vector<vector<int>>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			swap(vec[i][j], vec[j][i]);
		}
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size / 2; ++j)
		{
			swap(vec[i][j], vec[i][size - j - 1]);
		}
	}
}
vector<vector<string>>group(vector<string>& vec)
{
	map<string, vector<string>>ma;
	vector<vector<string>>ans;
	for (auto m : vec)
	{
		string tmp = m;
		sort(tmp.begin(), tmp.end());
		ma[tmp].push_back(m);
	}
	for (auto& p : ma) {
		ans.push_back(p.second);
	}
	return ans;
}
int findfirst(vector<int>vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] > 0 && vec[i] < vec.size()) {
			int a = vec[i] - 1;
			if (vec[i] != vec[a]) {
				swap(vec[i], vec[a]);
				i -= (a > i);
			}
		}
	}

	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] != i + 1)return i + 1;
	}
	return vec.size() + 1;
}
double mypow(double a, long long b) {
	double ans = 1;
	while (b) {
		if (b & 1)ans *= a;
		b >>= 1;
		a *= a;
	}
	return ans;
}
double pow(double x, long long n)
{
	if (n == 0)return 1;
	if (n > 0)return mypow(x, n);
	if (n < 0)return 1 / mypow(x, -n);
	return 1.0;
}
vector<int> spiralOrder(vector<vector<int>> matrix) {
	vector<int>ans;
	if (matrix.empty())return ans;
	int u = 0, l = 0;
	int d = matrix.size() - 1, r = matrix[0].size() - 1;
	while (1)
	{
		for (int i = l; i <= r; ++i)ans.push_back(matrix[u][i]);
		if (++u > d)break;
		for (int i = u; i <= d; ++i)ans.push_back(matrix[i][r]);
		if (--r < l)break;
		for (int i = r; i >= l; --i)ans.push_back(matrix[d][i]);
		if (--d < u)break;
		for (int i = d; i >= u; --i)ans.push_back(matrix[i][l]);
		if (++l > r)break;
	}
	return ans;
}
union asd
{
	double a;
	char ab[9];
};
vector<int> plusOne(vector<int> digits) {
	if (digits.front() == 0)return { 1 };
	vector<int>ans;
	int i = digits.size() - 1;
	for (; i >= 0; --i) {
		if (digits[i] != 9)break;
		ans.push_back(0);
	}
	if (i < 0) {
		ans.push_back(1);
	}
	else {
		ans.push_back(1 + digits[i]);
		i--;
		for (; i >= 0; --i) {
			ans.push_back(digits[i]);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

struct XY {
	int x;
	int y;
	XY(int a = 0, int b = 0) :x(a), y(b) {}
};
string addBinary(string a, string b) {
	if (a == b)return a + '0';
	int lena = a.size();
	int lenb = b.size();
	if (lena < lenb) {
		a = '0' + a;
		lena++;
	}
	if (lena > lenb) {
		b = '0' + b;
		lenb++;
	}
	int num = 0;
	for (int i = lenb - 1; i >= 0; --i) {
		int c = a[i] + b[i] + num - '0' - '0';
		if (c >= 2) {
			a[i] = c % 2 + '0';
			num = 1;
		}
		else {
			a[i] = c + '0';
			num = 0;
		}
	}
	if (num != 0) {
		a = '1' + a;
	}
	return a;
}
void sortColors(vector<int> nums) {
	int l = 0;
	int r = nums.size() - 1;
	int one = 0;
	int i = l;
	while (i <= r) {
		if (nums[i] == 1) {
			++one;
			++i;
		}
		else if (nums[i] < 1) {
			swap(nums[l++], nums[i]);
			if (nums[i] == 1) ++i;
			i = max(i, l);
		}
		else {
			swap(nums[r--], nums[i]);
		}
	}
	for (int i = 0; i < one; ++i) nums[i + l] = 1;
}

bool search(vector<int> nums, int target) {
	if (nums.size() == 0)return false;
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		/*while (l < r && nums[l] == nums[l + 1])l++;
		while (l < r && nums[r] == nums[r - 1])r--;*/
		int mid = (l + r) / 2;
		if (nums[mid] <= nums[r]) {
			if (nums[mid] == target)return true;
			if (nums[mid] < target && target <= nums[r])l = mid + 1;
			else r = mid - 1;
		}
		else {
			if (nums[mid] == target)return true;
			if (nums[mid] > target && target >= nums[l])r = mid - 1;
			else l = mid + 1;

		}
	}
	if (nums[l] == target)return true;
	return false;
}
#endif
int largestRectangleArea(vector<int> heights) {
	int ans = 0;
	stack<int>m_st;
	m_st.push(-1);
	int i = 0;
	for (; i < heights.size(); ++i) {
		while (m_st.top() != -1 && heights[m_st.top()] >= heights[i]) {
			int top = m_st.top();
			m_st.pop();
			ans = max(ans, heights[top] * (i - 1 - m_st.top()));
		}
		m_st.push(i);
	}
	while (m_st.top() != -1) {
		int top = m_st.top();
		m_st.pop();
		ans = max(ans, heights[top] * (i - 1 - m_st.top()));
	}
	return ans;
}
int main()
{
	largestRectangleArea({ 2,1,5,6,2,3 });
	return 0;
}
#if 0
int main5()
{
	unordered_set<XY>m_set;
	XY id;
	m_set.insert(id);

	int r, c;
	cin >> r >> c;
	vector<vector<char>>vec(r, vector<char>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> vec[i][j];
		}
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	bool a = false, b = false;//a表示左右交换  b上下交换
	if (r1 == r2 && c2 == c1) { printf("0\n"); return 0; }
	if (r1 == r2) { a = true; }
	else b = true;
	int ans = 0;
	int num = 1;
	if (a) {
		int i = r2, j = c2, count = 0;
		while (i - 1 >= 0) {
			if (vec[r1][c1] == vec[i - 1][j]) { i--; count++; }
			else { i = r2; break; }
		}
		while (i + 1 < r) {
			if (vec[r1][c1] == vec[i + 1][j]) { i++; count++; }
			else { i = r2; break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; num = 0; }
		while (j + 1 < c) {
			if (vec[r1][c1] == vec[i][j + 1]) { j++; count++; }
			else { break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; }


		i = r1; j = c1; num = 1;
		while (i - 1 >= 0) {
			if (vec[r2][c2] == vec[i - 1][j]) { i--; count++; }
			else { i = r1; break; }
		}
		while (i + 1 < r) {
			if (vec[r2][c2] == vec[i + 1][j]) { i++; count++; }
			else { i = r1; break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; num = 0; }
		while (j - 1 >= 0) {
			if (vec[r2][c2] == vec[i][j - 1]) { j--; count++; }
			else { break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; }
	}
	else {
		int i = r2, j = c2, count = 0;
		while (j - 1 >= 0) {
			if (vec[r1][c1] == vec[i][j - 1]) { j--; count++; }
			else { j = c2; break; }
		}
		while (j + 1 < c) {
			if (vec[r1][c1] == vec[i][j + 1]) { j++; count++; }
			else { j = c2; break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; num = 0; }
		while (i + 1 < r) {
			if (vec[r1][c1] == vec[i + 1][j]) { i++; count++; }
			else { break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; }


		i = r1; j = c1; num = 0;
		while (j - 1 >= 0) {
			if (vec[r2][c2] == vec[i][j - 1]) { j--; count++; }
			else { j = c1; break; }
		}
		while (j + 1 < c) {
			if (vec[r2][c2] == vec[i][j + 1]) { j++; count++; }
			else { j = c1; break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; num = 0; }
		while (i - 1 >= 0) {
			if (vec[r2][c2] == vec[i - 1][j]) { i--; count++; }
			else { break; }
		}
		if (count >= 2) { ans += (count + num); count = 0; }
	}
	printf("%d\n", ans);
	return 0;
}
int main12()
{
	char bb[200];
	cout << sizeof(bb) << endl;
	string str;
	cin >> str;
	int b = 0, e = 0, i = 0;
	int ans = 0;
	while (i < str.size())
	{
		if (str[i] == ';') {
			if (e == 0) { b = e = 0; i++; continue; }
			ans += abs(str[b] - str[e]);
			b = e = 0;
		}
		if (!(str[i] <= '9' && str[i] >= '0') && str[i] != ';') {
			if (b == 0)b = i;
			else e = i;
		}
		else {
			b = e = 0;
			while (i < str.size() && str[i] != ';')i++;
		}
		i++;
	}
	if (e != 0)
		ans += abs(str[b] - str[e]);
	printf("%d\n", ans);
	return 0;
}
int main1()
{
	spiralOrder({ {1,2},{3,4} });
	size_t a;
	//priority_queue<int, greater<int>>q;
	set<int>s;
	string str = "guojia";
	int num = str.find("cheng");
	cout << num << endl;
	//threeSumClosest({ 1, 1, 1, 0 }, 100);
	/*clock_t start = clock();
	clock_t finish = clock();
	thread t1(print_thread, 1);
	thread t2(print_thread, 2);
	print_thread(0);
	t1.join();
	t2.join();*/
	return 0;
}

string intToRoman(int num)
{
	map<int, string>mapRom = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"} };
	auto it = mapRom.rbegin();
	string rev;
	while (it != mapRom.rend()) {
		if (num > it->first) {
			rev += it->second;
			num -= it->first;
		}
		else {
			it++;
		}
	}
	return rev;
}
int findNum(string str)
{
	unordered_map<string, int>mmap{ {"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000} };
	int i = 0;
	int rev = 0;
	while (i < str.size()) {
		if (i + 1 < str.size()) {
			if (mmap.find(str.substr(i, 2)) != mmap.end()) {
				rev += mmap[str.substr(i, 2)]; i += 2; continue;
			}
		}
		rev += mmap[str.substr(i, 1)];
		i++;
	}
	return rev;
}
int fun() {
	string rev("guojia");
	cout << rev.substr(0, 2) << endl;
	//cout << rev << endl;
	string s1("hello"); //cout << s1 << endl;
	string s2(s1.begin(), s1.begin() + 1); //cout << s2 << endl;
	const char* p = "world";
	char arr[] = "abcd";
	string s3(p); //cout << s3 << endl;
	string s4(p + 2, p + 3); //cout << s4 << endl;//r
	string s5(arr); //cout << s5 << endl;
	string s6(arr); cout << s6 << endl;
	string s7(s6, 1); cout << s7 << endl;
	string s8(p, 1); cout << s8 << endl;
	s8.size();
	/*
	_NODISCARD size_type size() const noexcept { // return length of sequence
		return _Get_data()._Mysize;
	}
	*/
	s8.length();
	cout << s6.substr() << endl;
	s8.append("123");
	s8.append(s6);
	cout << s8 << endl;
	s8.replace(1, 2, s6);
	cout << s8 << endl;
	cout << s8.find("bcd");
	s8.compare(s6);
	/*
	_NODISCARD _Ret_z_ const _Elem* c_str() const noexcept { // return pointer to null-terminated immutable array
		return _Get_data()._Myptr();
	}

	_NODISCARD basic_string substr(const size_type _Off = 0, const size_type _Count = npos) const {
		// return [_Off, _Off + _Count) as new string
		return basic_string(*this, _Off, _Count, get_allocator());
	}
	*/
	return 0;
}
//int a = fun();
string maxlen(vector<string>strs) {
	int len = 0;
	while (len < strs[0].size() && len < strs[1].size() && strs[0][len] == strs[1][len])len++;
	for (int s = 2; s < strs.size(); ++s) {
		if (strs[s].size() < len)len = strs[s].size();
		while (len && strs[s][len - 1] != strs[0][len - 1])len--;
		if (len <= 0)break;
	}
	return string(strs[0].begin(), strs[0].begin() + len);
}
int main()
{
	string str("LVIII");
	findNum(str);
	return 0;
}

class A {
public:
	const static void show() { cout << 1 << endl; }
	const static int a = 1;
};
//int A::a = 1;
//void A::show() { cout << 1 << endl; }
//{ cout << 1 << endl; }
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	memset(arr, 1, n);
	//cout << arr[0] << endl;
	for (int i = 2; i <= sqrt(n); ++i) {
		for (int j = n - 1; j > 0; --j) {
			if (j % i == 0) {
				arr[j] = 0;
			}
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		if (arr[i] == 1) {
			cout << i << endl; return 0;
		}
	}
	/*string str;
	cin >> str;
	reverse(str.begin(), str.end());
	auto it = str.begin();

	while (it != str.end())
	{
		auto itTmp = it;
		if (*it == ' ')
		{
			reverse(itTmp, it);
		}
		it++;
	}
	cout << str;*/
	return 0;
}
#endif