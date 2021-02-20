#include "main.h"
#pragma warning (disable: 4996)
using namespace std;

bool getInput(int& n, char** x, char** y) 
{
	string s;
	cin >> s;
	n = stoi(s);
	if (!isNumber(s) || (s[0] == '0' && s.length() > 1))
		return false;
	initNumArr(n, x, y);
	cin >> *x >> *y;
	if (!isNumber(*x) || !isNumber(*y) || strlen(*x) != n || strlen(*y) != n)
		return false;
	return true;
}

bool isNumber(const string& str) 
{
	if (str.length() == 1 && str[0] == 0)
		return true;
	return (!str.empty() && find_if(str.begin(), str.end(), [](unsigned char c) { return !isdigit(c); }) == str.end());
}

void printMultiResult(int* res, int resSize) 
{
	cout << "Long multiplication : x * y = ";
	int i = resSize;
	while (i > 0 && res[i - 1] == 0)
		i--;
	resSize = i;
	if (resSize == 0)  
        cout << 0;
    else 
	{
        for (int i = resSize - 1; i >= 0; i--) 
            cout << res[i];
    }
	cout << endl;
}

void printResult2(char* res,int func) 
{
	if(func==2)
	cout << "Karatsuba (recursive): x * y = ";
	if(func==3)
		cout << "Karatsuba (iterative): x * y = ";
	while (res[0] == '0' && res[1] != '\0')
	{
		res = res + 1;
	}
	cout << res << endl;
}

int main(void)
{
	int n = 0, resSize = 0;
	int* resInt = nullptr;
	char* x = nullptr, * y = nullptr, * res = nullptr;
	bool flag = getInput(n, &x, &y);
	if (n == 0)
		return 0;
	if (!flag) 
	{
		cout << "wrong output" << endl;
		return 0;
	}
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	resInt = longMulti(n, x, y, resSize);
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); 
	myfile << "Time taken by function longMulti is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	printMultiResult(resInt, resSize);

	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	res = karatsuba(n, x, y);
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function karatsubaRec is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	printResult2(res,2);

	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	res = Karatsuba_Iter(n, x, y);
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function karatsuba_Iter is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	printResult2(res,3);

}

int intlen(int* arr)
{
	int i = 0;
	while (arr[i] != -1)
		i++;
	return i;
}

char* dup(const char* src)
{
	if (src)
	{
		char* dst = new char[strlen(src) + 1];
		strcpy(dst, src);
		return dst;
	}
	else
		return nullptr;
}

void intToChar(char* arr, int*& res)
{
	int size = strlen(arr);
	int i = 0;
	for (; i < size; i++)
	{
		res[i] = arr[i] - '0';
	}
	res[i] = -1;
}
