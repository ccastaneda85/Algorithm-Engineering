#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
{
  return lhs.second > rhs.second;
};


void topKMostFrequentElements(int List[], int size, int k) {
    std::unordered_map<int, int> counter; // initializing unordered_map to assist in storing keys and counting the number of occurences of each key
        for (int i = 0; i < size; i++) {
            counter[List[i]] += 1; // once accessing a duplicated element the associated value will increment by 1, thus counting the number of each element's occurence
        }

    std::priority_queue < std::pair<int, int>, std::vector< std::pair< int, int> >,  decltype(cmp)> myQueue(cmp);

    for(auto i = counter.begin(); i != counter.end(); i++) {
        std::cout << "Key: " << i->first << " Value: " << i->second << std::endl;
        myQueue.push({i->first, i->second});
        if(myQueue.size() > k) {
            myQueue.pop();
        }
    }

    std::cout << "Queue Size: " << myQueue.size() << std::endl;

       for(int i = 0; i <= myQueue.size(); i++) {
        std:: cout << "Top: Key: " << myQueue.top().first << " Value: " << myQueue.top().second << std::endl;
        myQueue.pop();
    }

}

int main(int argc, char const *argv[])
{
   
    int example1[] = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 4, 4, 1, -1};

    topKMostFrequentElements(example1, 14, 2);
 

    

    
    





    return 0;
}
