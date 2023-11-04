

#include <iostream>
using namespace std;
class queue {
private:
	int maxSize;
	int* queArray;
	int front;
	int rear;
	int nItems;
public:
	queue(int num) {
		maxSize = num;
		queArray = new int[maxSize];
		front = 0;
		rear = -1;
		nItems = 0;
	}
	void insert(int j) {
		if (rear == maxSize - 1) {
			rear = -1;
			nItems = 0;
		}
		queArray[++rear] = j;
		nItems++;
	}
	int remove() {
		int temp = queArray[front++];
		if (front == maxSize) 
			front = 0;
			nItems--;
			return temp;
		
	}
	int peekFront() {
		return queArray[front];
	}
	
	int size() {
		return nItems;
	}
	void show() {
		if (nItems == 0) {
			cout << "Queue is empty\n";
			return;
		}
		if (front > rear) {
			int j = front;
			while (j != maxSize) {
				cout << queArray[j] << endl;
				j++;
			}
			j = 0;
			while (j <= rear) {
				cout << queArray[j] << endl;
				j++;
			}
		}
		else if (front < rear) {
			for (int i = front; i <= rear; i++) {
				cout << i + 1 << ": " << queArray[i] << endl;
			}
		}
		else if (nItems == 1) {
			cout << "1: " << queArray[front];
			cout << endl;
			return;
		}
	}
	void SetElement(int index, int data) {
		
			
				queArray[index-1] = data;
		
		
	}
	 void GetElement(int index) {
		 cout << queArray[index - 1] << endl;
	}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		int choice = 1;
		int number;
		cin >> number;
		queue Thequeue(number);
		cout << "1 - Вставить элемент\n2 -Удалить элемент\n3 -Вывести очередь\n4-Выход\n5-Вставка\n6-Получение элемента\n";
		while (choice != 4) {
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Элемент:";
				cin >> number;
				Thequeue.insert(number);
				break;
			case 2:
				Thequeue.remove();
				break;
			case 3:
				Thequeue.show();
				break;
			case 5:
				int index, data;
				cout << "Введите индекс" << endl;
				cin >> index;
				cout << "Введите число" << endl;
				cin >> data;
				Thequeue.SetElement(index, data);
				break;
			case 6:
				cout << "Введите индекс" << endl;
				cin >> index;

				Thequeue.GetElement(index);
				break;
			}

		}
		
		return 0;
		

	}

