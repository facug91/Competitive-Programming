
/**
 * \brief Defines a class for a minimum/maximum queue, which allows to use a queue returning its minimum or maximum value.
 *        Ref: https://cp-algorithms.com/data_structures/stack_queue_modification.html
 *
 * \tparam ValueType Type of the elements.
 * \tparam Compare Comparator function to use (std::less by default, for a minimum queue).
 */
template<typename ValueType, typename Compare = std::less<ValueType>>
class MinMaxQueue {
private:
	Compare comp;
	std::vector<std::pair<ValueType, ValueType>> st1, st2;

public:

	void reset() {
		while (!st1.empty()) st1.pop();
		while (!st2.empty()) st2.pop();
	}

	void print() {
		std::cout << "Stack 1:";
		for (int i = 0; i < st1.size(); i++)
			std::cout << " (" << st1[i].first << ", " << st1[i].second << ")";
		std::cout << std::endl;
		std::cout << "Stack 2:";
		for (int i = 0; i < st2.size(); i++)
			std::cout << " (" << st2[i].first << ", " << st2[i].second << ")";
		std::cout << std::endl;
	}

	ValueType front() {
		if (st1.empty() || st2.empty())
			return st1.empty() ? st2.back().second : st1.back().second;
		else
			return comp(st1.back().second, st2.back().second) ? st1.back().second : st2.back().second;
	}

	void push(ValueType newElem) {
		int bestValue = (st1.empty() || comp(newElem, st1.back().second)) ? newElem : st1.back().second;
		st1.push_back({ newElem, bestValue });
	}

	void pop() {
		if (st2.empty()) {
			while (!st1.empty()) {
				int element = st1.back().first;
				st1.pop_back();
				int bestValue = (st2.empty() || comp(element, st2.back().second)) ? element : st2.back().second;
				st2.push_back({ element, bestValue });
			}
		}
		st2.pop_back();
	}
};