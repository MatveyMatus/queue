#include <iostream>
using namespace std;

class queue {
private:
	int maxSize,
		front,
		rear,
		nItems;
	int* queArray;

public:
	queue(int SIZE) {
		maxSize = SIZE;
		queArray = new int[maxSize];
		front = 0;
		rear = -1;
		nItems = 0;
	}

	~queue() {
		delete[]queArray;
	}

	void insert(int i);
	void result();

	int remove();

	int peekFront() {
		return queArray[front];
	}

	int SIZE() {
		return nItems;
	}

	bool isEmpty() {
		return(nItems == 0);
	}

	bool isFull() {
		return(nItems == maxSize);
	}

};

void queue::insert(int i) {
	if (rear == maxSize - 1) {
		rear = -1;
		nItems = 0;
	}
	queArray[++rear] = i;
	nItems++;
}

int queue::remove() {
	int temp = queArray[front++];
	if (front == maxSize) {
		front = 0;
	}
	nItems--;
	return temp;
}

void queue::result() {
	if (nItems == 0) {
		cout << "Очередь пуста" << endl;
		return;
	}
	if (front > rear) {
		for (int q = front; q != rear; ++q) {
			cout << queArray[q] << endl;
		}
	}
	else if (front < rear) {
		for (int p = front; p <= rear; ++p) {
			cout << queArray[p] << endl;
		}
	}
	else{
		cout << "1: " << queArray[front];
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	int option = 0,
		Items;
	cout << "Введите размер очереди: ";
	cin >> Items;
	queue Queue(option);
	cout << "1 - вставить элемент в очередь\n2 - удалить элемент из очереди\n3 - вывести очередь на консоль\n4 - выход" << endl;
	while (option != 4) {
		cin >> option;
		if (option == 1) {
			cin >> Items;
			Queue.insert(Items);
		}
		else if (option == 2) {
			Queue.remove();
		}
		else if (option == 3) {
			Queue.result();
		}
	}
}