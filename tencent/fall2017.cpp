#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
/*
�ٶ�һ�ֱ���ı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰѸñ��밴�ֵ�������
�γ�һ���������£� a, aa, aaa, aaaa, aaab, aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy
����a��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ� ��дһ������������������һ�����룬�����������Ӧ��Index.
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
/*����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
�磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10,�ֱ�Ϊ(5,5),(3,7)��*/
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
��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ���������һ����1024��������ID��Χ[1,1024]��
����32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ���ʼ״̬����δ��ɡ�
����������������������ID����Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ�
���һ������������ڶ���ID�������Ѿ�������1�����δ������0�������һ��ڶ���ID����[1,1024]��Χ�������-1��
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

