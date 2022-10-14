#include <iostream>
using namespace std;

class Student
{
public:
    int roll, marks;

    char name[50];
};

int main()
{

    Student temp;
    int m, i, j;
    cout << "enter no.of students";
    cin >> m;
    Student arr[m];
    for (i = 0; i < m; i++)
    {
        cin >> arr[i].name;
        cin >> arr[i].roll;
        cin >> arr[i].marks;
    }
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (arr[j].roll > arr[j + 1].roll)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < m; i++)
    {

        cout << arr[i].name << "\t" << arr[i].roll << "\t" << arr[i].marks << "\n";
    }
}