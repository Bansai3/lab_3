namespace algo_space
{
	template<typename T1, typename T2>
	bool all_of(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		while (start_iterator != end_iterator + 1)
		{
			if (!predicate(*start_iterator))
				return false;
			start_iterator++;
		}
		return true;
	}

	template<typename T1, typename T2>
	bool any_of(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		while (start_iterator != end_iterator + 1)
		{
			if (predicate(*start_iterator))
				return true;
			start_iterator++;
		}
		return false;
	}

	template<typename T1, typename T2>
	bool none_of(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		while (start_iterator != end_iterator + 1)
		{
			if (predicate(*start_iterator))
				return false;
			start_iterator++;
		}
		return true;
	}

	template<typename T1, typename T2>
	bool one_of(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		int count = 0;
		while (start_iterator != end_iterator + 1)
		{
			if (predicate(*start_iterator))
				count++;
			if (count > 1)
				return false;
			start_iterator++;
		}
		if (count == 1)
			return true;
		else
			return false;
	}

	template<typename T1, typename T2>
	bool is_sorted(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		while (start_iterator != end_iterator)
		{
			if (!predicate(*start_iterator, *(start_iterator + 1)))
			{
				return false;
			}
		}
		return true;
	}

	template<typename T1, typename T2>
	bool is_partitioned(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		bool appropriate = predicate(*start_iterator);
		while (start_iterator != end_iterator + 1)
		{
			if (appropriate == predicate(start_iterator))
			{
				start_iterator++;
			}
			else
			{
				appropriate = predicate(start_iterator);
				start_iterator++;
				while (start_iterator != end_iterator + 1)
				{
					if (appropriate == predicate(start_iterator))
						start_iterator++;
					else
						return false;
				}
				return true;
			}
		}
		if (appropriate == predicate(start_iterator))
			return false;
		else
			return true;
	}

	template<typename T1, typename T2>
	T1 find_not(T1 start_iterator, T1 end_iterator, T1 element)
	{
		while (start_iterator != end_iterator + 1)
		{
			if (*start_iterator == *element)
				return start_iterator;
			else
				start_iterator++;
		}
		return nullptr;
	}

	template<typename T1, typename T2>
	T1 find_backward(T1 start_iterator, T1 end_iterator, T1 element)
	{
		while (end_iterator != start_iterator - 1)
		{
			if (*end_iterator == *element)
				return end_iterator;
			else
				end_iterator--;
		}
		return nullptr;
	}

	template<typename T1, typename T2>
	bool is_palindrome(T1 start_iterator, T1 end_iterator, T2 predicate)
	{
		T1 it_for_end = end_iterator;
		for (T1 it = start_iterator; it < start_iterator + (end_iterator - start_iterator) / 2; it++)
		{
			if (!predicate(it, it_for_end--))
				return false;
		}
		return true;
	}
}