#include <iostream>
//#include <iomanip>

int main()
{
	int sequence[] = { 12, 3, 8, 10, 7, 5, 12, 8, 10 };
	const int seq_len = sizeof(sequence) / sizeof(int);

	int* sorted_sequence = new int[seq_len];

	int* sorting_plane_heads = new int[seq_len];
	int** sorting_plane = new int* [seq_len];
	int sorting_heaps_count = 0;

	for (int i = 0; i < seq_len; ++i) 
	{
		sorting_plane[i] = new int[seq_len];
		sorting_plane_heads[i] = 0;
	}

	// split the sequence into heaps
	for (int i = 0; i < seq_len; ++i) 
	{
		for (int h = 0; h < seq_len; ++h)
		{
			int cur_head = sorting_plane_heads[h];

			if (cur_head == 0 || sorting_plane[h][cur_head - 1] >= sequence[i])
			{
				if (cur_head == 0) 
				{
					++sorting_heaps_count;
				}
				sorting_plane[h][cur_head] = sequence[i];
				++sorting_plane_heads[h];
				break;
			}
		}
	}

	// for debugging

	/*for (int y = 0; y < seq_len; ++y) 
	{
		std::cout << std::setw(9) << sorting_plane_heads[y];
		for (int x = 0; x < seq_len; ++x)
		{
			std::cout << std::setw(9) << sorting_plane[y][x];
		}
		std::cout << std::endl;
	}*/
	
	// min element we can skip
	sorted_sequence[0] = sorting_plane[0][sorting_plane_heads[0] - 1];
	--sorting_plane_heads[0];

	// merge heaps
	for (int i = 1; i < seq_len; ++i) 
	{
		int min = INT32_MAX;
		int minH = 0;

		// select min top element among all heaps
		for (int h = 0; h < sorting_heaps_count; ++h) 
		{
			if (sorting_plane_heads[h] > 0 && sorting_plane[h][sorting_plane_heads[h] - 1] < min)
			{
				min = sorting_plane[h][sorting_plane_heads[h] - 1];
				minH = h;
			}
		}

		sorted_sequence[i] = min;
		--sorting_plane_heads[minH];
	}

	// out
	for (int i = 0; i < seq_len; ++i) 
	{
		std::cout << sorted_sequence[i] << std::endl;
	}

	for (int i = 0; i < seq_len; ++i) 
	{
		delete[] sorting_plane[i];
	}
	delete[] sorted_sequence;
	delete[] sorting_plane;
	delete[] sorting_plane_heads;
	return 0;
}