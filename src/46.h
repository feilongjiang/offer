/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 20:23:50 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 20:54:06
 * 0, 1, ... , n-1 这n个数字排成一个圈，从数字0开始每次从这个圆圈
 * 里删除第m个数字。求出这个圆圈最后剩下的数字(约瑟夫环问题)
 */

// 思路
// 可以有两种做法
// 一是用一个环形链表模拟圆圈，按照每走m步就删除一个元素的思路，可以
// 求解
// 二是分析被删数字的规律
// 首先我们可以定义关于 n 和 m 的方程 f(n, m),表示每次在n个数字
// 0, 1, ..., n-1中删除第 m 个数后剩下的数
// 在这n个数字中，第一个被删除的是(m-1)%n，可以将其记为k，那么删除
// k之后剩下的数字为0, 1, ..., k-1, k+1, ..., n-1，并且下一次删
// 除从k+1开始计数。相当于在剩下的序列里，k+1排在最前面，从而形成
// k+1, ..., n-1, 1, ..., k-1。该序列最后剩下的数字应该也是关于
// n和m的函数。由于这个序列的规律和前面最初的序列不一样(最初的序列
// 是从0开始的连续序列)，因此该函数不同于前面的函数，即为f'(n-1, m)
// 最初序列最后剩下的数字f(n, m)一定和删除一个数字后剩下的数字相同，
// 即f(n, m) = f'(n-1, m)
// 接下来可以吧从k+1开始的序列映射到0, 1, ..., n-2，将映射定义为p，
// 则有p(x) = (x-k-1)%n，表示如果映射前的数为x，那么映射后的数为
// (x-k-1)%n
// 该映射的逆映射为p'(x) = (x+k+1)%n
// 由于映射后的序列和最初的序列具有同样的形式，都是从0开始的序列，
// 因此仍然可以用f来表示，即f(n-1, m)。根据映射规则，映射之前的
// 序列最后剩下数字
// f'(n-1, m) = p'[f(n-1, m)] = [f(n-1, m)+k+1]%n 
// 把k=(m-1)%n带入得
// f(n, m) = f'(n-1, m) = [f(n-1, m)+m]%n，即为递归公式，即
// f(n, m) = 
// 0                当n==1时
// [f(n-1, m)+m]%n  当n>1时

#pragma once

class Solution46{
public:
    int last_remaining(int n, int m)
    {
        if (n < 1) return -1;
        if (n <= 1) return 0;

        int last = 0;
        for (int i = 2; i <= n; ++i)
            last = (last + m) % i;
        
        return last;
    }

    int last_remaining_recursive(int n, int m)
    {
        if (n == 1) return 0;
        return (last_remaining_recursive(n - 1, m) + m) % n;
    }
};
