

struct Node{
    int nex[26]={
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,
    };

    int end=0;
    int cnt=0;
}tr[10];
int root;int tp;

void insert(int& now,char* s)
{
    if( now==-1 )now=++tp;
    ++tr[now].cnt;
    if(*s) insert(tr[now].nex[*s-'a'],s+1);
    else ++tr[now].end;
}

int search(char* s)
{
    int now=root;
    while( true ){
        if(now==-1)return 0;
        if( !*s )return tr[now].cnt;
        now=tr[now].nex[*(s++)-'a'];
    }
}
