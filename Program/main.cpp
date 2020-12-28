// Lab_12_3_2
#include <iostream>
using namespace std;

struct S {
	S* next = nullptr;
	S* parent = nullptr;
	int num;
};

void list_factory(const int& count, S* next, S*&end, int i = 0) {
	cout << "Input " << i << " num: "; cin >> next->num; \
		i++;
	if (i < count)
	{
		next->next = new S();
		next->next->parent = next;
		end = next->next;
		list_factory(count, next->next, end, i);
	}
}

void list_draw(const S* list) {
	cout << list->num << endl;
	if (list->next != nullptr)
		list_draw(list->next);
}

void list_plus(S* cur, const int &count) {
	cur->num+= count;
	if (cur->next != nullptr)
		list_plus(cur->next, count);
}

void delete_list(S*& list, S *&end) {
	if (list->next)
		delete_list(list->next, end);
	else end = nullptr;
	delete list;
	list = nullptr;
}


void main() {
	int size;
	cout << "Input list size: "; cin >> size;
	S* start = new S(), * end = start;
	int count;
	list_factory(size, start, end);
	list_draw(start);
	cout << endl;
	cout << "Input list count plus: "; cin >> count;
	list_plus(start, count);
	list_draw(start);
	cout << endl << (int)start << endl << (int)end << endl;
	delete_list(start, end);
	cout << (int)start << endl << (int)end << endl;
}