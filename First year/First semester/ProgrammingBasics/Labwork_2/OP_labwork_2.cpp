#include <iostream>
using namespace std;
int main()
{
    float x; // ������ ����
    float y; // ���������
    cout << "Enter x: "; // �������� ����� � �������
    cin >> x; // �������� x
    /*������ �������� y � ��������� �� �������� x
    * ���� x ����� 0, �� y = -x
    * ������ (���� x ����� ��� ������� 0), �� y = x^2*/
    (x < 0) ? y = -x : y = x * x; 
    printf("y is %g", y); // �������� �������� y � �������
}