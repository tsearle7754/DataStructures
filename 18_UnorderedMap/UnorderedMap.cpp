#include <iostream>
#include <unordered_map>    // built-in hash table
#include <vector>
#include <string>


class HashExamples {
public:
    template <typename T>
    static void countFrequency(const std::vector<T>& v) {
        std::unordered_map<T, int> freq;
        
        for (const T& i : v) {
            freq[i]++;
        }

        for (const auto& f : freq) {
            std::cout << f.first << " : " << f.second << std::endl;
        }
    }

    template <typename T>
    static bool hasDuplicates(const std::vector<T>& v) {
        std::unordered_map<T, bool> seen;   // boolean map for seen
        for (const T& i : v) {  // iterate through
            if (seen[i]) {      // if seen already, return true, otherwise mark as true
                return true;
            }
            seen[i] = true;
        }
        return false;       // return false if no duplicates
    }

    static char firstNonRepeatingChar(const std::string& s) {
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }
        return '\0';    // no non-repeating character
    }

    static void groupStrings(const std::vector<std::string>& strings) {
        /*
        <first_letter> : strings        each character type is a vector of strings
        */
       std::unordered_map<char, std::vector<std::string>> groups;
        for (const std::string str : strings) {
            if (!str.empty()) {
                groups[str[0]].push_back(str);
            }
        }

       for(const auto& group : groups) {
            std::cout << group.first << " : ";
            for (const std::string& s : group.second) {
                std::cout << s << " ";
            }
            std::cout << std::endl;
       }
    }

private:


};


int main() {
    std::unordered_map<std::string, int> grades;

    // insert
    grades["Michael"] = 90;
    grades["Anna"] = 95;
    grades["John"] = 76;

    // iterate through the tables
    for (const auto& grade : grades) {      // because it's unordered, will print in random order
        std::cout << grade.first << " : " << grade.second << std::endl;
    }

    // search (find method)
    auto it = grades.find("John");

    if (it == grades.end()) {
        std::cout << "Not found\n";
    }
    else {
        std::cout << "Found\n";
        std::cout << it->first << " : " << it->second << std::endl;     // iterator is kind of like a pointer, use arrow to call
    }

    std::cout << "Count Frequency...\n";
    std::vector<int> v {1, 2, 3, 4, 1, 2, 2, 2, 5, 5, 12};
    HashExamples::countFrequency(v);

    std::cout << "Check Duplicates...\n";
    std::vector<std::string> x {"hello", "apple", "banana", "hey", "ban", "app"};
    HashExamples::countFrequency(x);

    return 0;
}