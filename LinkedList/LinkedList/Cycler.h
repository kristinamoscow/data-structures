
#ifndef CYCLER_H
#define CYCLER_H

#include "LinkedList.h"

namespace Cycler {

	template<typename T>
	void addCycle(LinkedList<T>& list, unsigned int dist) {
		node<T>* lastNode = list.getTail();
		node<T>* cycleStart = list.getHead();

		if (cycleStart == nullptr || dist > list.getLength()) {
			return;
		}

		int cycleStartIndex =  list.getLength() - dist;
		while (cycleStartIndex) {
			cycleStart = cycleStart->next;
			cycleStartIndex--;
		}
		lastNode->next = cycleStart;
	}

	template<typename T>
	node<T>* findCycle(LinkedList<T>& list) {
		node<T>* cycleStart = list.getHead();
		node<T>* slow = cycleStart;
		node<T>* fast = cycleStart;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				while (cycleStart != slow) {
					cycleStart = cycleStart->next;
					slow = slow->next;
				}
				return cycleStart;
			}
		}
		return nullptr;
	}

	template<typename T>
	void removeCycle(LinkedList<T>& list) {
		node<T>* cycleStart = findCycle(list);
		node<T>* lastNode = list.getTail();

		if (lastNode == nullptr || cycleStart == nullptr) {
			return;
		}

		lastNode->next = nullptr;
		while (lastNode != cycleStart) {
			list.popBack();
			lastNode = list.getTail();
		}
		list.popBack();
	}

	template<typename T>
	bool isCycled(LinkedList<T>& list) {
		node<T> *slow = list.getHead();
		node<T>* fast = slow;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				return true;
			}
		}
		return false;
	}

}

#endif