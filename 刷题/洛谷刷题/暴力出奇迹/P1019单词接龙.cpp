#include<bits/stdc++.h>
using namespace std;

int n;//������ 
string tr[30];//�洢�ַ��� 
int yc[30][30];//������ĸ����С�ص����� 
int vscode[30];//�жϵ���ʹ��Ƶ��. 
int mt(int x, int y){//mt����������x���ʺ�����һ��y���ʵ���С�ص����� 
    bool caonimade=true; 
    int ky=0;
    for(int k=tr[x].size()-1;k>=0;k--){//��x����β����ǰ������С�ص������Ǵ����￪ʼ�ģ���Ϊ��Ϊ�ǵ����������Ա�֤����С�� 
        for(int kx=k;kx<tr[x].size();kx++){
            if(tr[x][kx]!=tr[y][ky++]){
                caonimade=false;
                break;
            }
        }
        if(caonimade==true){//���˵��ǰ��kΪ��ͷ��ǰһ�����ʺ�׺ ,�Ǻ��浥�ʵ�ǰ׺�������Ϸ����ص����֡���tr[x].size()-k���ҳ����Ĺ��ɣ�
            return tr[x].size()-k;        } 
        ky=0;
        caonimade=true;//���оͼ���
    }
    return 0;
}//���������е�����⡣�����ֶ�ģ��һ��
char ch;//��ͷ��ĸ 
int ans=-1;//�� 
int an=0;//ÿ���ѵ��ĵ�ǰ��� 
void dddfs(int p){//pΪβ�����ʱ��(p�ĺ�׺���ǡ������ĺ�׺����Ϊp�Ѿ����ӵ�������������)
    bool jx=false; 
    for(int j=1;j<=n;j++){
        if(vscode[j]>=2) continue;//ʹ�������ξ����� 
        if(yc[p][j]==0) continue;//������֮��û���غϲ��־����� 
        if(yc[p][j]==tr[p].size() || yc[p][j]==tr[j].size()) continue;//���ߴ��ڰ�����ϵ������ 
        an+=tr[j].size()-yc[p][j];//�����ʺϲ��ټ�ȥ��С�غϲ��� 
        vscode[j]++;//ʹ����һ��
        jx=true;//���һ�µ�ǰ�Ѿ��ɹ�ƥ�䵽һ���������ӵĲ��� 
        dddfs(j); //����ȥ
        an-=tr[j].size()-yc[p][j];//���ݣ���Ҫ�ټ���ȥ��һ���ֳ��� 
        vscode[j]--;//����,ʹ��-- 
    }
    if(jx==false){//jx==false˵���������ҵ��κ�һ�����ʿ��������� 
        ans=max(ans,an);//����ans 
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>tr[i];
    cin>>ch; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            yc[i][j]=mt(i,j); 
        }
    }//Ԥ����yc���顣yc[i][j]�ͱ�ʾ��i���ʺ�����һ��j���ʵ���С�ص����� 
    //���� i��ʾat,j��ʾatt. yc[i][j]��Ϊ2 ����yc[j][i]��Ϊ0.
    //Ԥ������һ���ؼ�

    for(int i=1;i<=n;i++){//��ͷ��β��һ����û����ָ����ͷ��ĸΪ��ͷ�ĵ��� 
        if(tr[i][0]==ch){//����У����Ե�ǰ����Ϊ��׼���������� 
            vscode[i]++;//ʹ�ù�һ�� 
            an=tr[i].size();//���µ�ǰ������ 
            dddfs(i);//����
            vscode[i]=0;//����Ӱ�� 
        } 
    } 
    printf("%d",ans);
    return 0;
}
