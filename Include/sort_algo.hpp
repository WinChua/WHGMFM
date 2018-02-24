#ifndef SORT_ALGO_H
#define SORT_ALGO_H
#include "show_array.hpp"
using namespace std;
void swap_data(int * a, int * b) {
    if(a == b) {return;}
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return;
}
void buble_sort(int * data, int size) {
    for(int i=size-1; i > 0; --i) {
        for(int j=0; j < i; ++j) {
            if(data[j] > data[j+1]) {swap_data(data+j, data+j+1);}
        }
    }
    return;
}

void buble_sort_while(int * data, int size) {
    for(int i=size-1; i > 0; --i) {
        int j = i;
        do {
            if(data[j] < data[j-1]) {swap_data(data+j, data+j-1);}
        } while(j-- > 0);
    }
    return;
}

void select_sort(int * data, int size) {
    for(int *s = data; s < data + size - 1; ++s) {
        int *min = s;
        for(int *e=s+1; e < data + size; ++e) {
            if(*min > *e) {min = e;}
        }
        swap_data(min, s);
    }
    return;
}

int * quick_one(int * s, int * e) {
    while(s < e) {
        while(s < e && *s <= *e) --e;
        swap_data(s, e);
        while(s < e && *s <= *e) ++s;
        swap_data(s, e);
    }
    return s;
}

void quick_sort(int * data, int size) {
    if(size > 1) {
        int *start = data, *end = data+size-1;
        int *mid = quick_one(start, end);
        quick_sort(start, mid-start);
        quick_sort(mid+1, end-mid);
    }

}

void insert_sort(int *data, int size) {
    for(int *i = data+1; i < data+size; ++i) {
        int tmp = *i;
        int *j=i;
        for(; j > data; --j) {
            if(tmp < *(j-1)) {*j = *(j-1);}
            else break;
        }
        *j = tmp;
    }
}

void heap_adjust(int *data, int target, int size) {
    // ���������Ϊһ���󶥶ѣ�
    // ���㵱ǰ�������Ľڵ�������ӽڵ�������
    int lch=2*(target+1)-1, rch=lch+1;
    if(lch >= size) return;  // �����ӽڵ㶼�ǿգ� ���������
    else {
        if(rch >= size) {    // ���ӽڵ�Ϊ��
            if(data[lch] > data[target]) {   // ����ӽڵ� ���� ��ǰ�ڵ㣬 ���������ڵ��ֵ�����������ӽڵ�
                swap_data(data+lch, data+target);
                heap_adjust(data, lch, size);
            }
        }
        else {  // �����ӽڵ㶼�ǿ�
            int max_index = data[lch] > data[rch] ? lch : rch;  // �ҵ� �����ӽڵ��еĴ���
            if(data[max_index] > data[target]) {
                swap_data(data+max_index, data+target);
                heap_adjust(data, max_index, size);
            }
        }
    }
    return;
}

void build_heap(int * data, int size) {
    //�ѵ�ǰһ��Ľڵ�����ӽڵ�, ���������ӽڵ�Ľڵ㣬ʹ���������γ�һ����ѣ�
    for(int i = size / 2; i >=0; --i) {
        heap_adjust(data, i, size);
    }
    return;
}

void heap_sort(int *data, int size) {
    // ������
    build_heap(data, size);
    // �γɴ��֮�� ���Ѷ������һ��λ�ý��н��������µ�������ѣ�
    while(--size > 0){
        swap_data(data, data+size);
        heap_adjust(data, 0, size);
    }
    return;
}


typedef void sort_algo(int *, int);


void example_sort_algo(sort_algo * myalgo, int * data, int size) {
    int * check_data = new int[size];
    copy(data, data+size, check_data);
    sort(check_data, check_data + size);
    myalgo(data, size);
    if(equal(check_data, check_data+size, data)) {
        cout << "pass" << endl;
    }
    else {
        cout << "the result should be " << endl;
        show_container(check_data, size);
        cout << "while you output the result of " << endl;
        show_container(data, size);
    }
    delete [] check_data;
}
void generate_data(int *data, int size) {
    do {
            data[--size] = rand() % 100;
    } while(size > 0);
    return;
}



void merge_sort_one(int *data1, int *data2, int *data, int size1, int size2) {
    int *end1 = data1 + size1, *end2 = data2 + size2;
    while(data1 != end1 && data2 != end2) {
        if(*data1 < *data2) *data++ = *data1++;
        else *data++ = *data2++;
    }
    while(data1 != end1) *data++ = *data1++;
    while(data2 != end2) *data++ = *data2++;
}


void merge_sort_rec(int * data, int * tar, int size) {
    if(size == 1) { *tar = *data; }
    else {
        int size1 = size / 2, size2 = size - size1;
        merge_sort_rec(data, tar, size1);
        merge_sort_rec(data + size1, tar + size1, size2);
        merge_sort_one(tar, tar+size1, data, size1, size2);
        copy(data, data+size, tar);
    }
    return;
}

void merge_sort(int *data, int size) {
    int * tmp = new int[size];
    merge_sort_rec(data, tmp, size);
    delete[] tmp;
    return;
}

void test_all_sort_algo() {
    int size = 10;
    int data[size];
    cout << "the bubble sort " << endl;
    generate_data(data, size);
    example_sort_algo(buble_sort, data, size);
    cout << "the select_sort " << endl;
    generate_data(data, size);
    example_sort_algo(select_sort, data, size);
    cout << "the quick_sort "  << endl;
    generate_data(data, size);
    example_sort_algo(quick_sort, data, size);
    cout << "the insert_sort " << endl;
    generate_data(data, size);
    example_sort_algo(insert_sort, data, size);
    cout << "the heap_sort " << endl;
    generate_data(data, size);
    example_sort_algo(heap_sort, data, size);
    cout << "the merge_sort " << endl;
    generate_data(data, size);
    example_sort_algo(merge_sort, data, size);
    system("pause");

}
#endif // SORT_ALGO_H
