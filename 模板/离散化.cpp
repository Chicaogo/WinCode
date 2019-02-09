//离散化预处理
inline void discrete()
{
    //排序
    sort(a + 1,a + n + 1);
    //去重
    for(int i = 1;i <= n;++i)
    {
        if(i == 1 || a[i] != a[i-1])
            b[++m] = a[i];
    }
}

//二分查找 x映射为那个1~m之间的整数
inline int query(int x)
{
    return lower_bound(b + 1,b + m + 1,x) - b;
}