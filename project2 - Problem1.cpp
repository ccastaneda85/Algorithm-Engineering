/*
Abstract:
Develop a pseudocode for an algorithm; analyze your pseudocode mathematically; implement the code
for the algorithm of your choice; test your implementation; and describe your results.

Problem 1: Top k Most frequent elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the
answer in any order.

Example 1:
Input: nums = [1, 1, 1, 2, 2, 3], k = 2
Output: [1, 2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
• 1 <= nums.length <= 105
• -104 <= nums[i] <= 104
• k is in the range [1, the number of unique elements in the array].
• It is guaranteed that the answer is unique.

Your code should work for any input array. Try to solve it using priority queue as it gives better time
complexity in problems like this. But feel free to use any approach which is easy for you.

*/

/*
Pseudocode:

    TopKMostFrequentElements(List, int k) -> returns list of top k elements
        count the number of occurences in each element -> O(n)
            store in a container of key, value pair // for example: [1, 3], [2,2], [3, 1] -> O(n)
        sort the container in descending order of values -> O(nlogn)
            return the keys of the first k elements and store into a new list -> O(k)
            return the list to the caller. -> + 1


    Total Time Complexity:
        T(n)    = n + n + nlogn + k + 1
                = 2n + nlogn + k + 1
                = nlogn + k
        T(n)    = O(nlogn + k)
*/

#include <iostream>
#include <vector>
#include <algorithm>

/* Created comparator function to assist in sort of the key value pairs */
bool greater (std::pair<int,int> kv1, std::pair<int, int> kv2 ) {return (kv1.second > kv2.second);}

/* Main function to accept Array, array size, and K for "K top elements"*/
void topKMostFrequentElements(int List[], int size, int k) {
    std::unordered_map<int, int> counter; // initializing unordered_map to assist in storing keys and counting the number of occurences of each key
        for (int i = 0; i < size; i++) {
            counter[List[i]] += 1; // once accessing a duplicated element the associated value will increment by 1, thus counting the number of each element's occurence
        }

    std::vector<std::pair<int, int>> sortedCounter(counter.begin(), counter.end()); // placing the key value pairs in a sortable container
    std::sort(sortedCounter.begin(), sortedCounter.end(), greater); // sorting the container in descending order by the value of the key value pair


    /* Begin output of Top K most frequent */
    std::cout << "["; 

    for (int i = 0; i < k; i++) {
        if(i != k-1)
            std::cout << sortedCounter[i].first << ", ";
        else 
            std::cout << sortedCounter[i].first;
    }

    std::cout << "]";

}

int main(int argc, char const *argv[])
{
    int example1[] = {1, 1, 1, 2, 2, 3 };
    int example2[] = {1};
    int testArray2[] = {-1, -2, 4, 4, 4, -1, -1, -1};
    
    std::cout << std::endl;
    std::cout << "Example 1: {1, 1, 1, 2, 2, 3 }";
    std::cout << std::endl;
    std::cout << "Top K elements: ";
    topKMostFrequentElements(example1, 6, 2);
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Example 2: {1}";
    std::cout << std::endl;
    std::cout << "Top K elements: ";
    topKMostFrequentElements(example2, 1, 1);
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Example 3: {-1, -2, 4, 4, 4, -1, -1, -1} ";
    std::cout << std::endl;
    std::cout << "Top K elements: ";
    topKMostFrequentElements(testArray2, 8, 3);
    std::cout << std::endl;
    std::cout << std::endl;
   

    
    return 0;
}
