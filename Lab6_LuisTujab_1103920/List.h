#pragma once
#include"Comparator.h"

template <typename T>
class List
{
	struct Node
	{
		T* item; 
		Node* next; 
		Node(T* item)
		{
			this->item = item;
			this->next = nullptr; 
		}
	};

	Node* head;
	Node* tail; 

	int size = 0; 

public:
	int getZise()
	{
		return this->size; 
	}
	bool isEmpty()
	{
		return this->size == 0; 
	}

	void add(T* item)
	{
		Node* node = new Node(item); 
		if (this->isEmpty())
		{
			this->head = this->tail = node; 
		}
		else
		{
			this->tail->next = node;
			this->tail = this->tail->next;
		}
		this->size++; 
	}

	T* get(int index)
	{
		if (index >= this->size || index < 0)
		{
			return nullptr; 
		}
		Node* iterator = this->head; 

		int i = 0; 
		while (i<index)
		{
			iterator = iterator->next;
			i++; 
		}
		return iterator->item; 
	}

	T* remove(int index)
	{
		if (index >= this->size|| index <0)
		{
			return nullptr; 
		}
		Node** iterator = &this->head; 
		Node* previous = nullptr;
		int i = 0; 
		while (i< index)
		{
			iterator = &(*iterator)->next; 
			i++; 
		}
		T* item = (*iterator)->item; 

		*iterator = (*iterator)->next; 
		this->size--;
		if (this->size == index)
		{
			this->tail = previous; 
		}
		return item; 
	}

	List<T>* SelectionSort(Comparator<T>* comparator)
	{
		Node** i = &(this->head); 

		while (*i !=nullptr)
		{
			Node** j = &(*i)->next; 

			while (*j != nullptr)
			{
				T** itemA = &(*i)->item; 
				T** itemB = &(*j)->item; 

				if (comparator->compare(**itemA, **itemB)<0)
				{
					T* aux = *itemA; 
					*itemA = *itemB; 
					*itemB = aux; 
				}
				j = &(*j)->next; 

			}
			i = &(*i)->next; 
		}

		return this;
	}

	/*List<T*>QuickSort(Comparator<T>* comparator)
	{
		int  central; 
		int pivote;

		central = (this->head + this->tail) / 2; 
		pivote = central; 

		Node** i = &(this->head);
		while (*i != nullptr)
		{
			Node** j = &(this->tail);

			while (*j != nullptr)
			{
				T** itemA = &(*i)->item;
				T** itemB = &(*j)->item;

				do
				{

				} while (); 

			}
		} */

	/*}*/
};

