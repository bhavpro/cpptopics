#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

char inttoalpha(int x)
{
    return (96 + x);
}

int stringtoint(string &str, int &i, int num = 1)
{
    if(num == 1)
    {
        return (str[i] - 48);
    }
    // num == 2
    return (((str[i] - 48) * 10) + (str[i + 1] - 48));
}

int chartoint(char a,char b)
{
    if(b == '\0')
    {
        return (a - 48);
    }
    return ((10 * (a - 48)) + (b - 48));
}

void all(string str, int i = 0)
{
	static int s = 0;
    static string final = "";
    static int length = str.size();
    // base
    if( i == length)
    {
		if(s == 1)
		{
			cout << ", ";
		}
        cout << final ;
		s = 1;
        return;
    }

    // rec
    // 1 digit 
    int num = stringtoint(str, i, 1);
    final.push_back(inttochar(num));
    all(str, i + 1);
    final.pop_back();
    
    // 2 digit
    if(i + 1 == length)
    {
        return;
    }
    num = stringtoint(str, i, 2);
    final.push_back(inttochar(num));
    all(str, i + 2);
    final.pop_back();
}
/*

vector<string> ans(char *str, int n)
{
    // base
    if(n == 0)
    {
        vector<string> temp;
        temp.push_back("");
        return temp;
    }

    // rec

    vector<string> arr1, arr2, arrret;
    arr1 = ans(str + 1, n - 1);
    char x = inttoalpha(chartoint(str[0], '\0'));
    string temp;
    for (int i = 0; i < arr1.size(); i++)
    {
        // initiate temp
        temp = "";
        // create temp
        temp.push_back(x);
        for (int j = 0; j < arr1[i].size(); j++)
        {
            temp.push_back(arr1[i][j]);
        }
        // push temp in arrret
        arrret.push_back(temp);
    }

    if (n - 1 != 0)
    {
        arr2 = ans(str + 2, n - 2);
        char y = inttoalpha(chartoint(str[0], str[1]));
        string temp1;
        for (int i = 0; i < arr2.size(); i++)
        {
            // initiate temp1
            temp1 = "";
            // create temp1
            temp1.push_back(y);
            for (int j = 0; j < arr2[i].size(); j++)
            {
                temp1.push_back(arr2[i][j]);
            }
            // push temp in arrret
            arrret.push_back(temp1);
        }
    }
    return arrret;
}
*/
int main()
{
    char str[100];
    cin >> str;
    int n = 0;
    while(str[n] != '\0')
    {
        n++;
    }
    cout << '[';
    vector<string> temp = ans(str, n);
    int i;
    for (i = 0; i < temp.size() - 1; i++)
    {
        cout << temp[i] << ", ";
    }
    cout << temp[i] <<"]";
    return 0;
}