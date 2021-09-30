#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n; // ��������� ����� n
    cout << "Enter n: "; // ������� ����� � �������
    cin >> n; // ��������� �������� �����

    double x; // ��������� ����� x
    cout << "Enter x (0 < x < 1): "; // ������� ����� � �������
    cin >> x; // ��������� �������� �����

    int counter = 1; // ��������� ��������
    double result = 1; // ��������� ����� ��� ���������� (1, ���� �� ��� ������ � ����)

    // ���� ���� ��������� �� ���� �������� ������ ��� ������� n
    while (counter <= n) {
        // ���������� �������� �� ����������
        result += pow(-1, counter) * ((pow(x, 2 * counter) + 1) / (pow(2, counter) + 1));
        counter++; // ������� ��������
    }

    // �������� ��������� � ������� � ������� �� 5-� ����� ���� ����
    printf("The result is %.5g", result);
}
