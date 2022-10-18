#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class PatienceSorter 
{
    std::vector<std::stack<T>> sorting_plate;

public:
    void sort(std::vector<T> &sequence);
};

int main() 
{
    std::vector<int> a = { 4, 65, 2, -31, 0, 99, 83, 782, 1 };

    auto sorter = PatienceSorter<int>();

    sorter.sort(a);

    for (const auto& item : a)
    {
        std::cout << item << " " << std::endl;
    }

    return 0;
}

template<typename T>
void PatienceSorter<T>::sort(std::vector<T>& sequence)
{
    for (const auto& item : sequence) 
    {
        sorting_plate.push_back(std::stack<T>());

        for (auto& heap : sorting_plate) 
        {
            if (heap.empty() || (!heap.empty() && heap.top() >= item))
            {
                heap.push(item);
                break;
            }
        }
    }

    for (size_t i = 0; i < sequence.size(); ++i) 
    {
        T local_min = sorting_plate[0].top();
        int32_t heap_index = -1;

        for (size_t h = 0; h < sorting_plate.size(); ++h) 
        {
            if (sorting_plate[h].empty()) 
            {
                break;
            }
            else if (heap_index == -1 || (heap_index != -1 && sorting_plate[h].top() < local_min))
            {
                local_min = sorting_plate[h].top();
                heap_index = h;
            }
        }

        sequence[i] = local_min;
        sorting_plate[heap_index].pop();
        
        if (sorting_plate[heap_index].empty()) 
        {
            sorting_plate.erase(sorting_plate.begin() + heap_index);
        }
    }
}
