/*
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？
*/
/*
input data format:
asdDsSdHmm
*/
#include<iostream>
#include<string>
#include<vector>
#include "../Include/tencent/2017.hpp"
void one() {
    std::string line;
    while(std::cin >> line) {
        std::vector<char> uppervec;
        for(auto c : line) {
            if(c < 'a') {
                uppervec.push_back(c);
            }
            else
                std::cout << c;
        }
        for(auto c : uppervec) {
            std::cout << c;
        }
        std::cout << std::endl;

    }
}
/*小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？*/

#include<map>
#include<algorithm>
#include<set>
#include<fstream>
/*input data sample:
6
12 32 43 2 4 3
*/
void two() {
    int N = 0;
    std::cin >> N;
    if(N == 2) {
        std::cout << "1 1" <<std::endl;
    }
    std::vector<int> data;
    int d;
    while(std::cin >> d) data.push_back(d);
    std::map<int, int> box;
    bool flag = false;
    for(auto d: data) {
        if(box.find(d) == box.end()) {
            box.insert({d, 1});
        }
        else{
            flag = true;
            box[d] += 1;
        }
    }
    data.clear();
    for(auto p: box) data.push_back(p.first);
    std::sort(data.begin(), data.end());
    if(flag) {
        int sum = 0;
        for(auto p : box) {
            if(p.second != 1) {
                sum += p.second * (p.second - 1) / 2;
            }
        }
        std::cout << sum << " ";
    }
    else {
        int min_num = data[1] - data[0];
        std::vector<std::pair<int, int>> min_record = {{data[0], data[1]}};
        for(int i=1; i < data.size()-1; ++i) {
            int value = data[i+1] - data[i];
            if(min_num == value) {
                min_record.push_back({data[i], data[i+1]});
            }
            if(min_num > value) {
                min_record.clear();
                min_record.push_back({data[i], data[i+1]});
                min_num = value;
            }
        }
        int sum = 0;
        for(auto p : min_record) {
            sum += box[p.first]*box[p.second];
        }
        std::cout << sum << " ";
    }

    std::cout << box[data[0]] * box[data[data.size()-1]] << std::endl;
    return;

}

/*给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。*/
const int MAX = 1000;
int MaxLen[MAX+1][MAX+1];

int maxLen(std::string &s1, std::string &s2) {
    int l1 = s1.size(), l2 = s2.size();
    for(int i=0; i<l1; ++i)
        MaxLen[i][0] = 0;
    for(int j=1; j<l2; ++j)
        MaxLen[0][j] = 0;
    for(int i = 1; i <= l1; ++i) {
        for(int j = 1; j <= l2; ++j) {
            if(s1[i-1] == s2[j-1]) MaxLen[i][j] = MaxLen[i-1][j-1]+1;
            else MaxLen[i][j] = std::max(MaxLen[i-1][j], MaxLen[i][j-1]);
        }
    }
    return MaxLen[l1][l2];
}


void third() {
    std::string line;
    std::ifstream fin("data/third.txt");
    while(fin >> line) {
        std::string l2 = line;
        std::reverse(l2.begin(), l2.end());
        std::cout << l2.size() - maxLen(line, l2);
    }
    std::cout << std::endl;
}
void my_third() {

    std::vector<int> result;
    std::string line;
    std::ifstream fin("data/third.txt");
    while(fin >> line)
    {
        std::string reverse_line(line.size(), '0');
        std::reverse_copy(line.begin(), line.end(), reverse_line.begin());
        std::map<std::pair<int,int>, int> state;
        for(int i=0; i<line.size(); ++i) {
            state[{i,0}] = 0;
        }
        for(int j=0; j<line.size(); ++j) {
            state[{0, j}] = 0;
        }
        for(int i=1; i<line.size()+1; ++i) {
            for(int j=1; j<line.size()+1; ++j) {
                if(line[i-1] == reverse_line[j-1]) {
                    state[{i,j}] = state[{i-1,j-1}] + 1;
                }
                else {
                     state[{i,j}] = std::max( state[{i-1,j}],  state[{i,j-1}]);
                }
            }
        }
        result.push_back(line.size() - state[{line.size(),line.size()}]);
        state.clear();

    }
    for(auto i : result) {
        std::cout << i << std::endl;
    }

}

