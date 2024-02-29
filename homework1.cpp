#include<iostream>
#include<vector>


bool identical(std::vector<int> a) {
    int firstElement = a[0];
    for(auto i : a) {
        if(a.at(i) != firstElement)
            return false;
    }
    return true;
}

template<typename T>
void printVector(std::vector<T> a) {
    for(int i = 0; i < a.size(); ++i) {
        std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;
}

bool identicalString(std::string s1, std::string s2) {
        if(s1.length() != s2.length()) return false;
        
        for(int i = 0; i < s1.length(); ++i) {
                if(s1.at(i) != s2.at(i))
                    return false;
        }

        return true;
}

int main(int argc, char const *argv[])
{
    std::string string1 = "whatsup?";
    std::string string2 = "whatnot";
    std::string string3 = "whatsup?";

    bool s1s2 = identicalString(string1, string3);

    if(s1s2) { std::cout << "True" << std::endl;}
    else {std::cout << "False" << std::endl;}

    return 0;
}
