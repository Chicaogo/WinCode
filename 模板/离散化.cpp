//��ɢ��Ԥ����
inline void discrete()
{
    //����
    sort(a + 1,a + n + 1);
    //ȥ��
    for(int i = 1;i <= n;++i)
    {
        if(i == 1 || a[i] != a[i-1])
            b[++m] = a[i];
    }
}

//���ֲ��� xӳ��Ϊ�Ǹ�1~m֮�������
inline int query(int x)
{
    return lower_bound(b + 1,b + m + 1,x) - b;
}