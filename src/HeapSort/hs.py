#!/usr/bin/env python
#-*-coding:utf-8-*-

def heap_sort(lst):
    def sift_up(start, end):
        """mix heap adjust"""
        root = start
        while True:
            child = root * 2 + 1
            if child > end:
                break
            if child + 1 <= end and lst[child] > lst[child + 1]:
                child += 1
            if lst[root] > lst[child]:
                lst[root], lst[child] = lst[child], lst[root]
                root = child
            else:
                break

    def sift_down(start, end):
        """最大堆调整"""
        root = start
        while True:
            print '\t\t', lst
            child = 2 * root + 1 # right child
            if child > end:
                break
            if child + 1 <= end and lst[child] < lst[child + 1]: # right child < left child
                child += 1
            if lst[root] < lst[child]: # 根小于右孩子, swap
                lst[root], lst[child] = lst[child], lst[root]
                root = child
            else:
                break

    # 创建最大堆
    print lst
    for start in xrange((len(lst) - 2) // 2, -1, -1):
        # 3, 2, 1, 0
        print '\t', lst
        # sift_down(start, len(lst) - 1)
        sift_up(start, len(lst) - 1)

    print lst

    # 堆排序
    for end in xrange(len(lst) - 1, 0, -1):
        lst[0], lst[end] = lst[end], lst[0]
        # sift_down(0, end - 1)
        sift_up(0, end - 1)
    return lst

def main():
    l = [2,9,1,7,6,8,5,3,4]
    heap_sort(l)
    print l

if __name__ == "__main__":
    main()
