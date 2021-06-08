#include <iostream>
#include <string.h>

using namespace std;

class QueuePriority
{
	
	int* Wait; // массив значений очереди
	
	int* Pri; // массив приоритетов
	
	int MaxQueueLength; // Максимальный размер очереди
	
	int QueueLength; // Текущий размер очереди

public:
	
	QueuePriority(int m);

	
	~QueuePriority();

	
	void Add(int c, int p);

	
	int Extract(); // извлечение элемента с максимальным приоритетом

	
	
	bool IsEmpty(); // проверка очереди на пустоту

	
	bool IsFull(); // Проверка на переполнение очереди

	
	int GetCount(); // Количество элементов в очереди

	
	void Show(); // вывод очереди в консоль
};

void QueuePriority::Show() { // вывод очереди в консоль

	cout << "\n-------------------------------------\n";
	
	for (int i = 0; i < QueueLength; i++) {
		cout << "элемент "<< Wait[i] << " - " << " приоритет "<< Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	
	MaxQueueLength = m; //получаем размер
	
	Wait = new int[MaxQueueLength]; //создаем массив значений очереди
	Pri = new int[MaxQueueLength];  //создаем массив приоритетов
	
	QueueLength = 0; // Изначально очередь пуста
}



bool QueuePriority::IsEmpty() // проверка на пустоту
{
	
	return QueueLength == 0;
}

bool QueuePriority::IsFull() // проверка на максимальное заполнение
{
	
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount() // количесвто внесенных элементов
{
	
	return QueueLength;
}

void QueuePriority::Add(int c, int p) //
{
	
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract() // вывод элемента с максимальным приоритетом и его удаление их очереди (сдвиг очереди)
{
	
	if (!IsEmpty()) {


		
		int max_pri = Pri[0];
		
		int pos_max_pri = 0;

		
		for (int i = 1; i < QueueLength; i++) //определяем максимальный приоритет
			
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		
		for (int i = pos_max_pri; i < QueueLength - 1; i++) { 
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		
		QueueLength--;
			
		return temp1; // возврат элемента с максимальным приоритетом

	}
	else return -1;
}

void main()
{
	setlocale(LC_ALL, "Russian");

	QueuePriority QUP(5);

	QUP.Add(15, 1);
	QUP.Add(17, 2);
	QUP.Add(19, 0);
	QUP.Add(215, 10);
	QUP.Add(14, 9);

	cout << "выводим все элементы очереди и их приоритет"  << endl;

    QUP.Show();

	cout << "выводим элемент очереди с максимальным приоритетом и удаляем его:"  << endl << endl;


	cout << QUP.Extract();

	cout << endl << endl;

	cout << "выводим все элементы очереди и их приоритет"  << endl;
	
	QUP.Show();

	cout << "Hello world";
}