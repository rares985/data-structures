#include <vector>
class Sorter
{
public:
    template <typename T>
    static void Swap(T *x, T *y)
    {
        x = x ^ y;
        y = y ^ x;
        x = x ^ y;
    }

    template <typename T>
    static void Swap(T &x, T &y)
    {
        x = x ^ y;
        y = y ^ x;
        x = x ^ y;
    }

    template <typename T>
    static void BubbleSort(T &vec)
    {
        for (int i = 0; i < vec.Size() - 1; i++)
        {
            for (int j = i + 1; j < vec.Size(); j++)
            {
                if (vec[i] > vec[j])
                {
                    Swap(vec[i], vec[j]);
                }
            }
        }
    }

    template <typename T>
    static void InsertionSort(T &vec)
    {
        for (int i = 0; i < vec.Size(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (vec[j - 1] > vec[j])
                {
                    Swap(vec[j - 1], vec[j]);
                }
            }
        }
    }

    template <typename T>
    static void SelectionSort(T &vec)
    {
        int min = 0;
        int pos_min = 0;

        for (int i = 0; i < vec.Size(); i++)
        {
            min = vec[i];
            pos_min = i;

            for (int j = i; j < vec.Size(); j++)
            {
                if (vec[j] < min)
                {
                    pos_min = j;
                    min = vec[j];
                }
            }

            Swap(vec[i], vec[pos_min]);
        }
    }

    template <typename T>
    static void QuickSort(T &vec)
    {
        QuickSort(vec, 0, vec.Size() - 1);
    }

    template <typename T>
    static void Mergesort(T &vec)
    {
        MergeSort(vec, 0, vec.Size() - 1);
    }

private:
    template <typename T>
    static int Partition(T &vec, int low, int high)
    {
        int i = low - 1;
        int j = high + 1;
        T pivot = vec[(high + low) / 2];

        while (true)
        {
            do
            {
                i += 1;
            } while (vec[i] < pivot);

            do
            {
                j -= 1;
            } while (vec[j] > pivot);

            if (i >= j)
            {
                return j;
            }
            Swap(vec[i], vec[j]);
        }
    }

    template <typename T>
    static void QuickSort(T &vec, int low, int high)
    {
        if (low < high)
        {
            int pivot_idx = Partition(vec, low, high);
            QuickSort(vec, low, pivot_idx);
            QuickSort(vec, pivot_idx + 1, high);
        }
    }

    template <typename T>
    static void MergeSort(T &vec, int left, int right)
    {
        int middle = left + (right - left) / 2;
        if (right > left)
        {
            MergeSort(vec, left, middle);
            MergeSort(vec, middle + 1, right);
            Merge(vec, left, middle, right);
        }
    }

    template <typename T>
    static void merge(std::vector<int> &vec, int left, int middle, int right)
    {
        std::vector<int> leftvec(vec.begin() + left, vec.begin() + middle + 1);
        std::vector<int> rightvec(vec.begin() + middle + 1, vec.begin() + right + 1);

        int leftIdx = 0;
        int rightIdx = 0;
        int originalIdx = left;

        while (true)
        {
            if (leftIdx >= leftvec.size() || rightIdx >= rightvec.size())
            {
                break;
            }

            if (leftvec[leftIdx] <= rightvec[rightIdx])
            {
                vec[originalIdx] = leftvec[leftIdx];
                leftIdx += 1;
            }
            else
            {
                vec[originalIdx] = rightvec[rightIdx];
                rightIdx += 1;
            }

            originalIdx += 1;
        }

        /* What's remained of left subset, if any */
        if (leftIdx < leftvec.size())
        {
            std::copy(leftvec.begin() + leftIdx, leftvec.end(), vec.begin() + originalIdx);
        }

        /* What's remained of right subset, if any */
        if (rightIdx < rightvec.size())
        {
            std::copy(rightvec.begin() + rightIdx, rightvec.end(), vec.begin() + originalIdx);
        }
    }
};