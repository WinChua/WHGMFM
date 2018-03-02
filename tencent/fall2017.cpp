#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
/*
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy
其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
*/

/*
import sys
input_num = sys.stdin.readline().strip()

base = ord('a')

ids = map(lambda x: ord(x) - base, input_num)
index = 0
for i, d in enumerate(ids):
    index += d * (sum(25**(j) for j in range(1, 4 - i)) + 1)

print index + len(input_num) - 1
*/

void calculate_index(std::string & data)
{
    std::string line;
    std::cin >> line;
    int num[] = {16276, 651, 26, 1};
    // int num[] = {1+25*(1+25*(25+1)), 1+25*(25+1), 25+1, 1};
    int index = 0;
    for(int i = 0; i < line.size(); ++i)
    {
        int t = line[i] - 'a';
        index += 1;
        index += t * num[i];

    }
    std::cout << index-1 << std::endl;
}
/*给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）*/
bool is_judge(int n)
{
    for(int i=2; i < n/2+1; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}
int sum_prime() {
    int num;
    std::cin >> num;
    std::vector<int> prime_nums;
    for(int i=2; i<num; ++i) {
        if(is_judge(i)) prime_nums.push_back(i);
    }
    std::vector<int>::iterator ibegin=prime_nums.begin(), iend=prime_nums.end()-1;
    int count = 0;
    while(ibegin < iend) {
        while(ibegin < iend && *ibegin + *iend < num) {++ibegin;}
        if(*ibegin + *iend == num) {count += 1; ++ibegin;}
        if(ibegin == iend)
        {
            break;
        }
        while(ibegin < iend && *ibegin + *iend > num) {--iend;}
        if(*ibegin + *iend == num) {count += 1; --iend;}
    }
    std::cout << count << std::endl;
    return 0;
}
int sum_prime2() {
    int num;
    std::cin >> num;
    std::vector<int> prime_nums;
    for(int i=2; i<num; ++i) {
        if(is_judge(i)) prime_nums.push_back(i);
    }
    std::vector<int>::iterator ibegin=prime_nums.begin(), iend=prime_nums.end()-1;
    int count = 0;
    while(ibegin <= iend) {
        int value = *ibegin + *iend;
        if(value <= num) {
            if(value == num) count += 1;
            ++ibegin;
        }
        else --iend;
    }
    std::cout << count << std::endl;
    return 0;
}


/*
游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。
请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。
输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。
输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
*/

unsigned int record[32];
int game_task() {
    unsigned int ID;
    std::cin >> ID;
    if(ID < 1 || ID > 1024) {
        std::cout << -1 << std::endl;
        return 0;
    }
    record[(ID-1) / 32] |= 1 << (ID-1)%32;
    std::cin >> ID;
    if(ID < 1 || ID > 1024) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ((record[(ID-1)/32] >> (ID-1)%32) & 1) << std::endl;
    return 0;
}

