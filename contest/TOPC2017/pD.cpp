#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
struct XDD{
    char ww;
    long long s;
    XDD *pre, *next;
};
int T,n;
XDD *tp,*head,*tail,*qq1,*qq2;
void print(){
    XDD *tp = head -> next;
    while(tp){
        printf("%lld%c ",tp->s,tp->ww);
        tp = tp -> next;
    }
    puts("");
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tp = new XDD;
        tp->s = -1;
        tp->ww= '1';
        head = tp;
        for(int i = 0 ;i < n ;i++){
            char qq[20];
            long long in;
            scanf("%s %lld",qq,&in);
            tp->next = new XDD;
            tp -> next -> pre = tp;
            tp = tp -> next;
            tp -> ww = qq[0];
            tp -> s = in;
        }
        tp -> next = NULL;
        tail = tp;
        tp = head->next;
        while(tp){
          //  printf("tp %lld%c   ",tp->s,tp->ww);
           //` print();
            if(tp == tail){
                while(tp->s>=3){
                    int tt;
                    tt = (tp->s)/3;
                    tp->s = ((tp->s)%3)+tt;
                }
                break;
            }
            if(tp == head ) tp = tp->next;
            if((tp -> s) >= 3){
                long long need = (tp->s)/3;
                if(tail->ww == tp -> ww) tail->s += need;
                else{
                    tail -> next = new XDD;
                    tail -> next -> pre = tail;
                    tail = tail->next;
                    tail->ww = tp->ww;
                    tail->s = need;
                    tail -> next = NULL;
                }
            }
            if((tp->s) % 3 != 0) {
                (tp->s) = (tp->s) %3;
                tp = tp->next;
            }else{
                if(tp -> pre -> ww == tp ->next -> ww){
                    qq1 = tp;
                    qq2 = tp->next;
                    if(tp->next == tail) tail=tp -> pre;
                    tp ->pre -> s += tp -> next -> s;
                    tp -> pre -> next = tp -> next -> next;
                    tp = tp -> pre;
                    if(tp->next)tp -> next -> pre = tp;

                    delete qq1;
                    delete qq2;
                }else{
                    qq1 = tp;
                    tp -> pre -> next = tp -> next;
                    tp = tp -> pre;
                    tp -> next -> pre = tp ;
                    delete qq1;
                }
            }

        }
        tp = head -> next;
        long long ans = 0;
        //print();
        while(tp){
            ans += tp->s;
            tp = tp-> next;
        }
        printf("%lld\n",ans);
    }
}
