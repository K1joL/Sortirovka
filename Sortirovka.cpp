#include <iostream>
#include <ctime>
using namespace std;

int *Fill(int n, int randMin, int randMax);
void Out(int *mas, int n);
int *CocktailSort(int *mas, int n);
int *BubbleSort(int *mas, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	uint16_t N;
	int16_t randMin, randMax;

	cout << "Введите количество элементов в массиве: \n";
	cin >> N;
	int *arr;

	cout << "Введите минимальное случайное число: \n";
	cin >> randMin;
	cout << "Введите максимальное случайное число: \n";
	cin >> randMax;

	arr = Fill(N, randMin, randMax);
	cout << "Массив: \n";
	Out(arr, N);
	
	cout << "\nВыберите сортировку (1 - пузырек, 2 - шейкер): ";
	int Sort;
	cin >> Sort;
	if (Sort == 1)
		BubbleSort(arr, N);
	if (Sort == 2)
		CocktailSort(arr, N);

	cout << "\nОтсортированный массив: \n";
	Out(arr, N);

	delete []arr;
	return 32;
}

int *Fill(int n, int randMin, int randMax)
{
	int *mas;
	mas = new int[n];
	srand(time(0));
	for (int c = 0; c < n; c++)
		mas[c] = (randMin + rand() % (randMax - randMin + 1));
	return mas;
}
void Out(int *mas, int n)
{
	for (int c = 0; c < n; c++)
		cout << '[' << mas[c] << ']' << ' ';
}

int *CocktailSort(int *mas, int n)
{
	int left = 0, right = n - 1;
	do
	{
		for (int i = left; i < right; i++)
		{
			if (mas[i] > mas[i+1])
			{
				int tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (mas[i] < mas[i - 1])
			{
				int tmp = mas[i];
				mas[i] = mas[i - 1];
				mas[i - 1] = tmp;
			}
		}
		left++;
	}while (left < right);
	
	return mas;
}
int *BubbleSort(int *mas, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int f = 0;
		for (int k = 0; k <= n - 1 - i; k++)
		{
			if (mas[k] > mas[k + 1])
			{
				int tmp = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = tmp;
				f++;
			}
		}
		if (f == 0) break;
	}
	return mas;
}