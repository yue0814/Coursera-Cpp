#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char st[][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string wp[] = {"sword","bomb","arrow"};

class Weapon {
    private:
        string s;
    public:
        Weapon(string t){
            s=t;
        }
        string getName(){
            return s;
        }
};

class Soldier{
    private:
        int id;
        int type;
        double morale;
        int wpon[10];
        int loyalty;
    public:
        Soldier(int num,int b,int c,int d){
            id=num;
            type=b;
            if (b==3) loyalty=c; // lion
            if (b==0) { // dragon
                wpon[0]=1;
                wpon[1]=num%3;
                morale=(double)c/d; // 士气 
            }
            if (b==1){ //ninjia
                wpon[0]=2;
                wpon[1]=num%3;
                wpon[2]=(num+1)%3;
            }
            if (b==2){ // icemean
                wpon[0]=1;
                wpon[1]=num%3;
            }
        }
        double getMorale(){
            return morale;
        }
        int getLoyalty(){
            return loyalty;
        }
        int getWpon1(){
            return wpon[1];
        }
        int getWpon2(){
            return wpon[2];
        }
};

char typeName[2][10]={"red", "blue"};

class Camp{
    private:
        static int k[10];//soldiers' life
        int type;//red 0,blue 1;
        int cnt[10];//count for soldier
        int blood;
        int num;//soldier id
        int cnum;//creat num
    public:
        static void setK(int *p){
            for (int i=0;i<5;i++)
                k[i]=p[i];
        }
        Camp(int i,int b){//i:red or blue,b:blood
            if (i==0) type=0;
            else type=1;
            memset(cnt,0,sizeof(cnt));
            blood=b;
            num=0;cnum=0;
        }
        int getCamp(){
            return type;
        }
        string getName(){
            if (type==0) return "red";
            else return "blue";
        }
        int getTypeNum(int n){
            if (type==0){
                switch (n%5){
                    case 0:return 2;
                    case 1:return 3;
                    case 2:return 4;
                    case 3:return 1;
                    case 4:return 0;
                }
            }
            else {
                switch (n%5){
                    case 0:return 3;
                    case 1:return 0;
                    case 2:return 1;
                    case 3:return 2;
                    case 4:return 4;
                }
            }
        }
        int getNextSoldier(){
            int tmp=getTypeNum(cnum);
            blood-=k[tmp];
            int i;
            if (blood<0){
                blood+=k[tmp];
                for (i=1;i<5;i++){
                    tmp=getTypeNum(cnum+i);
                    if (blood>=k[tmp]){
                        cnum+=i;
                        blood-=k[tmp];
                        break;
                    }
                }
            }
            if (i==5) return 0;
            Soldier t(num+1,tmp,blood,k[0]);
            cnt[tmp]++;
            printf("%s %s %d born with strength %d,%d %s in %s headquarter\n",typeName[type],st[tmp],num+1,k[tmp],cnt[tmp],st[tmp],typeName[type]);
            if (tmp==0) printf("It has a %s,and it's morale is %.2lf\n",wp[t.getWpon1()].c_str(),t.getMorale());
            if (tmp==1) printf("It has a %s and a %s\n",wp[t.getWpon1()].c_str(),wp[t.getWpon2()].c_str());
            if (tmp==2) printf("It has a %s\n",wp[t.getWpon1()].c_str());
            if (tmp==3) printf("It's loyalty is %d\n",t.getLoyalty());
            num++;cnum++;
            return 1;
        }
};
int Camp::k[10]={0};
int main(int argc, char *argv[])
{
    int T;
    cin>>T;
    for (int i=1;i<=T;i++){
        int ti=0;
        cout<<"Case:"<<i<<endl;
        int b;cin>>b;
        Camp red(0,b),blue(1,b);
        int p[10];
        for (int i=0;i<5;i++)
            cin>>p[i];
        Camp::setK(p);
        int f1=0,f2=0;
        while (1){
            if (!f1)printf("%03d ",ti);
            if(!f1&&red.getNextSoldier()==0) {cout<<"red headquarter stops making warriors"<<endl;f1=1;}
            if (!f2)printf("%03d ",ti);
            if(!f2&&blue.getNextSoldier()==0) {cout<<"blue headquarter stops making warriors"<<endl;f2=1;}
            if (f1&&f2) break;
            ti++;
        }
    }
    return 0;
}